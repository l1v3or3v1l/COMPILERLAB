#include<stdio.h>
#include<string.h>
void main()
{
	int n,i,j,k,f;
	char s[10][10],t;
	printf("Enter the no.of statements ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the %dth statement ",i+1);
		scanf("%s",s[i]);
	}
	for(i=0;i<n;i++)
	{
		if(isdigit(s[i][2]) && s[i][3]=='\0')
		{
			f=s[i][2];
			t=s[i][0];
			s[i][0]='\0';
			for(j=i+1;j<n;j++)
			{
				if(s[j][0]==t)
				{
					break;
				}
				k=2;
				while(s[j][k]!='\0')
				{
					if(s[j][k]==t)
					{
						s[j][k]=f;
					}
					k=k+1;
				}
			}
		}
	}
	printf("Statement after removing constant propogation\n");
	for(i=0;i<n;i++)
	{
		printf("%s\n",s[i]);
	}
}
