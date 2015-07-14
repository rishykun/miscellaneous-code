#include <cstddef>
#include <stdlib.h>

using namespace std;

template <class T> struct node{
	T data;
	node<T>* next;
	node<T>* prev;
};


template <class T> class SinglyLinkedList{	
node<T>* tail;
public:
	SinglyLinkedList(T data){
		tail = (node<T>*) malloc(sizeof(struct node<T>));
		tail->data = data;
		tail->next = NULL;
	};
	node<T>* getTail() {return tail;};
	node<T>* search(T data){
		node<T>* currentNode = tail;
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
		ins->next = tail;
		tail = ins;
	};
	void remove(T data){
		node<T>* prevNode;
		node<T>* currentNode = tail;
		do{
			if (currentNode->data == data){
				if (currentNode == tail){
					tail = currentNode->next;
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
	node<T>* tail;
	node<T>* head;
public:
	DoublyLinkedList(T data){
		head = (node<T>*) malloc(sizeof(struct node<T>));
		tail = head;
		head->data = data;
		head->next = NULL;
		head->prev = NULL;
	};
	node<T>* getTail() {return tail;};
	node<T>* getHead() {return head;};
	node<T>* search(T data){
		node<T>* currentNode = tail;
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
		ins->next = tail;
		tail->prev = ins;
		tail = ins;
	};
	void remove(T data){
		node<T>* currentNode = tail;
		do{
			if (currentNode->data == data){
				if (currentNode == tail){
					tail = currentNode->next;
				}
				else if (currentNode == head){
					head = currentNode->prev;
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