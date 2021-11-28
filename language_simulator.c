#include<stdio.h>
#include<string.h>
#include<conio.h>

int no_states;
int no_symbs;
int no_final_states;

int final_states[7];
char symbols[5];
char string[20];

char arr[7][5];

void accept_numbers()
{
    printf("\tEnter the Transition Table Details... \n");

    printf("Enter the number of States [Less than 7] : ");
    scanf("%d", &no_states);

    printf("Enter the number of Symbols [Less than 5] : ");
    scanf("%d", &no_symbs);

    printf("Enter the number of Final States [Less than Number Of States] : ");
    scanf("%d", &no_final_states);

    if(no_states > 7 || no_symbs > 5 || no_states <= 0 || no_symbs <= 0 || no_final_states > no_states || no_final_states < 0)
    {
        printf("Enter Value in the Specified Range\n");
        accept_numbers();
    }
}

void accept_symbols()
{
    int flag=0;

    printf("\nEnter the Input Symbols :-\n");

    for(int i=0;i<no_symbs;i++)
    {
        printf("Symbol number %d : ",(i+1));
        printf("%c\n",symbols[i]=getch());
        flag = 0;
        for(int j=0;j<i;j++)
        {
            if(symbols[i] == symbols[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag==1)
        {
            printf("You cannot repeat symbols\n");
            i--;
        }
    }

}

void accept_final()
{
    if(no_states == 1)
        printf("The Only State is q0\n");
    else
    {
        printf("The Transition States are :-  ");
        for(int i=0;i<no_states;i++)
            printf("q%d  ",i);
        printf("\n");
    }

    printf("Number of Final States : %d\n",no_final_states);

    int flag=0;

    if(no_final_states > 0 && no_final_states < no_states)
    {
        printf("Enter the final state(s) :- \n");
        for(int i=0;i<no_final_states;i++)
        {
            printf("q");
            scanf("%d",&final_states[i]);
            for(int j=0;j<i;j++)
            {
                if(final_states[i] == final_states[j])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
            {
                printf("Already a final state.\n");
                i--;
            }
            if(final_states[i] >= no_states)
            {
                printf("Invalid Input. Final state not included in input states.\n");
                i--;
            }
        }

    }
    else if(no_final_states == no_states)
    {
        printf("Since Number of Final States = Number of States, Every State is a Final State\n");
        for(int i=0;i<no_states;i++)
        {
            final_states[i] = i;
        }
    }
    else
        printf("No Final States\n");

}

void accept_transition()
{
    printf("The set of states : q0 ");
    for(int i=1;i<no_states;i++)
        printf(", q%d ",i);
    printf("\n");

    printf("The set of input symbols : %c ", symbols[0]);
    for(int i=1;i<no_symbs;i++)
        printf(", %c ",symbols[i]);
    printf("\n");

    printf("\n define transition rule as (initial state, input symbol ) = final state\n");
    for(int i=0; i<no_symbs; i++)
    {
        for(int j=0; j<no_states; j++)
        {
            printf("(q%d , %c ) = q",j,symbols[i]);
            scanf("%d",&arr[i][j]);
        }
    }

}

void validate_dfa()
{
    printf("Enter the string to be validated [Enter 'empty' for empty string] : ");
    scanf("%s", string);

    int len = strlen(string);

    char ch;

    int flag = 0;
    int start = 0;
    int symb_count = -1;
    int valid_flag = 0;

    if(strcmp(string, "empty") == 0)
    {
        for(int i=0;i<no_final_states;i++)
        {
            if(final_states[i] == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            printf("The Given String is valid.\n");
        }
    }
    else
    {
        for(int l=0;l<len;l++)
        {
            flag = 0;
            ch = string[l];
            for(int i=0;i<no_symbs;i++)
            {
                if(ch == symbols[i])
                {
                  symb_count = i;
                  break;
                }
            }
            if(symb_count == -1)
            {
              valid_flag = 1;
              printf("The Given String is Invalid.\n");
              break;
            }
            else
            {
              start = arr[start][symb_count];
              printf("%d\n",start );
            }
        }

        flag = 0;
        for(int i=0;i<no_final_states;i++)
        {
          if(start == final_states[i])
          {
            flag=1;
            break;
          }
        }
        if(flag == 1)
        {
          printf("The given string is VALID\n");
        }
        else
        {
          printf("The given string is INVALID\n");
          valid_flag = 1;
        }
    }
    printf("\nTry again? \n0 - Yes\n1 - No \n");
    int again = 0;
    scanf("%d",&again);

    if(again == 0)
    validate_dfa();


}

int main()
{
    accept_numbers();
    accept_symbols();
    accept_final();
    accept_transition();
    validate_dfa();

    return 0;
}
