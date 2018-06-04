#ifndef C_PLUS_PLUS_MERGE_SORT_H
#define C_PLUS_PLUS_MERGE_SORT_H

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> vec)
{
    for(int i=0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";

    }
    cout << endl;
}


vector<int> merge(vector<int> left, vector<int> right)
{
    vector<int> result;

    while((int)left.size() > 0 || (int) right.size() >0)
    {
        if((int)left.size() > 0 && (int) right.size() > 0)
        {
            if((int)left.front() <= (int)right.front()){
                result.push_back((int)left.front());
                left.erase(left.begin());
            } else {
                result.push_back((int)right.front());
                right.erase(right.begin());
            }
        } else if ((int)left.size() > 0) {
            for(int i=0; i < (int)left.size(); i++)
            {
                result.push_back((int)left[i]);
            }
            break;
        } else if ((int)right.size() > 0) {
            for(int i=0; i < (int)right.size(); i++)
            {
                result.push_back((int)right[i]);
            }
            break;
        }
    }
    return result;
}

/*
 * Merge sort Average nlogn, Worst nlogn, Memory depends, stable
 * */
vector<int> mergeSort(vector<int> m){
    if(m.size() <= 1)
    {
        return m;
    }

    vector<int> left, right, result;

    int middle = ((int)m.size() + 1)/2;

    for(int i=0; i<middle; i++)
    {
        left.push_back(m[i]);
    }

    for(int i=middle; i < (int)m.size(); i++)
    {
        right.push_back(m[i]);
    }

    left = mergeSort(left);
    right = mergeSort(right);
    result = merge(left, right);

    return result;
}

#endif //C_PLUS_PLUS_MERGE_SORT_H
