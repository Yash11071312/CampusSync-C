#include <stdio.h>
#include "../include/utils.h"

int main(void)
{
    int choice;

    displayMainMenu();

    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("\nYou selected: %d\n", choice);

    return 0;
}