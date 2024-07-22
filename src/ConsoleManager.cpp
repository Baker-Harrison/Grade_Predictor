//
// Created by Harrison Baker on 7/19/24.
//



#include "../include/ConsoleManager.h"
// include the FileeManager header file

#include "../include/FileManager.h"






//void ConsoleManager::displayWelcomeMessage() {
//    cout << "Welcome to Grade Predictor" << endl;
//}

void ConsoleManager::displayCategorySummary(vector<Category> categories) {
    for (Category category : categories) {
        cout << "------------------------------------" << endl;
        cout << "Category Name: " << category.getName() << endl;
        cout << "Total Weight: " << category.getTotalWeight() << endl;
        cout << "Assignments Completed: " << category.getNumberOfAssignmentsCompleted() << endl;
        // get current grade
        cout << "Assignments Remaining: " << category.getNumberOfAssignmentsRemaining() << endl;
        cout << "------------------------------------" << endl;
    }
}

void ConsoleManager::displayCategoryDetails(Category category) {

}

string ConsoleManager::getUserInput(string prompt) {
    return std::string();
}