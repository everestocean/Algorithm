#ifndef DATA_STRUCTURE_HASH_MAP_1_H
#define DATA_STRUCTURE_HASH_MAP_1_H

#include <iostream>

using namespace std;

class HashEntry
{
private:
    int key;
    int value;
public:
    HashEntry(int key, int value){
        this->key = key;
        this->value = value;
    }

    int getKey()
    {
        return key;
    }

    int getValue()
    {
        return value;
    }
};


const int TABLE_SIZE = 5;

unsigned hashFunction(int key){
    return key % TABLE_SIZE;
}

unsigned rehash(unsigned hash)
{
    return (hash + 1) % TABLE_SIZE;
}

class HashMap1 {
private:
    HashEntry **table;

public:
    HashMap1(){
        table = new HashEntry* [TABLE_SIZE];
        for(int i=0; i<TABLE_SIZE; i++)
        {
            table[i] = NULL;
        }
    }

    int get(int key)
    {
        unsigned hash = hashFunction(key);

        while(table[hash] != NULL && table[hash]->getKey()!= key) {
                hash = rehash(hash);
        }
        if(table[hash] == NULL)
            return -1;
        else
            return table[hash]->getValue();
    }

    void put(int key, int value)
    {
        unsigned hash = hashFunction(key);

        int hashCount = 0;

        if(table[hash] != NULL)
        {
            while(table[hash] != NULL && table[hash]->getKey() != key)
            {
                hash = rehash(hash);

                // no found, give up
                if(hashCount++ == TABLE_SIZE) break;

            }
        }

        // some hash, delete the old one and make a new one
        if(table[hash] != NULL)
            delete table[hash];

        table[hash] = new HashEntry(key, value);
    }

    ~HashMap1(){
        for(int i = 0; i < TABLE_SIZE; i++)
        {
            if(table[i] != NULL)
                delete table[i];
        }
        delete[] table;
    }
};

#endif //DATA_STRUCTURE_HASH_MAP_1_H
