#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct
{
	int ID;
	int GE;
	int GI;
	int presch[5];
}Applicant;

typedef struct
{
	int quota;
	int remqu;
	int appID[40000];
	int appIndex[40000];
	int lab;
}School;

Applicant a[40000];
School s[100];

int cmp(const void *a, const void *b)
{
	int g1,g2;
	g1 = (* (Applicant *)a).GE + (* (Applicant *)a).GI;
	g2 = (* (Applicant *)b).GE + (* (Applicant *)b).GI;
	if(g1 > g2 || (g1 == g2 && (* (Applicant  *)a).GE > (* (Applicant *)b).GE))
		return -1;
	else if(g1 == g2 && (* (Applicant *)a).GE == (* (Applicant *)b).GE)
		return 0;
	else
		return 1;
}

int compare(const void *a, const void *b)
{
	return (* (int *)a) - (* (int *)b);
}

int main()
{
	int N,M,K;

	cin >> N >> M >> K;

	for(int i=0; i<M; i++)
	{
		cin >> s[i].quota;
		s[i].remqu = s[i].quota;
		s[i].lab = 0;
	}

	for(int i=0; i<N; i++)
	{
		a[i].ID = i;
		cin >> a[i].GE >> a[i].GI;
		for(int j=0; j<K; j++)
		{
			cin >> a[i].presch[j];
		}
	}

	qsort(a,N,sizeof(a[0]),cmp);

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<K; j++)
		{
			int temp = a[i].presch[j];
			if(s[temp].remqu >0)
			{
				int pos = s[temp].lab++;
				s[temp].appID[pos] = a[i].ID;
				s[temp].appIndex[pos] = i;
				s[temp].remqu --;
				break;
			}
			else if(s[temp].remqu == 0)
			{
				int pos = s[temp].lab - 1;
				int index = s[temp].appIndex[pos];
				if(a[index].GE == a[i].GE && a[index].GI == a[i].GI)
				{
					s[temp].appID[pos+1] = a[i].ID;
					s[temp].appIndex[pos+1] = i;
					s[temp].lab ++;
					break;
				}
			}
		}
	}
	
	for(int i=0; i<M; i++)
	{
		qsort(s[i].appID,s[i].lab,sizeof(s[i].appID[0]),compare);
		
		for(int j=0; j<s[i].lab; j++)
		{
			cout << s[i].appID[j];
			j < s[i].lab - 1 ? cout << " ":cout << "";
		}
		cout << endl;
	}

	return 0;
}
