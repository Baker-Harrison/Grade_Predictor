//
// Created by Harrison Baker on 7/19/24.
//

#ifndef GRADE_PREDICTOR_CONSOLEMANAGER_H
#define GRADE_PREDICTOR_CONSOLEMANAGER_H

#include "Category.h"
#include "FileManager.h"
#include "Assignment.h"

class ConsoleManager
{
public:
	void displayCategorySummary();
	void printCategories();
	void displayCategoryDetails();
	void createNewCategory();
	void createNewAssignment();
	void editAssignment();

	void menu();
	FileManager manager;
	vector<Category> categories = manager.readCategoriesAndAssignments(manager.FILENAME);
};


#endif //GRADE_PREDICTOR_CONSOLEMANAGER_H


