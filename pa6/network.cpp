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
    }//Print error message for bad files
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
    }//Parse file
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
            ofile<<users[i].friendID(j);
            if(j!=(users[i].nFriends()-1))
                ofile<<" ";
        }//Print each detail
    }//For each user
    ofile<<endl;
    cout<<"Network saved to file \'"<<file<<'\''<<endl;
}

int Network::get_id(string name) {
    for(int i=0;i<users.size();i++) {
        if(*(users[i].getName()) == name)
            return *(users[i].getID());
    }//search and return id
    return -1;
}

int Network::addConnection(string n1, string n2) {
    if(n1 == n2)
        return -1;//Cannot friend a user to himself/herself
    int id1= get_id(n1),
        id2= get_id(n2);
    if((id1 == -1) || (id2 == -1))
        return -1;//both ids must be valid
    for(int i=0; i<users.size(); i++) {
        if(id1 == *(users[i].getID()))
            users[i].add_friend(id2);
        if(id2 == *(users[i].getID()))
            users[i].add_friend(id1);
    }//call User class' add_friend function to create the connection
    return 0;
}

int Network::remConnection(string n1, string n2) {
    if(n1 == n2)
        return -1;
    int id1= get_id(n1),
        id2= get_id(n2);
    if((id1 == -1) || (id2 == -1))
        return -1;
    //Same error checking as addConnection()
    for(int i=0; i<users.size(); i++) {
        if(id1 == *(users[i].getID()))
            users[i].delete_friend(id2);
        if(id2 == *(users[i].getID()))
            users[i].delete_friend(id1);
    }//call User class' delete_friend function to remove the connection
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
    }//Print each user's details
}

void Network::printFriends(string name) {
    for(int i= 0; i<users.size(); i++) {
        if(!(*(users[i].getName()) == name))
            continue;//Scan array till user is found
        if(users[i].friends.size() == 0) {
            cout<<name<<" has no friends :("<<endl;
            return;
        }//user has no friends
        cout<<
                left<<setw(4)<<"ID"<<'\t'<<
                left<<setw(20)<<"Name"<<'\t'<<
                left<<setw(5)<<"Year"<<'\t'<<
                left<<setw(5)<<"Zip"<<
                endl;
        for(int j= 0; j<users[i].friends.size(); j++)
            users[users[i].friends[j]].print();//print the
        return;//print friends and stop scanning array
    }
    cout<<"Unable to find "<<name<<", please check input"<<endl;
    //print error message if user not found
}

void Network::printShortestPath(string name1, string name2) {
    int id1= get_id(name1),
        id2= get_id(name2);
    if(id1==-1 || id2==-1 || id1==id2)
        cout<<"Invalid input."<<endl;
    for(int i=0; i<users.size(); i++) {
        users[i].predecessor= -1;
        users[i].depth= -1;
    }
    vector<int> queue;
    int ptr, fptr, tmp;
    queue.push_back(id2);
    users[id2].depth=0;
    //work backward so that the path does not have to be reversed later
    while(!queue.empty()) {
        ptr= queue[0];
        //add all the friends of the first user in the queue to the vector
        for(int i=0; i<users[ptr].friends.size(); i++) {
            fptr= users[ptr].friends[i];
            if(users[fptr].depth != -1)
                continue;//skip users that have already been processed
            users[fptr].depth= users[ptr].depth+1;
            users[fptr].predecessor= ptr;//set the visitor
            //if the user has been found, print the path and distance
            if(fptr == id1) {
                cout<<"Distance: "<<users[id1].depth<<endl;
                tmp= id1;
                while(tmp!=id2) {
                    cout<<*(users[tmp].getName())<<" -> ";
                    tmp= users[tmp].predecessor;
                }//retrace path of visitors
                cout<<*(users[id2].getName())<<endl;
                return;//terminate
            }
            queue.push_back(fptr);
        }
        queue.erase(queue.begin());//remove the first user
    }//breadth first search
    //if the loop finishes, there is no path
    cout<<"None"<<endl;
}

int Network::disjointSets(int print) {
    //initially set all users to set 0
    for(int i=0; i<users.size(); i++)
        users[i].set_member= 0;
    int set=0;
    //assign a set to each user
    for(int i=0; i<users.size(); i++) {
        if(users[i].set_member!=0)
            continue;//skip users that have already been assigned a set
        makeSet(i, ++set);//call a function that assigns the user and all other joint users a set number
    }
    if(!print)
        return set;//skip printing if print=0
    vector<string> setNames;
    for(int i=1; i<=set; i++) {
        cout<<"Set "<<i<<" => ";
        for(int j=0; j<users.size(); j++) {
            if(users[j].set_member==i)
                setNames.push_back(*(users[j].getName()));
        }
        for(int j=0; j<setNames.size(); j++) {
            cout<<setNames[j];
            if(j!=(setNames.size()-1))
                cout<<", ";
        }
        cout<<endl;
        setNames.clear();
    }//print each set's members
    
    return 0;
}

void Network::makeSet(int id, int set) {
    if(users[id].set_member!=0)
        return;//skip users that have already been assigned numbers
    users[id].set_member= set;
    int fptr;
    for(int i=0; i<users[id].friends.size(); i++) {
        fptr= users[id].friends[i];
        makeSet(fptr, set);//recursively assign each friend of the user the same set number(depth first search)
    }
}

void Network::suggestFriends(string name) {
    int id= get_id(name);
    int fptr, ffptr;
    for(int i=0; i<users.size(); i++)
        users[i].added=0;
    vector<int> strong;
    vector<int> scores;
    int maxScore=0;
    for(int i=0; i<users[id].friends.size(); i++) {
        fptr= users[id].friends[i];
        f:for(int j=0; j<users[fptr].friends.size(); j++) {
            ffptr= users[fptr].friends[j];
            if(ffptr==id)
                continue;
            int skip=0;
            for(int k=0; k<users[id].friends.size(); k++) {
                if(users[id].friends[k] == ffptr) {
                    skip=1;
                    break;
                }
            }
            if(skip)
                continue;
            if(users[ffptr].added==0) {
                users[ffptr].added=1;
                strong.push_back(ffptr);
            }
        }
    }//Find all strong users and add to a vector
    if(strong.empty()) {
        cout<<"No suggestions for "<<name<<"."<<endl;
        return;
    }//No suggestions
    for(int i=0; i<strong.size(); i++) {
        scores.push_back(calcScore(id, strong[i]));
        if(scores[i]>maxScore)
            maxScore= scores[i];
    }//calculate each user's score
    cout<<"The strongest candidate(s) is/are:"<<endl;
    for(int i=0; i<strong.size(); i++) {
        if(scores[i]==maxScore)
            cout<<left<<setw(20)<<*(users[strong[i]].getName())<<endl;
    }//print suggestions
    cout<<"They scored "<<maxScore<<endl;
}

int Network::calcScore(int id1, int id2) {
    int score=0;
    int fptr;
    for(int i=0; i<users[id1].friends.size(); i++) {
        fptr= users[id1].friends[i];
        for(int j=0; j<users[fptr].friends.size(); j++) {
            if(users[fptr].friends[j]==id2) {
                score++;//increment score for each mutual friend
                continue;
            }
        }
    }
    return score;
}

void Network::hubs() {
    if(disjointSets(0)!=1) {
        cout<<"Error: More than one disjoint set"<<endl;
        return;
    }//there should only be one disjoint set
    for(int i=0; i<users.size(); i++) {
        users[i].covered= false;
        users[i].added= 0;
    }//initialise covered and added values
    int maxFriends, maxFriendsID;
    int fptr;
    int usersCovered=0;
    //loop till all users are covered
    while(usersCovered<users.size()) {
        maxFriends= 0;
        for(int i=0; i<users.size(); i++) {
            if(users[i].added==1)
                continue;//skip users that have been added
            if(uncoveredFriends(i)>maxFriends) {
                maxFriends= uncoveredFriends(i);
                maxFriendsID= i;
            }
        }//find the user with maximum number of uncovered friends
        users[maxFriendsID].added= 1;//the user is a part of the minimal spanning set
        users[maxFriendsID].covered= true;
        usersCovered++;
        for(int i=0; i<users[maxFriendsID].friends.size(); i++) {
            fptr= users[maxFriendsID].friends[i];
            if(users[fptr].covered)
                continue;
            users[fptr].covered= true;
            usersCovered++;
        }//if a user is added, all his/her friends are covered
    }
    cout<<"The smallest set of users that creates a path to any other user is: "<<endl;
    for(int i=0; i<users.size(); i++) {
        if(users[i].added==0)
            continue;
        cout<<'\t'<<*(users[i].getName())<<endl;
    }
}

int Network::uncoveredFriends(int id) {
    int ctr=0;
    int fptr;
    //check each of the user's friends
    for(int i=0; i<users[id].friends.size(); i++) {
        fptr= users[id].friends[i];
        if(!users[fptr].covered)
            ctr++;
        //if the current friend hasn't been covered, increment the counter
    }
    return ctr;
}
