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

        void put(nodeType *p) {
            nodeType **dp;
            dp = &root;
            while(*dp && (*dp)->weight <= p->weight) {
                dp = &(*dp)->next;
            }
            p->next = *dp;
            *dp = p;
        }

        void altprintHuffTree(nodeType *p, int lvl) {
            if(p) {
                cout << p->ch << " " << p->weight << " " << lvl << "\n";
                altprintHuffTree(p->zero, ++lvl);
                altprintHuffTree(p->one, ++lvl);
            }
        }

};
