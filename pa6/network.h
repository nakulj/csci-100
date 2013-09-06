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
  void read(string fileName);
  void write(string name);
  void addUser(string name, int yearOfBirth, int zip);
  int addConnection(string name1, string name2);
  int remConnection(string name1, string name2);
  int get_id(string name);
  void print();
  void printFriends(string name);
  void printShortestPath(string name1, string name2);
  int disjointSets(int print);
  void suggestFriends(string name);
  void hubs();
private:
    int uncoveredFriends(int id);
    bool covered();
    void makeSet(int id, int set);
    int calcScore(int id1, int id2);
    vector<User> users;
};


#endif
