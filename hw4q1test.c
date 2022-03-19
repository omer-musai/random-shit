#include <stdio.h>
#include <stdlib.h>


#define MAX_STUDENTS 10
#define MAX_NAME 100
#define INFO 2
#define INIT 100
#define ADD 200
#define DEL 300
#define SUCCESS 0
#define FAILURE -1

//function declaration
void init_db(int students_info[][INFO], char* students_names[], int n);
int read_students_info(int students_info[][INFO], char* students_names[], int n);
void add_student(int students_info[][INFO], char* students_names[],int n);
void delete_student(int students_info[][INFO], char* students_names[],int n);
//void clean_db( char* students_names[],int n);




int main()
{
        int students_info[MAX_STUDENTS][INFO];
        char* students_names[MAX_STUDENTS];
        init_db(students_info, students_names,MAX_STUDENTS);
        int op = INIT;
        while (scanf("%d", &op)!= EOF)

        {

            switch(op){
            case INIT: if (read_students_info(students_info, students_names,MAX_STUDENTS )!= SUCCESS){return FAILURE;} break;
            case ADD: add_student(students_info, students_names,MAX_STUDENTS); break;
            case DEL: delete_student(students_info, students_names,MAX_STUDENTS); break;
            default: break;
            }
        }
        //clean_db(students_names,MAX_STUDENTS);

return 0;
}


//CHECK ON THAT, NOT SURE IF DONE RIGHT
void init_db(int students_info[][INFO], char* students_names[], int n)
{
    for (int j = 0; j < INFO; j++)
    {
        for (int i = 0; i < n; i++)
        {
            students_info[i][j] = -1 ;
    
        }

    }
    for (int k = 0; k < n; k++)
    {
        students_names[k] = 0 ;
    }

}

int read_students_info(int students_info[][INFO], char* students_names[], int n)
{
int M = 0;

scanf("%d", &M);

if(M > n)
{
    printf("Too many students!! Aborting!!");
    return -1;
}
for (int i = 0; i < M; i++)
{
    scanf("%s %d %d", &students_names[0][i], &students_info[i][0], &students_info[i][1]) ;
}

printf("First %d students were added to the database!!", M);

}


void add_student(int students_info[][INFO], char* students_names[],int n)
{
    
    char name[MAX_NAME];
    int id = 0;
    int t = 0;


    scanf("%s %d %d", name, &id, &t) ;
    
    
    for (int i=0; i < n; i++)
    {
      
      if (students_info[i][0] == id)
      {
          printf("Student %d already exists!!", id);
          
      }


    if (students_info[MAX_STUDENTS][INFO] != -1)
    {
        printf("Cannot add student %d, class already full!!", id);
    }
    else
    {
        printf("Student %d was successfully added to the system!!", id);
    }
    
    }

}


void delete_student(int students_info[][INFO], char* students_names[],int n)
{
int id=0;
int t=0;
char name[MAX_NAME];

scanf("%s %d %d", name, &id, &t) ;

for (int i=0; i < n; i++)
    {
      if (students_info[i][0] == id)
      {
          students_info[i][0] = -1;
          students_info[i][1] = -1;
          students_names[0][i] = 0;
      }
    }
     printf("Student %d does not exist!!!", id);
          return 0;

}