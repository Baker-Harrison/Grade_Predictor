//
// Created by Harrison Baker on 7/19/24.
//

#ifndef GRADE_PREDICTOR_FILEMANAGER_H
#define GRADE_PREDICTOR_FILEMANAGER_H

#include "Category.h"
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

using namespace std;

class FileManager
{

    static const string FILENAME;


public:
    static void addCategoryToFile( const string& categoryName, double totalWeight);
    static void addAssignmentToCategory( const string& categoryName, const json& newAssignment);
    static vector<Category> readCategoriesAndAssignments() ;
	// void writeAssignments(string fileName, vector<Category> categories);


};

#endif //GRADE_PREDICTOR_FILEMANAGER_H
