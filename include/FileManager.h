//
// Created by Harrison Baker on 7/19/24.
//

#ifndef GRADE_PREDICTOR_FILEMANAGER_H
#define GRADE_PREDICTOR_FILEMANAGER_H

#include "Category.h"
#include <vector>

using namespace std;

class FileManager
{

public:
	vector<Category> readAssignments(string fileName);
	void writeAssignments(string fileName, vector<Category> categories);
    string getCategoryNameFromText(const string& lineOfText);
    double getCategoryWeightFromText(string lineOfText);

};

#endif //GRADE_PREDICTOR_FILEMANAGER_H
