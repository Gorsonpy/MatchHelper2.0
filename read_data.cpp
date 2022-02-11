#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"Data.h"

using std::cout;
using std::istream;
using std::ifstream;
using std::string;
using std::vector;
using std::to_string;

vector<Data> ReadData(string& file_name)
{
  ifstream fin(file_name);
  if (fin.good())
    cout << "now:" << file_name << " is opened successfully." << endl;
  else
    cout << "error:" << file_name << " failed to open." << endl;
  vector<Data> datalist;
  while (!fin.eof() && fin.peek() != EOF)
  {
    int64_t point_ip1 = 0, point_ip2 = 0, port1 = 0, port2 = 0, tcp = 0;
    fin >> point_ip1 >> point_ip2 >> port1 >> port2 >> tcp;
    string id = to_string(point_ip1) + to_string(point_ip2) + to_string(port1) + to_string(port2) + to_string(tcp);
    Data data(point_ip1, port1, point_ip2, port2, tcp, id);
    datalist.push_back(data);
  }
  datalist.pop_back();
  fin.close();
  return datalist;
}
