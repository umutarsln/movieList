#ifndef MOVIELIST_H_INCLUDED
#define MOVIELIST_H_INCLUDED
using namespace std;
class Node {
public:
    Node() {
        rateNext = 0;
        yearNext = 0;
        nameNext = 0;
    }
    Node(string cName, double cRate, int cYear, Node *yPtr=0, Node *nPtr=0, Node *rPtr=0){
        name = cName;
        rate = cRate;
        year = cYear;
        nameNext = nPtr;
        rateNext = rPtr;
        yearNext = yPtr;
    }
    int year;
    string name;
    double rate;
    Node *rateNext;
    Node *yearNext;
    Node *nameNext;
};

class MovieList {
public:
    MovieList() {
        head = 0;
        headR = 0;
        headY = 0;
    }

    void add(string,double,int); // name , rate , year
    bool remove(string); // name
    void update(string,double); // name , rate
    void printByYear();
    void printByName();
    void printByRate();
    void loadFile(string); //filename
    void saveToFileByYear(string); //filename
    void saveToFileByName(string); //filename
    void saveToFileByRate(string); //filename
public:
    Node *head, *headY, *headR;
};


#endif // MOVIELIST_H_INCLUDED

