#include<iostream>
#include<string>
#include<vector>
#include<fstream>  
#include"Data.h"
#include"Rule.h"
#include"match_util.h"

using std::ifstream;
using std::ofstream;
using std::string;
using std::cout;
using std::endl;


int main()
{
  string ans_name = "res.txt";
  /*
  string rulefile = argv[1];
  auto rulelist = ReadRule(rulefile);
  for(int i = 2; i < argc; ++i) //遍历数据集文件名数组
  {
    string datafile = argv[i]; //转换成string类型
    auto datalist = ReadData(datafile);
    WriteResult(ans_name, datafile, datalist, rulelist);
  }
  */
  string packet_name = "";
  string rulename = "rule.txt", dataname = "packet1.txt";
  auto rulelist = ReadRule(rulename);
  auto datalist = ReadData(dataname);
  WriteResult(ans_name, packet_name, datalist, rulelist);
  system("pause");
  return 0;
}
