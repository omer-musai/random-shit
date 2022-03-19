#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 10
#define MAX_NAME 100
#define INFO 2
#define INIT 100
#define ADD 200
#define DEL 300
#define SUCCESS 0
#define FAILURE -1

void init_db(int students_info[][INFO], char* students_names[], int n);
int read_students_info(int students_info[][INFO], char* students_names[], int n);
void add_student(int students_info[][INFO], char* students_names[],int n);
void delete_student(int students_info[][INFO], char* students_names[],int n);
void clean_db( char* students_names[],int n);



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
        clean_db(students_names,MAX_STUDENTS);

return 0;
}




void init_db(int students_info[][INFO], char* students_names[], int n)
{
    for (int j=0; j < INFO; j++)
    {
        for (int i=0; i < n; i++)
        {
            students_info[i][j] = -1;
        }

        for (int k=0; k < n; k++)
        {
            students_names[k] = NULL;
        }

    }

}

int read_students_info(int students_info[][INFO], char* students_names[], int n)
{
    int M = 0;

    scanf("%d", &M);

    if ( M > n)
    {
    printf("Too many students!! Aborting!!\n");
    return -1;
    }

    for (int i=0; i < M; i++)
    {
        char* names = (char*)malloc(MAX_NAME * sizeof(char));

        scanf("%s %d %d", names, &students_info[i][0], &students_info[i][1]);
        
    
        students_names[i] = names;

    }

    printf("First %d students were added to the database!!\n", M);
    return 0;
}

void add_student(int students_info[][INFO], char* students_names[],int n)
{
    char* sn = (char*)malloc(MAX_NAME * sizeof(char));
    int si[INFO];
    int cnt =0;
    scanf("%s %d %d", sn, &si[0], &si[1]);
    
    
    for (int i=0; i < n; i++)
    {
        if (si[0] == students_info[i][0] )
        {
            printf("Student %d already exists!!\n", si[0] );
            return;
        }
        
    }

    while (students_info[cnt][0] != -1)
    {
            cnt++;
            if(cnt == MAX_STUDENTS - 1)
            {
                printf("Cannot add student %d, class already full!!\n", si[0]);
                return;
            }
    }

    students_names[cnt] = sn;
    students_info[cnt][0] = si[0];
    students_info[cnt][1] = si[1];
    
   printf("Student %d was successfully added to the system!!\n", students_info[cnt][0]);

}


void delete_student(int students_info[][INFO], char* students_names[],int n)
{

    int id =0;
    
    scanf("%d", &id);

    for (int i=0; i < n; i++)
    {
        if (id == students_info[i][0] )
        {
            students_info[i][0] = -1;
            students_info[i][1] = -1;
            free(students_names[i]);
            students_names[i] = NULL;
            
            printf("Student %d information were deleted from the system!!!\n" ,id);
            return;
        }
        
    }
  printf("Student %d does not exist!!!\n", id);
  
}


void clean_db( char* students_names[],int n)
{ 
  int num=0;

  for (int i=0; i < n; i++)
  {
      if(students_names[i] != NULL)
      {
          free(students_names[i]);
          num++;
      }

  }
    
    printf("All %d entries were deleted!!!\n", num);

}
