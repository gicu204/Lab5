#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
  int *collection1;
  char *collection2;
  float *collection3;
  int capacity;
  int size;

} Stack;


///
Stack *create_stack(int capacity, int type)
{
  if (capacity <= 0) return NULL;

  Stack *stack = malloc(sizeof(Stack));
  if (stack == NULL) return NULL;



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






int main(void)
{

    int type;

    printf("enter the data type\nintegers(1), characters(2), floats(3): ");
    scanf(" %d", &type);

    Stack *stack = create_stack(5, type);


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


        //
        switch(i){
                    case 1:

                                int in;
                                char c;
                                float f;

                                printf("Enter your choice : ");

                            switch(type){
                                case 1:
                                    scanf(" %d", &in);
                                        push(stack, in, 0, 0, type);
                                        printf("\nElement %d pushed onto the stack.", in);
                                    try_peek = peek(stack, &peek_val1, 0, 0, type);

                                        if(try_peek == false){
                                            printf("\nStack Contents: ( empty ) \n");
                                        } else{
                                            printf("\nStack Contents: %d", peek_val1);
                                        }
                                break;
                                case 2:
                                    scanf(" %c", &c);
                                        push(stack, 0, c, 0, type);
                                        printf("\nElement %c pushed onto the stack.", c);
                                    try_peek = peek(stack, 0, &peek_val2, 0, type);

                                        if(try_peek == false){
                                            printf("\nStack Contents: ( empty ) \n");
                                        } else{
                                            printf("\nStack Contents: %c", peek_val2);
                                        }
                                break;
                                case 3:
                                    scanf(" %f", &f);
                                        push(stack, 0, 0, f, type);
                                        printf("\nElement %f pushed onto the stack.", f);
                                    try_peek = peek(stack, 0, 0, &peek_val3, type);
                                        if(try_peek == false){
                                            printf("\nStack Contents: ( empty ) \n");
                                        } else{
                                            printf("\nStack Contents: %f", peek_val3);
                                        }
                                break;
                            }

                    break;
                    case 2:
                            switch(type){
                                case 1:
                                    try_pop = pop(stack, &pop_val1, 0, 0, type);

                                        if (try_pop == false){
                                            printf("Pop Failed.\n");
                                        }else {
                                            printf("Popped Value: %d\n", pop_val1);
                                        }
                                    try_peek = peek(stack, &peek_val1, 0, 0, type);

                                            if(try_peek == false){
                                                printf("\nStack Contents: ( empty ) \n");
                                            } else{
                                                printf("\nStack Contents: %d", peek_val1);
                                            }
                                break;
                                case 2:
                                    try_pop = pop(stack, 0, &pop_val2, 0, type);

                                        if (try_pop == false){
                                            printf("Pop Failed.\n");
                                        }else {
                                            printf("Popped Value: %c\n", pop_val2);
                                        }
                                    try_peek = peek(stack, 0, &peek_val2, 0, type);

                                        if(try_peek == false){
                                            printf("\nStack Contents: ( empty ) \n");
                                        } else{
                                            printf("\nStack Contents: %c", peek_val2);
                                        }
                                break;
                                case 3:
                                    try_pop = pop(stack, 0, 0, &pop_val3, type);

                                        if (try_pop == false){
                                            printf("Pop Failed.\n");
                                        }else {
                                            printf("Popped Value: %f\n", pop_val3);
                                        }
                                    try_peek = peek(stack, 0, 0, &peek_val3, type);

                                        if(try_peek == false){
                                            printf("\nStack Contents: ( empty ) \n");
                                        } else{
                                            printf("\nStack Contents: %f", peek_val3);
                                        }
                                break;
                            }
                    break;
                    case 3:
                            switch(type){
                                case 1:
                                    try_peek = peek(stack, &peek_val1, 0, 0, type);

                                            if(try_peek == false){
                                                printf("Peek Failed. \n");
                                            } else{
                                                printf("Peeked element: %d", peek_val1);
                                            }
                                break;
                                case 2:
                                    try_peek = peek(stack, 0, &peek_val2, 0, type);

                                        if(try_peek == false){
                                            printf("Peek Failed. \n");
                                        } else{
                                            printf("Peeked element: %c", peek_val2);
                                        }
                                break;
                                case 3:
                                    try_peek = peek(stack, 0, 0, &peek_val3, type);

                                        if(try_peek == false){
                                            printf("Peek Failed. \n");
                                        } else{
                                            printf("Peeked element: %f", peek_val3);
                                        }
                                break;
                            }
                    break;
                    case 4:

                        if (is_empty(stack)){
                            printf("Stack is empty\n");
                        }else{
                            printf("Stack is n_o_t empty\n");
                        }

                    break;
                    case 5:

                        if (is_full(stack)){
                            printf("Stack is full.\n");
                        }else {
                            printf("Stack_is_not_full.\n");
                        }

                    break;
                    case 6:
                        verify = false;
                    break;
        }

    }


  destroy_stack(stack);

  return 0;
}
