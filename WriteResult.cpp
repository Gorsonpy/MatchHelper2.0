#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"Data.h"
#include"Rule.h"
#include"match_util.h"

using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ios;

void WriteResult(string& ans_name, string& packet_name, vector<Data>& datalist, vector<Rule>& rulelist)
{
  ofstream fout(ans_name, ios::app);
  if (fout.good())
    cout << "now: " << ans_name << " is opened successfully." << endl;
  else
    cout << "error: " << ans_name << " failed to open." << endl;
  auto ans = DoMatch(datalist, rulelist);
  for (auto i : ans)
  {
    fout << packet_name << ' ' << i << endl;
  }
  cout << "finished." << endl;
  fout.close();
}