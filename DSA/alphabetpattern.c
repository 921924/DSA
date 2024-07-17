#include <stdio.h>
#include<stdlib.h>
void alphabet(int height)
{
	int row, col;
	for(row=0;row<height; row++)
	{
		for(col=0;col<=height/2;col++)
		{
		if((col==0&&row!=0)||(col==height/2 && row!=0)||(row== 0 &&(col!=0 ||col !=height/2))||row==height/2)
		{
			printf("*");
		}
		else
		printf(" ");
		}
printf("\n");
	}
}
int main(){
	int alp;
	printf("Enter the height: ");
	scanf("%d",&alp);
	alphabet(alp);
}
