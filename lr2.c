#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    typedef struct sStudent
{
    char NAME[20];
    int AGE;
    char FACULTY[10];
    int GROUP;
    struct sStudent *next;
} tStudent;
    tStudent *get_struct(void)
{
    tStudent *p = (tStudent *) malloc(sizeof(tStudent));
    printf("Surname: ");
    scanf ("%s", &(p -> NAME));
    printf ("Age: ");
    scanf ("%d", &(p -> AGE));
    printf ("Faculty: ");
    scanf ("%s", &(p -> FACULTY));
    printf ("Group: ");
    scanf ("%d", &(p -> GROUP));
    if(!p)
        {
            printf("Allocation error!\n");
            exit(0);
        };
    return p;
};

    tStudent *pi = NULL;
    tStudent *p_begin = NULL;
    tStudent *p = NULL;
    tStudent *prev_p = NULL;
    char choice;
do
{
    printf(" Student Council Department \n");
    printf(" 1) Create a department, appoint its head\n");
    printf(" 2) Invite a new person to the department\n");
    printf(" 3) Exclude the last of new person\n");
    printf(" 4) Show whole department\n");
    printf(" 5) Exclude whole department\n");
    printf(" 6) Search for a person by parameter\n");
    printf(" 7) Exit\n");
    printf(" Enter choice: ");
    choice = getch();
    printf ("\n\n");
    switch(choice)
    {
        case '1':
        {
            if(p_begin == NULL)
            {
                p_begin = get_struct();
                p_begin -> next = NULL;
                p = p_begin;
                prev_p = p_begin;
            }
            else printf("Delete the created department first!\n\n");
        }break;

        case '2':
        {
            if(p_begin)
            {
                p -> next = get_struct();
                prev_p = p;
                p = p -> next;
                p -> next = NULL;
            }
            else printf("Error! The department does not exist\n\n");
        }break;

        case '3':
        {
            if(prev_p)
                if(prev_p -> next)
                {
                    free(p);
                    prev_p -> next = NULL;
                    for(p = p_begin; (p -> next != prev_p) & (p -> next != NULL); p = p -> next);
                    prev_p = p;
                    if(prev_p -> next)
                        p = prev_p -> next;
                }
                else printf("The head of the department cannot be excluded\n\n");
            else printf("Error! The department does not exist\n\n");
        }break;

        case '4':
        {
            int i;
            if(p_begin)
                for(i = 1, pi = p_begin; pi; pi = pi -> next, i++)
                {
                    printf("%d). \n", i);
                    printf("Surname: %s\n", pi -> NAME);
                    printf("Age: %d\n", pi -> AGE);
                    printf("Faculty: %s\n", pi -> FACULTY);
                    printf("Group: %d\n\n", pi -> GROUP);
                }
                else printf("Error! The department does not exist\n\n");
        }break;

        case '5':
        {
            if(p_begin)
            {
                int i = -1;
                for(pi = p_begin; pi; pi = pi -> next)
                i++;
                for(;i > 0; i--)
                {
                    if(prev_p)
                    if(prev_p -> next)
                    {
                        free(p);
                        prev_p -> next = NULL;
                        for(p = p_begin; (p -> next != prev_p) & (p -> next != NULL); p = p -> next);
                        prev_p = p;
                        if(prev_p -> next)
                        p = prev_p -> next;
                    }
                    else printf("The head of the department cannot be excluded\n\n");
                    else printf("Error! The department does not exist\n\n");
                }
                free(p);
                p_begin = NULL;
                prev_p = NULL;
                p = NULL;
                printf("Department deleted!\n\n");
                }
            else printf("Error! The department does not exist\n\n");
        }break;

        case '6':
        {
        if(p_begin)
        {
            printf("What parameter will be searched for?:\n");
            printf("1). Surname\n");
            printf("2). Age\n");
            printf("3). Faculty\n");
            printf("4). Group\n\n");
            printf("Enter choice: ");
            choice = getch();
            printf ("\n\n");
            printf(" Enter value: ");
            switch(choice)
            {
                case '1':
                {
                    int i, n;
                    char s[20];
                    n = scanf("%s", &s);
                    if(n != 1) return 0;
                    n = 0;
                    printf ("\n\n");
                    printf("Found:\n");
                    for(i = 1, pi = p_begin; pi; pi = pi -> next, i++)
                    {
                        if(pi -> NAME == s)
                        {
                            printf("%d)\n", i);
                            printf("Surname: %s\n", pi -> NAME);
                            printf("Age: %d\n", pi -> AGE);
                            printf("Faculty: %s\n", pi -> FACULTY);
                            printf("Group: %d\n\n", pi -> AGE);
                            n = 1;
                        }
                    }
                    if(!n) printf(" Not found!\n");
                }break;

                case '2':
                {
                    int i, n, x;
                    n = scanf("%d", &x);
                    if(n != 1) return 0;
                    n = 0;
                    printf ("\n\n");
                    printf("Found:\n");
                    for(i = 1, pi = p_begin; pi; pi = pi -> next, i++)
                    {
                        if(pi -> AGE == x)
                        {
                            printf("%d)\n", i);
                            printf("Surname: %s\n", pi -> NAME);
                            printf("Age: %d\n", pi -> AGE);
                            printf("Faculty: %s\n", pi -> FACULTY);
                            printf("Group: %d\n\n", pi -> GROUP);
                            n = 1;
                        }
                    }
                    if(!n) printf(" Not found!\n");
                }break;

                case '3':
                {
                    int i, n;
                    char s[10];
                    n = scanf("%s", &s);
                    if(n != 1) return 0;
                    n = 0;
                    printf ("\n\n");
                    printf("Found:\n");
                    for(i = 1, pi = p_begin; pi; pi = pi -> next, i++)
                    {
                        if(pi -> FACULTY == s)
                        {
                            printf("%d)\n", i);
                            printf("Surname: %s\n", pi -> NAME);
                            printf("Age: %d\n", pi -> AGE);
                            printf("Faculty: %s\n", pi -> FACULTY);
                            printf("Group: %d\n\n", pi -> GROUP);
                            n = 1;
                        }
                    }
                    if(!n) printf(" Not found!\n");
                }break;

                case '4':
                {
                    int i, n, x;
                    n = scanf("%d", &x);
                    if(n != 1) return 0;
                    n = 0;
                    printf ("\n\n");
                    printf("Found:\n");
                    for(i = 1, pi = p_begin; pi; pi = pi -> next, i++)
                    {
                        if(pi -> GROUP == x)
                        {
                            printf("%d)\n", i);
                            printf("Surname: %s\n", pi -> NAME);
                            printf("Age: %d\n", pi -> AGE);
                            printf("Faculty: %s\n", pi -> FACULTY);
                            printf("Group: %d\n\n", pi -> GROUP);
                            n = 1;
                        }
                    }
                    if(!n) printf(" Not found!\n");
                }break;
            default: printf("Wrong command!\n\n");
            }
        }
        else printf("Error! The department does not exist\n\n");
        printf("\n");
        }break;

        case '7': break;

        default: printf("Wrong command!\n\n");

    }
} while(choice != '7');

return 0;

}
