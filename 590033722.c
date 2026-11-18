#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

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


void clearInputBuffer(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }
}



void addStudent(struct Student students[], int *count)
{
    int i;
    int completedSemesters;
    int inputOK;

    if (*count >= MAX_STUDENTS)
    {
        printf("\nStudent storage is full.\n");
        return;
    }

    printf("\n--- Add New Student ---\n");

    // SAP ID input and duplicate checking
    while (1)
    {
        printf("Enter SAP ID: ");

        inputOK = scanf("%lld", &students[*count].sapID);

        if (inputOK != 1)
        {
            printf("Invalid SAP ID. Enter numbers only.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        if (students[*count].sapID <= 0)
        {
            printf("SAP ID must be positive.\n");
            continue;
        }

        for (i = 0; i < *count; i++)
        {
            if (students[i].sapID == students[*count].sapID)
            {
                break;
            }
        }

        if (i < *count)
        {
            printf("Error: This SAP ID already exists!\n");
            return;
        }

        break;
    }

    // Roll number
    printf("Enter Roll Number: ");
    while (scanf("%19s", students[*count].rollNo) != 1)
    {
        printf("Invalid roll number. Try again: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    
    
    // Student name validation
    int validName;
    int hasLetter;

    while (1)
    {
        printf("Enter Student Name: ");

        if (fgets(students[*count].name,
                  sizeof(students[*count].name), stdin) == NULL)
        {
            printf("Error reading name.\n");
            return;
        }

        // Remove newline
        students[*count].name[
            strcspn(students[*count].name, "\n")
        ] = '\0';

        validName = 1;
        hasLetter = 0;

        for (i = 0; students[*count].name[i] != '\0'; i++)
        {
            unsigned char ch =
                (unsigned char)students[*count].name[i];

            if (isalpha(ch))
            {
                hasLetter = 1;
            }
            else if (ch != ' ')
            {
                validName = 0;
                break;
            }
        }

        if (validName && hasLetter)
        {
            break;
        }

        printf("Invalid name! Only letters and spaces allowed.\n");
    }

    // Phone number
    printf("Enter Phone Number: ");
    while (scanf("%14s", students[*count].phone) != 1)
    {
        printf("Invalid phone number. Try again: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    // Email
    printf("Enter Email ID: ");
    while (scanf("%99s", students[*count].email) != 1)
    {
        printf("Invalid email. Try again: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    // Year validation
    while (1)
    {
        printf("Enter Year (1-4): ");

        if (scanf("%d", &students[*count].year) != 1)
        {
            printf("Invalid input. Enter a number.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        if (students[*count].year >= 1 &&
            students[*count].year <= 4)
        {
            break;
        }

        printf("Year must be between 1 and 4.\n");
    }

    // Semester validation
    while (1)
    {
        printf("Enter Current Semester (1-8): ");

        if (scanf("%d", &students[*count].semester) != 1)
        {
            printf("Invalid input. Enter a number.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        if (students[*count].semester >= 1 &&
            students[*count].semester <= 8 &&
            (students[*count].semester + 1) / 2 ==
            students[*count].year)
        {
            break;
        }

        printf("Invalid semester for the selected year.\n");
    }

    // Initialize unavailable SGPA values
    for (i = 0; i < 8; i++)
    {
        students[*count].sgpa[i] = -1.0f;
    }

    // Completed semesters validation
    while (1)
    {
        printf("How many semesters have been completed? ");

        if (scanf("%d", &completedSemesters) != 1)
        {
            printf("Invalid input. Enter a number.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        if (completedSemesters >= 0 &&
            completedSemesters <= students[*count].semester)
        {
            break;
        }

        printf("Invalid number of completed semesters.\n");
    }

    // SGPA input and validation
    for (i = 0; i < completedSemesters; i++)
    {
        while (1)
        {
            printf("Enter SGPA for Semester %d: ", i + 1);

            if (scanf("%f", &students[*count].sgpa[i]) != 1)
            {
                printf("Invalid input. Enter a number.\n");
                clearInputBuffer();
                continue;
            }

            clearInputBuffer();

            if (isfinite(students[*count].sgpa[i]) &&
                students[*count].sgpa[i] >= 0.0f &&
                students[*count].sgpa[i] <= 10.0f)
            {
                break;
            }

            printf("SGPA must be between 0 and 10.\n");
        }
    }

    (*count)++;

    printf("\nStudent added successfully!\n");
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

        if (scanf("%d", &choice) != 1)
{
    printf("Invalid input! Please enter a number.\n");

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }

    choice = -1;
    continue;
}

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