#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE (2)
int contents[STACK_SIZE];
int* top_ptr = &contents[0];

void stack_overflow(void);
void stack_underflow(void);
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int index);
int pop(void);

int main(void)
{
    push(1);
    push(2);
    push(3);
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    return 0;
}

void stack_overflow(void)
{
    printf("warning overflow\n");
}

void stack_underflow(void)
{
    printf("warning underflow\n");
}

void make_empty(void)
{
    top_ptr = &contents[0];
}

bool is_empty(void)
{
    return *top_ptr == contents[0];
}

bool is_full(void)
{
    return *top_ptr == contents[STACK_SIZE];
}


void push(int index)
{
    if (is_full()) {
        stack_overflow();
    } else {
        *top_ptr++ = index;
    }
}

int pop(void)
{
    if (is_empty()) {
        stack_underflow();
    } else {
        return *--top_ptr;
    }
}