#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
typedef struct
{
    char phone[15];
    char email[50];
} Contact;

typedef struct
{
    char name[15];
    Contact contact;
} Parent;

typedef struct
{
    char first_name[50];
    char last_name[50];
    int age;
    Contact contact;
    Parent parent;
} Student;

typedef struct
{
    int id;
    char name[122];
} Lesson;

typedef struct
{
    Lesson lesson;
    Student student;
    int score;
} Score;



// Global Variables
Student *students = NULL;
int student_count = 0;

Lesson *lessons = NULL;
int lesson_count = 0;

Score *scores = NULL;
int score_count = 0;

// Function Prototypes
void add_student();
void get_students();
void get_student_detail();
void get_student_by_name();
void add_lesson();
void add_score();
void get_lesson_statistics();
void menu();

// Main Function
int main()
{
    menu();
    // Free allocated memory before exiting
    free(students);
    free(lessons);
    free(scores);
    return 0;
}

// Function Definitions
void menu()
{
    int choice;
    do
    {
        printf("\n1. Add Student\n2. View Students\n3. View Student Details\n4. Find Student by Name\n5. Add Lesson\n6. Add Score\n7. Get Lesson Statistics\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_student();
            break;
        case 2:
            get_students();
            break;
        case 3:
            get_student_detail();
            break;
        case 4:
            get_student_by_name();
            break;
        case 5:
            add_lesson();
            break;
        case 6:
            add_score();
            break;
        case 7:
            get_lesson_statistics();
            break;
        case 8:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice, try again.\n");
        }
    } while (choice != 8);
}

void add_student()
{
    students = realloc(students, (student_count + 1) * sizeof(Student));
    if (!students)
    {
        printf("Memory allocation failed!\n");
        exit(1); // dasturni ishini yakunlash
    }

    printf("Enter first name: ");
    scanf("%s", students[student_count].first_name);

    printf("Enter last name: ");
    scanf("%s", students[student_count].last_name);

    printf("Enter age: ");
    scanf("%d", &students[student_count].age);

    printf("Enter phone: ");
    scanf("%s", students[student_count].contact.phone);

    printf("Enter email: ");
    scanf("%s", students[student_count].contact.email);

    printf("Enter parent's name: ");
    scanf("%s", students[student_count].parent.name);

    printf("Enter parent's phone: ");
    scanf("%s", students[student_count].parent.contact.phone);

    printf("Enter parent's email: ");
    scanf("%s", students[student_count].parent.contact.email);

    student_count++;
    printf("Student added successfully!\n");
}

void get_students()
{


    printf("First Name   |  Last Name\n");

    for (int i = 0; i < student_count; i++)
    {
        printf("%d. %-10s |",i, students[i].first_name);
        printf(" %s \n\n", students[i].last_name);
    }
};

void get_student_detail()
{
    int id;
    printf("Enter student ID to get: ");
    scanf("%d", &id);

    id--;

    printf("ID   |  Firs Name   |   Last Name   |   Age  |   Phone       |  Email       | Parent's Name |  Parent's Email |  Parent's Phone          \n");
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%d   |", id);
    printf(" %-10s |", students[id].first_name);
    printf(" %-10s |", students[id].last_name);
    printf(" %-10d |", students[id].age);
    printf(" %-10d |", students[id].contact.phone);
    printf(" %-10s |", students[id].contact.email);
    printf(" %-10s |", students[id].parent.name);
    printf(" %-10s |", students[id].parent.contact.email);
    printf(" %-10d \n", students[id].parent.contact.phone);
};

void get_student_by_name()
{
    char name[15];
    printf("Enter name that you want: ");
    scanf("%s",&name);

    for (int i = 0; i < student_count; i++)
    {
        if (strcmp(students[i].first_name, name))
        {
            printf("ID | Firs Name | Last Name | Age | Phone       |  Email          | Parent's Name |  Parent's Email |  Parent's Phone          \n");
            printf("------------------------------------------------------------------------------------------------------------------------------------\n");
            printf(" %-10s |", students[i].first_name);
            printf(" %-10s |", students[i].last_name);
            printf(" %-10d |", students[i].age);
            printf(" %-10d |", students[i].contact.phone);
            printf(" %-10s |", students[i].contact.email);
            printf(" %-10s |", students[i].parent.name);
            printf(" %-10s |", students[i].parent.contact.email);
            printf(" %-10d\n", students[i].parent.contact.phone);
        }
    }
};

void add_lesson()
{
    lessons = realloc(lessons, (lesson_count + 1) * sizeof(Lesson));

    printf("Add lesson name: ");
    scanf("%s", &lessons[lesson_count].name);
    printf("\nAdd lesson ID: ");
    scanf("%d", &lessons[lesson_count].id);

    lesson_count++;
    printf("Lesson added successfully\n");
};

void add_score()
{
    int studentID, lessonID, mark;

    printf("Enter student ID: ");
    scanf("%d\n", &studentID);

    printf("Enter lesson ID: ");
    scanf("%d\n", &lessonID);

    printf("Enter mark: ");
    scanf("%d\n", &mark);

    scores = realloc(scores, (score_count + 1) * sizeof(Score));

    scores[score_count].student = students[studentID - 1];
    scores[score_count].lesson = lessons[lessonID - 1];
    scores[score_count].score = mark;

    score_count++;

    printf("Marked successfully");
};

void get_lesson_statistics() {
    printf("First Name   |   Last Name   |   Lesson   |   Mark       \n");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < student_count; i++)
    {
        printf(" %-10s | %-10s | %-10s | %-10d \n", students[i].first_name,students[i].last_name, scores[i].lesson, scores[i].score);
    }
};


// yuqoridagi misoldan qarab bajarish mumkin