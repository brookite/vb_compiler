#pragma once
#include <string>
#include <sstream>
#include <vector>
#include "nodes.hpp"
#include "utils.hpp"

class DotWriter {
public:
	DotWriter();

	void appendOutput(std::string line);

	void addNodeLabel(node* node); // only label
	void addNode(node* node); // label and child nodes
	size_t addStringNode(std::string string);
	size_t addStringNode(int val);

	template <typename T>
	void addList(list<T>* list, bool add_indexes = true, bool ensure_nonempty = true) {
		if (list->isEmpty() && ensure_nonempty) return;
		label(list->id, "list");
		for (int i = 0; i < list->size(); i++) {
			addNode(list->get(i));
			link(list->id, list->get(i)->id, add_indexes ? std::to_string(i) : "");
		}
	}

	template<>
	void addList<int>(list<int>* list, bool add_indexes, bool ensure_nonempty) {
		if (list->isEmpty() && ensure_nonempty) return;
		label(list->id, "list");
		for (int i = 0; i < list->size(); i++) {
			size_t id = addStringNode(std::to_string(list->get(i)));
			link(list->id, id, add_indexes ? std::to_string(i) : "");
		}
	}

	void addStringList(list<std::string>* strings, bool add_indexes = true, bool ensure_nonempty = true);

	void linkNodes(node* node1, node* node2, std::string label = "");

	template <typename T>
	void linkList(node* node1, list<T>* list, std::string label = "", bool ensure_nonempty = true) {
		if (node1 == NULL || list == NULL) return;
		if (list->isEmpty() && ensure_nonempty) return;
		link(node1->id, list->id, label);
	}

	void label(size_t id, std::string label = "");
	void link(size_t id1, size_t id2, std::string label = "");

	template <typename T>
	DotWriter& operator<<(const T& value) {
		for (std::ostream* out : outputs) {
			*out << value;
		}
		return *this;
	}

	std::string write();
protected:
	std::vector<std::ostream *> outputs;
	std::stringstream * stringOutput;
};
