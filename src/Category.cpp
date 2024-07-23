//
// Created by Harrison Baker on 7/19/24.
//
#include "../include/Category.h"



Category::Category(string Name, double TotalWeight)
{
    name = Name;
    totalWeight = TotalWeight;

}

string Category::getName()
{
	return name;
}
double Category::getTotalWeight()
{
	return totalWeight;
}



vector<Assignment> Category::getAssignments()
{
    return assignments;
}

int Category::getNumberOfAssignmentsCompleted()
{
    int numOfAssignmentsCompleted = 0;
    for (Assignment assignment : assignments)
    {
        if (assignment.getIsCompleted())
        {
            numOfAssignmentsCompleted++;
        }
    }

    return numOfAssignmentsCompleted;
}


int Category::getNumberOfAssignmentsRemaining()
{
    int numOfAssignmentsRemaining = 0;
    for (Assignment assignment : assignments)
    {
        if (!assignment.getIsCompleted())
        {
            numOfAssignmentsRemaining++;
        }
    }

    return numOfAssignmentsRemaining;
}

void Category::addAssignment(Assignment assignment) {
    assignments.push_back(assignment);
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


void Category::setTotalPointsAchieved(double totalPoints)
{
	totalPointsAchieved = totalPoints;
}
void Category::setTotalPointsPossible(double totalPoints)
{
	totalPointsPossible = totalPoints;
}
double Category::getTotalPointsAchieved()
{
	return totalPointsAchieved;
}
double Category::getTotalPointsPossible()
{
	return totalPointsPossible;
}
