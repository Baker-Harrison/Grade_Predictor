//
// Created by Harrison Baker on 7/19/24.
//

#include "../include/Assignment.h"
Assignment::Assignment(string Name, double PointsAchieved, double PointsPossible, bool IsCompleted, bool IsEdited)
{
    name = Name;
    pointsAchieved = PointsAchieved;
    pointsPossible = PointsPossible;
    isCompleted = IsCompleted;
    isEdited = IsEdited;
}

string Assignment::getName() const
{
    return name;
}
double Assignment::getPointsAchieved() const
{
    return pointsAchieved;
}
double Assignment::getPointsPossible() const
{
    return pointsPossible;
}


double Assignment::getScore() const {
	return pointsAchieved;
}

bool Assignment::getIsCompleted() const
{
    return isCompleted;
}
bool Assignment::getIsEdited() const
{
    return isEdited;
}

void Assignment::setScore(double newScore) {
	pointsAchieved = newScore;
}




