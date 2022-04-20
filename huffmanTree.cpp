#include <iostream>
#include <map>
#include <fstream>
using namespace std;
const int MAX = 128;


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
                ch = '*';
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
                altprintHuffTree(p->zero, lvl+1);
                altprintHuffTree(p->one, lvl+1);
            }
        }

        bool isThere(nodeType *p, char cr) {
            if(!p) {
                return false;
            }
            else {
                if(!(p)->zero && p->ch == cr) {
                    return true;
                }
                else {
                    return isThere(p->zero, cr) || isThere(p->one, cr);
                }
            }
        }
    public:
        huffmanType() {
            root = NULL;
            envPtr = new nodeType*[MAX];
            for (int i = 0; i < MAX; ++i) {
                envPtr[i] = NULL;
            }
        }
        
        void loadArray(map<char, int> a) {
            for(auto it = a.begin(); it != a.end(); ++it) {
                int location = (int)it->first;
                envPtr[location] = new nodeType;
                envPtr[location]->ch = it->first;
                envPtr[location]->weight = it->second;
            }
        }

        void buildLinkedList() {
            for(int i = 0; i < MAX; ++i) {
                if(envPtr[i]) {
                    put(envPtr[i]);
                }
            }
        }

        void printLinkedList() {
            if(!root) {
                cout << "Linked List Empty" << endl;
                return;
            }
            else {
                nodeType *p;
                p = root->next;
                cout << root->ch << "\t" << root->weight << "\n";
                while (p) {
                    cout << p->ch << "\t" << p->weight << "\n";
                    p = p->next;
                }
            }

        }

        void buildhuffManTree() {
            nodeType *p;
            while(root->next) {
                p = new nodeType;
                p->zero = root;
                p->one = root->next;
                p->weight = p->zero->weight + p->one->weight;
                root = root->next->next;
                put(p);
            }
        }

        void printHuffTree() {
            altprintHuffTree(root, 0);
        }

        void encode(char i) {
            nodeType **dp;
            dp = &root;
            while((*dp)->one && (*dp)->zero) {
                if(isThere((*dp)->zero, i)) {
                    cout << "0";
                    dp = &(*dp)->zero;
                }
                else {
                    cout << "1";
                    dp = &(*dp)->one;
                }

            }
        }

};

void printMap(map<char, int> m)
{
    for(auto it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << "\t" << it->second << endl;
    }
}

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

    cout << "\n\nPrinting Characters In File\n\n";
    printMap(charMap);
    in.close();

    huffmanType test;
    test.loadArray(charMap);
    test.buildLinkedList();

    cout << "\n\nPrinting Linked List\n\n";
    test.printLinkedList();

    test.buildhuffManTree();

    cout << "\n\nPrinting Huffman Tree\n\n";
    test.printHuffTree();

    cout << "\n\nPrinting Character Encoding\n\n";
    for(auto it = charMap.begin(); it != charMap.end(); ++it)
    {
        cout << it->first << "\t";
        test.encode(it->first);
        cout << endl;
    }

    return 0;
}