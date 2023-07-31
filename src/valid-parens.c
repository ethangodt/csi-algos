#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isPair(char open, char close) {
    return (open == '{' && close == '}') || (open == '[' && close == ']') || (open == '(' && close == ')');
}

bool isValid(char *s) {
    size_t len = strlen(s);
    char *stack = calloc(len, sizeof(char));
    int stack_pos = 0;

    for (int i = 0; i < len; ++i) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            stack[stack_pos] = s[i];
            stack_pos++;
        } else if (stack_pos != 0 && isPair(stack[stack_pos - 1], s[i])) {
            stack[--stack_pos] = '\0';
        } else {
            free(stack);
            return false;
        }
    }

    free(stack);
    return stack_pos == 0;
}

int main(void) {
    printf("%i", isValid("()"));
}