//qtc 2013.3.20
#include<stdio.h>
int maze[5][5] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 0, 1, 0, 0,
	0, 0, 0, 1, 0
};


struct point {
	unsigned char l;
	unsigned char c;
};

struct element {
	struct point now;
	struct point previous;
};

struct element a = {0, 0, 0, 0};

void printmaze(struct element q)
{
	int i, j;
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			if(q.now.l == i && q.now.c == j)
				printf("Q ");
			else 
				printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
	printf("*********\n");
}

unsigned char forward(void)
{
	switch(1)
	{
		case 1://1:down
			if((a.now.l+1 != 5) && (maze[a.now.l+1][a.now.c] != 1) && (a.now.l+1 != a.previous.l))
			{
				a.previous = a.now;
				a.now.l++;
				return 1;
			}
		case 2://2:right
			if((a.now.c+1 != 5) && (maze[a.now.l][a.now.c+1] != 1) && (a.now.c+1 != a.previous.c))
			{
				a.previous = a.now;
				a.now.c++;
				return 2;
			}
		case 3://3:up
			if((a.now.l-1 >= 0) && (maze[a.now.l-1][a.now.c] != 1) && (a.now.l-1 != a.previous.l))
			{
				a.previous = a.now;
				a.now.l--;
				return 3;
			}
		case 4://4:left
			if((a.now.c-1 >= 0) && (maze[a.now.l][a.now.c-1] != 1) && (a.now.c-1 != a.previous.l))
			{
				a.previous = a.now;
				a.now.c--;
				return 4;
			}
		default:
			return 0;
	}
}

void back(void)
{
	switch(1)
	{
		case 1://1:up
			if((a.now.l-1 >= 0) && (maze[a.now.l-1][a.now.c] != 1))
			{
				a.previous = a.now;
				a.now.l--;
				break;
			}
		case 2://2:left
			if((a.now.c-1 >= 0) && (maze[a.now.l][a.now.c-1] != 1))
			{
				a.previous = a.now;
				a.now.c--;
				break;
			}
		case 3://3:down
			if((a.now.l+1 != 5) && (maze[a.now.l+1][a.now.c] != 1))
			{
				a.previous = a.now;
				a.now.l++;
				break;
			}
		case 4://4:right
			if((a.now.c+1 != 5) && (maze[a.now.l][a.now.c+1] != 1))
			{
				a.previous = a.now;
				a.now.c++;
				break;
			}
		default:
			break;
	}
}

int main(void)
{
	unsigned char flag = 0;
	printmaze(a);
	do {
		flag = forward();
		if(flag == 0)
			back();
		printmaze(a);
		} while((a.now.c + a.now.l != 0) && (a.now.c + a.now.l != 8));
	return 0;
}

