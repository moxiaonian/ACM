#include <stdio.h>
#include <math.h>

int a[10010];
int hashTable[10010];

int isPrime(int m)
{
	int i;
	if(m == 1)
		return 0;
	else
	{
		for(i=2; i<=sqrt(m); i++)
		{
			if(m % i == 0)
				return 0;
		}
		return 1;
	}
}

int findPrime(int m)
{
	int i;
	for(i=m+1; ;i++)
	{
		if(isPrime(i))
			return i;
	}
	return 0;
}

int printLab(int m,int prime)
{
	 int lab = m % prime;
	 int begin;
	 if(hashTable[lab] == 0)
	 {
	  	 hashTable[lab] = 1;
	  	 printf("%d",lab);
	 }
	 else
	 {
	 	begin = lab;
	 	for(int i=1; i<prime; i++)
	 	{
	 		lab = begin + i*i;
	 		if(lab >= prime)
	 			lab = lab % prime;
	 		if(hashTable[lab] == 0)
	 		{
	 			hashTable[lab] = 1;
	 			printf("%d",lab);
	 			return 0;
	 		}
	 	}
	 	printf("-");
	 }
	 return  0;
}

int main()
{
	int MSize,N;
	int i;
	int Prime;
      //freopen("b.txt","r",stdin);
	scanf("%d%d",&MSize,&N);
	for(i=0; i<N; i++)
	{
		scanf("%d",&a[i]);
  	}
  	if(isPrime(MSize))
  	{
  		Prime = MSize;
  	}
  	else
  	{
    	Prime = findPrime(MSize);
    }
    for(i=0; i<=N-2; i++)
    {
    	printLab(a[i],Prime);
    	printf(" ");
    }
    printLab(a[N-1],Prime);
    printf("\n");

    return 0;
}
