//
// Created by Harrison Baker on 7/19/24.
//
#include <fstream>
#include <iostream>
#include "../include/FileManager.h"
#include  <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;

const string FileManager::FILENAME = "C:\\Users\\thehe\\CLionProjects\\CPP\\Grade_Predictor\\src\\Text Files\\categories.json";

void FileManager::addCategoryToFile(const string& categoryName, double totalWeight) {
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


void FileManager::addAssignmentToCategory(const string& categoryName, const json& newAssignment) {
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
            category["assignments"].push_back(newAssignment);
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




vector<Category> FileManager::readCategoriesAndAssignments() {
    vector<Category> categories;

    ifstream categoriesFile(FILENAME);
    if (!categoriesFile.is_open()) {
        cout << "Invalid file" << endl;
        exit(0);
    }

    json jsonData;
    categoriesFile >> jsonData;

    // Read categories and assignments from JSON data
    for (const auto& categoryJson : jsonData["categories"]) {
        string categoryName = categoryJson["name"];
        double categoryWeight = categoryJson["totalWeight"];

        Category category(categoryName, categoryWeight);

        for (const auto& assignmentJson : categoryJson["assignments"]) {
            string assignmentName = assignmentJson["name"];
            double pointsAchieved = assignmentJson["pointsAchieved"];
            double pointsPossible = assignmentJson["pointsPossible"];
            bool isCompleted = assignmentJson["isCompleted"];
            bool isEdited = assignmentJson["isEdited"];

            Assignment assignment(assignmentName, pointsAchieved, pointsPossible, isCompleted, isEdited);
            category.addAssignment(assignment);
        }

        categories.push_back(category);
    }

    categoriesFile.close();
    return categories;
}




// void FileManager::writeAssignments(string fileName, vector<Category> categories)
// {}


