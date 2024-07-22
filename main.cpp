#include <iostream>
#include "include/FileManager.h"
#include "include/Category.h"
#include "include/ConsoleManager.h"
#include <vector>

using namespace std;
int main() {


    FileManager manager;

    ConsoleManager console;



	vector<Category> categories = manager.readCategoriesAndAssignments(manager.FILENAME);


    cout << "Number of categories: " << categories.size() << endl;
	console.displayCategorySummary(categories);

	return 0;
}
