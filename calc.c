#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "calc.h"

/* processes the expression and outputs true if the expression is valid and 
false otherwise */

bool processVal(stack *s, FILE *fp, float * result)
{
    char test_char[100];

    while (fscanf(fp, "%s", test_char) == 1)
    {
        if(test_char[0] == '-' && test_char[1] == '0'){
            push(s, (float)atof(test_char));
        }
        
        else if (atof(test_char) == 0)
        {
            switch (test_char[0])
            {
            case '0':
                push(s, (float)atof(test_char));
                break;

            case '+':
                if(processAdd(s) == false){
                    return false;
                };
                break;
            case '-':
                if(processMin(s) == false){
                    return false;
                };
                break;

            case '*':
                if(processMult(s) == false){
                    return false;
                };
                break;
            case '/':
                if(processDiv(s) == false){
                    return false;
                };
                break;
            }
        }
        else
        {
            push(s, (float)atof(test_char));
        }
    }

    if (s->top == NULL || s->top->next != NULL)
    {
        freeStack(s);
        return false;
    }

    *result = s -> top -> val;

    return true;
}

//adds two numbers by popping them off the stack
bool processAdd(stack *s)
{
    if (s->top == NULL || s->top->next == NULL)
    {
        freeStack(s);
        return false;
    }
    float second; 
    float first; 

    pop(s, &second);
    pop(s, &first);

    float sum = first + second;

    push(s, sum);

    return true;;
}

//subtracts two numbers by popping them off the stack
bool processMin(stack *s)
{
    if (s->top == NULL || s->top->next == NULL)
    {
        return false;;
    }
    float second; 
    float first; 

    pop(s, &second);
    pop(s, &first);

    float minus = first - second;

    push(s, minus);

    return true;
}

//multiplies two numbers by popping them off the stack
bool processMult(stack *s)
{
    if (s->top == NULL || s->top->next == NULL)
    {
        return false;
    }
    float second; 
    float first; 

    pop(s, &second);
    pop(s, &first);

    float multiply = first * second;

    push(s, multiply);

    return true;
}

//divides two numbers by popping them off the stack
bool processDiv(stack *s)
{
    if (s->top == NULL || s->top->next == NULL)
    {
        return false;
    }
    float second; 
    float first; 

    pop(s, &second);
    pop(s, &first);

    float divide = first / second;

    push(s, divide);

    return true;
}
