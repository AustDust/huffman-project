#include <iostream>
#include <fstream>
#include <map>
using namespace std;

template <typename T>
struct nodeType
{
    nodeType* left;
    nodeType* right;
    T payload;
};

void printMap(map<char, int> m);

int main()
{
    /***** TASK ONE- INPUT *****/
    /* OPen file stream */
    ifstream in;
    in.open("input.txt");
    if(!in)
    {
        cout << "ERR: File not found" << endl;
        return 1;
    }
    
    /* Use a map to count characters */
    char c;
    map<char, int> charMap;
    while(!in.eof())
    {
        in >> c;
        if(in.eof())
            break;

        if(charMap.find(c) == charMap.end())
            charMap.emplace(c, 1);
        else
            charMap.at(c)++;
    }
    printMap(charMap);
    in.close();


    return 0;
}

void printMap(map<char, int> m)
{
    for(auto it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
}
