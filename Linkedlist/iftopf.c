#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return -1;
}

int isOperator(char character) {
    return (character == '+' || character == '-' || character == '*' || character == '/');
}

void infixToPostfix(const char *infix, char *postfix) {
    char stack[MAX_SIZE];
    int top = -1;
    int i, j = 0;

    stack[++top] = '#'; 

    for (i = 0; infix[i] != '\0'; i++) {
        char currentChar = infix[i];

        if (isdigit(currentChar)) {
            postfix[j++] = currentChar; 
        } else if (currentChar == '(') {
            stack[++top] = currentChar; 
        } else if (currentChar == ')') {
            while (stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--; 
        } else if (isOperator(currentChar)) {
            while (precedence(stack[top]) >= precedence(currentChar)) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = currentChar;
        }
    }

    while (stack[top] != '#') {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0'; 
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
