#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
  int *collection1;
  char *collection2;
  float *collection3;
  int *type;
  int capacity;
  int size;

} Stack;


///
Stack *create_stack(int capacity)
{
  if (capacity <= 0) return NULL;

  Stack *stack = malloc(sizeof(Stack));
  if (stack == NULL) return NULL;

    stack->collection1 = malloc(sizeof(int) * capacity);

                if (stack->collection1 == NULL)
                {
                    free(stack);
                    return NULL;
                }

    stack->collection2 = malloc(sizeof(char) * capacity);

                if (stack->collection2 == NULL)
                {
                    free(stack);
                    return NULL;
                }
    stack->collection3 = malloc(sizeof(float) * capacity);

                if (stack->collection3 == NULL)
                {
                    free(stack);
                    return NULL;
                }
    stack->type = malloc(sizeof(int) * capacity);

                if (stack->type == NULL)
                {
                    free(stack);
                    return NULL;
                }

/*
    switch(type){
        case 1:
                stack->collection1 = malloc(sizeof(int) * capacity);

                if (stack->collection1 == NULL)
                {
                    free(stack);
                    return NULL;
                }
        break;
        case 2:
                stack->collection2 = malloc(sizeof(char) * capacity);

                if (stack->collection2 == NULL)
                {
                    free(stack);
                    return NULL;
                }
        break;
        case 3:
                stack->collection3 = malloc(sizeof(float) * capacity);

                if (stack->collection3 == NULL)
                {
                    free(stack);
                    return NULL;
                }

        break;
    }
*/


  stack->capacity = capacity;
  stack->size = 0;

  return stack;
}

///
void destroy_stack(Stack *stack)
{
  free(stack->collection1);
  free(stack->collection2);
  free(stack->collection3);
  free(stack->type);
  free(stack);
}

///
bool is_full(Stack *stack)
{
    return stack->capacity == stack->size;
}

///
bool is_empty(Stack *stack)
{
  return stack->size == 0;
}

///
bool push(Stack *stack, int item1, char item2, float item3, int type)
{
    switch(type){
        case 1:
            if (is_full(stack)) return false;
            stack->collection1[stack->size] = item1;
            stack->size++;
        break;
        case 2:
            if (is_full(stack)) return false;
            stack->collection2[stack->size] = item2;
            stack->size++;
        break;
        case 3:
            if (is_full(stack)) return false;
            stack->collection3[stack->size] = item3;
            stack->size++;
        break;
    }
  return true;
}

///
bool peek(Stack *stack, int *item1, char *item2, float *item3, int type)
{
  if (is_empty(stack)) return false;
  switch(type){
        case 1:
            *item1 = stack->collection1[stack->size - 1];
        break;
        case 2:
            *item2 = stack->collection2[stack->size - 1];
        break;
        case 3:
            *item3 = stack->collection3[stack->size - 1];
        break;
    }
  return true;
}

///
bool pop(Stack *stack, int *item1, char *item2, float *item3, int type)
{
  if (is_empty(stack)) return false;
  switch(type){
        case 1:
            stack->size--;
            *item1 = stack->collection1[stack->size];
        break;
        case 2:
            stack->size--;
            *item2 = stack->collection2[stack->size];
        break;
        case 3:
            stack->size--;
            *item3 = stack->collection3[stack->size];
        break;
    }
return true;
}

///
void info(Stack *stack)
{
    printf("\n    stack size: %d", stack->capacity);
    printf("\n          used: %d", stack->size);
    printf("\n          free: %d", stack->capacity - stack->size);

}




int main(void)
{



    Stack *stack = create_stack(5);


    if (stack == NULL)
        {
        printf("Error creating stack.\n");
        return 1;
    }


    bool verify = true;
    int i;



    while(verify){

        printf("\n\n------------------------------ \n options: \n 1. Push\n 2. Pop\n 3. Peek\n");
                printf(" 4. IsEmpty\n 5. IsFull\n 6. Exit");
        printf("\n choose the option with the number on the left of the option: ");
                scanf(" %d", &i);

        int peek_val1;
        int pop_val1;
        char peek_val2;
        char pop_val2;
        float peek_val3;
        float pop_val3;
        bool try_peek;
        bool try_pop;
        int s;


        //
        switch(i){
                    case 1:
                            if(is_full(stack)){
                                printf("\n The stack said that he doesn't want to take anything anymore. Maybe it should pop something first");
                                break;
                            }
                            s = stack->size;
                            printf("\nenter the data type\nintegers(1), characters(2), floats(3): ");
                            scanf(" %d", &stack->type[s]);

                                int in;
                                char c;
                                float f;

                                printf("Enter your choice : ");

                            switch(stack->type[s]){
                                case 1:
                                    scanf(" %d", &in);
                                        push(stack, in, 0, 0, stack->type[s]);
                                        printf("\nElement %d pushed onto the stack.\n", in);
                                    try_peek = peek(stack, &peek_val1, 0, 0, stack->type[s]);

                                        if(try_peek == false){
                                            printf("\nStack Contents: ( empty ) \n");
                                        } else{
                                            printf("\nStack Contents: %d", peek_val1);
                                        }
                                break;
                                case 2:
                                    scanf(" %c", &c);
                                        push(stack, 0, c, 0, stack->type[s]);
                                        printf("\nElement '%c' pushed onto the stack.\n", c);
                                    try_peek = peek(stack, 0, &peek_val2, 0, stack->type[s]);

                                        if(try_peek == false){
                                            printf("\nStack Contents: ( empty ) \n");
                                        } else{
                                            printf("\nStack Contents: '%c'", peek_val2);
                                        }
                                break;
                                case 3:
                                    scanf(" %f", &f);
                                        push(stack, 0, 0, f, stack->type[s]);
                                        printf("\nElement %f pushed onto the stack.\n", f);
                                    try_peek = peek(stack, 0, 0, &peek_val3, stack->type[s]);
                                        if(try_peek == false){
                                            printf("\nStack Contents: ( empty ) \n");
                                        } else{
                                            printf("\nStack Contents: %f", peek_val3);
                                        }
                                break;
                            }

                    break;
                    case 2:
                            s = stack->size - 1;
                            //printf(" %d", stack->type[s]);
                            switch(stack->type[s]){
                                case 1:
                                    try_pop = pop(stack, &pop_val1, 0, 0, stack->type[s]);

                                        if (try_pop == false){
                                            printf("\nPop Failed.\n");
                                        }else {
                                            printf("\nPopped Value: %d\n", pop_val1);
                                        }
                                break;
                                case 2:
                                    try_pop = pop(stack, 0, &pop_val2, 0, stack->type[s]);

                                        if (try_pop == false){
                                            printf("\nPop Failed.\n");
                                        }else {
                                            printf("\nPopped Value: '%c'\n", pop_val2);
                                        }
                                break;
                                case 3:
                                    try_pop = pop(stack, 0, 0, &pop_val3, stack->type[s]);

                                        if (try_pop == false){
                                            printf("\nPop Failed.\n");
                                        }else {
                                            printf("\nPopped Value: %f\n", pop_val3);
                                        }
                                break;
                            }

                            s = stack->size - 1;
                            switch(stack->type[s]){
                                case 1:
                                    try_peek = peek(stack, &peek_val1, 0, 0, stack->type[s]);

                                            if(try_peek == false){
                                                //printf("\nStack Contents: ( empty ) \n");
                                            } else{
                                                printf("\nStack Contents: %d", peek_val1);
                                            }
                                break;
                                case 2:
                                    try_peek = peek(stack, 0, &peek_val2, 0, stack->type[s]);

                                        if(try_peek == false){
                                            //printf("\nStack Contents: ( empty ) \n");
                                        } else{
                                            printf("\nStack Contents: '%c'", peek_val2);
                                        }
                                break;
                                case 3:
                                    try_peek = peek(stack, 0, 0, &peek_val3, stack->type[s]);

                                        if(try_peek == false){
                                            //printf("\nStack Contents: ( empty ) \n");
                                        } else{
                                            printf("\nStack Contents: %f", peek_val3);
                                        }
                                break;
                            }
                                            if(is_empty(stack)){
                                                printf("\nStack Contents: ( empty ) \n");
                                            }else{
                                            break;
                                            }
                    break;
                    case 3:
                            s = stack->size;
                            switch(stack->type[s]){
                                case 1:
                                    try_peek = peek(stack, &peek_val1, 0, 0, stack->type[s]);

                                            if(try_peek == false){
                                                printf("\nPeek Failed. \n");
                                            } else{
                                                printf("\nPeeked element: %d\n", peek_val1);
                                            }
                                break;
                                case 2:
                                    try_peek = peek(stack, 0, &peek_val2, 0, stack->type[s]);

                                        if(try_peek == false){
                                            printf("\nPeek Failed. \n");
                                        } else{
                                            printf("\nPeeked element: %c\n", peek_val2);
                                        }
                                break;
                                case 3:
                                    try_peek = peek(stack, 0, 0, &peek_val3, stack->type[s]);

                                        if(try_peek == false){
                                            printf("\nPeek Failed. \n");
                                        } else{
                                            printf("\nPeeked element: %f\n", peek_val3);
                                        }
                                break;
                            }
                    break;
                    case 4:

                        if (is_empty(stack)){
                            printf("\nStack is empty\n");
                        }else{
                            printf("\nStack is n_o_t empty\n");
                        }

                    break;
                    case 5:

                        if (is_full(stack)){
                            printf("\nStack is full.\n");
                        }else {
                            printf("\nStack_is_not_full.\n");
                        }

                    break;
                    case 6:
                        verify = false;
                    break;
        }
        if (verify) info(stack);

    }


  destroy_stack(stack);

  return 0;
}
