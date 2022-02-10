#pragma once
#ifndef MATCH_UTIL_H
#include<vector>
#include "Data.h"
#include "Rule.h"

using std::string;
using std::vector;

bool check(Data& data, Rule& rule);
vector<int64_t> DoMatch(vector<Data>& datalist, vector<Rule>& rulelist);
void WriteResult(string& ans_name, string& packet_name, vector<Data>& datalist, vector<Rule>& rulelist);
#endif // !MATCH_UTIL_H
