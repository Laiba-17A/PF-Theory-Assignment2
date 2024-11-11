#include<stdio.h>
#include<string.h>
void sortLetters(char word[]) {
    int length = strlen(word);
    char temp;
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length - 1; j++) {
            if(word[j] > word[j + 1]) {
                temp = word[j];
                word[j] = word[j + 1];
                word[j + 1] = temp;
            }
        }
    }
}
int main(){
	int n;
	printf("enter the length of array ");
	scanf("%d",&n);
	char str_arr[n][20];
	char sort_arr[n][20];
	int i,j,y,z,a,len,b;
	int found=1;
	printf("enter the words\n");
	for(i=0;i<n;i++){
		scanf("%s",&str_arr[i]);
		strcpy(sort_arr[i],str_arr[i]);
		sortLetters(sort_arr[i]);
	}
	
	//testing
	printf("Array: [");
	for(i=0;i<n;i++){
		printf("%s ",str_arr[i]);
	}
	printf("]\n");
		printf("sorted array:[");
	for(i=0;i<n;i++){
		printf("%s ",sort_arr[i]);
	}
	printf("]\n");
	int x=1;
	char group[n][20];
	char temp[20];
	i=0;
	while(i<n){
		
		strcpy(temp,sort_arr[i]);
		a=strlen(temp);
		strcpy(group[x],str_arr[i]);
		
		for(j=i+1;j<n;j++){
		
			
			    len=strlen(sort_arr[j]);
			    if(a==len){
				   found=strcmp(temp,sort_arr[j]);
				    if(found==0){
					   x=x+1;
					   
					   strcpy(group[x],str_arr[j]);
					   
					   strcpy(sort_arr[j],"");
					   strcpy(str_arr[j],"");
					   
				    }
				    else{
				    	continue;
					}
			    }
			    else{
			    	continue;
			   	}
		   
		}
		if(strlen(group[x]) !=0 ){	
		    printf("[");
		    for(y=0;y<=x;y++){
			    printf("%s ",group[y]);
	       }
	        printf("]\n");
	    }
		x=0;
		group[n][20]='\0';
		i=i+1;
	}
	

    
	return 0;
}