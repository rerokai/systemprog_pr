#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* create_list() {
    return NULL;
}

Node* add_node(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return head;
    }
    newNode->data = value;
    
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    } else {
        Node* last = head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
        return head;
    }
}

Node* delete_middle_node(Node* head) {
    if (head == NULL || head->next == head || head->next->next == head) {
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* to_delete = slow;
    Node* prev_node = to_delete->prev;
    Node* next_node = to_delete->next;

    prev_node->next = next_node;
    next_node->prev = prev_node;

    free(to_delete);

    return head;
}

void print_list(Node* head) {
    if (head == NULL) {
        printf("Список пуст.\n");
        return;
    }

    Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("...\n");
}

void free_list(Node* head) {
    if (head == NULL) {
        return;
    }
    Node* current = head->next;
    while (current != head) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(head);
}

int main() {
    Node* head = create_list();
    
    head = add_node(head, 10);
    head = add_node(head, 20);
    head = add_node(head, 30);
    head = add_node(head, 40);
    head = add_node(head, 50);

    printf("Исходный список:\n");
    print_list(head);

    head = delete_middle_node(head);
    
    printf("\nСписок после удаления среднего элемента:\n");
    print_list(head);

    free_list(head);

    return 0;
}