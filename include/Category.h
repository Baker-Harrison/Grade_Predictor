//
// Created by Harrison Baker on 7/19/24.
//

#include <iostream>
#include "Assignment.h"
#include <vector>

using namespace std;

#ifndef GRADE_PREDICTOR_CATEGORY_H
#define GRADE_PREDICTOR_CATEGORY_H

class Category
{
private:
	string name;
	double totalWeight;
	vector<Assignment> assignments;
public:
    Category(string &Name, double &TotalWeight);
    vector<Assignment> getAssignments();
	void addAssignment(Assignment assignment);
	vector<Assignment> getCompletedAssignments();
	double getCurrentGrade();
	vector<Assignment> getRemainingAssignments();
	double getProjectedGrade();
	double getPredictedGrade();
	void editAssignment(string assignmentName, double newScore);

};

#endif //GRADE_PREDICTOR_CATEGORY_H
