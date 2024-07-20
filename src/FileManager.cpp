//
// Created by Harrison Baker on 7/19/24.
//
#include <fstream>
#include "../include/FileManager.h"

string FileManager::getCategoryNameFromText(const string& lineOfText)
{
    string category;
    for (char character : lineOfText)
    {
        if (character == '!')
        {
            // cout << "Found precursor" << endl;
            const char* iterator = &character;
            int counter = 1;
            while (!isblank(*(iterator + counter)) && *(iterator + counter) != '\0')
            {
                category += *(iterator + counter);
                counter++;
            }
            break;
        }
    }

    return category;
}
double FileManager::getCategoryWeightFromText(string lineOfText)
{

}



vector<Category> FileManager::readAssignments(const string FILENAME) {



    vector<Category> assignments;

    ifstream categoriesFile;
    categoriesFile.open(FILENAME);



    vector<Category> categories;


    string name;
    double totalWeight;
    while (categoriesFile)
    {

    }



    categoriesFile.close();
	// return categories;
}

void FileManager::writeAssignments(string fileName, vector<Category> categories) {

}

