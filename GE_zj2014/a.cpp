#include <stdio.h>
#include <string.h>

char a[100][257];

int main()
{
	int N;
	int i;
	int com_len,len_temp;
	int flag;
	freopen("a.txt","r",stdin);
	scanf("%d\n",&N);
	for(i=0; i<N; i++)
	{
		gets(a[i]);
	}
	int num = i;
	int len0 = strlen(a[0]);
	com_len = 0;
	flag = 0;
	for(i=len0-1; i>=0; i--)
	{
		for(int j=1; j<num; j++)
		{
			len_temp = strlen(a[j]);
			if(len_temp <= com_len || a[0][i] != a[j][len_temp-1-com_len])
			{
				flag = 1;
				break;
			}
		}
		if(flag)
			break;
		com_len ++;
	}
	if(com_len)
	{
		for(i=len0-com_len; i<=len0-1; i++)
		{
			printf("%c",a[0][i]);
		}
		printf("\n");
	}
	else{
		printf("nai\n");
	}
	return 0;
}
