#include "../../DataStructures/LinkedList.h"
#include <cstddef>
#include <iostream>

using namespace std;

/* Problem 2.1
Remove duplicate elements in a linked list
*/
template <class T> 
void removeDuplicates(SinglyLinkedList<T> list){
	node<T>* cNode = list.getHead();
	node<T>* rNode;
	node<T>* pNode = cNode;
	while (cNode != NULL){	
		rNode = cNode->next;
		while (rNode != NULL){
			if ((cNode->data) == (rNode->data)){
				node<T>* temp = rNode;
				rNode = rNode->next;
				delete temp;
				pNode->next = rNode;
			}
			else{
				pNode = pNode->next;
				rNode = rNode->next;
			}
		}
		cNode = cNode->next;
		pNode = cNode;

	}
}

/* Problem 2.2
Return kth to last element (tail) in a linked list
*/
template<class T>
T getElementFromHead(int k, SinglyLinkedList<T> list){
	node<T>* first = list.getHead();
	node<T>* runner = first;
	int count = k;
	while (count != 0){
		first = first->next;
		count--;
	}
	while (first != NULL){
		first = first->next;
		runner = runner->next;
	}
	return runner->data;
} 

/* Problem 2.3
Remove from linked list given node
*/
template<class T>
void removeGivenNode(node<T>* theNode, SinglyLinkedList<T>* list){
	node<T>* runner = list->getHead();
	if (theNode == runner){
		list->remove(runner->data);
	}
	else {
		while (runner->next != theNode){
			runner = runner -> next;
		}
		runner->next = theNode->next;
	}
} 


/* Problem 2.4
Partitioning a linked list
*/
template<class T>
SinglyLinkedList<T> partitionLL(T data, SinglyLinkedList<T> list){
	SinglyLinkedList<T> front = SinglyLinkedList<T>();
	SinglyLinkedList<T> end = SinglyLinkedList<T>();
	node<T>* runner = list.getHead();
	while (runner != NULL){
		runner->data <= data ? front.insert(runner->data):end.insert(runner->data);
		runner = runner -> next;
	}
	runner = front.getHead();
	while (runner->next != NULL){
		runner = runner -> next;
	}
	runner -> next = end.getHead();
	return front;
}

/*
Used for testing
*/
int main(){
	SinglyLinkedList<int> list = SinglyLinkedList<int>();
	node<int>* give;
	for (int i = 1; i < 11; i++){
		list.insert(i*i*i % 11);
	}
	SinglyLinkedList<int> list2 = partitionLL(5, list);
	node<int>* print = list2.getHead();

	while (print != NULL){
		cout << print->data << " ";
		print = print->next;
	}

	cout << endl;

}