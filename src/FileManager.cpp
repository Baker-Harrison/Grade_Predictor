//
// Created by Harrison Baker on 7/19/24.
//
#include <fstream>
#include <iostream>
#include "../include/FileManager.h"
#include  <nlohmann/json.hpp>
#include <vector>
using namespace std;
using json = nlohmann::json;



void FileManager::addCategoryToFile(const string& FILENAME, const string& categoryName, double totalWeight) {
	fstream file(FILENAME, ios::in | ios::out | ios::binary);
	if (!file.is_open()) {
		cout << "Failed to open file" << endl;
		exit(0);
	}

	json jsonData;

	// Read existing data
	file.seekg(0, ios::end);
	if (file.tellg() > 0) {
		file.seekg(0, ios::beg);
		file >> jsonData;
	} else {
		// If the file is empty, initialize jsonData as an empty object
		jsonData = json::object();
		jsonData["categories"] = json::array();
	}

	// Create new category JSON object
	json newCategory;
	newCategory["name"] = categoryName;
	newCategory["totalWeight"] = totalWeight;
	newCategory["assignments"] = json::array();  // Initialize with an empty array

	// Add new category to the JSON data
	jsonData["categories"].push_back(newCategory);

	// Move to the beginning of the file to overwrite it
	file.clear();  // Clear EOF flag if set
	file.seekp(0, ios::beg);
	file << setw(4) << jsonData << endl;  // Pretty print with an indentation of 4 spaces

	file.close();
}




void FileManager::addAssignmentToCategory(const string& FILENAME, const string& categoryName, const Assignment& newAssignment) {
	fstream file(FILENAME, ios::in | ios::out | ios::binary);
	if (!file.is_open()) {
		cout << "Failed to open file" << endl;
		exit(0);
	}

	json jsonData;

	// Read existing data
	file.seekg(0, ios::end);
	if (file.tellg() > 0) {
		file.seekg(0, ios::beg);
		file >> jsonData;
	} else {
		// If the file is empty, initialize jsonData as an empty object
		jsonData = json::object();
		jsonData["categories"] = json::array();
	}

	// Find the target category and add the assignment
	bool categoryFound = false;
	for (auto& category : jsonData["categories"]) {
		if (category["name"] == categoryName) {
			json assignmentJson = {
					{"name", newAssignment.getName()},
					{"pointsAchieved", newAssignment.getPointsAchieved()},
					{"pointsPossible", newAssignment.getPointsPossible()},
					{"isCompleted", newAssignment.getIsCompleted()},
					{"isEdited", newAssignment.getIsEdited()}
			};
			category["assignments"].push_back(assignmentJson);
			categoryFound = true;
			break;
		}
	}

	if (!categoryFound) {
		cout << "Category not found" << endl;
		file.close();
		return;
	}

	// Move to the beginning of the file to overwrite it
	file.clear();  // Clear EOF flag if set
	file.seekp(0, ios::beg);
	file << setw(4) << jsonData << endl;  // Pretty print with an indentation of 4 spaces

	file.close();
}






vector<Category> FileManager::readCategoriesAndAssignments(const string& FILENAME) {
    vector<Category> categories;

    ifstream categoriesFile(FILENAME);
    if (!categoriesFile.is_open()) {
        cout << "Invalid file" << endl;
        return categories;
    }

    json jsonData;
    categoriesFile >> jsonData;

    // Check if the JSON object is an object
    if (!jsonData.is_object()) {
        cout << "Invalid JSON data" << endl;
        return categories;
    }

    // Read categories and assignments from JSON data
    if (jsonData.contains("categories")) {
        const json& categoriesArray = jsonData["categories"];
        if (categoriesArray.is_array()) {
            for (const auto& categoryJson : categoriesArray) {
                if (categoryJson.is_object()) {
                    string categoryName = categoryJson["name"];
                    double categoryWeight = categoryJson["totalWeight"];

                    Category category(categoryName, categoryWeight);

                    if (categoryJson.contains("assignments")) {
                        const json& assignmentsArray = categoryJson["assignments"];
                        if (assignmentsArray.is_array()) {
                            for (const auto& assignmentJson : assignmentsArray) {
                                if (assignmentJson.is_object()) {
                                    string assignmentName = assignmentJson["name"];
                                    double pointsAchieved = assignmentJson["pointsAchieved"];
                                    double pointsPossible = assignmentJson["pointsPossible"];
                                    bool isCompleted = assignmentJson["isCompleted"];
                                    bool isEdited = assignmentJson["isEdited"];

                                    Assignment assignment(assignmentName, pointsAchieved, pointsPossible, isCompleted, isEdited);
                                    category.addAssignment(assignment);
                                }
                            }
                        }
                    }

                    categories.push_back(category);
                }
            }
        }
    }

    categoriesFile.close();
    return categories;
}




void FileManager::editAssignment(std::string fileName, Category category, std::string assignmentName, double newScore, string newAssignmentName, bool isCompleted)
{
	std::ifstream inFile(fileName);
	json j;

	if (!inFile) {
		std::cerr << "Unable to open file " << fileName << std::endl;
		return;
	}

	inFile >> j;
	inFile.close();

	bool foundCategory = false;
	bool foundAssignment = false;

	for (auto& cat : j["categories"]) {
		if (cat["name"] == category.getName()) {

			foundCategory = true;
			for (auto& assignment : cat["assignments"]) {
				if (assignment["name"] == assignmentName) {
					if (assignment["pointsPossible"] < newScore) {
						cout << "Invalid score" << endl;
						return;
					}
					assignment["pointsAchieved"] = newScore;
					assignment["name"] = newAssignmentName;
					assignment["isCompleted"] = isCompleted;
					assignment["isEdited"] = true;
					foundAssignment = true;
					break;
				}
			}
			break;
		}
	}

	if (!foundCategory) {
		std::cerr << "Category " << category.getName() << " not found in file " << fileName << std::endl;
		return;
	}

	if (!foundAssignment) {
		std::cerr << "Assignment " << assignmentName << " not found in category " << category.getName() << std::endl;
		return;
	}

	std::ofstream outFile(fileName);
	outFile << j.dump(4);  // Pretty print with 4-space indentation
	outFile.close();
}


