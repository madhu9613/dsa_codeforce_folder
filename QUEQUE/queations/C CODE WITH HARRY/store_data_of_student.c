#include <stdio.h>
#include <string.h>

struct student
{
    int roll;
    float per;
    char name[20];
    char fname[20];
    char mname[20];
};

int main()
{
    struct student stu[100];
    int found = 0;
    int n, roll;
    
    printf("How many data entries do you want to store?\n");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        printf("Enter details of student %d:\n", i + 1);
        
        printf("Enter name:\n");
        scanf("%s", stu[i].name);  // No '&' needed for string input
        
        printf("Enter roll number:\n");
        scanf("%d", &stu[i].roll);
        
        printf("Enter father's name:\n");
        scanf("%s", stu[i].fname);  // No '&' needed for string input
        
        printf("Enter mother's name:\n");
        scanf("%s", stu[i].mname);  // No '&' needed for string input
        
        printf("Enter percentage obtained:\n");
        scanf("%f", &stu[i].per);  // Use '%f' for float input
    }
    
    // Search a student by their roll number
    printf("Enter the roll number of the student you want to search for:\n");
    scanf("%d", &roll);
    
    for (int i = 0; i < n; i++)
    {
        if (stu[i].roll == roll)
        {
            printf("Yes, we have found the data for roll number: %d\n", stu[i].roll);
            printf("Name: %s\n", stu[i].name);
            printf("Roll number: %d\n", stu[i].roll);
            printf("Father's name: %s\n", stu[i].fname);
            printf("Mother's name: %s\n", stu[i].mname);
            printf("Percentage obtained: %.2f\n", stu[i].per);
            found = 1;
            break;
        }
    }
    
    if (!found)
    {
        printf("Student with roll number %d is not found.\n", roll);
    }
    
    return 0;
}
