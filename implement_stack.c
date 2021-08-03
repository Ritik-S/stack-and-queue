/**
 * Program to implement stack in c.
 * Compilation : gcc implement_stack.c
 * Execution : ./a.out
 *
 * @Ritik Sedana ( 1910990138 )  , 02/8/2021
 * Day_2_Coding_Assignment.
 *
 */

/*

Runtime Complexities of created Functions : 

push()         -> O(1) 
              
       
pop()          -> O(1).

peek()         -> O(1).

is_empty()     -> O(1).

allocate_memory_to_stack->O(size)

*/


#include<stdio.h>
#include <stdlib.h>
int total_size=3;//total memory allocated to stack ,it increases when buffer is full
int call=0;//just a record of how many times push is called used to allocate memory to stack
int *stack;//our dynamic stack
int size=0;//current size of stack



 void allocate_memory_to_stack()
 {
    if(call==0)//call==0 means it is first time when push is called so stack is having no memory till now
     {
       stack = (int *)calloc(total_size , sizeof(int) );
       //now stack got some memory
       return ;
     }
    total_size*=2;//doubling the total size of stack
    int *temp;
    //tempory array to restore all the elements which were in stack and it is double the size of previous stack
    temp=(int *)calloc(total_size ,sizeof(int));
    for(int i=0;i<size;++i)
    temp[i]=stack[i];
    stack=temp;
    //now our stack has double size

 }



 // Adds a new element to the stack
void push(int value)
{
    if(!call||size==total_size-1)//if there is no memory in stack or there is only one block of memory left in our stack
    {
      allocate_memory_to_stack();
      //it will give memory to stack as well as double the memory of stack if required
    }
    stack[size]=value;//push the value in stack
    size++;
    call++;
}


// Remove and return the element from the stack.
int pop()
{
    if(!size)
    return -1;
    int top_value= stack[size];//top value of stack
    size--;
    return top_value;
}


// Return but not remove the element at the top of the stack.
int peek()
{
    if(size==0)
    return -1;// if empty return -1 because there is no peek element
    else
    return stack[size-1];//return top or peek element of stack
}


// Return 1 if the stack is empty, else return 0
int is_empty()
{
    if(size==0)
    return 1;
    else
    return 0;
}


int main()
{
    push(1);
    printf("pushed %d  \n",peek());
    printf("stack size = %d stack capacity = %d\n",size, total_size);
    push(2);
    printf("pushed %d  \n",peek());
    printf("stack size = %d stack capacity = %d\n",size, total_size);
    push(3);
    printf("pushed %d  \n",peek());
    printf("stack size = %d stack capacity = %d\n",size, total_size);
    push(4);
    printf("pushed %d  \n",peek());
    printf("stack size = %d stack capacity = %d\n",size, total_size);
    while(!is_empty()) {
       printf("popped %d  \n",peek());
       pop();
       printf("stack size = %d stack capacity = %d\n",size, total_size);
    }

}

