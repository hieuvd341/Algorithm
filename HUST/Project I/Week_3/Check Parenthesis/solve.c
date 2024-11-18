#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000000

int is_opening_bracket(char c) {
    return c == '(' || c == '{' || c == '[';
}

int is_matching_pair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

int is_correct_sequence(char* str) {
    int len = strlen(str);
    char stack[MAX_LENGTH]; 
    int top = -1; 
    
    for (int i = 0; i < len; i++) {
        if (is_opening_bracket(str[i])) {
            top++;
            stack[top] = str[i]; 
        } else {
            if (top == -1 || is_matching_pair(stack[top], str[i])== 0) {
                return 0;
            } else {
                top--;
            }
        }
    }
    
    return top == -1;
}

int main() {
    char str[MAX_LENGTH];
    scanf("%s", str);
    
    printf("%d\n", is_correct_sequence(str));
    return 0;
}
