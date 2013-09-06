#include "network.h"
#include "user.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    int in=0, year, zip, flag;
    string firstName, lastName,
           firstName2, lastName2,
           name, name2;
    Network net= *(new Network());
    net.read(argv[1]);
    while(in!=7) {
        cout<<"Choose an option:"<<endl;
        cout<<"1: Add a user"<<endl;
        cout<<"2: Add a friend connection"<<endl;
        cout<<"3: Delete a friend connection"<<endl;
        cout<<"4: Print users"<<endl;
        cout<<"5: List friends"<<endl;
        cout<<"6: Write to file"<<endl;
        cout<<"7: Exit"<<endl;
        cin>>in;
        switch(in) {
            case 1:
                cout<<"Enter the user's name, year of birth and zip"<<endl;
                cin>>firstName>>lastName>>year>>zip;
                net.addUser(firstName+" "+lastName, year, zip);
                break;
            case 2:
                cout<<"Enter the two user names"<<endl;
                cin>>firstName>>lastName>>firstName2>>lastName2;
                name= firstName+" "+lastName;
                name2= firstName2+" "+lastName2;
                flag= net.addConnection(name, name2);
                if(flag == -1)
                    cout<<"Failed to add connection, please check input"<<endl;
                else
                    cout<<name<<" and "<<name2<<" are now friends"<<endl;
                break;
            case 3:
                cout<<"Enter the two user names"<<endl;
                cin>>firstName>>lastName>>firstName2>>lastName2;
                name= firstName+" "+lastName;
                name2= firstName2+" "+lastName2;
                flag= net.remConnection(name, name2);
                if(flag == -1)
                    cout<<"Failed to remove connection, please check input"<<endl;
                else
                    cout<<name<<" and "<<name2<<" are no longer friends"<<endl;
                break;
            case 4:
                net.print();
                break;
            case 5:
                cout<<"Enter the user name"<<endl;
                cin>>firstName>>lastName;
                name= firstName+" "+lastName;
                net.printFriends(name);
                break;
            case 6:
                cout<<"Enter the file name"<<endl;
                cin>>name;
                net.write(name);
                break;
            case 7:
                cout<<"Exiting."<<endl;
        }
    }

    return 0;
}
