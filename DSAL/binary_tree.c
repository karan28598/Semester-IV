#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node* newNode(int data){
    struct node* node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct node* insert(struct node* node, int key){
    if (node == NULL) return newNode(key);
 
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);   
 
    return node;
}

void inorder(struct node *node){
     if (node == NULL)
          return;
     inorder(node->left);
     printf("%i ", node->data);  
     inorder(node->right);
}

void preorder(struct node* node){
     if (node == NULL)
          return;
     printf("%i ", node->data);  
     preorder(node->left);  
     preorder(node->right);
}    

void postorder(struct node* node){
     if (node == NULL)
        return;
     postorder(node->left);
     postorder(node->right);
     printf("%i ", node->data);
}

struct node* search(struct node* root, int key){
    if (root == NULL || root->data == key)
       return root;

    if (root->data < key)
       return search(root->right, key);

    return search(root->left, key);
}

int main(){
    int input, nodes, data, flag=1;
    struct node *root = newNode(-1);
    
    while(flag){
        printf("1. Insert\n");
        printf("2. Inorder\n");
        printf("3. Preorder\n");
        printf("4. Postorder\n");
        printf("5. Search\n");
        printf("Operation: ");
        scanf("%i", &input);
        switch(input){
            case 1:
                if(root->data == -1){
                    printf("Insert root node: ");
                    scanf("%i", &data);
                    root = newNode(data);
                }
                printf("\nEnter the number of nodes: ");
                scanf("%i", &nodes);
            
                printf("\nEnter the data for each node: ");
                while(nodes--){
                    scanf("%i", &data);
                    insert(root, data);
                }
                break;
                
            case 2:
                inorder(root);
                break;
                
            case 3:
                preorder(root);
                break;

            case 4:
                postorder(root);
                break;
                
            case 5:
                printf("Enter the key you want to search for: ");
                scanf("%i", &data);
                
                if(search(root, data)){
                    printf("Found\n");
                }
                else printf("Not Found\n");
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