// A complete working C program to
// demonstrate all insertion
// methods
#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

/* Given a reference (pointer to pointer) to the head of a
list and an int, inserts a new node on the front of the
list. */
void push_first(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node
            = (struct Node*)malloc(sizeof(struct Node));

    /* 2. put in the data */
    new_node->data = new_data;

    /* 3. Make next of new node as head and previous as NULL
    */
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    /* 4. change prev of head node to new node */
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    /* 5. move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Given a node as prev_node, insert a new node after the
* given node */
void push_after(struct Node* prev_node, int new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL) {
        printf("the given previous node cannot be NULL");
        return;
    }

    /* 2. allocate new node */
    struct Node* new_node
            = (struct Node*)malloc(sizeof(struct Node));

    /* 3. put in the data */
    new_node->data = new_data;

    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;

    /* 5. Make the next of prev_node as new_node */
    prev_node->next = new_node;

    /* 6. Make prev_node as previous of new_node */
    new_node->prev = prev_node;

    /* 7. Change previous of new_node's next node */
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

/* Given a reference (pointer to pointer) to the head
of a DLL and an int, appends a new node at the end */
void push_last(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node
            = (struct Node*)malloc(sizeof(struct Node));

    struct Node* last = *head_ref; /* used in step 5*/

    /* 2. put in the data */
    new_node->data = new_data;

    /* 3. This new node is going to be the last node, so
        make next of it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new
        node as head */
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;

    /* 7. Make last node as previous of new node */
    new_node->prev = last;

}

// This function prints contents of linked list starting
// from the given node
void printList(struct Node* node) {
    struct Node* last = NULL;

    if (node == NULL) {
        printf("\nThere are no elements in the list to print.\n");
        return;
    }

    printf("\nTraversal in forward direction \n");
    while (node != NULL) {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }

    printf("\nTraversal in reverse direction \n");
    while (last != NULL) {
        printf(" %d ", last->data);
        last = last->prev;
    }
}




// Deletes the last element in a list
void delete_last(struct Node** head) {
    struct Node *temp = *head;
    if (temp == NULL) {     // If empty list
        printf("Cannot delete last. List is empty.\n");
        return;
    }

    if (temp->next == NULL) {     // If only 1 element
        *head = NULL;
        return;
    }

    // Traverse until the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
}


// Deletes the first element in a list
void delete_front(struct Node** head) {
    if (*head == NULL) { // If list is empty
        printf("Cannot delete front. List is empty.\n");
        return;
    }

    struct Node *nextNode = (*head)->next;
    free(*head);
    *head = nextNode;
    (*head)->prev = NULL;
}


// Helper function for delete_by_value() method
void deleteElementValue(struct Node** current) {
    struct Node *prevNode = (*current)->prev;
    struct Node *nextNode = (*current)->next;
    prevNode->next = nextNode;

    if (nextNode != NULL) {         // If it's the last element
        nextNode->prev = prevNode;
    }

    printf("\nDeleted value: %d\n", (*current)->data);
}

// Deletes an element in a list by its data value
void delete_by_value(struct Node** head, int value) {
    struct Node *current = *head;
    if (current == NULL) {         // If empty list
        printf("Cannot delete value. List is empty.\n");
        return;
    }

    if (current->data == value) {  // If value is for first element
        struct Node *nextNode = current->next;
        nextNode->prev = NULL;
        printf("\nDeleted value: %d\n", current->data);
        free(current);
        *head = nextNode;
        return;
    }

    while (current != NULL) {
        if (current->data == value) {
            deleteElementValue(&current);
            free(current);
            return;
        }
        current = current->next;
    }

    printf("\nThe value: '%d' was not found.\n", value);
}


// Frees all elements in a list
void free_list(struct Node** head) {
    if (*head == NULL) {
        printf("Cannot free list. List is empty.\n");
        return;
    }

    struct Node *current = *head;
    struct Node *next = (*head)->next;
    while (current != NULL) {
        free(current);
        current = next;
        if (current != NULL) {
            next = current->next;
        }
    }
    *head = NULL;
    printf("\nFreed list.\n");
}



/* Driver program to test above functions*/
int main() {
    /* Start with the empty list */
    struct Node* head = NULL;

    // Insert 6. So linked list becomes 6->NULL
    push_first(&head, 6);

    // Insert 7 at the beginning. So linked list becomes
    // 7->6->NULL
    push_first(&head, 7);

    // Insert 1 at the beginning. So linked list becomes
    // 1->7->6->NULL
    push_first(&head, 1);

    // Insert 4 at the end. So linked list becomes
    // 1->7->6->4->NULL
    push_last(&head, 4);

    // Insert 8, after 7. So linked list becomes
    // 1->7->8->6->4->NULL
    push_after(head->next, 8);

    printf("Created DLL is: ");
    printList(head);

    printf("\n----------------------------------\n");

    printf("\n - Delete Front Method - \n");
    delete_front(&head);
    printList(head);

    printf("\n\n - Delete Last Method - \n");
    delete_last(&head);
    printList(head);

    printf("\n\n - Delete By Value Method - \n");
    delete_by_value(&head, 7);
    printList(head);

    printf("\n\n - Free List Method - \n");
    free_list(&head);
    printList(head);

    free(head);

    return 0;
}
