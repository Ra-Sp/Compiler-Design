#include <stdio.h>
#include <string.h>

/*
Symbol -> represented as

E' -> e
T' -> t
*/

int errorFlag = 0;
int accepted = 0;

void pp_table();

char stack[5] = {'$', 'E'};
char ipBuffer[10];

int Bptr = 0; //ipBuffer Pointer
int Sptr = 1; //Stack Pointer

void pp_table()
{
    if(ipBuffer[Bptr] == 'i')
    {
        if(stack[Sptr] == 'i')
        {
            Bptr++;
            Sptr--;
        }

        else if(stack[Sptr] == 'E')
        {
            stack[Sptr] = 'e';
            stack[Sptr + 1] = 'T';
            Sptr++;
        }

        else if(stack[Sptr] == 'T')
        {
            stack[Sptr] = 't';
            stack[Sptr + 1] = 'F';
            Sptr++;
        }

        else if(stack[Sptr] == 'F')
        {
            stack[Sptr] = 'i';
        }

        else
        {
            printf("\nError\n");
            errorFlag = 1;
        }
    }


    else if(ipBuffer[Bptr] == '+')
    {
        if(stack[Sptr] == '+')
        {
            Bptr++;
            Sptr--;
        }

        else if(stack[Sptr] == 'e')
        {
            stack[Sptr] = 'e';
            stack[Sptr + 1] = 'T';
            stack[Sptr + 2] = '+';
            Sptr++;
            Sptr++;
        }

        else if(stack[Sptr] == 't')
        {
            Sptr--;
        }

        else
        {
            printf("\nError\n");
            errorFlag = 1;
        }
    }


    else if(ipBuffer[Bptr] == '*')
    {
        if(stack[Sptr] == '*')
        {
            Bptr++;
            Sptr--;
        }

        else if(stack[Sptr] == 't')
        {
            stack[Sptr] = 't';
            stack[Sptr + 1] = 'F';
            stack[Sptr + 2] = '*';
            Sptr++;
            Sptr++;
        }

        else
        {
            printf("\nError\n");
            errorFlag = 1;
        }
    }

    else if(ipBuffer[Bptr] == '(')
    {
        if(stack[Sptr] == '(')
        {
            Bptr++;
            Sptr--;
        }

        else if(stack[Sptr] == 'E')
        {
            stack[Sptr] = 'e';
            stack[Sptr + 1] = 'T';
            Sptr++;
        }

        else if(stack[Sptr] == 'T')
        {
            stack[Sptr] = 't';
            stack[Sptr + 1] = 'F';
            Sptr++;
        }

        else if(stack[Sptr] == 'F')
        {
            stack[Sptr] = '(';
            stack[Sptr + 1] = 'E';
            stack[Sptr + 2] = ')';
            Sptr++;
            Sptr++;
        }

        else
        {
            printf("\nError\n");
            errorFlag = 1;
        }
    }

    else if(ipBuffer[Bptr] == ')')
    {
        if(stack[Sptr] == ')')
        {
            Bptr++;
            Sptr--;
        }

        else if(stack[Sptr] == 'e')
        {
            Sptr--;
        }

        else if(stack[Sptr] == 't')
        {
            Sptr--;
        }

        else
        {
            printf("\nError\n");
            errorFlag = 1;
        }
    }

    else if(ipBuffer[Bptr] == '$')
    {
        if(stack[Sptr] == '$')
        {
            printf("String Accepted");
            accepted = 1;
        }

        else if(stack[Sptr] == 'e')
        {
            Sptr--;
        }

        else if(stack[Sptr] == 't')
        {
            Sptr--;
        }

        else
        {
            printf("\nError\n");
            errorFlag = 1;
        }
    }
}

int main()
{
    scanf("%s", ipBuffer);

    while(accepted == 0 && errorFlag == 0)
    {
        pp_table();
    }
}