/*C program for input restricted deque [insert right, remove right & remove left].
 Show how this can be used to represent both stack & queue*/

 
#include <stdio.h>
#define N 5

int deque[N], f = -1, r = -1;//Globalally declaring the array and position of front and rear element initialized to -1

void enqueue_rear(int x)
 {
    if ((f==0 && r == N - 1) || (f==r+1))//Queue full condition will be checked 
    {
        printf("Queue is full\n");
    } else if (f == -1 && r == -1)//insertion of element in an empty queue
    {
        f = r = 0;
        deque[r] = x;
    } 
    else if(r==N-1)//insertion at beggining of queue
    {
        r=0;
        deque[r]=x;
    }
    else 
    {
        r++;
        deque[r] = x;
    }
}

int dequeue_rear() {
    int item = -1;//item is used to check whether
    if (f == -1 && r == -1) // Only one element in the queue
    {
        printf("Queue is empty\n");
    } else if (f == r)//Only one element in queue
     {
        item = deque[r];
        f = r = -1;
    } else if(r==0)//move rear to end of queue
    {
        item=deque[r];
        r=N-1;
    }
    else {
        item = deque[r];
        r--;
    }
    return item;
}

int dequeue_front() {
    int item = -1;
    if (f == -1 && r == -1)
     {
        printf("Queue is empty\n");
    } else if (f == r)
     {
        item = deque[f];
        f = r = -1;
    } else if(f==N-1)// To move front to starting of queue
    {
        item = deque[f];
        f=0;
    }
    else {
        item = deque[f];
        f++;
    }
    return item;
}

void display() {
    int i=f;
    if (f == -1 && r == -1) {
        printf("Queue is empty\n");
    } else {
        printf("The elements are: ");
        while(i!=r)
        {
            printf("%d ", deque[i]);
            i=(i+1)%N;//for circular traversal  
        }printf("%d\n",deque[r]);
    }
}


int main()
 {
    char choice;
    int choice1;
    int choice2;
    int item;

    while (1) {
        printf("Enter Q for Queue or S for Stack operations: ");
        scanf(" %c",&choice);

        switch (choice) 
        {
            case 'Q':
            case 'q':
                printf("\n1. Enqueue Rear\n2. Dequeue Rear\n3. Dequeue Front\n4. Display\n5. Exit\n");
                printf("Enter your choice: ");
                scanf(" %d", &choice1); 

                switch (choice1) {
                    case 1:
                        printf("Enter the element to enqueue at the rear: ");
                        scanf("%d", &item);
                        enqueue_rear(item);
                        break;
                    case 2:
                        item = dequeue_rear();
                        if (item != -1) //checks whether queue is empty
                        {
                            printf("Dequeued element from rear: %d\n", item);
                        }
                        break;
                    case 3:
                        item = dequeue_front();
                        if (item != -1) {
                            printf("Dequeued element from front: %d\n", item);
                        }
                        break;
                    case 4:
                        display();
                        break;
                    case 5:
                        printf("Exiting the program.\n");
                        return 0;
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
                break;

            case 'S':
            case 's':
                printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
                printf("Enter your choice: ");
                scanf(" %d", &choice2); 
                switch (choice2) {
                    case 1:
                        printf("Enter the element to push: ");
                        scanf("%d", &item);
                        enqueue_rear(item);
                        break;
                    case 2:
                        item = dequeue_rear();
                        if (item != -1) 
                        {
                            printf("Popped element: %d\n", item);
                        }
                        break;
                    case 3:
                        display();
                        break;
                    case 4:
                        printf("Exiting the program.\n");
                        return 0;
                    case 5:
                printf("Exiting the program.\n");
                return 0;                    
                default:
                        printf("Invalid choice. Please try again.\n");
                        
                }
                default:
                        printf("Invalid choice. Please try again.\n");
                break;
                }
                
            
        }
    }