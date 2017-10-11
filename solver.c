/*
 * Created by Ben Gustafson on 10/9/2017
 */

#include "input.h"

void SolveMaze(struct ReadMaze maze)
{
	struct Solver crawler;
	int endRow = maze.end[1];
	int endCol = maze.end[0];
	char nullChar = 'X'; /* Represents possible empty space on maze edge */
	char up, dn, rt, lf;

	crawler.row = maze.start[1];
	crawler.col = maze.start[0];

	/* Default value. Updates on loop start */
	crawler.currentDir = SOUTH;
	maze.MazeData[crawler.row][crawler.col] = '.';

	while (!(crawler.row == endRow && crawler.col == endCol))
	{
		/*
		 * Assign values from the Maze's data to placeholders; null if at an edge
		 * (That way, the code to assign them per direction isn't too verbose)
		 */
		if (crawler.row > 0)
			up = maze.MazeData[crawler.row - 1][crawler.col];
		else up = nullChar;
		if (crawler.col > 0)
			lf = maze.MazeData[crawler.row][crawler.col - 1];
		else lf = nullChar;
		if (crawler.row < maze.rows)
			dn = maze.MazeData[crawler.row + 1][crawler.col];
		else dn = nullChar;
		if (crawler.col < maze.Columns)
			rt = maze.MazeData[crawler.row][crawler.col + 1];
		else rt = nullChar;

		/*
		 * Assign placeholders to the Solver's respective values
		 * (Based on direction)
		 */
		switch (crawler.currentDir)
		{
			case NORTH:
				crawler.fwd = up;   /*    up    */
				crawler.left = lf;  /* lf  ^ rt */
				crawler.right = rt; /*    dn    */
				crawler.rear = dn;
				break;
			case EAST:
				crawler.fwd = rt;   /*    up    */
				crawler.left = up;  /* lf  > rt */
				crawler.right = dn; /*    dn    */
				crawler.rear = lf;
				break;
			case SOUTH:
				crawler.fwd = dn;   /*    up    */
				crawler.left = rt;  /* lf  v rt */
				crawler.right = lf; /*    dn    */
				crawler.rear = up;
				break;
			case WEST:
				crawler.fwd = lf;   /*    up    */
				crawler.left = dn;  /* lf  < rt */
				crawler.right = up; /*    dn    */
				crawler.rear = rt;
				break;
			default:
				break;
		}

		/*
		 * Get the solver to rotate and advance
		 * (Based on these previously set environment values)
		 * 
		 * Follows the right-hand-wall rule to solve
		 *
		 * Go until Solver's co-ords line up with maze's end
		 */
		switch (CheckEnvironment(crawler.fwd,   crawler.left,
								 crawler.right, crawler.rear))
		{
			/* If right is open */
			case 'R':
				/* Sets the enum to the next value (clockwise) */
				crawler.currentDir = (crawler.currentDir + 1) % 4;
				/* Move the solver based on its direction */
				if (crawler.currentDir == NORTH) --crawler.row;
				else if (crawler.currentDir == EAST) ++crawler.col;
				else if (crawler.currentDir == SOUTH) ++crawler.row;
				else if (crawler.currentDir == WEST) --crawler.col;
				break;
			/* If right is a wall and fwd is open */
			case 'F':
				/* Move the solver based on its direction */
				if (crawler.currentDir == NORTH) --crawler.row;
				else if (crawler.currentDir == EAST) ++crawler.col;
				else if (crawler.currentDir == SOUTH) ++crawler.row;
				else if (crawler.currentDir == WEST) --crawler.col;
				break;
			/* If right and fwd are walls and left is open */
			case 'L':
				/* Sets the enum to the previous value (counter-clockwise) */
				crawler.currentDir = (crawler.currentDir - 1) % 4;
				break;
			/* If all three but rear are walls */
			case 'B':
				/* Rotate the crawler 180 degrees */
				crawler.currentDir = (crawler.currentDir + 2) % 4;
				break;
			default:
				break;
		}
		/* Change the character under the solver to represent the path taken */
		maze.MazeData[crawler.row][crawler.col] = '.';
	}
	/* Display the solved maze */
	printf("Maze Solved!\n");
	Display(maze.MazeData, maze.Columns, maze.rows);
}

char CheckEnvironment(char fwd, char left, char right, char rear)
{
	/* Check if right is open */
	if (right != 'X')
		return 'R';
	/* Check if right is a wall and fwd is open */
	else if (right == 'X' && fwd != 'X')
		return 'F';
	/* Check if right and fwd are walls and left is open */
	else if (right == 'X' && fwd == 'X' && left != 'X')
		return 'L';
	/* Check if all three but rear are walls */
	else if (right == 'X' && fwd == 'X' && left == 'X' && rear != 'X')
		return 'B';
	/* Default return value, should never realistically be used */
	else
		return 'x';
}
