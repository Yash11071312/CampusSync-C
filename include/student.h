#ifndef STUDENT_H
#define STUDENT_H
typedef struct Student
{
    int rollNo;
    char name[50];
    char department[30];
    int semester;

    int marks[5];
    int total;
    float percentage;
    float cgpa;
    char grade;

    struct Student *next;

} Student;
extern Student *head;
void initializeStudentList(void);

void addStudent(void);

void viewStudents(void);

void updateStudent(void);

void deleteStudent(void);
void searchStudent(void);
void enterMarks(void);
void viewAcademicRecord(void);
void topperStudent(void);
void classAverage(void);
void failedStudents(void);
void passPercentage(void);
void topperStudent(void);
#endif