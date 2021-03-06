/*File: achilles.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COMPUTATIONS 10000000
int main(void){
int total, gcd, small, large, rem, i, temp, j, sum, m, n, POWERFULL,k,y,x,z;
srand(time(NULL));
total=0; //total of achilles

for (i=1;i<=COMPUTATIONS;i++){
	y=rand();
	z=rand();
	x=((y%32768)+1)*((z%32768)+1)+1;
	gcd=1;
	temp=x;
	POWERFULL=1;	/*lets say that it is POWERFULL because if it's not then this will change to 0 later or i will be forced with a continue back to asking for a new random number anyways*/
	sum=0;
	while (temp % 2 == 0){
		sum ++;
		temp /= 2;
		}
	
	if (sum==1){
		continue;		//if you find even one sum that's equal to 1 ask for a new random number
	}
	else{
		gcd=sum;		//the first gcd is the power of 2, if that is >1
	}
	
	//.............................................................................
	sum=0;
	while (temp % 3 == 0){
		sum ++;
		temp /= 3;
		}
	
	if (sum==1){
		continue;		//if you find even one sum that's equal to 1 ask for a new random number
	}
	else{				//find the new gcd
		m=gcd;			
		n=sum;
			if (m>n){
				large=m;
				small=n;
			}
			else{
				large=n;
				small=m;
			}
			while (small){
					rem=large%small;
				large=small;
				small=rem;
			}
			gcd=large;		
			}

	//........................................................................................
	for (j = 5; j*j <=x; j+=6){
		k=j+2;
		sum=0;
		while (temp % j == 0){
			temp /= j;
			sum++;
			}
		
		if (sum==1){
			POWERFULL=0;	//in case that i have a gcd from the % with 2 and 3
			break;
		}
		else{				//find the new gcd
			m=gcd;		
			n=sum;
				if (m>n){
					large=m;
					small=n;
				}
				else{
					large=n;
					small=m;
				}
				while (small){
					rem=large%small;
					large=small;
					small=rem;
				}
				gcd=large;
				}
		
		//............................................................................	
		sum=0;
		while (temp % k == 0){
			temp /=k;
			sum++;
			}
				if (sum==1){
					POWERFULL=0;	//in case that i have a gcd from the % with 2 and 3
					break;
				}
				else{				//find the new gcd
					m=gcd;	
					n=sum;
						if (m>n){
							large=m;
							small=n;
						}
						else{
							large=n;
							small=m;
						}
						while (small){
							rem=large%small;
							large=small;
							small=rem;
						}
						gcd=large;
						}


	
	}
	
//............................................................

if (temp>2){
	POWERFULL=0;
}

	if (POWERFULL==0){
		continue;				//the gcc that i have is invalid because x is not POWERFULL, so ask for a new random number
	}
	else{
		if (gcd==1){
			total++;
			printf("%d is achilles number\n",x);
		}
	}
	

}
		printf("I found %d achilles numbers",total);
		
			return 0;
}
