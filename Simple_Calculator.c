#include <stdio.h>
/*
    simple calculator
*/

int main()
{
    float num1, num2, result;
    char operation;
    int branch;

    printf("S I M P L E  C A L C U L A T O R\n");


    printf("\nEnter the first number: ");
    scanf("%f", &num1);
    printf("\nEnter the second number: ");
    scanf("%f", &num2);

    {   branch = 0;
        printf("\n\t(+)add \n\t(-)sub \n\t(*)mul \n\t(/)div");
        printf("\n\nWhich operation do you want to do? : ");
        scanf("\n%c", &operation);
        switch(operation)
        {
        case '+':
            result = num1+num2;
            break;
        case '-':
            result = num1-num2;
            break;
        case '*':
            result = num1*num2;
            break;
        case '/':
            result = num1/num2;
            break;
        default:
            printf("\nInvalid operation!\n");
            branch = 1;
            break;
        }
    }while(branch == 1);

    printf("\nThe result is: %.2f\n", result);
    return 0;
}
