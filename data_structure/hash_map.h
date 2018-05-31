#ifndef DATA_STRUCTURE_HASH_MAP_H
#define DATA_STRUCTURE_HASH_MAP_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int TABLE_SIZE = 128;

typedef struct TableList {
    struct TableList *next;
    string key;
    int value;
}TABLE_LIST;

unsigned hashFunction(string s)
{
    unsigned hash;

    for (int i = 0; i < s.length(); i++)
        hash = s[i] + 31*hash;
    return hash % TABLE_SIZE;
}

unsigned rehash(unsigned);


class HashMap
{
private:
    TABLE_LIST **table;
public:
    HashMap(){
        table = new TABLE_LIST*[TABLE_SIZE];
        for(int i=0; i < TABLE_SIZE; i++) table[i] = NULL;
    }

    ~HashMap() {
        for(int i=0; i<TABLE_SIZE; i++)
            if(table[i] != NULL) delete table[i];
        delete[] table;
    }


    TABLE_LIST* lookUp(string s)
    {
        TABLE_LIST *tp;
        for(tp=table[hashFunction(s)]; tp!=NULL; tp=tp->next)
        {
            if((tp->key).compare(s) == 0) return tp;
        }
        return NULL;
    }

    void put(string key, int value)
    {
        TABLE_LIST *tp;
        unsigned  hash;

        if(!(tp = lookUp(key))) {
            tp = new TABLE_LIST;
            tp->key = key;
            tp->value = value;
            hash = hashFunction(key);
            tp->next = table[hash];
            table[hash] = tp;
        } else {
            tp->key = key;
            tp->value = value;
            hash = hashFunction(key);
            table[hash] = tp;
        }
    }

    void showMap()
    {
        TABLE_LIST *tp;
        for(int i=0; i<TABLE_SIZE; i++)
        {
            tp = table[i];
            if(tp)
                cout << "table[" << i << "] " << tp->key << "(" << tp->value << ")";
            else
                continue;

            while(tp)
            {
                cout << "->" << tp->key << "(" << tp->value << ")";
                tp = tp->next;
            }
            cout << endl;
        }
    }
};

#endif //DATA_STRUCTURE_HASH_MAP_H
