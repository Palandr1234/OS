#include <stdio.h>

struct Node
{
    int value;
    struct Node* next;
};

void print_list(struct Node* head){
    struct Node* cur = head;
    while(cur != NULL){
        printf("%d ", cur->value);
        cur = cur->next;
    }
    printf("\n");
}

void insert_node(struct Node* head, struct Node* prev, int data){
    struct Node* cur = head;
    while((cur != prev)&&(cur != NULL)){
        cur = cur->next;
    }
    if(cur == NULL){
        printf("Error: the given elememt does not exist");
        return;
    }
    struct Node* node = malloc(sizeof(struct Node));
    node->value = data;
    node->next = prev->next;
    prev->next = node;
}

void delete_node(struct Node* head, struct Node* node){
    struct Node* cur = head;
    if(cur == node){
        *head = *(head->next);
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
}

int main(){
    struct Node* head = malloc(sizeof(struct Node));
    head->value = 98;
    head->next = NULL;
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