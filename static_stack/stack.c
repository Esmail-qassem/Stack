/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************          DataStructure              *****************/
/*****************        SWC:Static Stack.c           *****************/
/*****************           version:1.00              *****************/
/***********************************************************************/
/***********************************************************************/

#include <stdio.h>
#include"STD_tYPES.h"
#include "stack.h"
static Stack_status_t  Stack_Empty (stack_ds_t* MyStack)
{
if(MyStack->stack_pointer == -1)
     {
         return Stack_empty;
     }
     else{return Stack_NotFull;}
}

static Stack_status_t Stack_Full (stack_ds_t* MyStack)
{
if(MyStack->stack_pointer == STACK_MAX_SIZE-1)
     {
         return Stack_Fll;
     }
     else{return Stack_NotFull;}
}


Return_status_t Stack_Init(stack_ds_t* MyStack)
{
    Return_status_t Ret=R_NOK;
     if(NULL == MyStack)
     {
        Ret = R_NOK;
     }
     else{
        MyStack->stack_pointer= -1;
        Ret = R_OK;
     }
    return Ret;
}


Return_status_t Stack_Push(stack_ds_t* MyStack,u32 Copy_u32Data)
{
    Return_status_t ret =R_NOK;
if((MyStack== NULL)||(Stack_Fll==Stack_Full(MyStack)))
{
      printf("value (%i) not pushed to stack. \n",Copy_u32Data);
    ret =R_NOK;
}
else{
      MyStack->stack_pointer++;
      MyStack->data[MyStack->stack_pointer]=Copy_u32Data;

      printf("value (%i) pushed to stack. \n",Copy_u32Data);
      ret =R_OK;

}

    return ret;

}
Return_status_t Stack_Pop(stack_ds_t* MyStack,u32 *Copy_u32Data)
{

   Return_status_t ret =R_NOK;
if((MyStack== NULL)||(NULL==Copy_u32Data)||(Stack_empty==Stack_Empty(MyStack)))
{
    printf("ERROR... STACK IS EMPTY, CAN'T POP ANY VALUE\n");
    ret =R_NOK;
}
else{
    *Copy_u32Data=MyStack->data[MyStack->stack_pointer];
    MyStack->stack_pointer--;
      printf("value (%i) IS poped from stack. \n",*Copy_u32Data);
      ret =R_OK;

}

    return ret;


}
Return_status_t Stack_Top(stack_ds_t* MyStack,u32 *Copy_u32Data)
{
   Return_status_t ret =R_NOK;
if((MyStack== NULL)||(NULL==Copy_u32Data)||(Stack_empty==Stack_Empty(MyStack)))
{
    printf("ERROR... STACK IS EMPTY,\n");
    ret =R_NOK;
}
else{
    *Copy_u32Data=MyStack->data[MyStack->stack_pointer];
      printf("value (%i) Is TOP stack. \n",*Copy_u32Data);
      ret =R_OK;
}
    return ret;
}

Return_status_t Stack_Size(stack_ds_t* MyStack,u32 *Copy_u32Size)
{
Return_status_t ret =R_NOK;
if((MyStack== NULL)||(NULL==Copy_u32Size))
{
    ret =R_NOK;
}
else{
    *Copy_u32Size=(MyStack->stack_pointer)+1;
      ret =R_OK;
}
    return ret;
}
Return_status_t Stack_display(stack_ds_t* MyStack)
{
    Return_status_t ret =R_NOK;

    if((MyStack== NULL)||(Stack_Empty(MyStack)==Stack_empty))
       {
           ret =R_NOK;
       }
       else
        {
            for(int i=MyStack->stack_pointer;i>=0;i--)
            {
                printf("Index[%d] is : %d \n",i+1,MyStack->data[i]);
            }
          ret =R_OK;
        }
return ret;
}
