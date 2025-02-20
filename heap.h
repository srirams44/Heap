#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <cmath>

using namespace std;

class maxHeap {
public:
    maxHeap();
    ~maxHeap();
    void ADD(int value);


private:
    int heap[101];
    int size;

};



#endif //TREE_H
