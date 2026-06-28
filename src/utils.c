#include <stdio.h>
#include "../include/utils.h"
#include "../include/student.h"

void displayMainMenu(void)
{
    printf("==========================================\n");
    printf("          CAMPUSSYNC-C\n");
    printf("==========================================\n");
    printf("Student Information System\n\n");

    printf("1. Student Management\n");
    printf("2. Academic Records\n");

    printf("3. Rank List\n");
    printf("4. Statistics\n");
    printf("0. Exit\n\n");
}
void StudentManagement(void)
{
    int choice;
    do
    {
        printf("==========================================\n");
        printf("Student Management\n");
        printf("==========================================\n");

        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Enter Marks\n");
        printf("7. View Academic Record\n");

        printf("0. Main menu\n\n");

        printf("--------------------------------------------\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            viewStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            deleteStudent();
            break;
        case 6:
            enterMarks();
            break;

        case 7:
            viewAcademicRecord();
            break;
        case 0:
            printf("\nReturning to Main Menu...\n\n");
            break;
        }

    } while (choice != 0);
}
void statisticsMenu(void)
{
    int choice;

    do
    {
        printf("\n==========================================\n");
        printf("             STATISTICS\n");
        printf("==========================================\n");

        printf("1. Class Average\n");
        printf("2. Failed Students\n");
        printf("3. Pass Percentage\n");
        printf("4. Topper Student\n");
        printf("5. Total Students\n");
        printf("6. Highest Marks\n");
        printf("7. Lowest Marks\n");
        printf("8. Grade Statistics\n");
        printf("0. Back\n\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            classAverage();
            break;

        case 2:
            failedStudents();
            break;

        case 3:
            passPercentage();
            break;

        case 4:
            topperStudent();
            break;
        case 5:
            totalStudents();
            break;

        case 6:
            highestMarks();
            break;

        case 7:
            lowestMarks();
            break;

        case 8:
            gradeStatistics();
            break;

        case 0:
            printf("Returning to Main Menu...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 0);
}