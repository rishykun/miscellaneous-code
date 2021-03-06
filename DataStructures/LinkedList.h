#include <cstddef>
#include <stdlib.h>

using namespace std;

template <class T> struct node{
	T data;
	node<T>* next;
	node<T>* prev;
};


template <class T> class SinglyLinkedList{	
public:
	node<T>* head;
	SinglyLinkedList(T data){
		head = (node<T>*) malloc(sizeof(struct node<T>));
		head->data = data;
		head->next = NULL;
	};
	SinglyLinkedList(){
		head = NULL;
	}
	node<T>* getHead() {return head;};
	node<T>* search(T data){
		node<T>* currentNode = head;
		do{
			if (currentNode->data == data){
				return currentNode;
			}
			currentNode = currentNode->next;
		}
		while(currentNode != NULL);
		return NULL;
	};
	void insert(T data){
		node<T>* ins = (node<T>*) malloc(sizeof(struct node<T>));
		ins->data = data;
		ins->next = head;
		head = ins;
	};
	void remove(T data){
		node<T>* prevNode;
		node<T>* currentNode = head;
		do{
			if (currentNode->data == data){
				if (currentNode == head){
					head = currentNode->next;
				}
				else{
				prevNode->next = currentNode->next;
				}
				delete currentNode;
				break;
			}
			prevNode = currentNode;
			currentNode = currentNode->next;
		}
		while(currentNode != NULL);
	};
};

template <class T> class DoublyLinkedList{
public:
	node<T>* tail;
	node<T>* head;
	DoublyLinkedList(T data){
		head = (node<T>*) malloc(sizeof(struct node<T>));
		tail = head;
		head->data = data;
		head->next = NULL;
		head->prev = NULL;
	};
	DoublyLinkedList(){
		head = NULL;
		tail = NULL;
	};
	node<T>* getTail() {return tail;};
	node<T>* getHead() {return head;};
	node<T>* search(T data){
		node<T>* currentNode = head;
		do{
			if (currentNode->data == data){
				return currentNode;
			}
			currentNode = currentNode->next;
		}
		while(currentNode != NULL);
		return NULL;
	};
	void insert(T data){
		node<T>* ins = (node<T>*) malloc(sizeof(struct node<T>));
		ins->data = data;
		ins->next = head;
		if (head != NULL){
			head->prev = ins;
		}
		head = ins;
	};
	void remove(T data){
		node<T>* currentNode = head;
		do{
			if (currentNode->data == data){
				if (currentNode == head){
					head = currentNode->next;
				}
				else if (currentNode == head){
					tail = currentNode->prev;
				}
				else{
				currentNode->prev->next = currentNode->next;
				currentNode->next->prev = currentNode->prev;
				}
				delete currentNode;
				break;
			}
			currentNode = currentNode->next;
		}
		while(currentNode != NULL);
	};
};