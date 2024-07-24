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
    Assignment(string Name, double PointsAchieved, double PointsPossible, bool IsCompleted, bool IsEdited);
    string getName() const;
    double getPointsAchieved() const;
    double getPointsPossible() const;
	double getScore() const;
	bool getIsCompleted() const;
	bool getIsEdited() const;




	void setScore(double newScore);
	void setName(string newName);
	void setIsEdited(bool newIsEdited);
	void setIsCompleted(bool newIsCompleted);



};


#endif //GRADE_PREDICTOR_ASSIGNMENT_H
