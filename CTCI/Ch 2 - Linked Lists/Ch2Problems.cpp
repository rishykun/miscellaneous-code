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

/* Problem 2.5
Summing using linked list representations
*/
//1s digit is head
int BackwardSum(SinglyLinkedList<int> L1, SinglyLinkedList<int>L2){
	node<int>* runner1 = L1.getHead();
	node<int>* runner2 = L2.getHead();
	int sum = 0;
	int power = 1;
	while (runner1 != NULL){
		sum += power*(runner1->data + runner2 -> data);
		runner1 = runner1->next;
		runner2 = runner2->next;
		power*=10;
	}
	return sum;
}
//Leading digit is head
int ForwardSum(SinglyLinkedList<int> L1, SinglyLinkedList<int>L2){
	node<int>* runner1 = L1.getHead();
	node<int>* runner2 = L2.getHead();
	int sum = 0;
	while (runner1 != NULL){
		sum = (10*sum + (runner1->data + runner2 -> data));
		runner1 = runner1->next;
		runner2 = runner2->next;
	}
	return sum;
}

/* Problem 2.6
Find beginning of loop in circular linked list
*/
template <class T>
node<T>* FindLoopHead(SinglyLinkedList<T> L){
	node<T>* runner1 = L.getHead();
	node<T>* runner2 = L.getHead();
	node<T>* finalRunner = L.getHead();
	do {
		runner1 = runner1->next;
		runner2 = runner2->next->next;
	} 
	while (runner1 != runner2);
	while (finalRunner != runner1){
		runner1 = runner1->next;
		finalRunner = finalRunner->next;
	}
	return finalRunner;
}


/*
Used for testing
*/
int main(){
	SinglyLinkedList<int> L;
	node<int>* tail;
	node<int>* loophead;
	L.insert(5);
	tail = L.getHead();
	L.insert(4);
	L.insert(3);
	L.insert(2);
	L.insert(1);
	loophead = L.getHead();
	tail->next = loophead;
	cout << loophead << endl;
	L.insert(6);
	L.insert(7);
	L.insert(8);
	cout << FindLoopHead(L) << endl;
	cout << FindLoopHead(L)->data << endl;
}