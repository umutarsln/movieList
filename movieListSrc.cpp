#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "movieList.h"


using namespace std;

void MovieList::add(string name, double rate, int year){ // 3 head connection
    Node *cur;
    Node *newNode = new Node(name,rate,year);

    if(head == 0){
        newNode->nameNext = head;
        head = newNode;

    }
    else if (head->name >= newNode->name){
        newNode->nameNext = head;
        head = newNode;

    }
    else{

        cur = head;
        while(cur->nameNext != 0 && (cur->nameNext->name) < (newNode->name)){
            cur = cur->nameNext;
        }
        newNode->nameNext = cur->nameNext;
        cur->nameNext = newNode;
    }

    if(headR == 0){
        newNode->rateNext = headR;
        headR = newNode;

    }
    else if (headR->rate >= newNode->rate){
        newNode->rateNext = headR;
        headR = newNode;

    }
    else{

        cur = headR;
        while(cur->rateNext != 0 && (cur->rateNext->rate) < (newNode->rate)){
            cur = cur->rateNext;
        }
        newNode->rateNext = cur->rateNext;
        cur->rateNext = newNode;
    }

    if(headY == 0){
        newNode->yearNext = headY;
        headY = newNode;

    }
    else if (headY->year >= newNode->year){
        newNode->yearNext = headY;
        headY = newNode;

    }
    else{

        cur = headY;
        while(cur->yearNext != 0 && (cur->yearNext->year) < (newNode->year)){
            cur = cur->yearNext;
        }
        newNode->yearNext = cur->yearNext;
        cur->yearNext = newNode;
    }

}

bool MovieList::remove(string name){
    if(head == 0){                                     // empty list
        return false;
    }
    else{                        //non-empty list
        if(head->nameNext == 0 && name == head->name){ // only one node
            delete head, headR, headY;
            head = 0;
            headR = 0;
            headY = 0;
            return true;
        }
        else if(name == head->name){ // more than one node , deleting head
            Node *cur = head;
            if(name == headY->name){
                headY = headY->yearNext;
            }
            if(name == headY->name){
                headR = headR->rateNext;
            }
            head = head->nameNext;
            delete cur;
            return true;
        }
        else{
            Node *prev = headR;
            Node *cur = headR->rateNext;
            while(cur != 0 && !(cur->name == name)){
                prev = cur;
                cur = cur->rateNext;
            }
            if(cur == 0){
                return false;
            }
            prev->rateNext = cur->rateNext;          // link ayır

            prev = headY;
            cur = headY->yearNext;
            while(cur != 0 && !(cur->name == name)){
                prev = cur;
                cur = cur->yearNext;
            }
            prev->yearNext = cur->yearNext;      // link ayır

            prev = head;
            cur = head->nameNext;
            while(cur != 0 && !(cur->name == name)){
                prev = cur;
                cur = cur->nameNext;
            }
            prev->nameNext = cur->nameNext;  // link ayır

            delete cur;   //sil
            return true;
        }
    }
    return false;

}

void MovieList::update(string name, double rate){
    int year;
    if(head == 0){
        cout<<"Empty list";
        return;
    }
    for(Node *cur = head; cur != 0; cur = cur->nameNext){
        if(cur->name == name){
            year = cur->year;
            remove(name);
            add(name,rate,year);
            return;
        }
    }
    cout<<"There is no movie with this name!!"<<endl;
}

void MovieList::printByYear(){
   if(headY == 0){
        cout<<"Empty list"<<endl;
        return;
    }
    int i = 1;
    cout<<"In order by year\n";
    for(Node *cur = headY; cur != 0; cur = cur->yearNext){
        cout<<i<<". Movie: "<<endl;
        cout<<"\tName: "<<cur->name<<endl;
        cout<<"\tRate: "<<cur->rate<<endl;
        cout<<"\tYear: "<<cur->year<<endl;
        i++;
    }
}

void MovieList::printByName(){
    if(head == 0){
        cout<<"Empty list"<<endl;
        return;
    }
    int i = 1;
    cout<<"In order by name\n";
    for(Node *cur = head; cur != 0; cur = cur->nameNext){

        cout<<i<<". Movie: "<<endl;
        cout<<"\tName: "<<cur->name<<endl;
        cout<<"\tRate: "<<cur->rate<<endl;
        cout<<"\tYear: "<<cur->year<<endl;
        i++;
    }
}

void MovieList::printByRate(){
   if(headR == 0){
        cout<<"Empty list"<<endl;
        return;
    }
    int i = 1;
    cout<<"In order by rate\n";
    for(Node *cur = headR; cur != 0; cur = cur->rateNext){
        cout<<i<<". Movie: "<<endl;
        cout<<"\tName: "<<cur->name<<endl;
        cout<<"\tRate: "<<cur->rate<<endl;
        cout<<"\tYear: "<<cur->year<<endl;
        i++;
    }
}

void MovieList::loadFile(string filename){ // eksik
    ifstream readFile(filename);
    string line = "";
    
    string name;
    double rate;
    int year;
    
    if ( readFile.is_open() ){
        while(getline(readFile,line)){
            //cout<<line<<endl;
            istringstream iss(line);
            
            getline(iss, name, '\"'); // Read the name until the first double quote
            getline(iss, name, '\"'); // Read the name again, but stop at the closing double quote
            iss >> rate >> year;
           /*
            cout << "Name: " << name << endl;
            cout << "Rate: " << rate << endl;
            cout << "Year: " << year << endl;
            */
            add(name,rate,year);
        }
        readFile.close();
    }
}

void MovieList::saveToFileByName(string filename){

    ofstream outfile;
    outfile.open(filename);

    string name;
    double rate;
    int year;
    string write;

    outfile << "By Name Order:" << endl << endl;
    
    for(Node *cur = head; cur != 0; cur = cur->nameNext){
        name = cur->name;
        rate = cur->rate;
        year = cur->year;
        write = "Name: " + name + "\n"
                + "Rate: " + to_string(rate) + "\n"
                + "Year: " + to_string(year) + "\n\n";

        outfile << write;
    }
    outfile.close();
}

void MovieList::saveToFileByRate(string filename){

    ofstream outfile;
    outfile.open(filename);

    string name;
    double rate;
    int year;
    string write;

    outfile << "By Rate Order:" << endl << endl;
    
    for(Node *cur = headR; cur != 0; cur = cur->rateNext){
        name = cur->name;
        rate = cur->rate;
        year = cur->year;
        write = "Name: " + name + "\n"
                + "Rate: " + to_string(rate) + "\n"
                + "Year: " + to_string(year) + "\n\n";

        outfile << write;
    }
    outfile.close();
}

void MovieList::saveToFileByYear(string filename){
    ofstream outfile;
    outfile.open(filename);

    string name;
    double rate;
    int year;
    string write;
    
    outfile << "By Year Order:" << endl << endl;

    for(Node *cur = headY; cur != 0; cur = cur->yearNext){
        name = cur->name;
        rate = cur->rate;
        year = cur->year;
        write = "Name: " + name + "\n"
                + "Rate: " + to_string(rate) + "\n"
                + "Year: " + to_string(year) + "\n\n";

        outfile << write;
    }
    outfile.close();
}




