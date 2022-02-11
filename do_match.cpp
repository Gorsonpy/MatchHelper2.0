#include<vector>
#include<unordered_map>
#include"Data.h"
#include"Rule.h"
#include"match_util.h"
using std::vector; 
using std::unordered_map;

bool check(Data& data, Rule& rule)
{
  if (data.origin_ip() < rule.origin_ip_beg() ||
    data.origin_ip() > rule.origin_ip_end())
    return false;
  if (data.receiver_ip() < rule.receiver_ip_beg() ||
    data.receiver_ip() > rule.receiver_ip_end())
    return false;
  if (data.origin_port() < rule.origin_port_beg()
    || data.origin_port() > rule.origin_port_end())
    return false;
  if (data.receiver_port() < rule.receiver_port_beg()
    || data.receiver_port() > rule.receiver_port_end())
    return false;
  if (data.tcp() != rule.tcp() && rule.tcp() <= 255)
    return false;
  return true;
}
vector<int64_t> DoMatch(vector<Data>& datalist, vector<Rule>& rulelist)
{
  
  vector<int64_t> ans;
  for (Data& data : datalist)
  {
    
    if (match_map.find(data.id()) != match_map.end()) //如果哈希表中已经有算好答案
    {
      ans.push_back(match_map[data.id()]); //给出答案，结束当前数据匹配
      continue;
    }
    
    
    //没有存在的答案，下面遍历规则集寻找答案
    bool tag = true; //标记是否有存在的匹配位置
    for (size_t i = 0; i < rulelist.size(); ++i)
    {
      Rule rule = rulelist.at(i);
      if (!check(data, rule))
        continue;
      else
      {
        int32_t idx = static_cast<int>(i);
        ans.push_back(idx);
        match_map[data.id()] = idx; // 记录答案
        tag = false;
        break;
      }
    }
    if (tag)
    {
      ans.push_back(-1);
      match_map[data.id()] = -1; //记录答案
    }
  }
  return ans;
}
