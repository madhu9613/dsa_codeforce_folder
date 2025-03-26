#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL;  
    int capacity = 0; 
    int size = 0;     
    char input[20];  

    printf("Enter numbers (Press Enter to stop):\n");

    while (1) {
        fgets(input, sizeof(input), stdin); 
        
        
        if (input[0] == '\n') {
            break;
        }
        
        
        int value = atoi(input);

       
        if (size == capacity) {

            capacity = (capacity == 0) ? 1 : capacity*2;
            arr = realloc(arr, capacity * sizeof(int));
            
           
            if (arr == NULL) {
                printf("Memory allocation failed.\n");
                exit(1);
            }
        }

       
        arr[size++] = value;
    }

    
    printf("You entered: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); // Free allocated memory
    return 0;
}
