#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <string.h>

#define MAX_NAME 70
/***********************************************************************************************************************
*PROTOTYPE
***********************************************************************************************************************/
typedef struct student
{
    char name[MAX_NAME];
    struct student * pNext;
} student_t;
/* pHead point to the address of the first element on the list */
student_t * pHead = NULL;
/* pTail point to the address of the last element on the list */
student_t * pTail = NULL;

/*!
 *Function : {void} addStudent()
 * @brief: Add student querry
 *
 * @param: <none>
 *
 * @return: <none>.
 */
void addStudent();
/*!
 *Function : {void} addTopStudent()
 * @brief: Add a new student to the top of the list
 *
 * @param: pAdd - Poiter use for adding new student
 *
 * @return: <none>.
 */
void addTopStudent();
/*!
 *Function : {void} addBotStudent()
 * @brief: Add a new student to the bottom of the list
 *
 * @param: pAdd - Poiter use for adding  new student
 *
 * @return: <none>.
 */
void addBotStudent();
/*!
 *Function : {void} findStudent()
 * @brief: Find a student on the list
 *
 * @param: pFind - Poiter use for finding new student
 *
 * @return: <none>.
 */
void findStudent();
/*!
 *Function : {void} removeStudent()
 * @brief: Remove a student from the list
 *
 * @param:  pBefore - Temporary Pointer use to point the address before the address we want to remove
            pRemove - Temporary Pointer use to point the address we want to remove
            pAddress - The address have the same name with the user input
            pTemp - Temporary Pointer use to point the address before pTail
 *
 * @return: <none>.
 */
void removeStudent();
/*!
 *Function : {student_t *} findStudentTool()
 * @brief: find the address which had the student name matched user input
 *
 * @param: pFind - Poiter use for finding a student on the list
 *
 * @return: pFind - = NULL if there is no match
                    != NULL if there is a match
 */
student_t * findStudentTool();
void printStudent();
/***********************************************************************************************************************
*CODE
***********************************************************************************************************************/
int main()
{
    char selectFunction;
    do
    {
        /* Choose a function to execute */
        printf("\n Choose a function:");
        printf("\n 1 - Add a new student");
        printf("\n 2 - Find a student");
        printf("\n 3 - Remove a student");
        printf("\n 4 - Print students list");
        printf("\n 5 - Close the program");
        printf("\n \t --- \t");

        fflush(stdin);
        scanf("%c",&selectFunction);


        switch ((int)selectFunction-48)
        {
            /* Choose to add a new student */
            case 1:
            {
                printf("\n You choose 1 \n");
                addStudent();
                break;
            }

            /* Choose to find a student */
            {
                case 2:
                printf("\n You choose 2 \n");
                findStudent();
                break;
            }
            /* Choose to remove a student */
            {
                case 3:
                printf("\n You choose 3 \n");
                removeStudent();
                break;
            }
            /* Choose to print the student list */
            {
                case 4:
                printf("\n You choose 4 \n");
                printStudent();
                break;
            }
            /* Choose to close the program */
            {
                case 5:
                printf("\n You choose 5 \n");
                return 0;
            }
        }
    }
    while(1);
    getchar();
    return 0;
}

void addStudent()
{
    char selectPosition;
    char studentName[MAX_NAME];
    fflush(stdin);
    printf("\n What is his/her name ?");
    printf("\t ---- \t");
    fflush(stdin);
    gets(studentName);

    printf("\n Where do you want to put %s on the list ? ",studentName);
    printf("\n 1 - On top of the list");
    printf("\n 2 - At the botom of the list");
    printf("\t ---- \t");

    fflush(stdin);
    scanf("%c",&selectPosition);
    switch ((int)selectPosition - 48)
    {
        /* Add a student on the top of the list */
        case 1:
        {
            addTopStudent(studentName);
            break;
        }
        /* Add a student at the botom of the list */
        case 2:
        {
            addBotStudent(studentName);
            break;
        }
        /* If the user entered the wrong input */
        default:
        {
            printf("\n Wrong input - Try again later");
        }
    }
}


void addTopStudent(char studentName[])
{
    student_t *pAdd = NULL;
    pAdd = (student_t *) malloc(sizeof(student_t));
    if(pHead == NULL && pTail == NULL)
    {
        pAdd -> pNext = NULL;
        strcpy(pAdd->name,studentName);
        pHead = pAdd;
        pTail = pAdd;
    }
    else
    {
        pAdd->pNext = pHead;
        strcpy(pAdd->name,studentName);
        pHead = pAdd;
    }
    printf("\n You just add %s on top of the list \n",pHead->name);
}

void addBotStudent(char studentName[])
{
    student_t *pAdd = NULL;
    pAdd = (student_t *) malloc(sizeof(student_t));
    if(pTail == NULL && pHead == NULL)
    {
        pAdd -> pNext = NULL;
        strcpy(pAdd->name,studentName);
        pHead = pAdd;
        pTail = pAdd;
    }
    else
    {
        pTail->pNext = pAdd;
        pAdd->pNext = NULL;
        strcpy(pAdd->name,studentName);
        pTail = pAdd;
    }
    printf("\n You just add %s at the botom of the list \n",pTail->name);
}

void findStudent()
{
    char studentName[MAX_NAME];
    int row = 0;
    student_t *pFind = NULL;
    pFind = pHead;
    printf("\n********************************************************");
    printf("\n Who do you want to find on the student list ?");
    printf("\n \t---\t");
    fflush(stdin);
    gets(studentName);
    while(findStudentTool(studentName) !=NULL)
    {
        row++;
        if(pFind == findStudentTool(studentName))
        {
            printf("\n %s is on the row number %d on the list \n",studentName,row);
            break;
        }
        if(pFind == NULL)
        {
            break;
        }
        pFind = pFind -> pNext;
    }
    if(findStudentTool(studentName) == NULL)
    {
        printf("\n Student not found \n");
    }
}

student_t * findStudentTool(char studentName[])
{
    student_t *pFind = NULL;
    /*row - Number of rows & status  = 0 if not found student not the list */
    pFind = pHead;

    while(pFind != NULL)
    {
        /* Increse row number */
        if(strcmp(pFind->name,studentName)==0)
        {
            return pFind;
        }
        else
        {
            pFind = pFind -> pNext;
        }
    }
    return NULL;
}

void removeStudent()
{
    /*temporary pointer point to the address need to delete*/ 
    student_t *pRemove = NULL;
    /*temporary pointer before the address need to delete*/
    student_t *pBefore = NULL;
    /* temporary pointer point to the address before new pTail */
    student_t *pTemp = NULL;
    /* pointer to the first address have the same student name as user input */
    student_t *pAddress = NULL;
    
    char studentName[MAX_NAME];
    /* Number of rows */
    int row = 0;
    /* Status if there are nothing to remove */
    int status = 0;
    printf("********************************************************");
    printf("\n Who do you want to remove from the student list ?");
    printf("\n \t---\t");
    fflush(stdin);
    gets(studentName);

    /* use function */
    pAddress = findStudentTool(studentName);

    /* Check if the address existed or not */
    if(pAddress == NULL)
    {
        printf("\n Student not found \n");
    }
    /* Check if the address is the only address on the list */
    else if (pHead == pTail && pHead == pAddress && pHead != NULL && pTail != NULL)
    {
        pHead = NULL;
        pTail = NULL;
        free(pAddress);
        printf("\n %s is removed from the only row of the list \n",studentName);
    }
    /* Check if the address is the first address on the list */
    else if(pHead == pAddress)
    {
        pHead = pAddress->pNext;
        free(pAddress);
        printf("\n %s is removed from the first row of the list \n",studentName);
    }
    /* Check if the address is the last address on the list */
    else if(pTail == pAddress)
    {
        pTemp = pHead;

        while(pTemp->pNext != pAddress)
        {
            pTemp = pTemp -> pNext;
        }
        pTemp -> pNext = NULL;
        pTail = pTemp;
        free(pAddress);
        printf("\n %s is removed from the last row of the list \n",studentName);
    }
    /* The address must be in the middle of the list find the address before it and change the link */
    else
    {
        pBefore = pHead;
        while(pBefore->pNext != pAddress)
        {
            row ++;
            pBefore = pBefore -> pNext;
        }

        pRemove = pBefore -> pNext;

        if(pRemove == pAddress)
        {
            pBefore -> pNext = pRemove -> pNext;
            free(pRemove);
            printf("\n %s is removed from the row number %d of the list \n",studentName,row + 2);
        }
    }
}
void printStudent()
{
    student_t * pPrint = NULL;
    int row = 0;
    pPrint = pHead;
    printf("\n \t \t \t***  Student list  *** ");
    while(pPrint != NULL)
    {
        row++;
        printf("\n ( %-2d) --- %s",row,pPrint->name);
        pPrint = pPrint -> pNext;
    }
    printf("\n \t \t \t*** End of the list ***");
}