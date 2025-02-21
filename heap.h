#ifndef TREE_H
#define TREE_H


class maxHeap {
public:
    maxHeap();
    ~maxHeap();
    void add();
    void print();
    void printHelper(int index, int level);
    void addHelper(int value);
    void removeLargest();
    void removeAll();



private:
    int heap[101];
    int size;

};



#endif //TREE_H
