#include <iostream>
using namespace std;


class huffmanType
{
    private:
        struct nodeType
        {
            char ch;
            int weight;

            nodeType *next, *zero, *one;

            nodeType()
            {
                ch = '\0';
                weight = 0;
                next = NULL;
                zero = NULL;
                one = NULL;
            }
        };

        nodeType *root, **envPtr;
        

};
