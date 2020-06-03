#include <iostream>
#include <stdlib.h>
#include "linkedlist.h"
using namespace std;

int main() {
	//This program will create a linked list
	//More functions will be added if necessary
	

    Node* head = NULL;
	int choice = 1, value, removeValue;

	
	while (choice != 0) {
		printMenu();
		cout << "Enter an option" << endl;
		cin >> choice;

		if (choice == 1) {
			cout << "Enter a value: " << endl;
			cin >> value;
			if (head == NULL)
				head = createNode(value);
			else {
				head = appendNode(head, createNode(value));
			}
				
		}

		if (choice == 2) {
			cout << "Enter a value to add to the beginning of the list: " << endl;
			cin >> value;
			head = prependNode(head, value);
		}

		if (choice == 3) {
			cout << "Enter node value to remove: " << endl;
			cin >> removeValue;
			head = removeNode(head, removeValue);
		}

		if (choice == 4) {
			int length;
			length = listLength(head);
			cout << "Length of the list is " << length << endl;
		}

		if (choice == 5) {
			head = sortList(head);
		}

		if (choice == 6) {
			int total = totalSum(head);
			cout << "The total sum of all nodes is " << total << endl;
		}

		if (choice == 7) {
			printReverse(head);
		}
		cout << endl;
		printList(head);
	}
	
	return 0;
}