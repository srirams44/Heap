#include <iostream>
#include "heap.h"

using namespace std;

int main() {
    maxHeap myHeap;

    while (true) {
        char input[100] = "";
        cout << "What would you like to do?(ADD/REMOVELARGEST/REMOVEALL/PRINT): " ;
        cin.getline(input, 100);
        if (strcasecmp(input, "ADD") == 0) {
            //Run the add function
            myHeap.add();
        }
        else if (strcasecmp(input, "REMOVELARGEST") == 0) {
            //Run the remove largest function
            myHeap.removeLargest();
        }

        else if (strcasecmp(input, "REMOVEALL") == 0) {
            //Run the remove all function
            return 0;
        }
        else if (strcasecmp(input, "PRINT") == 0) {
            //Run the print function
        }
        else if (strcasecmp(input, "QUIT") == 0) {
            cout << "Thank you!" << endl;
            return 0;
        }
    }
}