#include "input.h"

void SolveMaze(struct ReadMaze maze)
{
	struct Solver crawler;
	int endRow = maze.end[1];
	int endCol = maze.end[0];
	char nullChar = 'x'; /* Represents possible empty space on maze edge */
	char up, dn, rt, lf;

	crawler.row = maze.start[1];
	crawler.col = maze.start[0];

	/* Default values. Updates on loop start */
	crawler.currentDir = SOUTH;
	crawler.fwd = nullChar;
	crawler.left = nullChar;
	crawler.right = nullChar;
	crawler.rear = nullChar;

	while (crawler.row != endRow && crawler.col != endCol)
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
		 * To-Do: Get the solver to know when to rotate and advance
		 * (Based on these previously set environment values)
		 *
		 * - Check if fwd is open (a '0')
		 * - If right is suddenly open, rotate right
		 * - If fwd and right are both blocked, rotate left
		 * - If fwd, right & left are blocked, do a 180 and go back
		 *   (Following the right-hand rule still)
		 *
		 * Go until Solver's co-ords line up with maze's end
		 */
	}
}

int DrawPath(char* spot)
{
	/*
	 * As a failsafe, only change a character if it is an empty space in the maze
	 * (In other words, don't change if a wall or something else)
	 */
	if(*spot == '0')
	{
		*spot = '.';
		return 0;
	}
	else
		return 1;
}
