#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>

int main()
{
    struct Node
    {
        int number;
        struct Node *next;
    };
    
    typedef struct Node *PNode;
    PNode List = (PNode) malloc(sizeof(struct Node));
    PNode List_4Head = List; // temporary head pointer(gonna be used for output)
    PNode List_Head = List; // absolute head pointer
    PNode List_Buff = (PNode) malloc(sizeof(struct Node));//buffer for the deletion opetations
    if (List==NULL|List_Buff==NULL) // memory usage check
    {
        printf("Out of memory \n");
        return -1;
    }

    
    //array fillage 
    int cmd = 0;
    int NCount = 0;
    int ExpectedSumm = 0;
    for(int i = 0; i<4; i++)
    {
        printf("Type in the %d element: ", i+1);
        scanf("%d", &cmd);
        /* if(isalpha(cmd)|isspace(cmd))
            {
                printf("Type error. \n");
                return 0;
            } */
        List->number= cmd;
        ExpectedSumm = ExpectedSumm + cmd;
        NCount++;
        List->next=(PNode) malloc(sizeof(struct Node));
        List = List->next;
        if (List==NULL) //one more memory usage check
        {
            printf("Out of Memory \n");
            return -1;
        }                
    }
    
    //array output
    printf("Your array: ");
    for(int i = 0; i!=NCount;i++)
    {
        printf("%d ;",List_4Head->number);
        List_4Head=List_4Head->next;
        List=List_4Head;
    }
    List_4Head = List_Head; //refresh the 4Head pointer for further usage
    printf("\n");
    
    //summ of all elements
    printf("===Checking the sum of all elements=== \n");
    int FactSumm = 0 ;
    for(int i = 0; i!=NCount;i++)
    {
        FactSumm = FactSumm + List_4Head->number;
        List_4Head=List_4Head->next;
        List=List_4Head;
    }
    List_4Head = List_Head;//anoter refresh
    printf("ExpectedSumm is: %d \n", ExpectedSumm);
    printf("Prog summ is: %d \n", FactSumm);
    
    printf("===Deleting wrong numbers=== \n");
    //trying to delete numbers div2
    for(int i = 0; i!=NCount;i++)
    {
        if ((List_4Head->number%2) != 0)
            {
                if(i == NCount)//in case it's the ending of the list
                {
                    printf("%d \n", List_4Head->number);
                    free(List_4Head);
                }
                else
                {
                    printf("Wrong node: %d ", List_4Head->number);
                    printf("next following: %d \n", List_4Head->next->number);
                    List_Buff = List_4Head->next;
                    List_4Head->number = List_Buff->number;
                    List_4Head->next = List_Buff->next;
                    free(List_Buff); // free the element
                    printf("The node was deleted\n");
                }
                NCount--; //decrease list elements due to the deleted element
                i--;//won't work without it(?)
            }
                else
                {
                if(List_4Head->next != NULL) List_4Head = List_4Head->next;
                }
    }
    
    List_4Head = List_Head; //refresh the 4Head pointer for further usage
    

 //array after the first operation output
    if(NCount>0)
    {
        printf("Your array: ");
        for(int i = 0; i!=NCount;i++)
        {
        printf("%d ;",List_4Head->number);
        List_4Head=List_4Head->next;
        }
    }
    else
    {
        printf("Your array is empty \n");
    }    
    List_4Head = List_Head; //refresh the 4Head pointer for further usage
    printf("\n");

    printf("===Putting squares=== \n");
    //trying to put the square ahead of the number
    int NSqr, LNum;
     for(int i = 0; i!=NCount;i++)
    {   
        LNum = List_4Head->number;
        NSqr = LNum*LNum;
        //printf("The square is: %d ;\n", NSqr);
        List_Buff = List_4Head->next;
        PNode New_Node = (PNode) malloc(sizeof(struct Node));//new node
        if (New_Node==NULL) // memory usage check
            {
                printf("Out of memory \n");
                return -1;
            }
        New_Node->number = NSqr;
        New_Node->next = List_4Head->next;
        List_4Head->next = New_Node;
        NCount++;
        i++;
        if(New_Node->next != NULL) List_4Head = New_Node->next;
        NSqr = 0;
    }
    
    List_4Head = List_Head; //refresh the 4Head pointer for further usage
    
    
    //array after the second operation output
    if(NCount>0)
    {
        printf("Your array: ");
        for(int i = 0; i!=NCount;i++)
        {
        printf("%d ;",List_4Head->number);
        List_4Head=List_4Head->next;
        }
    }
    else
    {
        printf("Your array is empty \n");
    }    
    List_4Head = List_Head; //refresh the 4Head pointer for further usage
    printf("\n");
    printf("===End===\n");
    return 0;
}
