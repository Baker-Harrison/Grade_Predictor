//
// Created by Harrison Baker on 7/19/24.
//

#ifndef GRADE_PREDICTOR_FILEMANAGER_H
#define GRADE_PREDICTOR_FILEMANAGER_H

#include "Category.h"
#include <vector>
#include <nlohmann/json.hpp>
#include "Assignment.h"

using json = nlohmann::json;

using namespace std;

class FileManager
{




public:
    const string FILENAME = "/Users/harrisonbaker/CLionProjects/Grade_Predictor/src/Text Files/categories.json";


    void addCategoryToFile(const string& FILENAME, const string& categoryName, double totalWeight);
    void addAssignmentToCategory(const string& FILENAME, const string& categoryName, const Assignment& newAssignment);
    vector<Category> readCategoriesAndAssignments(const string& FILENAME) ;
	void editAssignment(string fileName, Category category, string assignmentName, double newScore, string newAssignmentName, bool isCompleted);


};

#endif //GRADE_PREDICTOR_FILEMANAGER_H
