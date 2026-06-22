#include <stdio.h>

#include <stdlib.h>
#include <string.h>


#include "../include/student.h"

Student *head = NULL;
void initializeStudentList(void)
{
    head = NULL;

    printf("Initializing Student Database...\n");
    printf("Student Database Ready.\n\n");
}
void addStudent(void)
{
Student *newStudent = (Student *)malloc(sizeof(Student));
if (newStudent == NULL)
{
    printf("Memory allocation failed!\n");
    return;
}
printf("Enter Roll Number: ");
scanf("%d", &newStudent->rollNo);
printf("Enter Name: ");
scanf(" %49[^\n]", newStudent->name);
printf("Enter Department: ");
scanf(" %29[^\n]", newStudent->department);
printf("Enter Semester: ");
scanf("%d", &newStudent->semester);
newStudent->next = NULL;
if (head == NULL)
{
    head = newStudent;
}
else
{
    Student *temp = head;
while ((temp->next)!= NULL)
{
    temp = temp->next;


}
temp->next = newStudent;


}
printf("\nStudent added successfully!\n");
printf("\n");
}

void viewStudents(void)
{
    if (head == NULL)
    {
        printf("\nNo students found!\n");
        return;
    }

    Student *temp = head;

    while (temp != NULL)
    {
        printf("\n-----------------------------\n");
        printf("Roll No    : %d\n", temp->rollNo);
        printf("Name       : %s\n", temp->name);
        printf("Department : %s\n", temp->department);
        printf("Semester   : %d\n", temp->semester);
        printf("-----------------------------\n");

        temp = temp->next;
    }
}

void updateStudent(void)
{
    int searchRoll;

printf("Enter Roll Number: ");
scanf("%d",&searchRoll);

     Student * temp =head;

while(temp!=NULL)
{
    if(temp->rollNo==searchRoll)
    {printf("\nStudent Found!\n");
printf("-----------------------------\n");
printf("Enter Name: ");
scanf(" %49[^\n]", temp->name);
printf("Enter Department: ");
scanf(" %29[^\n]", temp->department);
printf("Enter Semester: ");
scanf("%d", &temp->semester);

printf("\nStudent updated successfully!\n");
         return;
    }

    temp=temp->next;
}

    printf("\nStudent not found!\n");



}

void deleteStudent(void)
{
    int searchRoll;

printf("Enter Roll Number: ");
scanf("%d",&searchRoll);

     Student * temp =head;
Student * prev =NULL;
while(temp!=NULL)
{
   
    
    if(temp->rollNo==searchRoll){
         if (temp==head)
    {
    head=temp->next;
    free(temp);
printf("\nStudent with Roll No %d deleted successfully!\n", searchRoll);
    return;
    }
  prev->next=temp->next;
  free(temp);
printf("\nStudent with Roll No %d deleted successfully!\n", searchRoll);
         return;
    }

    prev=temp;
    temp=temp->next;
}

    printf("\nStudent not found!\n");

}

void searchStudent(void){
    int searchRoll;

printf("Enter Roll Number: ");
scanf("%d",&searchRoll);

     Student * temp =head;

while(temp!=NULL)
{
    if(temp->rollNo==searchRoll)
    {printf("\nStudent Found!\n");
printf("-----------------------------\n");
        printf("Roll No    : %d\n", temp->rollNo);
        printf("Name       : %s\n", temp->name);
        printf("Department : %s\n", temp->department);
        printf("Semester   : %d\n", temp->semester);
        printf("-----------------------------\n");


         return;
    }

    temp=temp->next;
}

    printf("\nStudent not found!\n");



}