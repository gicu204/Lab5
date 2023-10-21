#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
  char *collection;
  int capacity;
  int size;

} Stack;


///
Stack *create_stack(int capacity)
{
  if (capacity <= 0) return NULL;

  Stack *stack = malloc(sizeof(Stack));
  if (stack == NULL) return NULL;

  stack->collection = malloc(sizeof(char) * capacity);

  if (stack->collection == NULL)
  {
    free(stack);
    return NULL;
  }

  stack->capacity = capacity;
  stack->size = 0;

  return stack;
}

///
void destroy_stack(Stack *stack)
{
  free(stack->collection);
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
bool push(Stack *stack, char item)
{
  if (is_full(stack)) return false;

  stack->collection[stack->size] = item;

  stack->size++;

  return true;
}

///
bool peek(Stack *stack, char *item)
{
  if (is_empty(stack)) return false;

  *item = stack->collection[stack->size - 1];

  return true;
}

///
bool pop(Stack *stack, char *item)
{
  if (is_empty(stack)) return false;

  stack->size--;

  *item = stack->collection[stack->size];

  return true;
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


        char peek_val;
        char pop_val;
        bool try_peek;


        //
        switch(i){
            case 1:

                char c;
                printf("Enter your choice : ");
                scanf(" %c", &c);
                push(stack, c);
                printf("\nElement %c pushed onto the stack.", c);

               // char peek_val;
                try_peek = peek(stack, &peek_val);

                    if(try_peek == false){
                        printf("\nStack Contents: ( empty ) \n");
                    } else{
                        printf("\nStack Contents: %c", peek_val);
                        //for(int j = stack->size; j < 0; j--){
                        //        printf("ddd");
                        //    printf(" %c \n\t", stack->collection[j]);
                        //}
                    }

            break;
            case 2:

                //char pop_val;
                char peek_val;
                bool try_pop = pop(stack, &pop_val);

                    if (try_pop == false){
                        printf("Pop Failed.\n");
                    }else {
                        printf("Popped Value: %c\n", pop_val);
                    }


                    try_peek = peek(stack, &peek_val);

                    if(try_peek == false){
                        printf("\nStack Contents: ( empty ) \n");
                    } else{
                        printf("\nStack Contents: %c", peek_val);
                        //for(int j = stack->size; j < 0; j--){
                        //        printf("ddd");
                        //    printf(" %c \n\t", stack->collection[j]);
                        //}
                    }

            break;
            case 3:

                    try_peek = peek(stack, &peek_val);

                    if(try_peek == false){
                        printf("Peek Failed. \n");
                    } else{
                        printf("Peeked element: %c", peek_val);
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
