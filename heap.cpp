#include "heap.h"

maxHeap::maxHeap() { //Constructor
    size = 0;
}

maxHeap::~maxHeap() { //Destructor (nothing really needs to be deleted)
    size = 0;
}

void maxHeap::ADD(int value) { //add function that reads in a value to insert into the max heap
    char input[100];
    if (size >= 100) { //If the heap already has 100 elements
        cout << "Heap is full." << endl;
        return;
    } //If the heap is full no point in asking how to add
    cout << "Would you like to add from file or manually? (File/Man): " << cin.getline(input, 100);
    if (strcasecmp(input, "File") == 0) {
        char filepath[100];
        cout << "Please enter the filepath exactly: " << cin.getline(filepath, 100);
        //Access the file with the filepath provided
        //The file should have numbers seperated by a space, and should be read in one by one
    }
    else if (strcasecmp(input, "Man") == 0 or strcasecmp(input, "Manual") == 0){
        //Read in each number seperated by a space then deal with it one by one
    }
    heap[size] = value; //Add the new element at the next blank spot
    ++size; //Increment size since we now have something

    //Next we must heapify, which means to adjust the heap to ensure the max heap property is maintained
    //The following conditions must hold heap[i] >= heap[2*i] and heap[i] >= heap[2*i+1] (left and right child respectively)


}