#include <stdio.h>
#include <stdlib.h>

// Define the node structure for doubly linked list
struct Node {
  int data;
  struct Node* prev;
  struct Node* next;
};

// Function prototypes
void insertFront(struct Node** front, int data);
void insertRear(struct Node** front, struct Node** rear, int data);
struct Node* deleteFront(struct Node** front);
struct Node* deleteRear(struct Node** front, struct Node** rear);
int isEmpty(struct Node* front);

int main() {
   struct front;
  struct Node* front = NULL;
  struct Node* rear = NULL;

  // Insert elements from both ends
  insertFront(&front, 10);
  insertRear(&front, &rear, 20);
  insertFront(&front, 5);
  insertRear(&front, &rear, 30);

  // Delete elements from both ends
  printf("Dequeued from front: %d\n", deleteFront(&front)->data);
  printf("Dequeued from rear: %d\n", deleteRear(&front, &rear)->data);

  // Check if deque is empty
  if (isEmpty(front)) {
    printf("Deque is empty\n");
  } else {
    printf("Deque is not empty\n");
  }

  return 0;
}

// Insert an element at the front of the deque
void insertFront(struct Node** front, int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = NULL;

  if (*front == NULL) {
    newNode->next = NULL;
    *front = *rear = newNode;
  } else {
    newNode->next = *front;
    (*front)->prev = newNode;
    *front = newNode;
  }
}

// Insert an element at the rear of the deque
void insertRear(struct Node** front, struct Node** rear, int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*rear == NULL) {
    newNode->prev = NULL;
    *front = *rear = newNode;
  } else {
    (*rear)->next = newNode;
    newNode->prev = *rear;
    *rear = newNode;
  }
}

// Delete an element from the front of the deque
struct Node* deleteFront(struct Node** front) {
  if (*front == NULL) {
    return NULL;
  }
  struct Node* temp = *front;
  *front = (*front)->next;

  if (*front != NULL) {
    (*front)->prev = NULL;
  } else {
    *rear = NULL; // Queue becomes empty
  }

  free(temp);
  return temp;
}

// Delete an element from the rear of the deque
struct Node* deleteRear(struct Node** front, struct Node** rear) {
  if (*rear == NULL) {
    return NULL;
  }
  struct Node* temp = *rear;
  *rear = (*rear)->prev;

  if (*rear != NULL) {
    (*rear)->next = NULL;
  } else {
    *front = NULL; // Queue becomes empty
  }

  free(temp);
  return temp;
}

// Check if the deque is empty
int isEmpty(struct Node* front) {
  return front == NULL;
}
