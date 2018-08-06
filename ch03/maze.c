#include <stdio.h>

void path(){
	int i, row, col, nextrow, nextcol, dir, found = 0;
	element position;
	mark[1][1] = 1; top = 0;
	stack[0].row = 1; stack[0].col = 1; stack[0].dir = 1;
	while (top > -1 && !found){
		position = pop();
		row = position.row; col = position.col;
		dir = position.dir;
		while (dir < 8 && !found){
			nextrow = row + move[dir].vert;
			nextcol = col + move[dir].horiz;
			
		}
	}
}