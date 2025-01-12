#pragma once
#include "record.hpp"
#include "types.hpp"

class semantic_analyzer;
struct rtl_class_record;

enum access_target {
	FIELD, METHOD, STATIC_METHOD, STATIC_FIELD, STRUCT, STATIC_STRUCT, LOCAL_VAR
};

struct semantic_context {
	std::map<std::string, struct_record*> classes;
	std::map<type_node, struct_type*> specializedTypes;

	struct_record* addClass(struct_node* cls);
	rtl_class_record* addRTL(rtl_class_record* record);
	std::pair<record*, access_target> resolveId(expr_node* left, struct_record* context, method_record* methodContext);
	std::pair<record*, access_target> resolveMember(record* record, std::string member, struct_record* context, expr_type memAccessType, bool onlyStatic = false, type** ownerType = nullptr);
	std::pair<record*, access_target> resolveMemberAccess(expr_node* memAccess, struct_record* context, method_record* methodContext, type** ownerType = nullptr);
	void processCallOrIndex(expr_node* expr, struct_record* structRecord, method_record* method);
	type* specializeType(type_node* node);
	void setAnalyzer(semantic_analyzer* analyzer) {
		this->analyzer = analyzer;
	}
private:
	semantic_analyzer* analyzer;
};

