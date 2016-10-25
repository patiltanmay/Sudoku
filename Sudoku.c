#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
char sudoku[10][10][10] = {1};
char ref[10][10][10] = {1};

void sudoku_1()
{
	sudoku[0][1][3] = 7;
	sudoku[0][1][4] = 2;
	sudoku[0][1][6] = 8;
	sudoku[0][1][7] = 3;
	sudoku[0][2][2] = 4;
	sudoku[0][2][4] = 6;
	sudoku[0][2][6] = 9;
	sudoku[0][2][8] = 7;
	sudoku[0][3][3] = 9;
	sudoku[0][3][7] = 2;
	sudoku[0][4][2] = 1;
	sudoku[0][4][4] = 5;
	sudoku[0][4][6] = 3;
	sudoku[0][4][8] = 8;
	sudoku[0][6][2] = 2;
	sudoku[0][6][4] = 1;
	sudoku[0][6][6] = 7;
	sudoku[0][6][8] = 6;
	sudoku[0][7][3] = 2;
	sudoku[0][7][7] = 6;
	sudoku[0][8][2] = 6;
	sudoku[0][8][4] = 7;
	sudoku[0][8][6] = 2;
	sudoku[0][8][8] = 5;
	sudoku[0][9][3] = 4;
	sudoku[0][9][4] = 3;
	sudoku[0][9][6] = 6;
	sudoku[0][9][7] = 9;
}
void sudoku_2()
{
	sudoku[0][1][2] = 8;
	sudoku[0][1][8] = 5;
	sudoku[0][2][1] = 5;
	sudoku[0][2][9] = 2;
	sudoku[0][3][1] = 1;
	sudoku[0][3][4] = 4;
	sudoku[0][3][6] = 8;
	sudoku[0][3][9] = 3;
	sudoku[0][4][2] = 4;
	sudoku[0][4][4] = 3;
	sudoku[0][4][6] = 1;
	sudoku[0][4][8] = 2;
	sudoku[0][5][3] = 2;
	sudoku[0][5][7] = 8;
	sudoku[0][6][2] = 5;
	sudoku[0][6][4] = 2;
	sudoku[0][6][6] = 7;
	sudoku[0][6][8] = 6;
	sudoku[0][7][1] = 4;
	sudoku[0][7][4] = 1;
	sudoku[0][7][6] = 9;
	sudoku[0][7][9] = 8;
	sudoku[0][8][1] = 6;
	sudoku[0][8][9] = 9;
	sudoku[0][9][2] = 3;
	sudoku[0][9][8] = 7;
}
void sudoku_3()
{
	sudoku[0][1][1] = 2;
	sudoku[0][1][2] = 7;
	sudoku[0][1][4] = 3;
	sudoku[0][1][9] = 5;
	sudoku[0][2][2] = 1;
	sudoku[0][2][6] = 6;
	sudoku[0][2][7] = 2;
	sudoku[0][3][1] = 6;
	sudoku[0][3][4] = 5;
	sudoku[0][4][3] = 7;
	sudoku[0][4][4] = 6;
	sudoku[0][4][8] = 5;
	sudoku[0][5][1] = 5;
	sudoku[0][5][9] = 6;
	sudoku[0][6][2] = 3;
	sudoku[0][6][6] = 7;
	sudoku[0][6][7] = 1;
	sudoku[0][7][6] = 3;
	sudoku[0][7][9] = 4;
	sudoku[0][8][3] = 3;
	sudoku[0][8][4] = 7;
	sudoku[0][8][8] = 9;
	sudoku[0][9][1] = 9;
	sudoku[0][9][6] = 2;
	sudoku[0][9][8] = 6;
	sudoku[0][9][9] = 7;
}

void print_sudoku(int z)
{
	int x,y;
	printf("\nSudoku[%d][][]\n",z);
	printf("-------------------------------------------------\n");
	for(y=1;y<10;y++)
	{
		for(x=1;x<10;x++)
		{
			if ((x-1)%3 == 0)
			{
				printf("|");
			}
			printf("  ");
			if (z == 0 && sudoku[z][y][x] == 0)
			{
				printf(" ");
			}
			else
			{
				printf("%c",sudoku[z][y][x]+48);
			}
			printf("  ");
		}
		printf("|");
		if (y%3 == 0)
		{
			printf("\n-------------------------------------------------");
		}
		printf("\n");
	}
	printf("\n");
}
void print_backup(char *back_up ,int z)
{
	int x,y;
	printf("\nBackUp - %d\n",z);
	printf("-------------------------------------------------\n");
	for(y=1;y<10;y++)
	{
		for(x=1;x<10;x++)
		{
			if ((x-1)%3 == 0)
			{
				printf("|");
			}
			printf("  ");
			if (z == 0 && back_up[(z*100)+(y*10)+x] == 0)
			{
				printf(" ");
			}
			else
			{
				printf("%c",back_up[(z*100)+(y*10)+x]+48);
			}
			printf("  ");
		}
		printf("|");
		if (y%3 == 0)
		{
			printf("\n-------------------------------------------------");
		}
		printf("\n");
	}
	printf("\n");
}

void load_sudoku()
{
	int x,y,z;
	for(y=1;y<10;y++)
	{
		for(x=1;x<10;x++)
		{
			for(z=1;z<10;z++)
			{
				sudoku[z][y][x] = 1;
				ref[z][y][x] = 1;
			}
		}
	}

	for(y=1;y<10;y++)
	{
		for(x=1;x<10;x++)
		{
			sudoku[0][y][x] = 0;
			ref[0][y][x] = 0;
		}
	}

	sudoku_3();

	for(y=1;y<10;y++)
	{
		for(x=1;x<10;x++)
		{
			ref[0][y][x] = sudoku[0][y][x];
			if(sudoku[0][y][x] != 0)
			{
				for(z=1;z<10;z++)
				{
					sudoku[z][y][x] = 0;
					ref[z][y][x] = 0;
				}
			}
		}
	}
}
int progress()
{
	int x,y,z;
	for(y=1;y<10;y++)
	{
		for(x=1;x<10;x++)
		{
			for(z=1;z<10;z++)
			{
				if(sudoku[z][y][x] != ref[z][y][x])
				{
					return 4;
				}
			}
		}
	}
	return 0;
}
void copy_to_ref()
{
	int x,y,z;
	for(y=1;y<10;y++)
	{
		for(x=1;x<10;x++)
		{
			for(z=1;z<10;z++)
			{
				ref[z][y][x] = sudoku[z][y][x];
			}
		}
	}
}
void calc_possibilities_row(int y,int z)
{
	int x;
	for(x=1;x<10;x++)
	{
		sudoku[z][y][x] = 0;
	}
}
void calc_possibilities_col(int x,int z)
{
	int y;
	for(y=1;y<10;y++)
	{
		sudoku[z][y][x] = 0;
	}
}
void calc_possibilities_box(int x,int y,int z)
{
	int xl,yl;
	xl=x-((x-1)%3);
	yl=y-((y-1)%3);
	//printf("xl = %d\nyl = %d\n", xl,yl);
	for(y=yl;y<yl+3;y++)
	{
		for(x=xl;x<xl+3;x++)
		{
			sudoku[z][y][x] = 0;
		}
	}
}
void calc_possibilities_z(int x,int y)
{
	int z;
	for(z=1;z<10;z++)
	{
		sudoku[z][y][x] = 0;
	}
}
void calc_possibilities()
{
	int x,y,z;
	for(y=1;y<10;y++)
	{
		for(x=1;x<10;x++)
		{
			if(sudoku[0][y][x] != 0)
			{
				calc_possibilities_row(y,sudoku[0][y][x]);
				calc_possibilities_col(x,sudoku[0][y][x]);
				calc_possibilities_box(x,y,sudoku[0][y][x]);
				calc_possibilities_z(x,y);
			}
		}
	}
}
void examine_possibility_rows(int z)
{
	int x,y,count,val;
	for(y=1;y<10;y++)
	{
		count=0;
		for(x=1;x<10;x++)
		{
			if(sudoku[z][y][x]==1)
			{
				count++;
				val = x;
			}
		}
		if (count==1)
		{
			sudoku[0][y][val] = z;
			calc_possibilities();
		}
	}
}
void examine_possibility_cols(int z)
{
	int x,y,count,val;
	for(x=1;x<10;x++)
	{
		count=0;
		for(y=1;y<10;y++)
		{
			if(sudoku[z][y][x]==1)
			{
				count++;
				val = y;
			}
		}
		if (count==1)
		{
			sudoku[0][val][x] = z;
			calc_possibilities();
		}
	}
}
void examine_possibility_boxs(int z)
{
	int xl,yl;
	int x,y,count,val;
	for(y=1;y<8;y=y+3)
	{
		for(x=1;x<8;x=x+3)
		{
			count=0;
			for(yl=y;yl<y+3;yl++)
			{
				for(xl=x;xl<x+3;xl++)
				{
					if(sudoku[z][y][x]==1)
					{
						count++;
						val = x;
					}
				}
			}
			if (count==1)
			{
				sudoku[0][y][val] = z;
				calc_possibilities();
			}
		}
	}
}
void examine_possibility()
{
	int x,y,z;
	for(z=1;z<10;z++)
	{
		examine_possibility_rows(z);
		examine_possibility_cols(z);
		examine_possibility_boxs(z);
	}
}
void one_possibility()
{
	int x,y,z,count,val;
	for(y=1;y<10;y++)
	{
		for(x=1;x<10;x++)
		{
			if(sudoku[0][y][x] == 0)
			{
				count=0;
				for(z=1;z<10;z++)
				{
					if(sudoku[z][y][x] == 1)
					{
						count++;
						val = z;
					}
				}
				if(count == 1)
				{
					sudoku[0][y][x]=val;
					sudoku[val][y][x]=0;
				}
			}
		}
	}
}
int check_completion()
{
	int x,y;
	for(y=1;y<10;y++)
		for(x=1;x<10;x++)
			if(sudoku[0][y][x] == 0)
				return 0;
	return 1;
}
int check_row(int y, int val)
{
	int x,count;
	count=0;
	for(x=1;x<10;x++)
		if(sudoku[0][y][x] == val)
			count++;
	if (count == 1)
	{
		return 1;
	}
	return 0;
}
int check_col(int x,int val)
{
	int y,count;
	count=0;
	for(y=1;y<10;y++)
		if(sudoku[0][y][x] == val)
			count++;
	if (count == 1)
	{
		return 1;
	}
	return 0;
}
int check_box(int x,int y,int val)
{
	int xl,yl,count;
	count=0;
	xl=x-((x-1)%3);
	yl=y-((y-1)%3);
	for(y=yl;y<yl+3;y++)
	{
		for(x=xl;x<xl+3;x++)
		{
			if(sudoku[0][y][x] == val)
				count++;
		}
	}
	if (count == 1)
	{
		return 1;
	}
	return 0;
}
int check_consistancy()
{
	int x,y;
	for(y=1;y<10;y++)
		for(x=1;x<10;x++)
		{
			if (check_box(x,y,sudoku[0][x][y]) == 0 ||	check_row(y,sudoku[0][x][y]) == 0 || check_col(x,sudoku[0][x][y]) == 0)
			{return 0;}
		}
	return 1;
}
int calc_min_assume(char *back_up)
{
	int x,y,z,count,min,val;
	val=-1;
	min = 100;
	for(z=1;z<10;z++)
	{
		count=0;
		for(y=1;y<10;y++)
			for(x=1;x<10;x++)
				count += back_up[(z*100) + (y*10) + x];
		if (count < min && count!=0)
		{
			min = count;
			val=z;
		}
	}
	return val;
}

void copy_to_backup(char *back_up)
{
	int x,y,z;
	for(z=0;z<10;z++)
		for(y=1;y<10;y++)
			for(x=1;x<10;x++)
				back_up[(z*100)+(y*10)+x] = sudoku[z][y][x];
}

void copy_from_backup(char *back_up)
{
	int x,y,z;
	for(z=0;z<10;z++)
		for(y=1;y<10;y++)
			for(x=1;x<10;x++)
				sudoku[z][y][x] = back_up[(z*100)+(y*10)+x];
}

int assume()
{
	int i =3;
	int x,y,z;
	char back_up[10][10][10];
	do
	{
		if (i>6)
		{i=6;}
		copy_to_ref();
		calc_possibilities();
		examine_possibility();
		one_possibility();
		i = progress()-1+i;
	}while(i >0);

	if (check_completion() == 1)
	{
		if (check_consistancy() == 1)
		{return 1;}
		else
		{return 0;}
	}
	else
	{
		copy_to_backup(&back_up[0][0][0]);
		i = calc_min_assume(&back_up[0][0][0]);
		if (i<1)
		{return 0;}
		for(y=1;y<10;y++)
			for(x=1;x<10;x++)
				if(back_up[i][y][x] == 1)
				{
					sudoku[0][y][x] = i;
					if(assume()==0)
						copy_from_backup(&back_up[0][0][0]);
					else
						return 1;
				}
		return 0;
	}
}

int main()
{
	int done=0;
	load_sudoku();
	printf("\nThe selected Q is :\n");
	print_sudoku(0);
	done = assume();
	if (done == 1)
		printf("\n\nThe solution is: ......enjoy :)\n");
	else
		printf("\n\nCannot find solution.   :(\n");
	print_sudoku(0);
	return 0;
}
