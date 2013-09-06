#include <iostream>
#include "ListInt.h"

using namespace std;

int main(int argc, char *argv[])
{
  int temp;
  ListInt l1,*l2;

  cout << "Added 1, 2, 3, and 9 to list 1" << endl;
  push_back(1);
  push_back(2);
  push_back(3);
  push_back(9);
  print_list();
  cout << "List 1 size is " << list_size() << endl;  
  cout << "Trying to find 3" << endl;
  if(find(3) != NULL){
	cout << "3 is in the list" << endl;
  }
  else {
	cout << "Error:  3 is not in the list" << endl;
  }
  temp = peek_front();
  cout << "Front item is " << temp << endl;
  temp = pop_front();
  cout << "Removed front item: " << temp << endl;
  cout << "Adding 120, 121, 122" << endl;
  push_back(120);
  push_back(121);
  push_back(122);
  cout << "List 1 size is " << list_size() << endl;  
  //--------------------------------------------------
  // Uncomment these lines once you implement remove()
  //--------------------------------------------------
  cout << "Attempted to remove 9";
  if(remove(9))
  	cout << "...successfully" << endl;
  else
  	cout << "...unsuccessfully" << endl;
    cout << "Attemptint to remove 10";
  if(remove(10))
	cout << "...successfully" << endl;
  else
	cout << "...unsuccessfully" << endl;
  cout << "List 1 => " << endl;
  print_list();
  cout << "Clearing the list 1" << endl;
  while(list_size() > 0){
	pop_front();
  }
  cout << "Attempting to remove from empty list...let's see how you handle it" << endl;
  pop_front();
  print_list();

  return 0;
}
