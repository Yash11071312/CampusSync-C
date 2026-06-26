#include <stdio.h>
#include "../include/student.h"
#include "../include/utils.h"
#include "../include/file.h"
int main(void)
{
    int choice;
   initializeStudentList();
printf("Loading Student Database...\n");
loadStudents();
    do
    {
        displayMainMenu();

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
           case 1:
        StudentManagement();
        break;

    case 2:
        printf("Academic Records - Coming Soon\n");
        break;

    case 3:
        printf("Rank List - Coming Soon\n");
        break;

case 4:
    statisticsMenu();
    break;
   case 0:
    saveStudents();
    printf("Goodbye!\n");
    break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 0);

    return 0;
}