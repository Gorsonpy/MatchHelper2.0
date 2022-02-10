#include<iostream>
#include"Data.h"
using std::ostream;
ostream& operator<<(ostream& os, Data& data)
{
  os << data.origin_ip_ << " " << data.receiver_ip_ << " "
    << data.origin_port_ << " " << data.receiver_port_ << " "
    << data.tcp_;
  return os;
}