#include <stdio.h>
#include "../include/utils.h"
#include "../include/student.h"
int main(void)
{
    int choice;
initializeStudentList();
    displayMainMenu();

    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("\nYou selected: %d\n", choice);

    return 0;
}