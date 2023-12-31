#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "stack.h"

u32 Stack1_Size = 0, Stack1_Count = 0;
Stack_t *Stack1 = NULL;
void *Stack1_Return = NULL;

u32 Var1 = 0x11;
f32 Var2 = 2.14;
char Var3 = 'a';

int main()
{
    StackStatus_t Stack1_Status = STACK_NOK;

    printf("Enter number of stack 1 elements : ");
    scanf("%i", &Stack1_Size);
    Stack1 = CreateStack(Stack1_Size, &Stack1_Status);
    if(Stack1){
        printf("Stack 1 created \n");
    }

    Stack1_Status = PushStack(Stack1, &Var1); printf("Stack1_Status = %i \n", Stack1_Status);
    Stack1_Status = PushStack(Stack1, &Var2); printf("Stack1_Status = %i \n", Stack1_Status);
    Stack1_Status = PushStack(Stack1, &Var3); printf("Stack1_Status = %i \n", Stack1_Status);
    Stack1_Status = PushStack(Stack1, &Var3); printf("Stack1_Status = %i \n", Stack1_Status);
    Stack1_Status = PushStack(Stack1, &Var3); printf("Stack1_Status = %i \n", Stack1_Status);
    Stack1_Status = PushStack(Stack1, &Var3); printf("Stack1_Status = %i \n", Stack1_Status);

    Stack1_Status = StackCount(Stack1, &Stack1_Count); printf("Stack1_Status = %i \n", Stack1_Status);
   printf("Stack1_Count = %i \n", Stack1_Count);

    Stack1_Return = StackTop(Stack1, &Stack1_Status); printf("Stack1_Status = %i \n", Stack1_Status);
    printf("StackTop = %c \n", *((u32 *)Stack1_Return));

    Stack1_Return = PopStack(Stack1, &Stack1_Status); printf("Stack1_Status = %i \n", Stack1_Status);
    printf("PopStack = %c \n", *((char *)Stack1_Return));
    Stack1_Return = PopStack(Stack1, &Stack1_Status); printf("Stack1_Status = %i \n", Stack1_Status);
    printf("PopStack = %f \n", *((f32 *)Stack1_Return));
    Stack1_Return = PopStack(Stack1, &Stack1_Status); printf("Stack1_Status = %i \n", Stack1_Status);
    printf("PopStack = 0x%X\n", *((u32 *)Stack1_Return));
    Stack1_Return = PopStack(Stack1, &Stack1_Status); printf("Stack1_Status = %i \n", Stack1_Status);


//    Stack1_Status = StackCount(Stack1, &Stack1_Count); printf("Stack1_Status = %i \n", Stack1_Status);
//    printf("Stack1_Count = %i \n", Stack1_Count);
//
//    Stack1_Return = PopStack(Stack1, &Stack1_Status); printf("Stack1_Status = %i \n", Stack1_Status);
//
//    Stack1 = DestroyStack(Stack1, &Stack1_Status);
//    if(!Stack1){
//        printf("Stack 1 destroyed \n");
//    }
    return 0;
}
