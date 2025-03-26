#include <stdio.h>
#include <string.h>

struct student {
    char name[100];
    float per;
};

// Function to store students' data
void store(struct student arr[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%s %f", arr[i].name, &arr[i].per); // Corrected format specifier
    }
}

// Function to print the names of students in sorted order
void print_name(struct student arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i].name);
    }
}

// Function to swap two students
void swap(struct student *a, struct student *b) {
    struct student temp = *a;
    *a = *b;
    *b = temp;
}

// Selection sort based on percentage
void selection_sort(struct student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxindex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[maxindex].per < arr[j].per) {
                maxindex = j;
            }
        }
        swap(&arr[maxindex], &arr[i]); // Swapping the entire struct
    }
}

int main() {
    int n;
    struct student students[100];
    
    printf("Enter the number of students (max 100): \n");
    scanf("%d", &n);
    
    // Input student data
    store(students, n);
    
    // Sort students based on percentage
    selection_sort(students, n);
    
    // Output the sorted names of students
    print_name(students, n);
    
    return 0;
}
