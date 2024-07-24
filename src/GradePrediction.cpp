


#include "../include/GradePrediction.h"
#include <vector>

double GradePrediction::getTotalPredictedGrade(vector<Category> categories)
{
double totalPredictedGrade = 0;
for (Category category : categories)
{
totalPredictedGrade += category.calculatePredictedGrade() * category.getTotalWeight();
}
return totalPredictedGrade;
}