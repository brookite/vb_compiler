#include "../compiler/nodes.hpp"

expr_node* create_binary(expr_node* left, expr_node * right, expr_type type) {
	expr_node* node = new expr_node(type);
	node->left = left;
	node->right = right;
	return node;
}

expr_node* create_int(long long value) {
	expr_node* node = new expr_node(Int);
	node->Int = value;
	return node;
}

// здесь будет код создания других узлов, либо можешь определять конструкторы в nodes.hpp для каждого узла