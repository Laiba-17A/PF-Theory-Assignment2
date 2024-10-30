#include <stdio.h>
int main(){
    int arr[5];
    int temp;
    printf("Input 5 elements in the array\n");
    for(int a=0;a<5;a++){
    printf("element %d: ",a+1);
    scanf("%d",&arr[a]);
    }
    int swap=1;
    int top=5;
   
       for(int x=0;x<5;x++){
        for(int i=0;i<5;i++){
            if (arr[i]>arr[i+1]){
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                
            }
          
        }
    }
    
    printf("the second smallest element in array is %d\n",arr[1]);
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    
    return 0;
}