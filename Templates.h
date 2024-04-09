#pragma once
#include <cstdlib>
#include <iostream>
using namespace std;

template <class T>
class Node {
private:
	T value;
	Node* parent;
	Node ** children;
	int count;
	int size;
public:
	Node(const T& val) {
		value = val; 
		count = 0;
		size = 10;
		parent = nullptr;
		children = (Node **)(malloc(size * sizeof(Node *)));
	}
	~Node() {
		delete[] children;
	}
	Node** GetChildren()
	{
		return children;
	}
	int GetCount() {
		return count;
	}
	T GetValue() {
		if(this!=nullptr)
		return value;
	}
	Node<T>* get_node(Node<T>* parent, int index)
	{
		if (index < parent->childcount)
			return parent->children[index];
		else return nullptr;
	}
	void add_node(const T val, Node  *parent_node) 
	{
			Node* new_node = new Node(val);
			new_node->parent = parent_node;

				if (parent_node->count + 1 == parent_node->size)
				{
					parent_node->children = (Node**)(realloc(parent_node->children, (parent_node->count * 2) * sizeof(Node*)));
					parent_node->size *= 2;
				}
				parent_node->children[parent_node->count] = new_node;
				parent_node->count++;
	}
	
	void delete_node(Node<T>* node)
	{	if(node->parent!=nullptr)
		{
			int i = 0;
			for (i = 0; i < node->parent->count; i++)
				if (node->parent->children[i] == node)
					break;
			for (int j = i; j < node->parent->count - 1; j++)
				node->parent->children[j] = node->parent->children[j + 1];
			node->parent->count--;
		}
		for (int i = 0; i < node->count; i++)
		{
			node->delete_node(children[i]);
			delete node->children[i];
		}
		delete[] node->children;
		node->children = nullptr;
		node->count = 0;
	}
	Node* find(T val) {
		if (this != nullptr) {
			if (value == val)
				return this;

			Node* result = nullptr;
			for (int i = 0; i < count; i++) {
				if (children[i] != nullptr) {
					result = children[i]->find(val);
					if (result != nullptr)
						return result; // Found the node, so return it immediately
				}
			}

			return nullptr; // Return nullptr only if no match is found
		}
		return nullptr; // Return nullptr if the current node is nullptr
	}
	void insert(T val,int index, Node* par) {
		
		if (par->count + 1 == par->size)
		{
			par->children = (Node**)(realloc(par->children, (par->count * 2) * sizeof(Node*)));
			par->size *= 2;
		}
		if (index < par->count)
		{
			Node* new_node = new Node(val);
			new_node->parent = par;
			for (int i = count; i > index; i--)
				children[i] = children[i - 1];
			par->children[index] = new_node;
			count++;
		}
			
		else
			add_node(val, par);
	}
	void sort(bool(*callback)(T,T)) {
		if (callback != nullptr) 
		{
			int i, j;
			bool swapped;
			for (i = 0; i < count - 1; i++) {
				swapped = false;
				for (j = 0; j < count - i - 1; j++) {
					if (callback(children[j+1]->value,children[j]->value)) {
						swap(children[j], children[j + 1]);
						swapped = true;
					}
				}
				if (swapped == false)
					break;
			}
		}
		else
		{
			int i, j;
			bool swapped;
			for (i = 0; i < count - 1; i++) {
				swapped = false;
				for (j = 0; j < count - i - 1; j++) {
					if (children[j]->value > children[j + 1]->value) {
						swap(children[j], children[j + 1]);
						swapped = true;
					}
				}
				if (swapped == false)
					break;
			}
		}
		for (int k = 0; k < count; k++)
			if (children[k] != nullptr && children[k]->count != 0)
			{
				if (callback != nullptr)
					children[k]->sort(callback);
				else
					children[k]->sort(nullptr);
			}
	}
	
	int get_count()
	{
		int count1 = this->count;
		if (this->parent == nullptr)
			count1++;
		for (int i = 0; i < this->count; i++)
			count1 += this->children[i]->get_count();
		return count1;
	}
	void print() {
		if(this!=nullptr)
		{
			cout << value << " ";
			for (int i = 0; i < count; i++)
			{
				if (children[i] != nullptr)
					children[i]->print();
			}
		}
	}
};// getnode insert count