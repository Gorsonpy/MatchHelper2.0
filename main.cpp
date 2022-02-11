#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<fstream>  
#include<time.h>
#include"Data.h"
#include"Rule.h"
#include"match_util.h"

using std::unordered_map;
using std::ifstream;
using std::ofstream;
using std::string;
using std::cout;
using std::endl;

unordered_map<string, int32_t> match_map; //在源文件中做出定义，通过头文件声明让do_match可以多次使用match_map
int main(int argc, char** argv)
{
  
  clock_t beg, end;
  beg = clock();
  string ans_name = "res.txt";
  string rulename = argv[1];
  auto rulelist = ReadRule(rulename);
  for(int i = 2; i < argc; ++i) //遍历数据集文件名数组
  {
    string dataname = argv[i]; //转换成string类型
    auto datalist = ReadData(dataname);
    WriteResult(ans_name, dataname, datalist, rulelist);
  }
  end = clock();
  cout << "Total:" << (double)(end - beg) / CLOCKS_PER_SEC << "s" << endl;
  system("pause");
  
  return 0;
}
