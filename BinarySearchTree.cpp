#include "pch.h"

//// USAGE
//BST b;
//
//b.insert(42);
//b.insert(55);
//b.insert(12);
//auto result = b.height();
//
//auto result2 = b.validate();
//
//auto result3 = b.isSymmetric();
//
class BSTNode {
public:
	int data;
	BSTNode* left = nullptr;
	BSTNode* right = nullptr;
	BSTNode(int data = 0)
		: data(data)
	{}

	BSTNode(const BSTNode& copy)
		: data(copy.data)
		, left(copy.left)
		, right(copy.right)
	{}

	BSTNode& operator=(BSTNode copy) {
		swap(*this, copy);
		return *this;
	}

	friend void swap(BSTNode& first, BSTNode& second) {
		using std::swap;
		swap(first.data, second.data);
		swap(first.left, second.left);
		swap(first.right, second.right);
	}

	BSTNode(BSTNode&& copy)
		: BSTNode()
	{
		swap(*this, copy);
	}

	~BSTNode() {
		delete left;
		delete right;
	}
};

class BST {
private:
	BSTNode * root = nullptr;
public:
	BST() = default;
	BST(const BST& copy) = delete;
	BST(BST&& copy) = delete;
	BST& operator=(BST copy) = delete;
	~BST() {
		delete root;
	}

	void insert(int data) {
		root = insertUtil(root, data);
	}

	BSTNode* insertUtil(BSTNode* current, int data) {
		if (current == nullptr) {
			current = new BSTNode(data);
			return current;
		}

		if (data > current->data) {
			current->right = insertUtil(current->right, data);
		}
		else {
			current->left = insertUtil(current->left, data);
		}
		return current;
	}

	int height() {
		return heightUtil(root);
	}

	int heightUtil(BSTNode* current) {
		if (current == nullptr) return -1;
		return std::max(heightUtil(current->left), heightUtil(current->right)) + 1;
	}

	bool validate() {
		return validateUtil(root, INT_MIN, INT_MAX);
	}

	bool validateUtil(BSTNode* current, int min, int max) {
		if (current == nullptr) return true;
		return (current->data <= max && current->data > min
			&& validateUtil(current->left, min, current->data) && validateUtil(current->right, current->data, max));
	}

	void erase(int data) {
		eraseUtil(root, data);
	}

	BSTNode* eraseUtil(BSTNode* current, int data) {
		if (current == nullptr) return current;

		if (current->data > data) {
			current->left = eraseUtil(current->left, data);
		}
		else if (current->data < data) {
			current->right = eraseUtil(current->right, data);
		}
		else {
			// found it. aka matches the data.. match without duplicates
			// delete it now based on its "children" status

			// 0 CHILDREN
			if (current->left == nullptr && current->right == nullptr) return nullptr;
			// 1 CHILDREN
			if (current->left == nullptr) return current->right;
			if (current->right == nullptr) return current->left;
			// 2 CHILDREN
			BSTNode* successor = findMinNode(current->right);
			current->data = successor->data;
			current->right = eraseUtil(current->right, successor->data);
		}
	}

	BSTNode* findMinNode(BSTNode* current) {
		if (current->left == nullptr) return current;
		return findMinNode(current->left);
	}

	bool isSymmetric() {
		if (root == nullptr) return true;
		return symmetricUtil(root->left, root->right);
	}

	bool symmetricUtil(BSTNode* left, BSTNode* right) {
		if (left == nullptr && right == nullptr) return true;
		if (left == nullptr || right == nullptr) return false;
		if (left->left != right->right) return false;

		return symmetricUtil(left->left, right->right) && symmetricUtil(left->right, right->left);
	}

};
