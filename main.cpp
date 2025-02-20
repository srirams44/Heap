#include <iostream>
using namespace std;

int main() {

    char input[100];
    cout << "What would you like to do?(ADD/REMOVELARGEST/REMOVEALL/PRINT): " << cin.getline(input, 100);
    if (strcasecmp(input, "ADD") == 0) {
        //Run the add function
    }
    else if (strcasecmp(input, "REMOVELARGEST") == 0) {
        //Run the remove largest function
    }
    else if (strcasecmp(input, "REMOVEALL") == 0) {
        //Run the remove all function
    }
    else if (strcasecmp(input, "PRINT") == 0) {
        //Run the print function
    }
    else if (strcasecmp(input, "QUIT") == 0) {
        cout << "Thank you!" << endl;
    }
}