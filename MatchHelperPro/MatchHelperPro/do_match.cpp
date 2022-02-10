#include<vector>
#include"Data.h"
#include"Rule.h"
#include"match_util.h"
using std::vector;

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
        tag = false;
        break;
      }
    }
    if (tag)
      ans.push_back(-1);
  }
  return ans;
}
