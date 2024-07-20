//
// Created by Harrison Baker on 7/19/24.
//

#ifndef GRADE_PREDICTOR_ASSIGNMENT_H
#define GRADE_PREDICTOR_ASSIGNMENT_H

#include <iostream>

using namespace std;

class Assignment {
private:
	string name;
	double pointsAchieved;
	double pointsPossible;
	bool isCompleted;
	bool isEdited;
public:
	double getScore();
	bool getIsCompleted();
	bool getIsEdited();



	void setScore(double newScore);


};


#endif //GRADE_PREDICTOR_ASSIGNMENT_H
