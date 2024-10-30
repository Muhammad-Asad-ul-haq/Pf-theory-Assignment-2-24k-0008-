#include <stdio.h>
#include <limits.h>

int main() {
	int i,num;
	int array[5];
	
	// taking input and storing them in array
	for(i=0;i<5;i++){
		printf("element - %d: ",i);
		scanf("%d",&num);
		array[i]=num;
	}
	
	//finding the second smallest element
	int smallest = INT_MAX, second_smallest = INT_MAX;
	for(i=0;i<5;i++){
		 if (array[i] < smallest) {
            second_smallest = smallest; 
            smallest = array[i]; 
        } else if (array[i] < second_smallest && array[i] != smallest) {
            second_smallest = array[i]; 
        }
	}
	
	//displaying the element
	printf("The second smallest element in the array is: %d\n", second_smallest);
    

    return 0;
}