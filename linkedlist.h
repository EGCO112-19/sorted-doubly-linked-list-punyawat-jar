struct Node{
    int data;                                // each listNode contains a character
    struct Node *nextPtr;                    // pointer to next node
    struct Node *prevPtr;
};

typedef struct Node LLnode;                 // synonym for struct listNode
typedef LLnode *LLPtr;                      // synonym for ListNode*

// prototypes

int deletes(LLPtr *sPtr,int value); //DONE
int isEmpty(LLPtr sPtr);
void insert(LLPtr *sPtr, int value);//DONE
void printList(LLPtr currentPtr);
void printListR(LLPtr currentPtr);  //DONE
void instructions(void);

// display program instructions to user
void instructions(void){
   puts( "Enter your choice:\n"
      "   1 to insert an element into the list.\n"
      "   2 to delete an element from the list.\n"
      "   3 to end." );
}

// insert a new value into the list in sorted order
void insert(LLPtr *sPtr,int value){
    LLPtr newPtr;                      // pointer to new node
    LLPtr previousPtr;                 // pointer to previous node in list
    LLPtr currentPtr;                  // pointer to current node in list

    newPtr =(LLPtr) malloc(sizeof(LLnode));     // create node

    if(newPtr != NULL){                         // is space available
        newPtr->data = value;                   // place value in node
        newPtr->nextPtr = NULL;                 // node does not link to another node
        previousPtr = NULL;
        currentPtr = *sPtr;

                        // loop to find the correct location in the list
        while(currentPtr != NULL && value > currentPtr->data){
            previousPtr = currentPtr;       // walk to ...
            currentPtr = currentPtr->nextPtr;   // ... next node
        }
                          // insert new node at beginning of list
        if(previousPtr == NULL){
            newPtr->nextPtr = *sPtr;
            newPtr->prevPtr = NULL;
            if(currentPtr){
                currentPtr ->prevPtr = newPtr;
            }
            *sPtr = newPtr;
        }
        else{  // insert new node between previousPtr and currentPtr
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
            newPtr -> prevPtr = previousPtr;
            if(currentPtr){
                currentPtr -> prevPtr = newPtr;
            }
        }
    }
    else{
        printf("%d not inserted. No memory available.\n",value);
    }
}


  // delete a list element
int deletes(LLPtr *sPtr,int value){
    LLPtr previousPtr;                 // pointer to previous node in list
    LLPtr currentPtr;                  // pointer to current node in list
    LLPtr tempPtr;                              // temporary node pointer

  // delete first node
    if(value == (*sPtr)->data){
        tempPtr = *sPtr;              // hold onto node being removed
        *sPtr = (*sPtr)->nextPtr;               // de-thread the node
        if(*sPtr){
            (*sPtr)->prevPtr = NULL;
        }
        free(tempPtr);                          // free the de-threaded node
        return value;
    }
    else{
        previousPtr = *sPtr;
        currentPtr = (*sPtr)->nextPtr;

    // loop to find the correct location in the list
        while(currentPtr != NULL && currentPtr->data != value){
            previousPtr = currentPtr;          // walk to ...
            currentPtr = currentPtr->nextPtr;  // ... next node
        }

        // delete node at currentPtr
        if(currentPtr != NULL){
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
            if(currentPtr){
                currentPtr->prevPtr = tempPtr->prevPtr;
            }
            free(tempPtr);
            return value;
        }
    }

   return '\0';
}
                  // return 1 if the list is empty, 0 otherwise
int isEmpty(LLPtr sPtr){
    return sPtr == NULL;
}                 // end function isEmpty

                  // print the list
void printList(LLPtr currentPtr){
                  // if list is empty
    if(isEmpty(currentPtr)){
        puts("List is empty.\n");
    }
    else{
        puts("The list is:");

        // while not the end of the list
        while(currentPtr != NULL){
            printf("%d --> ",currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

        puts("NULL\n");
    }
}


void printListR(LLPtr currentPtr){
    if(isEmpty(currentPtr)){
        puts("List is empty.\n");
    }
    else{
        puts("The list is:");

        while(currentPtr->nextPtr != NULL){
            currentPtr = currentPtr->nextPtr;
        }
        
        printf("NULL ");
        while(currentPtr != NULL){
            printf("--> %d ",currentPtr->data);
            currentPtr = currentPtr->prevPtr;
        }
        puts("\n");
    }
}
