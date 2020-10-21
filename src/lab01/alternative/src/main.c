/**
 * Entry point function (main)
 */

#include "../headers/externalDependencies.h"
#include "../headers/internalDependencies.h"

/**
 * Entry function of application
 * @param  argc Number of command line parameters
 * @param  argv Command line parameters
 * @return      Execution result of application
 */
int main(int argc, char** argv) {
    person* data = NULL;
    int dataCount = 0;

    double maxAbsGrade = 0.0;

    int result = 0;

    data = readDataFromFile(&dataCount, &maxAbsGrade);
    if (data == NULL) {
        printf("There was a problem inside readDataFromFile()\n");
        return RETURN_OK;
    }

    result = calculateRelativeGrade(data, dataCount, maxAbsGrade);

    result = printDataToConsole(data, dataCount);

    result = deallocMemory(data);

    return RETURN_OK;
}
