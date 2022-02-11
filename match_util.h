#pragma once
#ifndef MATCH_UTIL_H
#include<vector>
#include<unordered_map>
#include "Data.h"
#include "Rule.h"

using std::string;
using std::vector;
using std::unordered_map;

bool check(Data& data, Rule& rule);
vector<int64_t> DoMatch(vector<Data>& datalist, vector<Rule>& rulelist);
void WriteResult(string& ans_name, string& packet_name, vector<Data>& datalist, vector<Rule>& rulelist);

extern unordered_map<string, int32_t> match_map;
#endif // !MATCH_UTIL_H
