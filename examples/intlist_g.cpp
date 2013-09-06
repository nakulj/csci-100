#include <iostream>
#include "intlist_g.h"

using namespace std;

extern IntItem *head;


bool is_empty()
{
  if(head==NULL)
	  return 1;
  return 0;
}

void push_back(int new_val)
{
  IntItem *tmp;
  // Allocate a new item and set its value 
  //  and set its next pointer to NULL

  // Is the list empty and we need to update head
  //   or does it contain other items and we need
  //   to scan to the end and add the new item?
  if( is_empty() ){
	  head= new IntItem;
	  head->val= new_val;
	  head->next= NULL;
  }
  else {
	  tmp= head;
	  while(tmp->next != NULL) {
		tmp= tmp->next;
	  }
	  tmp->next= new IntItem;
	  tmp->next->val= new_val;
	  tmp->next->next= NULL;
  }
}


int pop_front()
{	
	if(is_empty())
		return -1;
	IntItem *temp= head;
	head= head->next;
	return(temp->val);
	delete temp;
  // Remember to return -1 if the list is empty

  // Be sure to deallocate the memory from the IntItem you removed

}

int peek_front()
{
	if(is_empty())
		return -1;
	return head->val;
  // Remember to return -1 if the list is empty

}

void print_list()
{
  IntItem *tmp;
  tmp = head;
  cout << "Current list => ";
  // print each item followed by a space...all on the same line
  if(is_empty()) {
	return;
  }
  while(tmp->next != NULL) {
	cout << (tmp->val) << " ";
	tmp= tmp->next;
  }
  cout<< (tmp->val) <<endl;
}

IntItem *find(int find_val)
{
	if(is_empty())
		return NULL;
	IntItem *temp= head;
	while(temp->next != NULL) {
		if(temp->val == find_val)
			return temp;
		temp= temp->next;
	}
	return NULL;


}

bool remove(int del_val)
{
return 0;
}

int list_size()
{
  if(is_empty())
	  return 0;
  int mysize = 1;
  IntItem* temp= head;
  while(temp->next != NULL) {
	mysize++;
	temp= temp->next;
  }


  return mysize;
}
