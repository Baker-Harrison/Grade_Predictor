//
// Created by Harrison Baker on 7/19/24.
//



#include "../include/ConsoleManager.h"
#include "unistd.h"
// include the FileManager header file


#include "../include/GradePrediction.h"






//void ConsoleManager::displayWelcomeMessage() {
//    cout << "Welcome to Grade Predictor" << endl;
//}

void ConsoleManager::displayCategorySummary() {

    for (Category category : categories) {
        cout << "------------------------------------" << endl;
        cout << "Category Name: " << category.getName() << endl;
        cout << "Total Weight: " << category.getTotalWeight() << endl;
        cout << "Assignments Completed: " << category.getNumberOfAssignmentsCompleted() << endl;
	    cout << "Grade: " << category.getCurrentGrade() << "%" << endl;
        cout << "Assignments Remaining: " << category.getNumberOfAssignmentsRemaining() << endl;
		cout << "Projected Grade on remaining assignments: " << category.getProjectedGrade() << "%" << endl;


    }
	cout << "------------------------------------" << endl;
	cout << "Class Predicted Grade: " <<  GradePrediction::getTotalPredictedGrade(categories) << "%" << endl;
	cout << "------------------------------------" << endl;
}

void ConsoleManager::printCategories()
{
	int counter = 1;
	for (Category category: categories)
	{
		cout << counter << ". " << category.getName() << endl;
		counter++;
	}
}

void ConsoleManager::createNewCategory()
{
	string category;
	double weight;
	cout << "Enter the name for a new category";
	cin >> category;
	cout << "Enter a weight for the category";
	cin >> weight;

	manager.addCategoryToFile(manager.FILENAME, category, weight);

}

void ConsoleManager::createNewAssignment() {
	string name;
	double pointsPossible;

	// Get assignment name
	cout << "Enter an assignment name and the points possible(separated by a space): ";
	cin >> name >> pointsPossible;
	cout << endl;

	// Get points possible as a string and convert to double



	// Create the assignment
	Assignment assignment(name, 0, pointsPossible, false, false);

	// Print categories and get category name
	printCategories();
	string categoryName;
	cout << "Which category is this going into: ";
	cin >> categoryName;

	// Check if the category exists and add the assignment if it does
	bool categoryFound = false;
	for (Category category : categories) {
		if (categoryName == category.getName()) {
			manager.addAssignmentToCategory(manager.FILENAME, categoryName, assignment);
			categoryFound = true;
			cout << "Assignment added to category: " << categoryName << endl;
			break;
		}
	}

	// Provide feedback if the category was not found
	if (!categoryFound) {
		cout << "Category not found!" << endl;
	}
}


void ConsoleManager::displayCategoryDetails()
{
	string selection;
	printCategories();
	cout << "Enter a category: ";
	cin >> selection;
	cout << "------------------------------------" << endl;
	for (Category category: categories)
	{
		if (selection == category.getName() )
		{
			cout << "------------------------------------" << endl;
			cout << "Category Name: " << category.getName() << endl;
			int counter = 1;
			double totalPointsAchieved = 0;
			double totalPointsPossible = 0;
			for (const Assignment &assignment: category.getAssignments())
			{
				cout << "------------------------------------" << endl;
				cout << counter << ". " << endl;
				cout << "Assignment Name: " << assignment.getName() << endl;
				cout <<  "Grade: " << assignment.getGrade()<< "%" << endl;
				cout << "Edited: " << (assignment.getIsEdited() ? "Yes" : "No") << endl;
				cout << "Completed: " << (assignment.getIsCompleted() ? "Yes" : "No") << endl;
				totalPointsPossible += assignment.getPointsPossible();
				totalPointsAchieved += assignment.getPointsAchieved();

				counter++;
			}
			category.setTotalPointsAchieved(totalPointsAchieved);
			category.setTotalPointsPossible(totalPointsPossible);
			cout << "------------------------------------" << endl;
			cout << "Total points: " << category.getTotalPointsPossible() << endl;
			cout << "Unfinished assignments: " << category.getNumberOfAssignmentsRemaining() << endl;
			cout << "Expected score on unfinished assignments: " << category.getProjectedGrade() << "%" << endl;
			cout << "Predicted Final category Grade: " << category.calculatePredictedGrade() << "%" << endl;



			break;
		}
	}

	cout << endl;
}


void ConsoleManager::editAssignment()
{
	printCategories();

	string selection;
	cout << "Enter a category: ";
	cin >> selection;
	cout << "------------------------------------" << endl;
	for (Category category: categories)
	{
		if (selection == category.getName() )
		{
			cout << "------------------------------------" << endl;
			cout << "Category Name: " << category.getName() << endl;
			int counter = 1;
			for (const Assignment &assignment: category.getAssignments())
			{
				cout << "------------------------------------" << endl;
				cout << counter << ". " << endl;
				cout << "Assignment Name: " << assignment.getName() << endl;
				cout <<  "Grade: " << assignment.getGrade()<< "%" << endl;
				cout << "Edited: " << (assignment.getIsEdited() ? "Yes" : "No") << endl;
				cout << "Completed: " << (assignment.getIsCompleted() ? "Yes" : "No") << endl;
				counter++;

			}
			string assignmentName;
			cout << "Enter the name of the assignment you want to edit: ";
			cin >> assignmentName;
			for (Assignment assignment: category.getAssignments())
			{
				if (assignmentName == assignment.getName())
				{
					cout << "Total score possible: " << assignment.getPointsPossible() << endl;
					cout << "Enter the new score: ";
					double newScore;
					cin >> newScore;

					//  add an option to edit the name of the assignment
					string newName;
					cout << "Enter a new name for the assignment or enter none to keep the old name: ";

					cin >> newName;
					if (newName != "none") {
						assignment.setName(newName);
					}
					else{
                        newName = assignment.getName();
                    }
					// add an option to set complete
					char isCompleted;
					cout << "is the assignment completed? (y/n): ";

					cin >> isCompleted;
					if (isCompleted == 'y')
					{
						assignment.setIsCompleted(true);
					}


					manager.editAssignment(manager.FILENAME, category, assignmentName, newScore, newName, isCompleted);

				}
			}
			break;
		}
	}
}



void ConsoleManager::menu() {
	char selection;
	cout << "Choose an option from the menu:" << endl
			<< "1. Display category summary" << endl
			<< "2. Display Category details" << endl
			<< "3. Add new category" << endl
			<< "4. Add new assignment" << endl
			<< "5. edit assignment" << endl
			<< "6  exit" << endl;
	cin >> selection;
	if (selection == '1')
	{
		displayCategorySummary();
		sleep(2);
		menu();
	}
	else if (selection == '2')
	{
		displayCategoryDetails();
		sleep(2);
		menu();
	}
	else if (selection == '3')
	{
		createNewCategory();
		sleep(2);
		menu();
	}
	else if (selection == '4')
	{
		// Assignment(string Name, double PointsAchieved, double PointsPossible, bool IsCompleted, bool IsEdited);
		createNewAssignment();
		sleep(2);
		menu();

	}
	else if (selection == '5')
	{
		editAssignment();
		menu();
	}
	else if (selection == '6')
	{
		cout << "Thank you for using the grade predictor" << endl;
		exit(0);
	}

}