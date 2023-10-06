#include <stdio.h>
#include <stdlib.h>
#include"STD_tYPES.h"
#include "stack.h"

stack_ds_t stack1;
stack_ds_t stack2;
int x;
int main()
{
    Return_status_t ret=R_NOK;

    ret= Stack_Init(&stack1);

    if(ret == R_NOK)
    {
        printf("stack1 failed to be initialized");
    }else
    {
        ret=Stack_Push(&stack1,11);
        ret=Stack_Push(&stack1,22);
        ret=Stack_Push(&stack1,33);
        ret=Stack_Push(&stack1,44);
        ret=Stack_Push(&stack1,55);
        ret=Stack_Push(&stack1,66);
        ret=Stack_Push(&stack1,77);
  printf("---------------------------------\n",x);

        ret=Stack_Pop(&stack1,&x);
      printf("STACK POP VALUE = %i\n",x);
//        ret=Stack_Pop(&stack1,&x);
//        printf("STACK POP VALUE = %i\n",x);
//        ret=Stack_Pop(&stack1,&x);
//        printf("STACK POP VALUE = %i\n",x);
//        ret=Stack_Pop(&stack1,&x);
//        printf("STACK POP VALUE = %i\n",x);
      //  ret=Stack_Pop(&stack1,&x);
//printf("STACK POP VALUE = %i\n",x);
//        ret=Stack_Pop(&stack1,&x);
//        ret=Stack_Pop(&stack1,&x);
printf("---------------------------------\n",x);
//ret=Stack_Top(&stack1,&x);
Stack_display(&stack1);
    }

}
