//
// Created by Harrison Baker on 7/19/24.
//

#include "../include/Assignment.h"

double Assignment::getScore() {
	return pointsAchieved;
}

void Assignment::setScore(double newScore) {
	pointsAchieved = newScore;
}

bool Assignment::getIsCompleted() {
	return isCompleted;
}

bool Assignment::getIsEdited() {
	return isEdited;
}
