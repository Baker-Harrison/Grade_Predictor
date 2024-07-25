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

double Category::getCurrentGrade() {
	for (Assignment assignment : assignments)
	{
		totalPointsAchieved += assignment.getPointsAchieved();
		totalPointsPossible += assignment.getPointsPossible();
	}
	return (totalPointsAchieved / totalPointsPossible) * 100;
}

double Category::getProjectedGrade() {
	double totalPointsAchieved = 0.0;
	double totalPointsPossible = 0.0;
	double totalProjectedPoints = 0.0;
	int completedAssignments = 0;

	// Calculate the total points achieved and possible for completed assignments
	for (const Assignment& assignment : assignments) {
		if (assignment.getIsCompleted()) {
			totalPointsAchieved += assignment.getPointsAchieved();
			totalPointsPossible += assignment.getPointsPossible();
			completedAssignments++;
		}
	}

	// Calculate the average score of the completed assignments
	double averageScore = (completedAssignments > 0) ? (totalPointsAchieved / totalPointsPossible) : 0.0;

	// Calculate the projected points for remaining assignments based on the average score
	for (Assignment& assignment : assignments) {
		if (!assignment.getIsCompleted()) {
			assignment.setScore(assignment.getPointsPossible() * averageScore);
			totalProjectedPoints += assignment.getPointsAchieved();
			totalPointsPossible += assignment.getPointsPossible();
		} else {
			totalProjectedPoints += assignment.getPointsAchieved();
		}
	}

	// Return the projected grade as a percentage
	return (totalProjectedPoints / totalPointsPossible) * 100.0;
}


double Category::calculatePredictedGrade() {
	double totalProjectedPoints = 0.0;
	int completedAssignments = 0;

	// Calculate the total points achieved and possible for completed assignments
	for (const Assignment& assignment : assignments) {
		if (assignment.getIsCompleted()) {
			totalPointsAchieved += assignment.getPointsAchieved();
			totalPointsPossible += assignment.getPointsPossible();
			completedAssignments++;
		}
	}

	// Calculate the average score of the completed assignments
	double averageScore = (completedAssignments > 0) ? (totalPointsAchieved / totalPointsPossible) : 0.0;

	// Calculate the projected points for remaining assignments based on the average score
	for (Assignment& assignment : assignments) {
		if (!assignment.getIsCompleted()) {
			assignment.setScore(assignment.getPointsPossible() * averageScore);
			totalProjectedPoints += assignment.getPointsAchieved();
			totalPointsPossible += assignment.getPointsPossible();
		} else {
			totalProjectedPoints += assignment.getPointsAchieved();
		}
	}

	// Return the predicted grade as a percentage



	return (totalProjectedPoints / totalPointsPossible) * 100.0;
}


void Category::setTotalPointsAchieved(double totalPoints)
{
	totalPointsAchieved = totalPoints;
}
void Category::setTotalPointsPossible(double totalPoints)
{
	totalPointsPossible = totalPoints;
}

double Category::getTotalPointsPossible()
{
	return totalPointsPossible;
}

