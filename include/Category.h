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
	double totalPointsAchieved = 0;
	double totalPointsPossible = 0;
public:
    Category(string Name, double TotalWeight);
	string getName();
	double getTotalWeight();
    vector<Assignment> getAssignments();
    int getNumberOfAssignmentsCompleted();
    int getNumberOfAssignmentsRemaining();
	void addAssignment(Assignment assignment);

    double getCurrentGrade();

    double getProjectedGrade();

    void setTotalPointsAchieved(double totalPoints);
	void setTotalPointsPossible(double totalPoints);

    double getTotalPointsPossible();
	double calculatePredictedGrade();
};

#endif //GRADE_PREDICTOR_CATEGORY_H
