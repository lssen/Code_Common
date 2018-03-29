/*
Author: ©Copyright by Huang Sen
Time: 11/17/2017
Main function: trie Tree(字典树)
Mode: C ++

*/
#include"stdafx.h"
#include<iostream>
using namespace std;

const int TREE_WIDTH = 26;
struct Node {
	int path;
	int end;
	char ch;
	Node *next[TREE_WIDTH];
	Node(char ch = ' ') {
		this->ch = ch;
		this->path = this->end = 0;
		for (int i = 0; i < TREE_WIDTH; i++) {
			this->next[i] = nullptr;
		}
	}
};

class TrieTree {
private:
	Node * root;
public:
	TrieTree();
	~TrieTree();
	void destroy(Node *t);
	int query(char *);
	void add(char *s);
	bool remove(char *s);

};


// implementation

TrieTree::TrieTree() {
	root = new Node();
}

TrieTree::~TrieTree(){
	destroy(root);
}

void TrieTree::destroy(Node *t) {
	for (int i = 0; i < TREE_WIDTH; ++i) {
		if (t->next[i])
			destroy(t->next[i]);
	}

	delete t;
}

void TrieTree::add(char *s) {
	Node * t = root;
	while (*s) {
		if (t->next[*s - 'a'] == nullptr)
			t->next[*s - 'a'] = new Node(*s);
		t->next[*s - 'a']->path++;
		t = t->next[*s - 'a'];
		s++;
	}
	t->end++;
}

int TrieTree::query(char *s) {
	Node *t = root;
	while (*s) {
		if (t->next[*s - 'a'] == nullptr || t->next[*s - 'a']->path == 0)
			return 0;
		t = t->next[*s-'a'];
		s++;
	}
	return t->end;
}

bool TrieTree::remove(char * s) {
	if (query(s)) {
		Node * t = root;
		while (*s) {
			t->next[*s - 'a']->path--;
			t = t->next[*s-'a'];
			s++;
		}
		t->end--;
		return true;
	}
	return false;
}

int main() {
	TrieTree tree;
	tree.add("strawberry");
	tree.add("gradfather");
	tree.add("policeman");
	tree.add("breakfeast");
	tree.add("mutton");
	tree.add("bus");
	tree.add("bus");
	tree.add("bustop");
	tree.add("computer");


	cout << tree.query("bud") << endl;
	cout << tree.query("bus") << endl;



	cout << tree.remove("bustop") << endl;
	cout << tree.query("bustop") << endl;
	system("pause");
	return 0;
}