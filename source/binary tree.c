#include <binary tree.h>

struct Binary_tree_node
{
	struct Binary_tree_node* parent;
	struct Binary_tree_node* left;
	struct Binary_tree_node* right;
	void* data;
};