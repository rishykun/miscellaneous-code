#include <cstddef>


template <class T> class SinglyLinkedList{
struct node {
	T data;
	node* next;
	node* prev;
};
	node* tail;
public:
	SinglyLinkedList(T data){
		struct node init = {data};
		tail = &init;
	};
	node getTail() {return *tail;};
	node search(T data){
		node* currentNode = tail;
		do{
			if (currentNode->data == data){
				return *currentNode;
			}
			currentNode = currentNode->next;
		}
		while(currentNode != NULL);
		return NULL;
	};
	void insert(T data){
		struct node ins = {data, tail};
		tail = &ins;
	};
	void Delete(T data){
		node* prevNode;
		node* currentNode = tail;
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
struct node {
	T data;
	node* next;
	node* prev;
};
	node* tail;
	node* head;
public:
	DoublyLinkedList(T data){
		struct node init = {data};
		tail = &init;
		head = &init;
	};
	node getTail() {return *tail;};
	node getHead() {return *head;};
	node search(T data){
		node* currentNode = tail;
		do{
			if (currentNode->data == data){
				return *currentNode;
			}
			currentNode = currentNode->next;
		}
		while(currentNode != NULL);
		return NULL;
	};
	void insert(T data){
		node ins = {data, tail};
		tail->prev = &ins;
		tail = &ins;
	};
	void Delete(T data){
		node* currentNode = tail;
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