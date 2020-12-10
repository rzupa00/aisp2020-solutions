#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INPUT_STACK_PUSH  1
#define INPUT_STACK_POP   2
#define INPUT_STACK_PRINT 3
#define INPUT_QUEUE_PUSH  4
#define INPUT_QUEUE_POP   5
#define INPUT_QUEUE_PRINT 6
#define INPUT_EXIT        7

#define RANGE_MIN 10
#define RANGE_MAX 100

typedef struct _node node;
typedef node* position;
struct _node
{
    int element;
    position next;
};


void printMenu(void);
void clearScreen(void);

void pushStack(position);
void pushQueue(position);

void pop(position);

void print(position);

void deleteAll(position);

int getRandom(void);
position createNew(const int);

int main(void)
{
    node stack;
    node queue;
    
    int isAppRunning = 1;
    int input = 0;
    
    stack.next = NULL;
    queue.next = NULL;
    
	srand(time(NULL));
	
    while(isAppRunning)
    {
        printMenu();
        scanf(" %d", &input);
        
        clearScreen();
        
        switch(input)
        {
        case INPUT_STACK_PUSH:
            pushStack(&stack);
            break;
        
        case INPUT_STACK_POP:
            pop(&stack);
            break;
        
        case INPUT_STACK_PRINT:
            print(&stack);
            break;
            
        case INPUT_QUEUE_PUSH:
            pushQueue(&queue);
            break;
        
        case INPUT_QUEUE_POP:
            pop(&queue);
            break;
        
        case INPUT_QUEUE_PRINT:
            print(&queue);
            break;
        
        case INPUT_EXIT:
            isAppRunning = 0;
            break;
            
        default:
            printf("WRONG SELECTION!!!\n");
            printf("PLEASE GO AGAIN!!!\n");
        }        
    }
    
    deleteAll(&stack);
    deleteAll(&queue);
    return 0;
}

void printMenu(void)
{
    printf("###################################\n");
    printf("# Push to stack ********** %d #\n", INPUT_STACK_PUSH);
    printf("# Pop from stack ********* %d #\n", INPUT_STACK_POP);
    printf("# Print stack ************ %d #\n", INPUT_STACK_PRINT);
    printf("# Push to queue ********** %d #\n", INPUT_QUEUE_PUSH);
    printf("# Pop from queue ********* %d #\n", INPUT_QUEUE_POP);
    printf("# Print queue ************ %d #\n", INPUT_QUEUE_PRINT);
    printf("# Close the application ** %d #\n", INPUT_EXIT);
    printf("###################################\n\n");

    printf("Enter your command:\t");
}

void clearScreen(void)
{
    #ifdef _WIN32
        #define CLEAR_SCREEN "cls"
    #else
        #define CLEAR_SCREEN "clear"
    #endif

    system(CLEAR_SCREEN);
}

void pushStack(position head)
{
    int targetValue = getRandom();
    position target = createNew(targetValue);
    if(target == NULL)
    {
        printf("ERROR!!!");
        printf("ALLOCATION FAILED!!!");
        return;
    }
    
    target->next = head->next;
    head->next = target;

    printf("Pushed number %d\n", targetValue);
}

void pushQueue(position head)
{
    int targetValue = getRandom();
    position target = createNew(targetValue);
    
	static position lastElement = NULL;
	if(lastElement == NULL)
	{
		lastElement = head;
	}
    
    if(target == NULL)
    {
        printf("ERROR!!!");
        printf("ALLOCATION FAILED!!!");
        return;
    }
    
    target->next = NULL;
    lastElement->next = target;
	lastElement = target;

    printf("Pushed number %d\n", targetValue);
}

void pop(position head)
{
    position target = head->next;
    if(target == NULL)
	{
		printf("NOTE:\t STRUCTURE IS EMPTY!!!\n");
		return;
	}
	
	head->next = target->next;

    printf("Popped number %d\n", target->element);
    free(target);
}

void print(position head)
{
	int counter = 1;
    position current = head->next;
    
    while(current != NULL)
    {
        printf("%d) %d\n", counter, current->element);
		current = current->next;
		counter++;
    }
}

void deleteAll(position head)
{
    while(head->next != NULL)
        pop(head);
}

int getRandom(void)
{
    int target = (rand() % (RANGE_MAX - RANGE_MIN + 1)) + RANGE_MIN;
    
    return target;
}

position createNew(const int value)
{
    position target = (position) malloc(sizeof(node));
    if(target == NULL)
        return NULL;
    
    target->element = value;
    target->next    = NULL;
    return target;
}