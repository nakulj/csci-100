#include "network.h"
#include "user.h"
#include <iostream>
#include <iomanip>

Network::Network() {

}

Network::~Network(){

}

void Network::addUser(string name, int year, int zip) {
    User* temp= new User(name, year, zip);
    *(temp->getID()) = users.size();
    users.push_back(*temp);
}

void Network::read(string file) {
    ifstream ifile(file.c_str(), ifstream::in);
    if(!ifile.good()) {
        cout<<"Error reading "<<file<<endl;
        exit(1);
    }
    int n;
    ifile>>n;
    string name;
    string firstName, lastName;
    int id, year, zip;
    while(ifile.get() != '\n');
    for(int i= 0; i<n; i++) {
        ifile>>id;
        while(ifile.get() != '\n');
        ifile>>firstName>>lastName;
        name= firstName+" "+lastName;
        while(ifile.get() != '\n');
        ifile>>year;
        while(ifile.get() != '\n');
        ifile>>zip;
        while(ifile.get() != '\n');
        addUser(name, year, zip);
        while(ifile.peek() != '\n'){
            ifile>>id;
            users[i].add_friend(id);
        }
        while(ifile.get() != '\n');
    }
}

void Network::write(string file) {
    ofstream ofile(file.c_str(), ofstream::out);
    ofile<<users.size();
    for(int i= 0; i<users.size(); i++) {
        ofile<<endl<<*(users[i].getID());
        ofile<<endl<<'\t'<<*(users[i].getName());
        ofile<<endl<<'\t'<<*(users[i].getYear());
        ofile<<endl<<'\t'<<*(users[i].getZip());
        ofile<<endl<<'\t';
        for(int j= 0; j<users[i].nFriends(); j++) {
            ofile<<users[i].friendID(j)<<" ";
        }
    }
    ofile<<endl;
}

int Network::get_id(string name) {
    for(int i=0;i<users.size();i++) {
        if(*(users[i].getName()) == name)
            return *(users[i].getID());
    }
    return -1;
}

int Network::addConnection(string n1, string n2) {
    if(n1 == n2)
        return -1;
    int id1= get_id(n1),
        id2= get_id(n2);
    if((id1 == -1) || (id2 == -1))
        return -1;
    for(int i=0; i<users.size(); i++) {
        if(id1 == *(users[i].getID()))
            users[i].add_friend(id2);
        if(id2 == *(users[i].getID()))
            users[i].add_friend(id1);
    }
    return 0;
}

int Network::remConnection(string n1, string n2) {
    if(n1 == n2)
        return -1;
    int id1= get_id(n1),
        id2= get_id(n2);
    if((id1 == -1) || (id2 == -1))
        return -1;
    for(int i=0; i<users.size(); i++) {
        if(id1 == *(users[i].getID()))
            users[i].delete_friend(id2);
        if(id2 == *(users[i].getID()))
            users[i].delete_friend(id1);
    }
    return 0;
}

void Network::print() {
    cout<<
            left<<setw(4)<<"ID"<<'\t'<<
            left<<setw(20)<<"Name"<<'\t'<<
            left<<setw(5)<<"Year"<<'\t'<<
            left<<setw(5)<<"Zip"<<
            endl;
    for(int i= 0; i<users.size(); i++) {
        users[i].print();
    }
}

void Network::printFriends(string name) {
    for(int i= 0; i<users.size(); i++) {
        if(!(*(users[i].getName()) == name))
            continue;
        if(users[i].friends.size() == 0) {
            cout<<name<<" has no friends :("<<endl;
            return;
        }
        cout<<
                left<<setw(4)<<"ID"<<'\t'<<
                left<<setw(20)<<"Name"<<'\t'<<
                left<<setw(5)<<"Year"<<'\t'<<
                left<<setw(5)<<"Zip"<<
                endl;
        for(int j= 0; j<users[i].friends.size(); j++)
            users[users[i].friends[j]].print();
        return;
    }
    cout<<"Unable to find "<<name<<", please check input"<<endl;
}
