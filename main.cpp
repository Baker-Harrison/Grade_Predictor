#include <iostream>
#include "include/FileManager.h"

using namespace std;
int main() {


    FileManager manager;

    string category = manager.getCategoryNameFromText("vnueguguergjgrtnbu!Homework");

    cout << "Category: " << category << endl;

    cout << "Hello, World!" << std::endl;

	return 0;
}
