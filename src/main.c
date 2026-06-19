#include <stdio.h>
#include "../include/student.h"
#include "../include/utils.h"

int main(void)
{
    int choice;

    initializeStudentList();

    do
    {
        displayMainMenu();

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

            case 0:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 0);

    return 0;
}