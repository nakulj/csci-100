#include <iostream>
#include <vector>

using namespace std;

void print_list(vector<int> &myvec)
{
  int i;
  // complete the for loop and its body
  for(i=0;i<myvec.size();i++){
	  cout<<myvec[i]<<" ";
  }
  cout << endl;
}


int main(int argc, char *argv[])
{
  int temp;
  vector<int> l1, *l2;

  cout << "Added 1, 2, 3, and 9 to list 1" << endl;
  // add code to put 1, 2, 3, and 9 into the vector in that order


  print_list( l1 );

  // print out the number of items (list size) in the list


  cout<<l1.front()<<endl;
  // print out the front item


  l1.erase(l1.begin());
  // delete the item at index 1
  cout << "Removing second item (i.e. at index 1): " << endl;
  

  // will print the resulting list
  print_list( l1 );

  // add code to put 120, 121, 122 onto the front of the list 
  //  use the insert() method
  cout << "Adding 120, 121, 122" << endl;
  l1.insert(l1.begin(),120);
  l1.insert(l1.begin(),121);
  l1.insert(l1.begin(),122);

  print_list( l1 );

  return 0;
}
