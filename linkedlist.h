#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
	int value;
	struct Node* next;
};

void printMenu();
Node* createNode(int value);
void printList(Node* head);
Node* appendNode(Node* head, Node* add);
Node* prependNode(Node* head, int Value);
Node* removeNode(Node* head, int removeValue);
Node* sortList(Node* head);
int listLength(Node* head);
int totalSum(Node* head);
void printReverse(Node* head);

#endif

