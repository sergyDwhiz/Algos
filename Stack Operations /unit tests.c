#include <stdio.h>
#include <assert.h>

int main() {
    int top = -1;
    int stack[10];

    // Test push function
    push(stack, &top, 5);
    assert(stack[top] == 5);

    // Test pop function
    int val = pop(stack, &top);
    assert(val == 5);

    // Test is_empty function
    assert(is_empty(top) == 1);

    // Test is_full function
    assert(is_full(top) == 0);

    printf("All tests passed successfully!\n");

    return 0;
}
