#ifndef NETWORK_H
#define NETWORK_H
#include <fstream>
#include <iostream>
#include "user.h"
using namespace std;

class Network {
public:
  Network();
  ~Network();
  void read(string);
  void write(string);
  void addUser(string, int, int);
  int addConnection(string, string);
  int remConnection(string, string);
  int get_id(string);
  void print();
  void printFriends(string);
private:
    vector<User> users;
};


#endif
