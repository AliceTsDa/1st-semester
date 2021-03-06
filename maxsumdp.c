//maxsumdpPATH
#include<stdio.h>
#include<stdlib.h>

int max(int a, int b, int c){
 int maximum=a;
	if(b>maximum)maximum=b;
	if(c>maximum)maximum=c;
	return maximum;
}
//.............................................................................................
int maxEXTRA(int a, int b, int c, int p1, int p2, int p3,int *k){
int maximum;
	maximum=a;
	*k=p1;
	if(b>maximum){
		maximum=b;
		*k=p2;
	}
	if(c>maximum){
		maximum=c;
		*k=p3;
	}
	
	return maximum;
}
//.............................................................................................
void solve(int n, int m, int **board){
int maxsum=0, j, sum, i, tempm=0, collum, row, k=0;
int **S;
	printf("Running maxsumdp\n");
	
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

	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			S[i][j]=board[i][j];
		}
	}

	for(i=n-1;i>=0;i--){
		for(j=0;j<=m;j++){
			if(j==0){
				S[i][j]+=(max(S[i+1][j],S[i+1][j+1],S[i+1][m]));
			}
			else if(j==m){
				S[i][j]+=(max(S[i+1][j],S[i+1][m-1],S[i+1][0]));
			}
			else{
				S[i][j]+=(max(S[i+1][j],S[i+1][j+1],S[i+1][j-1]));
			}
		}
	}

	for (j=0;j<=m;j++){
		if(maxsum<S[0][j]){
			maxsum=S[0][j];
		}
	}
	printf("Max sum is: %d\n", maxsum);

#ifdef PATH
	for(i=0;i<=n;i++){
		if(i==0){
			for (j=0;j<=m;j++){
				if(tempm<S[0][j]){
				tempm=S[0][j];
				collum=j;
				row=0;
				}
			}
			printf("%d",board[row][collum]);
		}
		else{
			if(collum==0){
				tempm=maxEXTRA(S[i][collum],S[i][collum+1],S[i][m],collum,(collum+1),m,&k);
				collum=k;
			}
			else if(collum==m){
				tempm=maxEXTRA(S[i][collum],S[i][m-1],S[i][0],collum,(m-1),0,&k);
				collum=k;
			}
			else{
				tempm=maxEXTRA(S[i][collum],S[i][collum+1],S[i][collum-1],collum,(collum+1),(collum-1),&k);
				collum=k;
			}

			printf("-> %d",board[i][collum]);
		}
		if(i==n)printf("\n");
	}
#endif

	for(i=0;i<(n+1);i++)
		free(S[i]);
	free(S);
}
