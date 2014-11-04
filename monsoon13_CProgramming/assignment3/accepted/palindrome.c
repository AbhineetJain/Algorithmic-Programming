#include<stdio.h>
#include<string.h>

int main()
{
	char string[10000], longest[10000]="", temp[10000]="";
	int i, j, k, l, p;
	int length, len=0, longst=0;
	while(~scanf("%s", string))
	{
		length=strlen(string);
		longest[0]='\0';
		longst=0;
		for(i=0; i<length; i++)
		{
			for(j=i; j<length; j++)
			{
				len=0;
				temp[0]='\0';
				if(string[j]==string[i])
				{
					for(k=i, l=j, p=0 ; k<=l; k++, l--)
					{
						if(string[k]==string[l])
						{
							temp[p]=temp[p+l-k]=string[k];
							p++;
						}
						else
						{
							p=-2;
							break;	
						}
					}
					if(p==-2)
						temp[p+2]='\0';					
					else
						temp[j-i+1]='\0';
					len=strlen(temp);
					if(len>longst)
					{
						longst=len;
						strcpy(longest, temp);
					}
					else if(len==longst)
					{
						if(strcmp(temp, longest)<0)
							strcpy(longest, temp);
					}
				}
			}
		}
		printf("%s\n", longest);
	}
	return 0;
}
