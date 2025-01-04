#pragma once
#include "nodes.hpp"
#include "codegen/record.hpp"
#include "codegen/context.hpp"

class semantic_analyzer {
	friend struct semantic_context;
public:
	semantic_analyzer(); 

	void analyzeProgram(program_node* node);

	semantic_context ctx;
	method_record* entryPoint;
private:
	void processMethod(struct_record* structRecord, method_record* method);
	void processStmtList(struct_record* structRecord, method_record* method, block* block, size_t* returnCount);
	void processStmt(struct_record* structRecord, method_record* method, stmt_node* stmt, size_t* returnCount);
	void processExpr(struct_record* structRecord, method_record* method, expr_node* expr);
	void processStruct(struct_record* clsRecord);

	program_node* target;
};

