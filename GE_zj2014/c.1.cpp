#include <stdio.h>
#include <math.h>

#define MAX 100000

typedef struct{
	int M;
	int ID;
}Retailer;

int parent[MAX];
//int step[MAX];
int steptable[MAX]; 

Retailer retailer[MAX];

int main()
{
	int N;
	float P,r;
	int num,num_ret;
	int i,j;
	int temp,ret_temp;
	int dis;
	double sale, totalsales;

	freopen("c.txt","r",stdin);
	scanf("%d%f%f",&N,&P,&r);
	for(i=0; i<N; i++)
	{
		parent[i] = -1;
		//step[i] = 0;
	//	steptable[i] = 0;
	}

	num_ret = 0;

	for(i=0; i<N; i++)
	{
		scanf("%d",&num);
		if(num != 0)
		{
			j = 0;
			while(j++<num)
			{
				scanf("%d",&temp);
				//step[temp] = step[i]+1;
				parent[temp] = i;
				//printf("%d %d--",i,step[temp]);
			}
		}
		else
		{
			scanf("%d",&retailer[num_ret].M);
			retailer[num_ret].ID = i;
			num_ret ++;
		}
		//printf("\n");
	}

	totalsales = 0;
	for(i=0; i<num_ret; i++)
	{
		//printf("%d\n",step[i]);
		dis = 0;
		sale = 0;
		ret_temp = parent[retailer[i].ID];
		while(steptable[ret_temp] == 0 && ret_temp != -1)
		{
			steptable[ret_temp] = dis;
			ret_temp = parent[ret_temp];
			dis ++;
		}
		/*
ret_temp = parent[retailer[i].ID];
		while(ret_temp != -1)
		{
			steptable[ret_temp] = dis - steptable[ret_temp]; 
		}*/
		sale = retailer[i].M * P * pow((1+r/100),dis);
//		sale = retailer[i].M * P * pow((1+r/100),step[retailer[i].ID]);
		totalsales += sale;
	}
	printf("%.1f\n", totalsales);

	return 0;
}
