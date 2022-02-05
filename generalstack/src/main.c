# include <stdio.h>
# include <stdlib.h>
#include <string>

typedef enum
{
    STACK_INT,
    STACK_UINT64,
    STACK_CHAR
} DataType;

typedef struct Stack
{
    DataType type;
    size_t size;
    void* data;
    void head;
} Stack;

Stack create_stack(size_t size, DataType type)
{
    size_t check_size = 0;
    check_size =  effective_size(type, size);

    Stack s = 
    {
        .type = type,
        .size = size,
        .data = malloc(check_size),
        .head = NULL
    };
}

int effective_size(DataType type, size_t size)
{
    int type_s = 0;
    if(type == STACK_INT)
        type_s = size * sizeof(int);
    else if (type == STACK_UINT64)
        type_s = size * sizeof(unsigned long long);
    else if (type == STACK_CHAR)
        type_s = size * sizeof(char);

    return type_s;
}

void delete_stack(Stack* s)
{
    free(s->data);
    s->data = NULL;
}

int main(int argc, char* argv[])
{
    // test creating a stack of 10 ints with STACK_INT
    Stack s = create_stack(10, STACK_INT);
    ((int)s.data)[0] = 64;
    s.head = ((int)s.data) + 0;

    ((int)s.data)[1] = 128;
    s.head = ((int)s.data) + 1;

    delete_stack(&s);
    return 0;
}