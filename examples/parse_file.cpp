#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
  int anum;
  string astring, bstring, cstring;

  // opens the filename specified as a command line argument
  ifstream myfile(argv[1], ifstream::in);
  if(!myfile.good()){
	cout << "Error opening file " << argv[1] << endl;
	exit(1);
  }

  // expects two words on a single line
  myfile >> astring >> bstring;
  // C++ string concatenation
  cstring = astring + " " + bstring;
  cout << "The two words read from the file are: " << cstring << endl;

  // the '>>' operator won't have read the '\n' at 
  // the end of the line with two words.  Thus, we
  // can manually read (and discard) any other characters
  // until we encounter the '\n'
  while(myfile.get() != '\n');  
  
  // Now we're at the beginning of a newline
  
  // We'll read in integers checking if the next character 
    // is a '\n' and if so, stop reading in integers
  while(myfile.peek() != '\n'){
	myfile >> anum;
	// we'll print out the number we read for the heck of it
	cout << anum << " ";
  }
  cout << endl;
  return 0;
}
