#include "dot.hpp"

DotWriter::DotWriter() {
	std::stringstream* sstream = new std::stringstream();
	this->outputs.push_back(sstream);
	this->stringOutput = sstream;
}

void DotWriter::addLine(std::string line) {
	for (std::ostream * out : outputs) {
		*out << line << std::endl;
	}
}

void DotWriter::addNode(node* node) {
	label(node->id, node->getName());
	node->dot(this);
}

template <typename T>
void DotWriter::addList(list<T*>* list) {
	label(list->id, "list");
	for (int i = 0; i < list.size(); i++) {
		addNode(list[i]);
		linkNodes(list->id, list[i]->id, std::string(i));
	}
}

void DotWriter::linkNodes(node* node1, node* node2, std::string label) {
	link(node1->id, node2->id, label);
}

template <typename T>
void DotWriter::linkList(node* node1, list<T*>* list, std::string label) {
	link(node1->id, list->id, label);
}

void DotWriter::label(size_t id, std::string label) {
	for (std::ostream* out : outputs) {
		*out << id << "[label=\"" << label << "\"]" << std::endl;
	}
}

void DotWriter::link(size_t id1, size_t id2, std::string label) {
	for (std::ostream* out : outputs) {
		if (!label.empty()) {
			*out << id1 << "->" << id2 << "[label=\"" << label << "\"]" << std::endl;
		}
		else {
			*out << id1 << "->" << id2 << std::endl;
		}
	}
}

template <typename T>
DotWriter& DotWriter::operator<<(const T & value) {
	for (std::ostream* out : outputs) {
		*out << value;
	}
	return *this;
}

std::string DotWriter::write() {
	return stringOutput->str();
}