/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************          DataStructure              *****************/
/*****************       SWC:Dynamic Stack.h           *****************/
/*****************           version:1.00              *****************/
/***********************************************************************/
/***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "stack.h"

static u8 StackEmpty(Stack_t * Copy_structure)
{
return (Copy_structure->ElementCount == 0);
}
static u8 StackFull(Stack_t * Copy_structure)
{
return (Copy_structure->ElementCount == Copy_structure->StackMaxSize);
}



Stack_t* CreateStack (u32 maxSize, StackStatus_t *ret_status)
{
    Stack_t* My_Stack=NULL;

    if(NULL == ret_status)
    {
        *ret_status = STACK_NULL_POINTER;
        My_Stack=NULL;
    }
    else
    {
      My_Stack = (Stack_t *)malloc(sizeof(Stack_t));
      if(!My_Stack)
      {
          *ret_status = STACK_NOK;
          My_Stack=NULL;
      }
      else
      {
          My_Stack->ElementCount=0;
          My_Stack->StackTop=-1;
          My_Stack->StackMaxSize=maxSize;
          My_Stack->StackArray=(void**) calloc(My_Stack->StackMaxSize,sizeof(void *));
          if(!My_Stack->StackArray)
          {
              free(My_Stack);
              My_Stack=NULL;
               *ret_status=STACK_NOK;

          }else{

              *ret_status=STACK_OK;
          }
      }

    }

return My_Stack;
}
Stack_t* DestroyStack (Stack_t* stack_obj, StackStatus_t *ret_status)
{
    if(NULL == ret_status || NULL == stack_obj)
    {
        *ret_status = STACK_NULL_POINTER;
    }
    else
    {
        free(stack_obj->StackArray);
        free(stack_obj);
        *ret_status=STACK_OK;
    }
    return NULL;
}
StackStatus_t PushStack (Stack_t* stack_obj, void* itemPtr)
{
    StackStatus_t Local_Status=STACK_NOK;

    if((NULL == stack_obj)||(NULL == itemPtr))
    {
        Local_Status=STACK_NULL_POINTER;
    }
    else
    {
        if(StackFull(stack_obj))
        {
          Local_Status =STACK_FULL;
        }
        else{
       (stack_obj->StackTop)++;
       stack_obj->StackArray[stack_obj->StackTop]=itemPtr;
       (stack_obj->ElementCount)++;
         Local_Status =STACK_OK;
        }



    }

return Local_Status;
}
void* PopStack (Stack_t* stack_obj, StackStatus_t *ret_status)
{
    void* PtrOut=NULL;
 if((NULL == stack_obj)||(NULL == ret_status))
    {
        *ret_status=STACK_NULL_POINTER;
    }
    else
    {
         if(StackEmpty(stack_obj))
          {
             *ret_status=STACK_EMPTY;
          }
          else
          {
            PtrOut=stack_obj->StackArray[stack_obj->StackTop];
            (stack_obj->StackTop)--;
            (stack_obj->ElementCount)--;
             *ret_status=STACK_OK;
          }
    }
    return PtrOut;
}
void* StackTop (Stack_t* stack_obj, StackStatus_t *ret_status)
{
  void* PtrOut=NULL;
 if((NULL == stack_obj)||(NULL == ret_status))
    {
        *ret_status=STACK_NULL_POINTER;
    }
    else
    {
         if(StackEmpty(stack_obj))
          {
             *ret_status=STACK_EMPTY;
          }
          else
          {
            PtrOut=stack_obj->StackArray[stack_obj->StackTop];
             *ret_status=STACK_OK;
          }
    }
    return PtrOut;
}

StackStatus_t StackCount (Stack_t* stack_obj, u32 *stack_count)
{
    StackStatus_t  Local_Status= STACK_NOK;
     if((NULL == stack_obj)||(NULL == stack_count))
     {
         Local_Status = STACK_NULL_POINTER;
     }
     else
     {
         *stack_count=stack_obj->ElementCount;
        Local_Status = STACK_OK;
     }
return Local_Status;
}
