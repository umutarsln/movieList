#include<iostream>
#include<string>
#include "movieList.h"

using namespace std;

int main()
{
    MovieList list;
    
    /*
    list.add("example film",6.5,2009);
*/

    list.loadFile("sampleInput.txt");
    //list.update("nnn",5);
    //list.remove("ooo");
    //list.printByName();
    //list.printByRate();
    list.printByYear();
    //list.saveToFileByName("name.txt");
    //list.saveToFileByRate("rate.txt");
    //list.saveToFileByYear("year.txt");

}

