#include <cstddef>
#include <stdlib.h>

template <class T> struct Node{
	T data;
	Node<T>* next;
};

template <class T> class Stack {
Node<T>* head = NULL;
public:
	bool isEmpty(){
		return (head == NULL);
	}
	T peek(){
		if (head != NULL){
			return head->data;
		}
	}
	void push(T data){
		Node<T>* temp = (Node<T>*) malloc(sizeof(struct Node<T>));
		temp->data = data;
		temp->next = head;
		head = temp; 
	};
	T pop(){
		if (head != NULL){
			Node<T>* temp = head;
			head = head->next;
			return temp->data;	
		}
	}
};

template <class T> class Queue {
Node<T>* head = NULL;
Node<T>* tail = NULL;
public:
	bool isEmpty(){
		return (head == NULL);
	}
	void enqueue(T data){
		Node<T>* temp = (Node<T>*) malloc(sizeof(struct Node<T>));
		temp->data = data;
		temp->next = NULL;
		if (head == NULL){
			head = temp;
			tail = head;
			head->next = NULL;
		}
		else{
			head->next = temp;
			head = temp;
		} 
	};
	T dequeue(){
		if (tail != NULL){
			Node<T>* temp = tail;
			tail = tail->next;
			if (tail == NULL){
				head = NULL;
			}
			return temp->data;	
		}
	}
};