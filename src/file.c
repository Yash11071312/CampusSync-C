#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/file.h"
#include "../include/student.h"
typedef struct
{
    int rollNo;
    char name[50];
    char department[30];
    int semester;
} StudentData;

void saveStudents(void)
{
    FILE *fp = fopen("students.dat", "wb");

    if(fp == NULL)
    {
        printf("Error saving file!\n");
        return;
    }

    Student *temp = head;

    while(temp != NULL)
    {
        StudentData data;

        data.rollNo = temp->rollNo;
        strcpy(data.name, temp->name);
        strcpy(data.department, temp->department);
        data.semester = temp->semester;

        fwrite(&data, sizeof(StudentData), 1, fp);

        temp = temp->next;
    }

    fclose(fp);

    printf("Data saved successfully!\n");
}
void loadStudents(void)
{
    FILE *fp = fopen("students.dat", "rb");

    if(fp == NULL)
    {
        printf("No previous data found.\n");
        return;
    }

    StudentData data;

    while(fread(&data, sizeof(StudentData), 1, fp))
    {
        Student *newStudent = malloc(sizeof(Student));

        newStudent->rollNo = data.rollNo;
        strcpy(newStudent->name, data.name);
        strcpy(newStudent->department, data.department);
        newStudent->semester = data.semester;

        newStudent->next = NULL;

        if(head == NULL)
        {
            head = newStudent;
        }
        else
        {
            Student *temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newStudent;
        }
    }

    fclose(fp);

    printf("Students loaded successfully!\n");
}