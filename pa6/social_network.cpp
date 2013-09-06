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
    while(in!=11) {
        cout<<"----------------------------------------------"<<endl;
        cout<<"Choose an option:"<<endl<<endl;
        cout<<"Add a user"<<endl;
        cout<<'\t'<<"1 first_name last_name birth_year zip"<<endl;
        cout<<"Add a friend connection"<<endl;
        cout<<'\t'<<"2 first_name_1 last_name_1 first_name_2 last_name_2"<<endl;
        cout<<"Delete a friend connection"<<endl;
        cout<<'\t'<<"3 first_name_1 last_name_1 first_name_2 last_name_2"<<endl;
        cout<<"Print users"<<endl;
        cout<<'\t'<<"4"<<endl;
        cout<<"List friends"<<endl;
        cout<<'\t'<<"5 first_name last_name"<<endl;
        cout<<"Write to file"<<endl;
        cout<<'\t'<<"6 file_name"<<endl;
        cout<<"Find shortest path"<<endl;
        cout<<'\t'<<"7 first_name_1 last_name_1 first_name_2 last_name_2"<<endl;
        cout<<"Find disjoint groups"<<endl;
        cout<<'\t'<<"8"<<endl;
        cout<<"Suggest friends for a user"<<endl;
        cout<<'\t'<<"9 first_name last_name"<<endl;
        cout<<"Find minimum spanning set"<<endl;
        cout<<'\t'<<"10"<<endl;
        cout<<"Exit"<<endl;
        cout<<'\t'<<"11"<<endl;
        cin>>in;
        switch(in) {
            case 1:
                //cout<<"Enter the user's name, year of birth and zip"<<endl;
                cin>>firstName>>lastName>>year>>zip;
                net.addUser(firstName+" "+lastName, year, zip);
                cout<<"Added user \'"<<firstName<<" "<<lastName<<'\''<<endl;
                break;
            case 2:
                //cout<<"Enter the two user names"<<endl;
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
                //cout<<"Enter the two user names"<<endl;
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
                //cout<<"Enter the user name"<<endl;
                cin>>firstName>>lastName;
                name= firstName+" "+lastName;
                net.printFriends(name);
                break;
            case 6:
                //cout<<"Enter the file name"<<endl;
                cin>>name;
                net.write(name);
                break;
            case 7:
                //cout<<"Enter the two user names"<<endl;
                cin>>firstName>>lastName>>firstName2>>lastName2;
                name= firstName+" "+lastName;
                name2= firstName2+" "+lastName2;
                net.printShortestPath(name, name2);
                break;
            case 8:
                net.disjointSets(1);
                break;
            case 9:
                cin>>firstName>>lastName;
                net.suggestFriends(firstName+" "+lastName);
                break;
            case 10:
                net.hubs();
                break;
            case 11:
                cout<<"Exiting."<<endl;
        }
        cout<<"----------------------------------------------"<<endl;
    }

    return 0;
}
