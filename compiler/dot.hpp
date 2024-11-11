#pragma once
#include <string>
#include <sstream>
#include <vector>
#include "nodes.hpp"
#include "utils.hpp"

class DotWriter {
public:
	DotWriter();

	void addLine(std::string line);
	void addNode(node* node);

	template <typename T>
	void addList(list<T*> * node);

	void linkNodes(node* node1, node* node2, std::string label = "");

	template <typename T>
	void linkList(node* node1, list<T*>* list, std::string label = "");

	void label(size_t id, std::string label);
	void link(size_t id1, size_t id2, std::string label);

	std::string write();
protected:
	std::vector<std::ostream *> outputs;
	std::stringstream * stringOutput;
};
