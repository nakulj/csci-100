#ifndef USER_H
#define USER_H
#include <string>
#include <vector>

using namespace std;

class User {
public:
  User(string, int, int);
  ~User();
  void add_friend(int);
  void delete_friend(int);
  int* getID();
  string* getName();
  int* getYear();
  int* getZip();
  int nFriends();
  int friendID(int);
  void print();
  vector<int> friends;
  int predecessor;
  int depth;
  int set_member;
  int added;
  bool covered;
private:
  int id;
  string name;
  int year;
  int zip;
};


#endif
