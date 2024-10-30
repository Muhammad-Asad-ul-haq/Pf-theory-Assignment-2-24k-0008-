#include <stdio.h>

int main()
{
    int p;
    printf("Enter number of elements: ");
    scanf("%d",&p);
    int arr[p];
    for (int i=0;i<p;i++)   
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    int min;
    int sec_min;
    int y;
     if (arr[0]<arr[1])
        {
            min=arr[0];
            sec_min=arr[1];
        }else{
            min=arr[1];
            sec_min=arr[0];
        }
        
    for (int i=2;i<p;i++)
    {
        if(arr[i]<min)
        {
            sec_min=min;
            min=arr[i];
        
        }
        else if(arr[i]<sec_min && arr[i]>min)
        {
            sec_min=arr[i];
        }
      
    }
            printf("Second Smallest element is: %d\n",sec_min);
   

    

    return 0;
}
