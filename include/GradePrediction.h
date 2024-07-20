//
// Created by Harrison Baker on 7/19/24.
//
#include "Category.h"
#include "Assignment.h"
#include <vector>

using namespace std;

#ifndef GRADE_PREDICTOR_GRADEPREDICTION_H
#define GRADE_PREDICTOR_GRADEPREDICTION_H

class GradePrediction
{
private:
	vector<Category> categories;

public:
	void readAssignmentsFromFile(string fileName);
	void addCategory(Category category);
	void addAssignmentToCategory(string categoryName, Assignment assigment);
	string getCategorySummary();
	string getCategoryDetails(string categoryName);
	void editAssignment(string categoryName, string assignmentName, double newScore);
	void saveGradesToFile(string fileName);


};



#endif //GRADE_PREDICTOR_GRADEPREDICTION_H
