#include <iostream>
#include "include/FileManager.h"
#include "include/Category.h"

using namespace std;
int main() {


    FileManager manager;

    string category = manager.getCategoryNameFromText("vnueguguergjgrtnbu!Homework");

    cout << "Category: " << category << endl;

    cout << "Hello, World!" << std::endl;

	vector<Category> categories = manager.readAssignments("/Users/harrisonbaker/CLionProjects/Grade_Predictor/src/Text Files/categories.txt");

	for (Category category: categories)
	{
		cout << category.getName() << endl;
	}

	return 0;
}
