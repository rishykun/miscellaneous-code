#include "../../../DataStructures/LinkedList.h"
#include <cstddef>
#include <iostream>

using namespace std;
template <class T> 
void removeDuplicates(SinglyLinkedList<T> list){
	node<T>* cNode = list.getTail();
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

int main(){
	SinglyLinkedList<int> list = SinglyLinkedList<int>(5);
	list.insert(5);
	removeDuplicates(list);
	cout << list.getTail()->data << endl;
	cout << list.getTail()->next << endl;
}