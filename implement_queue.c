
/**
 * Program to implement queue in c.
 * Compilation : gcc implement_queue.c
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

allocate_memory_to_queue() ->O(size).

*/


#include<stdio.h>
#include<stdlib.h>


int size = 0 , total_size = 2 , call = 0 , front_idx = -1 , current_idx = 0;

//size is current size of queue total_size is total memory given to circular queue call is number of times enqueue  is called front_idx is the index of front element current idx is the current index where element is to be added

int *queue;//our circular queue




void allocate_memory_to_queue()
{
    //if there is no memory allocated to our queue
    if(call == 0)
     {
        //allocating memory
        queue = (int*)calloc(total_size , sizeof(int));
        return;
     }
    total_size *= 2;//doubling the size
    int *temp;//temporary queue

    //allocating memory to temp
    temp = (int*)calloc(total_size , sizeof(int));
    int added_elements = 0;

    while(added_elements < size)  {
	 //copying all the elements of queue to temp
         temp[added_elements] = queue[front_idx];
         added_elements++;
         front_idx = (front_idx + 1) % size;
	 //as after size elements were added to start of array 
     }
    front_idx = 0; 
    current_idx = size;
    queue = temp;
    //now queue points towards temporary queue
}



// Adds a new element to the tail of the queue 
void enqueue(int value)
{
    if(!call || size == total_size - 1){
        allocate_memory_to_queue();
     }
    queue[current_idx] = value;//enqueueing the new element
    size++;
    ++current_idx;
    current_idx %= total_size;
    if(front_idx == -1) front_idx++;//now front represents first element
    call++;
}



// Remove and return the element at the head of the queue.
int dequeue()
{
    if(size == 0) {
       front_idx = -1;//queue is empty
       return -1;
     }
    size--;
    int front_element = queue[front_idx];//front element of queue
    ++front_idx;
    front_idx %= total_size;
    //front can be at start of array as it is circular queue so elements are added at start also
    if(size == 0){
          front_idx = -1;
          current_idx = 0;
      }

    return front_element;
}


// Return but not remove the element at the head of the queue.
int peek()
{
    if(front_idx == -1)
        return -1;

    else
        return queue[front_idx];
        //returns peek element 

}



// Return 1 if the queue is empty, else return 0
int is_empty()
{
    if(size == 0)
        return 1;//1 means it is empty
    else
        return 0;
}




int main()
{
    enqueue(1);
    printf("enqueued %d  \n",1);
    printf("queue size = %d queue capacity = %d\n",size, total_size);
    enqueue(2);
    printf("enqueued %d  \n",2);
    printf("queue size = %d queue capacity = %d\n",size, total_size);
    enqueue(3);
    printf("enqueued %d  \n",3);
    printf("queue size = %d queue capacity = %d\n",size, total_size);
    enqueue(4);
    printf("enqueued %d  \n",4);
    printf("queue size = %d queue capacity = %d\n",size, total_size);
    printf("peek = %d\n",peek());

    while(!is_empty()) {
       printf("dequeued %d  \n",peek());
       dequeue();
       printf("queue size = %d queue capacity = %d\n",size, total_size);
     }


    
    if(is_empty)
	printf("queue is empty\n");
}

