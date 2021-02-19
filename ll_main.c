#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(){
    LLPtr startPtr = NULL;    // initially there are no nodes
    unsigned int choice;      // user's choice
    int item;                 // value entered by user

    instructions(); // display the menu
    printf("%s","? ");
    scanf("%u",&choice);

                              // loop while user does not choose 3
    while(choice != 3){
        switch (choice){
            case 1:
                printf("%s","Enter a number: ");
                scanf("%d",&item);
                insert(&startPtr,item);                         // insert item in list : ใส่ค่าเข้าไปใน linkedlist
                printList(startPtr);
                printListR(startPtr);                           //---for assignment : DONE!!---
                break;
            case 2:                          // delete an element
                                             // if list is not empty
                if(!isEmpty(startPtr)){
                    printf("%s","Enter number to be deleted: ");
                    scanf("%d",&item);

                              // if character is found, remove it
                    if(deletes(&startPtr,item)){// remove item
                        printf("%d deleted.\n",item);
                        printList(startPtr);
                        printListR(startPtr);
                    }
                    else{
                        printf("%d not found.\n\n",item);
                    }
                }
                else{
                    puts("List is empty.\n");
                }
                break;

            default:
                puts("Invalid choice.\n");
                instructions();
                break;
        }
        printf("%s","? ");
        scanf("%u",&choice);
    }
    puts("End of run.");
}
