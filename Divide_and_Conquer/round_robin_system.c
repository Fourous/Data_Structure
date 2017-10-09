#include <stdio.h>
#define Max  10000
int table[Max][Max] ;
void circlelateschedule(int row,int column,int n){
	if(n==1) return ;
	int half=n/2;
	table[row+half][column+half]=table[row][column];
	table[row][column+half]=table[row+half][column]=table[row][column]+half;
	circlelateschedule(row,column,half);
	circlelateschedule(row,column+half,half);
	circlelateschedule(row+half,column,half);
	circlelateschedule(row+half,column+half,half);
}

int main(void)
{
	int n;
	while(1){
		printf("please enter the player number\n");
		scanf("%d",&n);
		if(n==0){break;}
		table[0][0]=1;
		for (int i = 0; i < n; ++i)
		{
			for (int j= 0; j < n-1; ++j)
			{
				printf("%d      ",table[i][j] );
			}
			printf("\n");
		}
	}
	return 0;
}