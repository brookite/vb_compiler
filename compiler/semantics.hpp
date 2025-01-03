#pragma once
#include "nodes.hpp"
#include "codegen/record.hpp"
#include "codegen/context.hpp"

class semantic_analyzer {
	friend struct semantic_context;
public:
	semantic_analyzer(); 

	void analyzeProgram(program_node* node);
private:
	void processMethod(struct_record* structRecord, method_record* method);
	void processStmtList(struct_record* structRecord, method_record* method, block* block);
	void processStmt(struct_record* structRecord, method_record* method, stmt_node* stmt);
	void processExpr(struct_record* structRecord, method_record* method, expr_node* expr);
	void processStruct(struct_record* clsRecord);

	semantic_context ctx;
	program_node* target;
};

