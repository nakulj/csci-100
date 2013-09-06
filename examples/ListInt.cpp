#include <iostream>
#include "ListInt.h"

using namespace std;

ListInt::ListInt()
{
  cout << "***Creating ListInt object" << endl;
  head = NULL;
}

ListInt::~ListInt()
{
  cout << "***Deleteing ListInt object" << endl;
  IntItem *tmp, *ptr= head;
  while(ptr != NULL){
    tmp= ptr->next;
    delete ptr;
    ptr= tmp;
  }
   

}

void ListInt::push_back(int new_val)
{

}

int ListInt::pop_front()
{

}

int ListInt::peek_front()
{

}

void ListInt::print_list()
{

}

IntItem *ListInt::find(int find_val)
{

}

bool ListInt::remove(int del_val)
{

}

// Add code for list_size() here
