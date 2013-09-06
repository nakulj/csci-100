#include "user.h"
#include <iostream>
#include <iomanip>

User::User(string myname, int myyear, int myzip) {
    name= myname;
    year= myyear;
    zip= myzip;
    id= 0;
}

User::~User() {

}

void User::add_friend(int id) {
    friends.push_back(id);
}

void User::delete_friend(int id) {
    for(int i=0; i<friends.size(); i++) {
        if(friends[i] == id)
            friends.erase(friends.begin()+i);
    }
}

string* User::getName() {
    return &name;
}

int* User::getID() {
    return &id;
}

int* User::getYear() {
    return &year;
}

int* User::getZip() {
    return &zip;
}

int User::nFriends() {
    return friends.size();
}

int User::friendID(int i) {
    return friends[i];
}

void User::print() {
    cout<<
            left<<setw(4)<<id<<'\t'<<
            left<<setw(20)<<name<<'\t'<<
            left<<setw(5)<<year<<'\t'<<
            left<<setw(5)<<zip<<
            endl;
}
