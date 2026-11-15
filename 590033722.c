#include <stdio.h>

#define MAX_STUDENTS 100

struct Student
{
    long long sapID;
    char rollNo[100];
    char name[50];
    char phone[15];
    char email[100];
    int year;
    int semester;
    float sgpa[8];
};

void addStudent(struct Student students[], int *count)
{
    if (*count >= MAX_STUDENTS)
    {
        printf("Student storage is full.\n");
        return;
    }

    int i;
    int completedSemesters;

    printf("\n--- Add New Student ---\n");

    printf("Enter SAP ID: ");
    scanf("%lld", &students[*count].sapID);

    printf("Enter Roll Number: ");
    scanf("%19s", students[*count].rollNo);

    printf("Enter Student Name: ");
    scanf(" %49[^\n]", students[*count].name);

    printf("Enter Phone Number: ");
    scanf("%14s", students[*count].phone);

    printf("Enter Email ID: ");
    scanf("%99s", students[*count].email);

    printf("Enter Year (1-4): ");
    scanf("%d", &students[*count].year);

    printf("Enter Current Semester (1-8): ");
    scanf("%d", &students[*count].semester);

    // Initialize all SGPA values as unavailable
    for (i = 0; i < 8; i++)
    {
        students[*count].sgpa[i] = -1;
    }

    printf("How many semesters have been completed (0-8)? ");
    scanf("%d", &completedSemesters);

    if (completedSemesters < 0 || completedSemesters > 8)
    {
        printf("Invalid number of semesters!\n");
        return;
    }

    for (i = 0; i < completedSemesters; i++)
    {
        printf("Enter SGPA for Semester %d: ", i + 1);
        scanf("%f", &students[*count].sgpa[i]);

        if (students[*count].sgpa[i] < 0 ||
            students[*count].sgpa[i] > 10)
        {
            printf("Invalid SGPA! Enter between 0 and 10.\n");
            i--;
        }
    }

    (*count)++;

    printf("Student SAP ID entered successfully!\n");
}

int main()
{
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do
    {
        printf("\n============================================\n");
        printf(" STUDENT RECORD AND RESULT MANAGEMENT SYSTEM\n");
        printf("============================================\n");

        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Display Student CGPA\n");
        printf("4. Display Average CGPA by Year\n");
        printf("5. Display All Students\n");
        printf("6. Delete Student\n");
        printf("7. Display Students Sorted by SAP ID\n");
        printf("8. Display Students Sorted by Name\n");
        printf("9. Academic Advisor\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent(students, &studentCount);
                break;

            case 2:
                printf("Search Student selected.\n");
                break;

            case 3:
                printf("Display Student CGPA selected.\n");
                break;

            case 4:
                printf("Display Average CGPA by Year selected.\n");
                break;

            case 5:
                printf("Display All Students selected.\n");
                break;

            case 6:
                printf("Delete Student selected.\n");
                break;

            case 7:
                printf("Sort by SAP ID selected.\n");
                break;

            case 8:
                printf("Sort by Name selected.\n");
                break;

            case 9:
                printf("Academic Advisor selected.\n");
                break;

            case 0:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;

}