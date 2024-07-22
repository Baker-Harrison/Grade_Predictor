#include <iostream>
#include "include/FileManager.h"
#include "include/Category.h"
#include <vector>

using namespace std;
int main() {


    FileManager manager;





	vector<Category> categories = FileManager::readCategoriesAndAssignments();

    FileManager::addCategoryToFile( "Test Category", 0.1);
    FileManager::addAssignmentToCategory( "Test Category", "Test Assignment");

    cout << "Number of categories: " << categories.size() << endl;
	for (Category category: categories)
	{
		cout << "Category Name: " << category.getName() << endl;
        cout << "Category Weight: " << category.getTotalWeight() << endl;



	}

	return 0;
}
