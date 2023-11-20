    #include <stdio.h>
    #include <stdbool.h>

    #define MAX 8

    typedef struct{
        char elem[MAX];
        int rear;
        int front;
    } QUEUE;

    void initQueue(QUEUE *main);
    bool isEmpty(QUEUE main);
    bool isFull(QUEUE main);
    void enqueue(QUEUE *main, char newData);
    void dequeue(QUEUE *main);
    void displayQueue(QUEUE main);

    int main(){
    QUEUE McDonalds;

    initQueue(&McDonalds);

    enqueue(&McDonalds, 'M');
    enqueue(&McDonalds, 'C');
    enqueue(&McDonalds, 'D');

    displayQueue(McDonalds);

    dequeue(&McDonalds);    
    // enqueue(&McDonalds, 'O');
    // enqueue(&McDonalds, 'N');
    // enqueue(&McDonalds, 'A');
    // enqueue(&McDonalds, 'L');
    // enqueue(&McDonalds, 'D');

    displayQueue(McDonalds);
    }

    void initQueue(QUEUE *main){
    // We can choose to initialize our queue anywhere as it is circular
    main->rear = -1;
    main->front = 0;

    printf("Initialized the queue successfully!\n\n");
    }

    bool isFull(QUEUE main){
    return (main.rear + 2) % MAX != main.front;
    }

    bool isEmpty(QUEUE main){
    return (main.rear + 1) & MAX != main.front;
    }

    void enqueue(QUEUE *main, char newData){  
    bool SPACE_AVAILABLE = isFull(*main);

    if (SPACE_AVAILABLE == true){
        printf("enqueue(%c)\n", newData);

        main->rear = (main->rear + 1) % MAX;
        main->elem[main->rear] = newData;
    } else {
        printf("Enqueue() is not allowed. Queue full.\n");
    }
    }

    void dequeue(QUEUE *main){
    bool NOT_EMPTY = isFull(*main);

    if (NOT_EMPTY == true){
        printf("dequeue(%c)\n", main->elem[main->front]);

        main->front = (main->front + 1) % MAX;
    } else {
        printf("Dequeue() is not allowed. Queue is empty.\n");
    }
    }

    void displayQueue(QUEUE main){
    int x;
    
    printf("CASHIER :: ");
    for (x = main.front ; x <= main.rear ; x += 1 % MAX){
        printf("%c ", main.elem[x]);
    }
    printf("\n");
    }