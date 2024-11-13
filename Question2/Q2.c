#include <stdio.h>
int main()
{
	int len,i,j,c;
	int flag=0;
	int count[26]={0};//initialize it to 0
	char a[26]={0};//initialize it to 0
	char str[15];
	
	// get slogan from user
	printf("enter slogan:");
	gets(str);
	len=strlen(str);

	// compare each letter to every alphabet in the alphabet array
	for(i=0;i<len;i++)
	{
		flag=0;
		//nested loop to check single element with all element in the alphabet array
		for(j=0;j<26;j++)
		{
			//if the letter exists in alphabet array, increment count
			if(str[i]==a[j])
			{
				count[j]=count[j] + 1;
				flag=1;
				break;
			}
			
		}
		//add the letter to the albhabet array if it does not already exists
		if(flag==0)
		{
			a[c]=str[i];
			count[c]=count[c]+1;
			c=c+1;//increment count
		}
		
	}
	
	
	// displaying output
	for(i=0;i<26;i++)
	{
		if(count[i]>0)
		{
			printf("%c:%d ",a[i],count[i]);
		}
	}
}