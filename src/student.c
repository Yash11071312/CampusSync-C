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
    newStudent->total = 0;
    newStudent->percentage = 0;
    newStudent->cgpa = 0;
    newStudent->grade = 'F';
    for (int i = 0; i < 5; i++)
    {
        newStudent->marks[i] = 0;
    }
    newStudent->next = NULL;
    if (head == NULL)
    {
        head = newStudent;
    }
    else
    {
        Student *temp = head;
        while ((temp->next) != NULL)
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
    scanf("%d", &searchRoll);

    Student *temp = head;

    while (temp != NULL)
    {
        if (temp->rollNo == searchRoll)
        {
            printf("\nStudent Found!\n");
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

        temp = temp->next;
    }

    printf("\nStudent not found!\n");
}

void deleteStudent(void)
{
    int searchRoll;

    printf("Enter Roll Number: ");
    scanf("%d", &searchRoll);

    Student *temp = head;
    Student *prev = NULL;
    while (temp != NULL)
    {

        if (temp->rollNo == searchRoll)
        {
            if (temp == head)
            {
                head = temp->next;
                free(temp);
                printf("\nStudent with Roll No %d deleted successfully!\n", searchRoll);
                return;
            }
            prev->next = temp->next;
            free(temp);
            printf("\nStudent with Roll No %d deleted successfully!\n", searchRoll);
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("\nStudent not found!\n");
}

void searchStudent(void)
{
    int searchRoll;

    printf("Enter Roll Number: ");
    scanf("%d", &searchRoll);

    Student *temp = head;

    while (temp != NULL)
    {
        if (temp->rollNo == searchRoll)
        {
            printf("\nStudent Found!\n");
            printf("-----------------------------\n");
            printf("Roll No    : %d\n", temp->rollNo);
            printf("Name       : %s\n", temp->name);
            printf("Department : %s\n", temp->department);
            printf("Semester   : %d\n", temp->semester);
            printf("-----------------------------\n");

            return;
        }

        temp = temp->next;
    }

    printf("\nStudent not found!\n");
}
void enterMarks(void)
{
    int searchRoll;

    printf("Enter Roll Number: ");
    scanf("%d", &searchRoll);

    Student *temp = head;

    while (temp != NULL)
    {
        if (temp->rollNo == searchRoll)
        {
            printf("\nStudent Found!\n");
            temp->total = 0;
            for (int i = 0; i < 5; i++)
            {
                printf("Enter Subject %d Marks: ", i + 1);
                scanf("%d", &temp->marks[i]);

                temp->total += temp->marks[i];
            }

            temp->percentage = temp->total / 5.0;
            temp->cgpa = temp->percentage / 9.5;

            if (temp->percentage >= 90)
                temp->grade = 'A';
            else if (temp->percentage >= 75)
                temp->grade = 'B';
            else if (temp->percentage >= 60)
                temp->grade = 'C';
            else if (temp->percentage >= 40)
                temp->grade = 'D';
            else
                temp->grade = 'F';

            printf("\nAcademic Record Added Successfully!\n");

            return;
        }

        temp = temp->next;
    }

    printf("\nStudent not found!\n");
}
void viewAcademicRecord(void)
{
    int searchRoll;

    printf("Enter Roll Number: ");
    scanf("%d", &searchRoll);

    Student *temp = head;

    while (temp != NULL)
    {
        if (temp->rollNo == searchRoll)
        {
            printf("\n===== Academic Record =====\n");

            printf("Name       : %s\n", temp->name);
            printf("Roll No    : %d\n", temp->rollNo);

            for (int i = 0; i < 5; i++)
            {
                printf("Subject %d : %d\n",
                       i + 1,
                       temp->marks[i]);
            }

            printf("Total      : %d\n", temp->total);
            printf("Percentage : %.2f\n", temp->percentage);
            printf("CGPA       : %.2f\n", temp->cgpa);
            printf("Grade      : %c\n", temp->grade);

            return;
        }

        temp = temp->next;
    }

    printf("\nStudent not found!\n");
}
void topperStudent(void)
{
    if (head == NULL)
    {
        printf("No students found!\n");
        return;
    }

    Student *temp = head;
    Student *topper = head;

    while (temp != NULL)
    {
        if (temp->percentage > topper->percentage)
        {
            topper = temp;
        }

        temp = temp->next;
    }

    printf("\n===== TOPPER =====\n");

    printf("Name       : %s\n", topper->name);
    printf("Roll No    : %d\n", topper->rollNo);
    printf("Percentage : %.2f\n", topper->percentage);
    printf("CGPA       : %.2f\n", topper->cgpa);
}
void classAverage(void)
{
    Student *temp = head;
    float sum = 0;
    int count = 0;
    if (head == NULL)
    {
        printf("No students found!\n");
        return;
    }
    while (temp != NULL)
    {
        sum += temp->percentage;
        count++;
        temp = temp->next;
    }
    if (count == 0)
    {
        printf("No students found!\n");
        return;
    }
    float average = sum / count;
    printf("\n===== CLASS AVERAGE =====\n");
    printf("Average Percentage : %.2f%%\n", average);
}
void failedStudents(void)
{
    Student *temp = head;
    int failCount = 0;
    while (temp != NULL)
    {
        if (temp->percentage < 40)
        {
            printf("\n--------------------------------------------");
            printf("Roll No    : %d\n", temp->rollNo);
            printf("Name       : %s\n", temp->name);
            printf("Percentage : %.2f%%\n", temp->percentage);
            printf("Failed\n");
            printf("\n--------------------------------------------");
            failCount++;
        }

        temp = temp->next;
    }
    if (failCount == 0)
    {
        printf("No failed students.\n");
        return;
    }
    printf("\nTotal Failed Students : %d\n", failCount);
}
void passPercentage(void)
{
    Student *temp = head;
    int passStudents = 0;
    int totalStudents = 0;

    if (head == NULL)
    {
        printf("No students found!\n");
        return;
    }
    while (temp != NULL)
    {
        if (temp->percentage >= 40)
        {
            passStudents++;
        }
        totalStudents++;
        temp = temp->next;
    }

    if (passStudents == 0)
    {
        printf("\n===== PASS PERCENTAGE =====\n");
        printf("Pass Percentage : 0.00%%\n");
        return;
    }
    float percentage = (passStudents * 100.0) / totalStudents;
    printf("\n===== Pass percentage =====\n");
    printf("Pass percentage : %.2f%%\n", percentage);
}
void totalStudents(void)
{
    Student *temp = head;
    int count = 0;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("\n===== TOTAL STUDENTS =====\n");
    printf("Total Students : %d\n", count);
}
void highestMarks(void)
{
    if(head == NULL)
    {
        printf("No students found!\n");
        return;
    }

    Student *temp = head;
    Student *highest = head;

    while(temp != NULL)
    {
        if(temp->total > highest->total)
        {
            highest = temp;
        }

        temp = temp->next;
    }

    printf("\n===== HIGHEST MARKS =====\n");
    printf("Name  : %s\n", highest->name);
    printf("Marks : %d\n", highest->total);
}
void lowestMarks(void)
{
    if(head == NULL)
    {
        printf("No students found!\n");
        return;
    }

    Student *temp = head;
    Student *lowest = head;

    while(temp != NULL)
    {
        if(temp->total < lowest->total)
        {
            lowest = temp;
        }

        temp = temp->next;
    }

    printf("\n===== LOWEST MARKS =====\n");
    printf("Name  : %s\n", lowest->name);
    printf("Marks : %d\n", lowest->total);
}