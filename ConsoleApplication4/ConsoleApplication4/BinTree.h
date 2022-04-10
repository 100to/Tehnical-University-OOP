#pragma once
#include "lexicalUnit.h"
struct node {
	lexicalUnit table;
	node* left;
	node* right;
};


class BinTree
{
private:
	void destroy_tree(node* leaf);
	void insert(lexicalUnit& key, node* leaf);
	node* search(lexicalUnit& key, node* leaf);
	void print(node* root, int space);
	node* root;
public:
	BinTree();
	~BinTree();
	void insert(lexicalUnit& key);
	node* search(lexicalUnit& key);
	void destroy_tree();
	void print();
};

