#ifndef TREE_H
#define TREE_H


class maxHeap {
public:
    maxHeap();
    ~maxHeap();
    void add();
    void addHelper(int value);
    void removeLargest();


private:
    int heap[101];
    int size;

};



#endif //TREE_H
