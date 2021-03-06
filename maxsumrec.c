//maxsumrec
#include<stdio.h>
#include<stdlib.h>

int max(int a, int b, int c){
 int max=0;
	if(a>max)max=a;
	if(b>max)max=b;
	if(c>max)max=c;
	return max;
}
//......................................................................................................................
int recursion(int i, int j, int m, int **board){
	int sum=0;
		if(i==0){
			sum=board[i][j];
		 }
		else {
			if(j==0){
				sum=board[i][j]+max(recursion(i-1, m, m, board), recursion(i-1, 0, m, board), recursion(i-1, 1,  m, board));
			}
			else if(j>0 && j<m){
				sum=board[i][j]+max(recursion(i-1, j-1,m, board), recursion(i-1, j, m, board), recursion(i-1, j+1, m, board));
			}
			else if(j==m){
				sum=board[i][j]+max(recursion(i-1, m-1, m, board), recursion(i-1, m, m, board), recursion(i-1, 0, m, board));
			}			
		}
	return sum;
}
//.......................................................................................
void solve(int n, int m, int **board){
	int max=0, j, sum;
	printf("Running maxsumrec\n");
		for(j=0;j<=m;j++){
			sum=recursion(n, j, m, board);
			if(sum>max)max=sum;
		}
	printf("Max sum is: %d\n", max);
}
