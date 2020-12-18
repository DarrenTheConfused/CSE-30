#pragma once

#include <iostream>
#include <ostream>

struct Node{
	int data;
	Node* next;

	Node (){
		data = 0;
		next = NULL;
	}

	Node (int n){
		data = n;
		next = NULL;
	}
};

struct LinkedList{

	Node* head;

	LinkedList(){
		head = NULL;
	}

	LinkedList(const LinkedList& other){ 
		head = NULL;

		if (other.head != NULL){
			Node* temp = other.head;
			while (temp != NULL){
				append(temp->data);
				temp = temp->next;
			}
		}
	}

	void append (int n){
		if (head == NULL){
			head = new Node(n);
		}
		else{
			Node* temp = head;
			while (temp->next != NULL){
				temp = temp->next;
			}
			// temp is pointing to the last element of the list
			Node* theNode = new Node(n); 
			temp->next = theNode;
		}
	}

	bool operator==(const LinkedList& other) const {
		Node* ours = head;
		Node* theirs = other.head;

		while (ours != NULL){
			if (theirs == NULL){
				return false;
			}
			if (ours->data != theirs->data){
				return false;
			}
			else{
				ours = ours->next;
				theirs = theirs->next;
			}
		}
		return theirs == NULL;
	}

	~LinkedList(){
		Node* temp = head;
		while (temp != NULL){
			head = head->next;
			delete temp;
			temp = head;
		}
	}

};

std::ostream& operator<< (std::ostream& os, const LinkedList& theList){
	Node* temp = theList.head;
	while (temp != NULL){
		os << temp->data << " ";
		temp = temp->next;
	}
	return os;
}




struct LinkedList {
	Node* head;
	LinkedList(){
		head = NULL;
	}
	void append(int value){
		if (head == NULL){
			head = new Node(value);
		}
		else{
			// Allocate a new node with value
			// Go to the last element of the list
			// Make the next of the last element point to the new node
			Node* newNode = new Node(value);
			Node* temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			// At this point, temp is pointing to the last existing element of list
			temp->next = newNode;
		}
	}
	void insert(int index, int value) {
		int count = 0;
		if (LinkedList->Node->head == NULL){
			set(index, value);
		}
		else{
			while (current != NULL){
				count++;
				current = current->next;
			}
			
		}
	}
	int get(int index){
		int x;
		x = LinkedList->Node->head;
		return x;
	}
	void set(int index, int value){
		LinkedList->Node->head = value;
	}
	void print (){
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
	˜LinkedList(){
		Node* temp = head;
		while(temp != NULL){
			temp = temp->next;
			delete head;
			head = temp;
		}
	}
};
