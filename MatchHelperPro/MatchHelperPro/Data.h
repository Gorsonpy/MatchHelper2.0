#pragma once
#ifndef DATA_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::istream;
using std::ostream;
using int64_t = long long;

class Data
{
  int64_t origin_ip_; 
  int64_t origin_port_;
  int64_t receiver_ip_; 
  int64_t receiver_port_;
  int64_t tcp_;
  string id_; //id作为哈希表中的键

public:
  friend vector<Data> ReadData(string& file_name);
  friend ostream& operator<<(ostream& os, Data& data);

  Data() = default;
  Data(int64_t ip1, int64_t port1, int64_t ip2, int64_t port2,
    int64_t tcp, string id) : origin_ip_(ip1), origin_port_(port1), receiver_ip_(ip2),
    receiver_port_(port2), tcp_(tcp), id_(id) {};

  int64_t origin_ip()const { return origin_ip_; }
  int64_t origin_port()const { return origin_port_; }
  int64_t receiver_ip()const { return receiver_ip_; }
  int64_t receiver_port()const { return receiver_port_; }
  int64_t tcp()const { return tcp_; }
  string id()const { return id_; }
};
#endif // DATA_H

ostream& operator<<(ostream& os, Data& data);
vector<Data> ReadData(string& file_name);
