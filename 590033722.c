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

    printf("Student added successfully.\n");
}


void displayAllStudents(struct Student students[], int count)
{
    int i, j;

    if (count == 0)
    {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n========== ALL STUDENT RECORDS ==========\n");

    for (i = 0; i < count; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("-----------------------------------------\n");

        printf("SAP ID: %lld\n", students[i].sapID);
        printf("Roll Number: %s\n", students[i].rollNo);
        printf("Name: %s\n", students[i].name);
        printf("Phone: %s\n", students[i].phone);
        printf("Email: %s\n", students[i].email);
        printf("Year: %d\n", students[i].year);
        printf("Semester: %d\n", students[i].semester);

        printf("Semester-wise SGPA:\n");

        for (j = 0; j < 8; j++)
        {
            if (students[i].sgpa[j] >= 0)
            {
                printf("Semester %d: %.2f\n",
                       j + 1, students[i].sgpa[j]);
            }
        }
    }
}


void searchStudent(struct Student students[], int count)
{
    long long searchID;
    int i, j;

    printf("\nEnter SAP ID to search: ");
    if (scanf("%lld", &searchID) != 1)
    {
        printf("Invalid SAP ID input.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        if (students[i].sapID == searchID)
        {
            printf("\nStudent Found!\n");
            printf("SAP ID: %lld\n", students[i].sapID);
            printf("Roll Number: %s\n", students[i].rollNo);
            printf("Name: %s\n", students[i].name);
            printf("Phone: %s\n", students[i].phone);
            printf("Email: %s\n", students[i].email);
            printf("Year: %d\n", students[i].year);
            printf("Semester: %d\n", students[i].semester);

            for (j = 0; j < 8; j++)
            {
                if (students[i].sgpa[j] >= 0)
                {
                    printf("Semester %d SGPA: %.2f\n",
                           j + 1, students[i].sgpa[j]);
                }
            }

            return;
        }
    }

    printf("\nStudent with SAP ID %lld not found.\n", searchID);
}


float calculateCGPA(struct Student student)
{
    float total = 0.0f;
    int count = 0;

    for (int i = 0; i < 8; i++)
    {
        if (student.sgpa[i] >= 0 && student.sgpa[i] <= 10)
        {
            total += student.sgpa[i];
            count++;
        }
    }

    if (count == 0)
    {
        return -1.0f;
    }

    return total / count;
}


void academicAdvisor(struct Student students[], int count)
{
    long long sapID;
    int i;
    float cgpa;

    if (count == 0)
    {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n===== AI-ASSISTED ACADEMIC ADVISOR =====\n");
    printf("Enter Student SAP ID: ");

    if (scanf("%lld", &sapID) != 1)
    {
        printf("Invalid SAP ID input.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        if (students[i].sapID == sapID)
        {
            cgpa = calculateCGPA(students[i]);

            printf("\nStudent: %s\n", students[i].name);

            if (cgpa < 0)
            {
                printf("No SGPA available yet.\n");
                printf("Academic advice cannot be generated.\n");
            }
            else if (cgpa > 10.0f)
            {
                printf("Invalid CGPA value.\n");
            }
            else
            {
                printf("CGPA: %.2f\n", cgpa);

                if (cgpa >= 8.5f)
                {
                    printf("Category: Excellent Performance\n");
                    printf("Advice: Great work! Maintain your study routine and explore new learning opportunities.\n");
                }
                else if (cgpa >= 7.0f)
                {
                    printf("Category: Good Performance\n");
                    printf("Advice: You're doing well. Review weaker semesters and aim for consistent improvement.\n");
                }
                else if (cgpa >= 6.0f)
                {
                    printf("Category: Needs Improvement\n");
                    printf("Advice: Focus on regular revision, attendance and completing assignments on time.\n");
                }
                else
                {
                    printf("Category: Requires Immediate Attention\n");
                    printf("Advice: Speak with your academic mentor and prepare a weekly study plan.\n");
                }
            }

            return;
        }
    }

    printf("\nStudent not found!\n");
}




void displayStudentCGPA(struct Student students[], int count)
{
    long long sapID;
    int found = 0;

    printf("\nEnter SAP ID to calculate CGPA: ");
    if (scanf("%lld", &sapID) != 1)
    {
        printf("Invalid SAP ID input.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        if (students[i].sapID == sapID)
        {
            found = 1;

            float cgpa = calculateCGPA(students[i]);

            printf("\nStudent Name: %s\n", students[i].name);
            printf("SAP ID: %lld\n", students[i].sapID);

            if (cgpa < 0)
            {
                printf("CGPA not available. No semesters completed.\n");
            }
            else
            {
                printf("CGPA: %.2f\n", cgpa);
            }

            break;
        }
    }

    if (!found)
    {
        printf("\nStudent not found!\n");
    }
}


void displayYearAverage(struct Student students[], int count)
{
    int year, i;
    int studentCount;
    float totalCGPA, cgpa;

    printf("\n===== YEAR-WISE AVERAGE CGPA =====\n");

    for (year = 1; year <= 4; year++)
    {
        totalCGPA = 0.0f;
        studentCount = 0;

        for (i = 0; i < count; i++)
        {
            if (students[i].year == year)
            {
                cgpa = calculateCGPA(students[i]);

                if (cgpa >= 0)
                {
                    totalCGPA += cgpa;
                    studentCount++;
                }
            }
        }

        printf("\nYear %d: ", year);

        if (studentCount == 0)
        {
            printf("No CGPA data available.\n");
        }
        else
        {
            printf("Average CGPA = %.2f (%d students)\n",
                   totalCGPA / studentCount, studentCount);
        }
    }
}


void deleteStudent(struct Student students[], int *count)
{
    long long sapID;
    int i, j;

    if (*count == 0)
    {
        printf("\nNo student records available to delete.\n");
        return;
    }

    printf("\nEnter SAP ID of student to delete: ");

    if (scanf("%lld", &sapID) != 1)
    {
        printf("Invalid SAP ID input.\n");
        return;
    }

    for (i = 0; i < *count; i++)
    {
        if (students[i].sapID == sapID)
        {
            printf("\nDeleting student: %s\n", students[i].name);

            for (j = i; j < *count - 1; j++)
            {
                students[j] = students[j + 1];
            }

            (*count)--;

            printf("Student record deleted successfully!\n");
            return;
        }
    }

    printf("\nStudent with SAP ID %lld not found.\n", sapID);
}


void sortBySAPID(struct Student students[], int count)
{
    struct Student temp;
    int i, j;

    if (count == 0)
    {
        printf("\nNo student records available.\n");
        return;
    }

    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if (students[j].sapID > students[j + 1].sapID)
            {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("\nStudents sorted by SAP ID successfully!\n");
    displayAllStudents(students, count);
}


void sortByName(struct Student students[], int count)
{
    struct Student temp;
    int i, j;

    if (count == 0)
    {
        printf("\nNo student records available.\n");
        return;
    }

    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if (strcmp(students[j].name,
                       students[j + 1].name) > 0)
            {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("\nStudents sorted by Name successfully!\n");
    displayAllStudents(students, count);
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
                searchStudent(students, studentCount);
                break;

            case 3:
                displayStudentCGPA(students, studentCount);
                break;

            case 4:
                displayYearAverage(students, studentCount);
                break;

            case 5:
                displayAllStudents(students, studentCount);
                break;

            case 6:
                deleteStudent(students, &studentCount);
                break;

            case 7:
                sortBySAPID(students, studentCount);
                break;

            case 8:
                sortByName(students, studentCount);
                break;

            case 9:
                academicAdvisor(students, studentCount);
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