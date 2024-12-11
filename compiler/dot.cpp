#include "dot.hpp"

DotWriter::DotWriter() {
	std::stringstream* sstream = new std::stringstream();
	this->outputs.push_back(sstream);
	this->stringOutput = sstream;
}

void DotWriter::appendOutput(std::string line) {
	for (std::ostream * out : outputs) {
		*out << line << std::endl;
	}
}

void DotWriter::addStringList(list<std::string>* strings, bool add_indexes, bool ensure_nonempty) {
	if (strings->isEmpty() && ensure_nonempty) return;
	for (int i = 0; i < strings->size(); i++) {
		size_t id = addStringNode(strings->get(i));
		link(strings->id, id, add_indexes ? std::to_string(i) : "");
	}
}

size_t DotWriter::addStringNode(std::string string) {
	size_t id = getNewId();
	label(id, string);
	return id;
}

size_t DotWriter::addStringNode(int val) {
	size_t id = getNewId();
	label(id, std::to_string(val));
	return id;
}

void DotWriter::addNode(node* node) {
	if (node == NULL) return;
	label(node->id, node->getName());
	node->dot(this);
}

void DotWriter::addNodeLabel(node* node) {
	label(node->id, node->getName());
}

void DotWriter::linkNodes(node* node1, node* node2, std::string label) {
	if (node1 == NULL || node2 == NULL) return;
	link(node1->id, node2->id, label);
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

void DotWriter::close() {
	for (std::ostream* s : outputs) {
		s->flush();
	}
	stringOutput->flush();
}

std::string DotWriter::write() {
	return stringOutput->str();
}

void outputDot(node* node, std::string filename) {
	if (node != NULL) {
		DotWriter writer;
		char cmd[256];
		sprintf(cmd, "dot -Tpng -o %s", filename.c_str());

		FILE* pipe = _popen(cmd, "w");
		if (!pipe) {
			std::cerr << "Failed to open pipe to dot.\n";
			return;
		}
		node->dot(&writer);
		std::string dot_data = writer.write();
		//std::cout << dot_data << std::endl;

		fwrite(dot_data.c_str(), sizeof(char), dot_data.size(), pipe);
		_pclose(pipe);
		writer.close();
		// system(("start " + filename).c_str()); // open png in default application
	}
}