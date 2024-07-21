//
// Created by Harrison Baker on 7/19/24.
//
#include <fstream>
#include "../include/FileManager.h"

string FileManager::getCategoryNameFromText(const string& lineOfText)
{
	string category;
	int startPos = lineOfText.find('!');

	if (startPos != string::npos)
	{
		startPos++; // Move past the '!'
		for (size_t i = startPos; i < lineOfText.length(); ++i)
		{
			if (isblank(lineOfText[i]) || lineOfText[i] == '\0')
			{
				break;
			}
			category += lineOfText[i];
		}
	}

	return category;
}
double FileManager::getCategoryWeightFromText(string lineOfText)
{
	double totalWeight;
	totalWeight = 0;


	return totalWeight;
}



vector<Category> FileManager::readAssignments(const string FILENAME) {



    vector<Category> assignments;

    ifstream categoriesFile;
    categoriesFile.open(FILENAME);

	if (categoriesFile.is_open() == false)
	{
		cout << "invalid file" << endl;
		exit(0);
	}



    vector<Category> categories;


    string name;
	string line;
    double totalWeight;
    while (categoriesFile)
    {
		categoriesFile >> line;

	    name = getCategoryNameFromText(line);
		totalWeight = getCategoryWeightFromText(line);
		Category category (name, 0.05);
		categories.push_back(category);
    }



    categoriesFile.close();
	// return categories;

	return categories;
}

void FileManager::writeAssignments(string fileName, vector<Category> categories) {

}

