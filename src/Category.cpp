//
// Created by Harrison Baker on 7/19/24.
//
#include "../include/Category.h"



Category::Category(string &Name, double &TotalWeight)
{
    name = Name;
    totalWeight = TotalWeight;

}



vector<Assignment> Category::getAssignments()
{
    return assignments;
}


void Category::addAssignment(Assignment assignment) {

}

vector<Assignment> Category::getCompletedAssignments() {
	vector<Assignment> completedAssignments;

	for (Assignment assignment : assignments)
	{
		if (assignment.getIsCompleted())
		{
			completedAssignments.push_back(assignment);
		}
	}

	return completedAssignments;
}

double Category::getCurrentGrade() {
	return 0;
}

vector<Assignment> Category::getRemainingAssignments() {
	vector<Assignment> remainingAssignments;

	for (Assignment assignment : assignments)
	{
		if (!assignment.getIsCompleted())
		{
			remainingAssignments.push_back(assignment);
		}
	}

	return remainingAssignments;
}

double Category::getProjectedGrade() {
	return 0;
}

double Category::getPredictedGrade() {
	return 0;
}

void Category::editAssignment(string assignmentName, double newScore) {

}

