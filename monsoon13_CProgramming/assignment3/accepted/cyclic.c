#include<stdio.h>
#include<string.h>

int main()
{
	int t, count, l1, l2, i=0, j, k, l, tmp;
	char s1[1002], s2[1002];
	scanf("%d", &t);
	for(i=0; i<t; i++)
	{
		scanf("%s %s", s1, s2);
		l1=strlen(s1);
		l2=strlen(s2);
		if(l1!=l2)
			printf("NO\n");
		else
		{	
		 for(j=0; j<l1; j++)
		 {
			for(k=0; k<l1; k++)
			{
				count=0;
				if(s1[j%l1]==s2[k%l1])
				{
					tmp=j;
					for(l=k; count<l1; l++,tmp++)
					{
						if(s1[tmp%l1]==s2[l%l1])
							count++;
						else
							break;
					}
				}
				if(count==l1)
					break;
			}
			if(count==l1)
				break;
		 }  
		 if(count==l1)
			printf("YES\n");
		 else
			printf("NO\n");
		}	
	}
	return 0;
}
