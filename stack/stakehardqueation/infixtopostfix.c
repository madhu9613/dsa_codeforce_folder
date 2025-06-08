#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1)
        stack[++top] = c;
}

char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

char peek() {
    if (top >= 0)
        return stack[top];
    return '\0';
}

// Function to check precedence
int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Check if the operator is right associative
int isRightAssociative(char op) {
    return op == '^';
}

// Check if character is operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%';
}

// Main infix to postfix converter
void infixToPostfix(char *infix, char *postfix) {
    int i, k = 0;
    char ch;
    for (i = 0; infix[i]; i++) {
        ch = infix[i];

        if (isalnum(ch)) {
            postfix[k++] = ch; // Operand goes to output
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = pop();
            pop(); // remove '('
        }
        else if (isOperator(ch)) {
            while (top != -1 && isOperator(stack[top]) &&
                   ((precedence(stack[top]) > precedence(ch)) ||
                    (precedence(stack[top]) == precedence(ch) && !isRightAssociative(ch))))
            {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
