//
// Created by Harrison Baker on 7/19/24.
//

#ifndef GRADE_PREDICTOR_CONSOLEMANAGER_H
#define GRADE_PREDICTOR_CONSOLEMANAGER_H

#include "Category.h"

class ConsoleManager
{
	void displayCategorySummary(vector<Category> categories);
	void displayCategoryDetails(Category category);
	string getUserInput(string prompt);
};


#endif //GRADE_PREDICTOR_CONSOLEMANAGER_H

void ConsoleManager::displayCategorySummary(vector<Category> categories) {

}

void ConsoleManager::displayCategoryDetails(Category category) {

}

string ConsoleManager::getUserInput(string prompt) {
	return std::string();
}
