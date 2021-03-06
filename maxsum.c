//main
#include<stdio.h>
#include<stdlib.h>
#include"headers.h"
int main(void){
	int m, n, i, j;
	int **board;
		
		scanf("%d",&n);
		scanf("%d",&m);
		
		board=malloc(n*sizeof(int *));
		if(board==NULL){
			printf("Sorry, cannot allocate memory\n");
			return -1;
		}
		for(i=0;i<n;i++){
			*(board+i)=malloc(m*sizeof(int));
			if(*(board+i)==NULL){
				printf("Sorry, cannot allocate memory\n");
				return -1;
			}
		}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&board[i][j]);
		}
	}
		solve(n-1, m-1, board);

	for(i=0;i<n;i++)
		free(board[i]);
	free(board);

	return 0;
}
