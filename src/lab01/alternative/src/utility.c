/**
 * Utility functions
 */

#include "../headers/internalDependencies.h"

/**
 * Function to calculate relative grade variable for every object in array
 * @param  data        Array of objects
 * @param  dataCount   Number of objects in array
 * @param  maxAbsGrade Maximum absolute grade
 * @return             Result of operation
 */
int calculateRelativeGrade(person* data, const int dataCount, const double maxAbsGrade) {
    int i = 0;
    for (i = 0; i < dataCount; ++i)
        data[i].relGrade = data[i].absGrade / maxAbsGrade * 100;

    return 0;
}
