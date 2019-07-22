/*

// ===========ListNode class
// data
// next pointer
// =========== List class
// root ListNode, start with nullptr
// ================================== insertAtHead
// newNode->next = head
// head = newNode
// ================================== insert
// while ->next != nullptr keep moving
// current->next = newNode
// ======================================print
// while ->next != nullptr keep moving
// cout current
// ======================================reverseIterative
// 3 pointers, prev, current, next
// figure out arithmetic and swaps
// ======================================reverseRecursive
// recurse until the end (exit condition is ->next == nullptr)
// now run some swaps as you return up the stack
// first - make head = node and return to go back down the tree
// Base case fired and returned already, so current position is second last node
// Q->next = current;
// current->next = nullptr;

*/

#include "pch.h"

//// USAGE
//LinkedList ll;
//
//ll.insert(42);
//ll.insert(55);
//ll.insert(12);
//ll.insert(77);
//
//ll.reverseRecursive();
//
//auto result = ll.hasCycle();
//
class ListNode {
public:
	int data;
	ListNode* next{};

	ListNode(int data)
		: data(data)
	{}

	ListNode(const ListNode& copy) = delete;
	ListNode(ListNode&& copy) = delete;
	ListNode& operator=(ListNode copy) = delete;

	~ListNode() {
		delete next;
	}

};

class LinkedList {
private:
	ListNode * root = nullptr;
public:
	void insert(int data) {
		ListNode* newNode = new ListNode(data);
		if (root == nullptr) {
			root = newNode;
		}
		else {
			ListNode* temp = root;
			while (temp->next) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}

	void print() {
		printRecursive(root);
	}

	void printReverse() {
		printRecursiveReverse(root);
	}

	void printRecursive(ListNode* current) {
		if (current == nullptr) {
			return;
		}
		std::cout << current->data << '\n';
		printRecursive(current->next);
	}

	void printRecursiveReverse(ListNode* current) {
		if (current == nullptr) {
			return;
		}
		printRecursiveReverse(current->next);
		std::cout << current->data << '\n';
	}

	void reverseIterative() {
		ListNode* current = root;
		if (current == nullptr) return;
		ListNode* prev = nullptr;
		ListNode* next = nullptr;

		while (current) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		root = prev;
	}

	void reverseRecursive() {
		reverseRecursiveUtil(root);
	}

	void reverseRecursiveUtil(ListNode* current) {
		if (current->next == nullptr) {
			root = current;
			return;
		}
		reverseRecursiveUtil(current->next);
		current->next->next = current;
		current->next = nullptr;

	}

	bool hasCycle() {
		if (root == nullptr || root->next == nullptr) return false;
		ListNode* normal = root;
		ListNode* fast = root;

		while (normal && fast && fast->next) {
			normal = normal->next;
			fast = fast->next->next;
			if (normal == fast) return true;
		}

		return false;

	}

	LinkedList() = default;
	LinkedList(const LinkedList& copy) = delete;
	LinkedList(LinkedList&& copy) = delete;
	LinkedList& operator=(LinkedList copy) = delete;
	~LinkedList() {
		delete root;
	}
};
