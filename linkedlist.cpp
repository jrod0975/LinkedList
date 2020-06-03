#include "linkedlist.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

void printMenu() {
	cout << "\n0 - EXIT" << endl;
	cout << "1 - APPEND NODE" << endl;
	cout << "2 - PREPEND NODE" << endl;
	cout << "3 - REMOVE NODE" << endl;
	cout << "4 - LIST LENGTH" << endl;
	cout << "5 - SORT LIST" << endl;
	cout << "6 - TOTAL SUM" << endl;
	cout << "7 - PRINT LIST REVERSE" << endl;
}

Node* createNode(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;
	return newNode;
}

void printList(Node* head) {
	Node* curr = head;
	while (curr != NULL) {
		cout << curr->value << "->";
		curr = curr->next;
	}
}

Node* appendNode(Node* head, Node* temp) {
	Node* curr = head;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = temp;
	return head;
}

Node* prependNode(Node* head, int value) {
	Node* prepend = createNode(value);
	prepend->next = head;
	return prepend;
}

Node* removeNode(Node* head, int removeValue) {
	Node* prev = NULL;
	Node* curr = head;

	if (head->value == removeValue) {
		Node* temp = head;
		head = head->next;
		free(temp);
		return head;
	}

	while (curr->value != removeValue) {
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	free(curr);
	return head;
	
}

int listLength(Node* head) {
	Node* curr = head;
	int count = 0;
	while (curr != NULL) {
		count++;
		curr = curr->next;
	}
	return count;
}

Node* sortList(Node* head) {
	int length = listLength(head);
	int i = 0;

	for (i = 0; i < length; i++) {
		Node* prev = NULL;
		Node* curr = head;
		Node* next = head->next; //or curr->next

		while (next != NULL) {
			if (curr->value > next->value) {
				int temp = curr->value;
				curr->value = next->value;
				next->value = temp;
			}
			else {
				prev = curr;
				curr = curr->next;
				next = curr->next;
			}
		}
	}
	return head;

}

int totalSum(Node* head) {
	Node* curr = head;
	int totalSum = 0;
	while (curr != NULL) {
		totalSum += curr->value;
		curr = curr->next;
	}
	return totalSum;
}

void printReverse(Node* head) {
	if (head != NULL) {
		printReverse(head->next);
		cout << head->value << "->";
	}
}