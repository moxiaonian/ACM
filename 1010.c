#include <stdio.h>
#include <string.h>

char a[2][10];
char b[2][10];

int strtonum(char a[][10])
{
	int a1,a2;
	if(strcmp(a[0],"zero")==0)
		a1=0;
	else if(strcmp(a[0],"one")==0)
		a1=1;
	else if(strcmp(a[0],"two")==0)
		a1=2;
	else if(strcmp(a[0],"three")==0)
		a1=3;
	else if(strcmp(a[0],"four")==0)
		a1=4;
	else if(strcmp(a[0],"five")==0)
		a1=5;
	else if(strcmp(a[0],"six")==0)
		a1=6;
	else if(strcmp(a[0],"seven")==0)
		a1=7;
	else if(strcmp(a[0],"eight")==0)
		a1=8;
	else if(strcmp(a[0],"nine")==0)
		a1=9;
	if(a[1][0]!='\0'){
		if(strcmp(a[1],"zero")==0)
			a2=0;
		else if(strcmp(a[1],"one")==0)
			a2=1;
		else if(strcmp(a[1],"two")==0)
			a2=2;
		else if(strcmp(a[1],"three")==0)
			a2=3;
		else if(strcmp(a[1],"four")==0)
			a2=4;
		else if(strcmp(a[1],"five")==0)
			a2=5;
		else if(strcmp(a[1],"six")==0)
			a2=6;
		else if(strcmp(a[1],"seven")==0)
			a2=7;
		else if(strcmp(a[1],"eight")==0)
			a2=8;
		else if(strcmp(a[1],"nine")==0)
			a2=9;
		return a1*10+a2;
	}
	return a1;
}

int main()
{
	int anum,bnum;
	int i;
	char c;
	while(1)
	{
		for(i=0;i<=1;i++){
			memset(a[i],'\0',sizeof(a[i]));
			memset(b[i],'\0',sizeof(b[i]));
		}
		i=0;
		while((c=getchar())!=' ')
		{
			a[0][i++]=c;
		}
		a[0][i]='\0';
		if((c=getchar())!='+')
		{
			a[1][0]=c;
			for(i=1;(c=getchar())!=' ';i++)
		 		a[1][i]=c;
			a[1][i]='\0';
			getchar();
		}
		getchar();
	//	puts(a[0]);
	//	puts(a[1]);
		i=0;
		while((c=getchar())!=' ')
		{
			b[0][i++]=c;
		}
		b[0][i]='\0';
		if((c=getchar())!='=')
		{
			b[1][0]=c;
			for(i=1;(c=getchar())!=' ';i++)
		 		b[1][i]=c;
			b[1][i]='\0';
			getchar();
		}
		getchar();
	//	puts(b[0]);
	//	puts(b[1]);
		if(strcmp(a[0],"zero")==0 && strcmp(b[0],"zero")==0 && a[1][0]=='\0' &&b[1][0]=='\0')
			return 0;
		anum=strtonum(a);
		bnum=strtonum(b);
		printf("%d\n",anum+bnum);		
	//	fflush(stdin);
	}
	return 0;
}
