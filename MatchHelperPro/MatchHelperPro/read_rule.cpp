
#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include"Rule.h"

using std::string;
using std::vector;
using std::ifstream;
using std::pair;
using PII = pair<int64_t, int64_t>;


long long qpower(int64_t a, int64_t b)
{
  int64_t basic = a, ans = 1;
  while (b > 0)
  {
    if (b & 1)
    {
      ans *= basic;
    }
    basic *= basic;
    b >>= 1;
  }
  return ans;
}

PII StrBin_To_Dec(string& str_bin, int64_t bit) 
{
  PII min_max;
  int64_t num = 0;
  int base = 31;


  for (int i = 0; i < bit; ++i) 
  {
    int64_t curr = 0;
    if (str_bin[i] == '1')
    {
      curr = qpower(2, base);
    }
    num += curr;
    --base;
  }

  min_max.first = num; 

  for (int i = bit; i < str_bin.size(); ++i)
  {
    //���ֵ���Ǻ���ȫΪ1
    num += qpower(2, base);
    --base;
  }
  min_max.second = num;

  return min_max;
}

string Dec_To_Bin(int64_t num) 
{
  string str_bin = "00000000"; 
  for (int i = 7; i >= 0; --i)
  {
    str_bin[i] = num % 2 + 48;
    num >>= 1;
  }
  return str_bin;
}


void TransCidr(string& cidr, int cnt[]) 
{
  auto iter = cidr.begin();
  int64_t i = 0; 
  while (iter != cidr.end()) 
  {
    while (iter != cidr.end() && *iter != '.' && *iter != '/')
    {
      cnt[i] = 10 * cnt[i] + (*iter) - 48; 
      ++iter;
    }

    if (*iter == '/')
    {
      ++iter;
      while (iter != cidr.end())
      {
        cnt[4] = 10 * cnt[4] + (*iter) - 48;
        ++iter;
      }
      return;
    }
    else
      ++iter, ++i;
  }
}


vector<Rule> ReadRule(string& file_name)
{
  ifstream fin(file_name);
  vector<Rule> rulelist;
  int64_t port1_beg = 0, port1_end = 0, port2_beg = 0, port2_end = 0,
    tcp = 0;

  //���·�����ip��ַ
  while (!fin.eof() && fin.peek() != EOF)
  {
    char other = '\0';
    fin >> other; 
    if (other == '\0')  
      break;


    string cidr1, cidr2; 
    fin >> cidr1 >> cidr2;
    int cnt1[5] = { 0, 0, 0, 0, 0 }; 
    int cnt2[5] = { 0, 0, 0, 0, 0 };
    TransCidr(cidr1, cnt1), TransCidr(cidr2, cnt2); 
    string str_bin1, str_bin2;
    for (int i = 0; i < 4; ++i) 
    {
      str_bin1 += Dec_To_Bin(cnt1[i]);
    }

    PII ip1 = StrBin_To_Dec(str_bin1, cnt1[4]);

    for (int i = 0; i < 4; ++i)
    {
      str_bin2 += Dec_To_Bin(cnt2[i]);
    }

    PII ip2 = StrBin_To_Dec(str_bin2, cnt2[4]);


    fin >> port1_beg >> other >> port1_end;
    fin >> port2_beg >> other >> port2_end;

    string str_tcp;
    fin >> str_tcp;
    if (str_tcp[7] == 'F' && str_tcp[8] == 'F')
      tcp = 16 * (str_tcp[2] - 48) + str_tcp[3] - 48;
    else if (str_tcp[7] == '0' && str_tcp[8] == '0')
      tcp = 256;   
    Rule rule(ip1.first, ip1.second, ip2.first, ip2.second, port1_beg, port1_end,
      port2_beg, port2_end, tcp);
    rulelist.push_back(rule);
  }
  fin.close();
  return rulelist;
}
