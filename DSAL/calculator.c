//Calculator program using switch-case
#include <stdio.h>

float add(float num1, float num2) {
    return num1 + num2;
}

float subtract(float num1, float num2) {
    return num1 - num2;
}

float multiply(float num1, float num2) {
    return num1 * num2;
}

float divide(float num1, float num2) {
    return num1 / num2;
}
 
int main() {
    int input, num1, num2;
     
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("Operation: ");
    scanf("%d", &input);
    
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
     
    float result=0;
    switch(input)    
    {
        case 1:
            result = add(num1, num2);
            break;
             
        case 2:
            result = subtract(num1, num2);
            break;
         
        case 3:
            result = multiply(num1, num2);
            break;
             
        case 4:
            result = divide(num1, num2);
            break;
    
        default:
            printf("Invalid operation.\n");
    }
    printf("Result: %f\n", result);
    return 0;
}

//Calculator program using function-pointers
#include <stdio.h>

void add(int a, int b) {
    printf("Addition is %d\n", a+b);
}
void subtract(int a, int b) {
    printf("Subtraction is %d\n", a-b);
}
void multiply(int a, int b) {
    printf("Multiplication is %d\n", a*b);
}
void divide(int a, int b) {
    printf("Division is %d\n", a/b);
}

int main() {
    unsigned int input, a, b;

    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("Operation: ");
    scanf("%d", &input);
    
    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    
    void (*funcArr[])(int, int) = {add, subtract, multiply, divide};
     
    (*funcArr[input-1])(a, b);
    return 0;
}