#include <stdio.h>
#include "../include/student.h"

int main(void)
{
    int choice;

    printf("==========================================\n");
    printf("          CAMPUSSYNC-C\n");
    printf("==========================================\n");
    printf("Student Information System\n\n");

    printf("1. Student Management\n");
    printf("2. Academic Records\n");
    printf("3. Search Student\n");
    printf("4. Rank List\n");
    printf("5. Statistics\n");
    printf("0. Exit\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("\nYou selected: %d\n", choice);

    return 0;
}