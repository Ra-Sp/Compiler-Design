/*
Grammar:
E -> E + T | T
T -> T * F | F
F -> (E) | i

Removed Left Recursion before constructing the parser
*/

#include <stdio.h>
#include <string.h>

int E();
int Ep();
int F();
int T();
int Tp();

int i;
char input[10];

int E()
{
    if (T())
    {
        if (Ep())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int Ep()
{
    if (input[i] == '#')
    {
        i++;
        if (Ep())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    else
    {
        return 1;
    }
}

int T()
{
    if (F())
    {
        if (Tp())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    else
    {
        return 0;
    }
}

int Tp()
{
    if (input[i] == '&')

    {
        i++;
        if (F())

        {
            if (Tp())

            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 1;
    }
}

int F()
{
    if (input[i] == '!')
    {
        i++;
        if (F())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    else if(input[i] == ')')
    {
        i++;
        if (E())
        {
            if (input[i] == ')')
            {
                i++;
                return 1;
            }
            else
            {
                return 0;
            }
        }

        else
        {
            return 0;
        }
    }

    else
    {
        if (input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z')
        {
            i++;
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    i = 0;
    scanf("%s", input);
    if (E())
    {
        if (input[i] == '$')
        {
            printf("\nstring is accepted\n");
        }
        else
        {
            printf("\nstring is not accepted\n");
        }
    }
    else
    {
        printf("\nstring is not accepted\n");
    }
}
