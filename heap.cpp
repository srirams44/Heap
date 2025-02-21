#include "heap.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

maxHeap::maxHeap() { //Constructor
    size = 0;
}

maxHeap::~maxHeap() { //Destructor (nothing really needs to be deleted)
    size = 0;
}

void maxHeap::add() {
    //add function that reads in a value to insert into the max heap
    char input[100] = "";
    if (size >= 100) { //If the heap already has 100 elements
        cout << "Heap is full." << endl;
        return;
    } //If the heap is full no point in asking how to add
    cout << "Would you like to add from file or manually? (File/Man): " ;
    cin.getline(input, 100);
    if (strcasecmp(input, "File") == 0) {
        //Access the file with the filepath provided
        //The file should have numbers seperated by a space, and should be read in one by one
        char filepath[100] = "";
        cout << "Please enter the filepath exactly: " ;
        cin.getline(filepath, 100);
        ifstream file(filepath); //Open the file
        if (!file) {
            cout << "Error opening file. " << filepath << endl;
            return;
        }
        int num;
        while (file >> num) { //Read numbers one by one
            addHelper(num);
        }
        file.close(); //Close the file
    }
    else if (strcasecmp(input, "Man") == 0 or strcasecmp(input, "Manual") == 0){
        //Read in each number seperated by a space then deal with it one by one
        cout << "Please enter numbers seperated by a space between 1 and 1000, do not exceed 100 numbers." << endl;
        int num;
        while (cin >> num) { //Read the numbers one by one
            addHelper(num); //Add to the heap
            if (cin.peek() == '\n') { //If the next number is a newline character, break.
                break;
            }
        }
        cin.ignore();
    }
}


void maxHeap::addHelper(int value) {
    heap[size + 1] = value; //Add the new element at the next blank spot
    ++size; //Increment size since we now have something
    //Next we must heapify, which means to adjust the heap to ensure the max heap property is maintained
    //The following conditions must hold heap[i] >= heap[2*i] and heap[i] >= heap[2*i+1] (left and right child respectively)
    int current = size;
    while (current > 1) {
        int parent = current / 2;
        if (heap[current] > heap[parent]) { //If the current element is greater than its parent, swap them
            int temp = heap[current];
            heap[current] = heap[parent];
            heap[parent] = temp;

            current = parent; //Move up to the parent
        }
        else { //This is if the current element is smaller than the parent
            break;
        }
    }
}


void maxHeap::removeLargest() {
    int parent = heap[1];
    if (size == 0) {
        cout << "Heap is empty." << endl;
        return;
    }

    cout << "Removed: " << parent << endl;

    if (size == 1) {
        size = 0; //Setting size to 0 can help us when doing checks for function like print, so we dont accidentally print something left over when we are trying to treat it like the heap is empty.
        return;
    }

    //Set the last element in the heap to the first, and reduce the size, essentially removing the first element
    heap[1] = heap[size];
    --size;
    //After these steps you have to heapify again to ensure the max heap property is taken
    int index = 1;
    while (true) {
        int leftChild = 2 * index;
        int rightChild = 2 * index + 1;
        int largest = index;

        if (leftChild <= size && heap[leftChild] > heap[largest]) { //If the left child is larger
            largest = leftChild;
        }
        else if (rightChild <= size && heap[rightChild] > heap[largest]) { //If the right child is larger
            largest = rightChild;
        }
        if (largest == index) { //If both are smaller
            break;
        }

        int temp = heap[index]; //Swap parent with larger child
        heap[index] = heap[largest];
        heap[largest] = temp;

        index = largest; //Move down to the new index
    }
}