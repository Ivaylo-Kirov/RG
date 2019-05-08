#include "pch.h"

class TrieNode {
public:
	TrieNode * children[26]{ nullptr };
	bool end_of_word = false;

	bool hasChildren() {
		for (const auto& child : children) {
			if (child != nullptr) return true;
		}
		return false;
	}

};

class PrefixTrie {
private:
	TrieNode * root = new TrieNode();
public:
	void insert(const std::string& str) {
		TrieNode* temp = root;
		for (gsl::index i{}; i < str.size(); ++i) {
			int index = str[i] - 'a';
			if (temp->children[index] == nullptr) {
				temp->children[index] = new TrieNode();
			}
			temp = temp->children[index];
		}
		temp->end_of_word = true;
	}

	void erase(const std::string& str) {
		TrieNode* temp = root;
		std::stack<TrieNode*> S;
		for (gsl::index i{}; i < str.size(); ++i) {
			int index = str[i] - 'a';
			if (temp->children[index] == nullptr) {
				return;
			}
			else {
				S.push(temp->children[index]);
				temp = temp->children[index];
			}
		}

		while (!S.empty()) {
			auto current = S.top();
			S.pop();
			current->end_of_word = false;
			if (!current->hasChildren()) {
				delete current;
				current = nullptr;
			}
		}
	}

	bool search(const std::string& str) {
		TrieNode* temp = root;
		for (gsl::index i{}; i < str.size(); ++i) {
			int index = str[i] - 'a';
			if (temp->children[index] == nullptr) {
				return false;
			}
			temp = temp->children[index];
		}
		return (temp && temp->end_of_word);
	}

	~PrefixTrie() {
		delete root;
	}

};
