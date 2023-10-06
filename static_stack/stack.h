/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************          DataStructure              *****************/
/*****************        SWC:Static Stack.h           *****************/
/*****************           version:1.00              *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef STACK_H_
#define STACK_H_

/*********************************************************/

#define STACK_MAX_SIZE 5

/*********************************************************/
typedef struct stack_ds{

u32 stack_pointer; // this pointer point for the last element added in stack
//he see the top of stack
u32  data[STACK_MAX_SIZE];
}stack_ds_t;

typedef enum status
{
    R_NOK,
    R_OK

}Return_status_t;

typedef enum Stack_status
{
    Stack_empty,
    Stack_Fll,
    Stack_NotFull,

}Stack_status_t;



/**
*@brief  inialize the stack pointer
*@param  MyStack  pointer to stack
*@retval Status of the initialization process
*/
Return_status_t Stack_Init(stack_ds_t* MyStack);



Return_status_t Stack_Push(stack_ds_t* MyStack,u32 Copy_u32Data);
Return_status_t Stack_Pop(stack_ds_t* MyStack,u32 *Copy_u32Data);
Return_status_t Stack_Top(stack_ds_t* MyStack,u32 *Copy_u32Data);
Return_status_t Stack_Size(stack_ds_t* MyStack,u32 *Copy_u32Size);
Return_status_t Stack_display(stack_ds_t* MyStack);



#endif
