#pragma once
#ifndef RULE_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>


using std::vector;
using std::cout;
using std::endl;
using std::ostream;
using std::string;
using int64_t = long long;

class Rule
{
  int64_t origin_ip_beg_;
  int64_t origin_ip_end_;
  int64_t receiver_ip_beg_;
  int64_t receiver_ip_end_;
  int64_t origin_port_beg_;
  int64_t origin_port_end_;
  int64_t receiver_port_beg_;
  int64_t receiver_port_end_;
  int64_t tcp_;
public:
  friend vector<Rule> ReadRule(string& file_name);
  friend ostream& operator<<(ostream& out, Rule rule);


  Rule() = default;
  Rule(int64_t ip1_beg, int64_t ip1_end, int64_t ip2_beg, int64_t ip2_end,
    int64_t port1_beg, int64_t port1_end,
    int64_t port2_beg, int64_t port2_end, int64_t tcp)
    : origin_ip_beg_(ip1_beg), origin_ip_end_(ip1_end), receiver_ip_beg_(ip2_beg),
    receiver_ip_end_(ip2_end), origin_port_beg_(port1_beg),
    origin_port_end_(port1_end), receiver_port_beg_(port2_beg),
    receiver_port_end_(port2_end), tcp_(tcp) {}


  int64_t origin_ip_beg()const { return origin_ip_beg_; }
  int64_t origin_ip_end()const { return origin_ip_end_; }
  int64_t receiver_ip_beg()const { return receiver_ip_beg_; }
  int64_t receiver_ip_end()const { return receiver_ip_end_; }
  int64_t origin_port_beg()const { return origin_port_beg_; }
  int64_t origin_port_end()const { return origin_port_end_; }
  int64_t receiver_port_beg()const { return receiver_port_beg_; }
  int64_t receiver_port_end()const { return receiver_port_end_; }
  int64_t tcp()const { return tcp_; }
};
#endif // !RULE_H

vector<Rule> ReadRule(string& file_name);
#pragma once
