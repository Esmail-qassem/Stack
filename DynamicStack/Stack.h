/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************          DataStructure              *****************/
/*****************       SWC:Dynamic Stack.h           *****************/
/*****************           version:1.00              *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef STACK_H_
#define STACK_H_
typedef struct
{
    void ** StackArray;   /** Pointer to the array that allocated in the heap **/
    s32     ElementCount; /** Has Actual number of element in the stack*/
    u32     StackMaxSize; /** Has Maximum number of element in the stack*/
    s32     StackTop;     /** Has the index of element in the stack*/
}Stack_t;

typedef enum
{
    STACK_NOK=0,
    STACK_OK,
    STACK_FULL,
    STACK_EMPTY,
    STACK_NULL_POINTER
}StackStatus_t;


/**
  * @brief  This algorithm creates an empty stack by allocating the head
            structure and the array from dynamic memory.
  * @param  (maxSize) Stack maximum number of elements
  * @param  (ret_status) Status returned while performing this operation
  * @retval Pointer to the allocated stack in the heap
  */
Stack_t* CreateStack (u32 maxSize, StackStatus_t *ret_status);

/**
  * @brief  This function releases all memory to the heap.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (ret_status) Status returned while performing this operation
  * @retval NULL
  */
Stack_t* DestroyStack (Stack_t* stack_obj, StackStatus_t *ret_status);

/**
  * @brief This function pushes an item onto the stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (itemPtr) pointer to be inserted
  * @retval Status returned while performing this operation
  */
StackStatus_t PushStack (Stack_t* stack_obj, void* itemPtr);

/**
  * @brief This function pops the item on the top of the stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (ret_status) Status returned while performing this operation
  * @retval Pointer to user data if successful, NULL if underflow
  */
void* PopStack (Stack_t* stack_obj, StackStatus_t *ret_status);

/**
  * @brief  This function retrieves the data from the top of the
            stack without changing the stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (ret_status) Status returned while performing this operation
  * @retval Pointer to user data if successful, NULL if underflow
  */
void* StackTop (Stack_t* stack_obj, StackStatus_t *ret_status);

/**
  * @brief  Returns number of elements in stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (stack_count) number of elements in stack.
  * @retval Status returned while performing this operation
  */
StackStatus_t StackCount (Stack_t* stack_obj, u32 *stack_count);

#endif // STACK_H_
