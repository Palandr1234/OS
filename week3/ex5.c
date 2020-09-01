#include <stdio.h>

struct Node
{
    int value;
    struct Node* next;
    struct Node* prev;
};

void print_list(struct Node* head){
    struct Node* cur = head;
    while(cur != NULL){
        printf("%d ", cur->value);
        cur = cur->next;
    }
    printf("\n");
}

void insert_node(struct Node* head, struct Node* n, int data){
    struct Node* cur = head;
    while((cur != n)&&(cur != NULL)){
        cur = cur->next;
    }
    if(cur == NULL){
        printf("Error: the given elememt does not exist");
        return;
    }
    struct Node* node = malloc(sizeof(struct Node));
    node->value = data;
    node->next = n->next;
    node->prev = n;
    if(n->next!=NULL){
        n->next->prev = node;
    }
    n->next = node;

}

void delete_node(struct Node* head, struct Node* node){
    struct Node* cur = head;
    if(cur == node){
        *head = *(head->next);
        head->prev = NULL;
        return;
    }
    while((cur->next != node)&&(cur->next != NULL)){
        cur = cur->next;
    }
    if(cur->next == NULL){
        printf("Error: the given elememt does not exist");
        return;
    }
    cur->next = node->next;
    if(node->next != NULL){
        node->next->prev = cur;
    }
}

int main(){
    struct Node* head = malloc(sizeof(struct Node));
    head->value = 98;
    head->next = NULL;
    head->prev = NULL;
    insert_node(head, head, 56);
    insert_node(head, head, 76);
    insert_node(head, head->next, 58);
    print_list(head);
    delete_node(head, head);
    print_list(head);
    delete_node(head, head->next);
    print_list(head);
    delete_node(head,head);
    print_list(head);
}