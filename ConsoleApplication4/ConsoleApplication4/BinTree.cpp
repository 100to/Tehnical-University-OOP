#include "stdafx.h"
#include "BinTree.h"
#include <iostream>
#include "lexicalUnit.h"
using namespace std;

void BinTree::destroy_tree(node* leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void BinTree::insert(lexicalUnit& key, node* leaf)
{
    if (strcmp(key.getIdetificator(),leaf->table.getIdetificator())<0)
    {
        if (leaf->left != NULL)
            insert(key, leaf->left);
        else
        {
            leaf->left = new node;
            leaf->left->table = key;
            leaf->left->left = NULL;   
            leaf->left->right = NULL; 
        }
    }
    else if (strcmp(key.getIdetificator(), leaf->table.getIdetificator()) >= 0)
    {
        if (leaf->right != NULL)
            insert(key, leaf->right);
        else
        {
            leaf->right = new node;
            leaf->right->table = key;
            leaf->right->left = NULL; 
            leaf->right->right = NULL; 
        }
    }
}

node* BinTree::search(lexicalUnit& key, node* leaf)
{
    if (leaf != NULL)
    {
        if (strcmp(key.getIdetificator(), leaf->table.getIdetificator()) == 0)
            return leaf;
        if (strcmp(key.getIdetificator(), leaf->table.getIdetificator())<0)
            return search(key, leaf->left);
        else
            return search(key, leaf->right);
    }
    else return NULL;
}


BinTree::BinTree()
{
	root = NULL;
}

BinTree::~BinTree()
{
	destroy_tree();
}

void BinTree::insert(lexicalUnit& key)
{
    if (root != NULL)
        insert(key, root);
    else
    {
        root = new node;
        root->table = key;
        root->left = NULL;
        root->right = NULL;
    }
}

node* BinTree::search(lexicalUnit& key)
{
    return search(key,root);
}

void BinTree::destroy_tree()
{
    destroy_tree(root);
}

void BinTree::print()
{
    print(root,0);
}


void BinTree::print(node* root, int space)
{
    if (root == NULL)
    {
        return;
    }

    space += 5;

    print(root->left, space);

    cout << endl;
    for (int i = 5; i < space; i++)
        cout << " ";
    cout << root->table.getIdetificator() << endl;

    print(root->right, space);
}
