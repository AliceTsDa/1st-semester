//maxsummem
#include<stdio.h>
#include<stdlib.h>

int max(int a, int b, int c){
 int max=a;
	if(b>max)max=b;
	if(c>max)max=c;
	return max;
}
//...............................................................................................
int recursion(int i, int j, int m, int **board, int **S){

		if(S[i][j]!=-1){//i have it on my memory
			return S[i][j];
		}
		if(i==0){
			return S[i][j]=board[i][j];
		 }
		else {
			if(j==0){
				return S[i][j]=board[i][j]+max(recursion(i-1, m, m, board, S), recursion(i-1, 0, m, board, S), recursion(i-1, 1,  m, board, S));
			}
			else if(j>0 && j<m){
				return S[i][j]=board[i][j]+max(recursion(i-1, j-1,m, board, S), recursion(i-1, j, m, board, S), recursion(i-1, j+1, m, board, S));
			}
			else if(j==m){
				return S[i][j]=board[i][j]+max(recursion(i-1, m-1, m, board, S), recursion(i-1, m, m, board, S), recursion(i-1, 0, m, board, S));
			}			
		}
		
}
//-------------------------------------------------------------------------------------------------------------
int rightcollum(int j,int m){
	if (j<0){
		return m;
	}
	else if(j>m){
		return 0;
	}
	else if(j>=0 && j<=m){
		return j;
	}
}
//.............................................................................................
int check (int i,int j,int **S,int m){
	int p1,p2,p3,p4,p5,p6,maximum;

	p1=rightcollum(j-1,m);
	p2=rightcollum(j,m);
	p3=rightcollum(j+1,m);
	p4=S[i-1][p1];
	p5=S[i-1][p2];
	p6=S[i-1][p3];
	
	maximum=max(p4,p5,p6);

	if (maximum==p4){
		return p1;
	}
	else if(maximum==p5){
		return p2;
	}
	else if(maximum==p6){
		return p3;
	}
}
//......................................
int findpath(int n,int m,int **S,int *helpmatrix){
	int max=0,collum,j,i,k;
	for(collum=0;collum<=m;collum++){
		max=S[n][0];
		if(S[n][collum]>max){
			max=S[n][collum];
			j=collum;
		}
	}
	for (i=n;i>=1;i--){
		k=check(i,j,S,m);
		helpmatrix[i]=S[i][j]-S[i-1][k];
		j=k;
	}
	helpmatrix[0]=S[0][j];
}
//...............................................
void solve(int n, int m, int **board){
	int max=0, j, sum, k, z, i;
	int **S;
#ifdef PATH
	int *helpmatrix;
#endif

	printf("Running maxsummem\n");
	
		S=malloc((n+1)*sizeof(int *));
		if(S==NULL){
			printf("Sorry, cannot allocate memory\n");
			exit(1);
		}
		for(i=0;i<(n+1);i++){
			*(S+i)=malloc((m+1)*sizeof(int));
			if(*(S+i)==NULL){
				printf("Sorry, cannot allocate memory\n");
				exit(1);
			}
		}
	for(k=0;k<(n+1);k++){
		for(z=0;z<(m+1);z++){
			S[k][z]=-1;
		}
	}

#ifdef PATH
	helpmatrix = malloc((n+1) * sizeof(int));
	if(helpmatrix==NULL){
			printf("Sorry, cannot allocate memory\n");
			exit(1);
		}
	for(k=0;k<=n;k++){
		helpmatrix[k]=0;
	}
#endif
	
	for (j=0;j<=m;j++){
		if(max<recursion(n,j,m,board,S)){
			max=recursion(n,j,m,board,S);
		}
	}

	printf("Max sum is: %d\n", max);

#ifdef PATH
	findpath(n,m,S,helpmatrix);
	
	for(i=0;i<n;i++){
		printf("%d -> ",helpmatrix[i]);
	}
	printf("%d\n",helpmatrix[n]);
#endif
	
	for(i=0;i<(n+1);i++)
		free(S[i]);
	free(S);
}
