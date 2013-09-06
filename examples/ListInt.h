#ifndef LISTINT_H
#define LISTINT_H

typedef struct IntItem_s {
  int val;
  struct IntItem_s *next;
} IntItem;

class ListInt {
 public:
  ListInt();
  ~ListInt();
  void push_back(int new_val);
  int pop_front();
  int peek_front();
  void print_list();
  IntItem *find(int find_val);
  bool remove(int del_val);
  int list_size();
 private:
  IntItem_s *head;
};

#endif
