#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
 
using namespace std;
//set up a node
class Node {
public:
	int data;
	Node* next;
	Node(int d) {
		next = NULL;
		data = d;
	}
};
//set up a linked list?
class SinglyLinkedList {
public:
	Node* head;
	SinglyLinkedList() {
		this->head = nullptr;
	}
};

//travelling in a linked list
Node findNode(Node* head, int pos) {
	Node* curr = head;
	int cur = 0;
	while (cur < p) {
		++p;
		curr = curr->next;
	}
	return curr;
}

Node insertNode(Node* head, Node* here, int pos) {
	Node* curr = head;
	int cur = 0;
	while (cur < p - 1) {
		++cur;
		curr = curr->next;
	}
	Node* temp = curr->next;
	curr->next = here;
	here->next = temp;
}
//hình như là phải giải phóng node cũ 
void deleteNode(Node* head, int pos) {
	Node* curr = head;
	int curr = 0;
	if (p == 0) head = head->next;

	while (cur < p - 1) {
		++p;
		curr = curr->next;
	}
	curr->next = curr->next->next;
	
}
//Node reverseLinkedList(Node* head) {
//	Node* curr = head;
//	Node* prev = nullptr;
//	Node* next = nullptr;
//	while (cur != nullptr) {
//		next = curr->next;
//		prev = curr->next;
//
//		curr = next;
//	}
//}
Node reverse(Node* head) {
	Node* curr = head;
	Node* prev = nullptr, next = NULL;
	while (curr != nullptr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
}
Node reverseRecursive(Node* head) {
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	Node* rest = reverseRecursive(head->next);
	head->next->next = head;
	head->next = nullptr;
	return rest;
}
Node changeHead(Node* head) {
	if (head->next->next == head) {
		head = head->next;
		return head;
	}
	Node* p = head;
	while (p->next->next != head) {
		p = p->next;
	}
	p->next->next = head->next;
	head->next = p->next;
	p->next = head;
	head = head->next;
	return head;
}