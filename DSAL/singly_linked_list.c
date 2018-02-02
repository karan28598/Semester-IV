#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
 
void insert(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
 
void delete(struct Node **head_ref, int key){
    struct Node* temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key){
        *head_ref = temp->next;   
        free(temp);               
        return;
    }
 
    while (temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;
 
    prev->next = temp->next;
 
    free(temp); 
}

void printList(struct Node *node){
    while (node != NULL){
        printf(" %d ", node->data);
        node = node->next;
    }
}
 
int main(){
    struct Node* head = NULL;
    int input, nodes, data, flag=1;
    
    while(flag){
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("Operation: ");
        scanf("%d", &input);
    
        switch(input){
            case 1:
                printf("\nEnter the number of nodes: ");
                scanf("%i", &nodes);
            
                printf("\nEnter the data for each node: ");
                while(nodes--){
                    scanf("%i", &data);
                    insert(&head, data);
                }
                
                printf("\nLinked List after insertion\n ");
                printList(head);
                break;
                
            case 2:
                printf("\nEnter the data to be deleted at the node: ");
                scanf("%i", &data);
                delete(&head, data);
                printf("\nLinked List after deletion\n ");
                printList(head);
                break;
                
            case 3:
                printf("\nContents of Linked List\n ");
                printList(head);
                break;
        
            default:
                printf("Invalid operation.\n");
        }
        printf("\n\nDo you wish to continue?\n1. Yes\n0. No\n");
    scanf("%i", &flag);
    printf("\n");
    }
    return 0;
}