# Grade Predictor

### How to run:

* Step 1: Install the json library from here https://github.com/nlohmann/json
* Step 2: add the library to your version of this project (I don't currently know how to do it for Visual Studio)
* Step 3: if you are using cmake, edit the cmakelists.txt file to the proper settings to work with the json library 
* Step 4: In the FileManager.h file, edit the path to link to the json file provided in the src/TextFiles directory
* Step 5: build the project.

### Using this app

<b>Menu Options </b>
> 1. Display category summary
* Displays a category summary for all categories



> 2. Display Category details
* You choose a category and you get a list of assignments and other details about that particular
category
* NOTE: atm I was unable to use getline and instead had to use cin >> so you can access a category that has spaces.
This also applies to any other part where input is taken in. 

> 3. Add new category
* Add a new category by inputting a name a weight. Note that the name needs to be one word. Also the weight needs to be a number
between 0 and 1 because it is used to calculate the total score.

> 4. Add new assignment

* The user inputs name and points for the new assignment. Then category is selected. The name should be one word for the reasons stated before.

> 5.  edit assignment
* You select the category and the assignment. Then, you can edit the name, points achieved, and if its completed. 
> 6. exit
* This exits the program.


## Current Problems

1. The program has to be restarted for file changes
* Potential Solution: none at the moment
2. The cin inputs cant have spaces in Assignment or category names
* Potential Solution: potentially using the getline function although that using it caused other errors
3. Predicted Grades are a bit strange as they calculate predicted grade based on the average of assignments
* Potential Solution: none at the moment
4. Prevent duplicate assignments and categories
* Potential Solution: use a if to check if assignment/category already exists before creating it
5. If there are no assignments in category, then the grade is nan%
* check if there are any assignments








