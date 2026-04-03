#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "calc.h"

/* Convert command-line arguments to thickness data array

Args:
    argc (int): Number of command-line arguments
    *argv[]: Array of argument strings
    thicknessDataCount (int): Number of thickness data elements
    thicknessData[] (int): Thickness data array

Returns:
    Returns 0 if conversion succeeds, 1 if it fails.

Raises:
    Abnormal termination in the following cases:
    - Number of thicknessData elements is less than 1
    - Number of thicknessData elements does not match the number of arguments (excluding argv[0])
    - Arguments contain non-numeric strings (excluding argv[0])
*/
int extractThicknessData(int argc, char *argv[], int thicknessDataCount, int thicknessData[])
{
    if (thicknessDataCount < 1)
    {
        printf("[ERROR] Element count must be 1 or more: %d\n", thicknessDataCount);
        return 1;
    }
    if (argc != thicknessDataCount + 1)
    {
        printf("[ERROR] %d arguments required. Received %d arguments.\n", thicknessDataCount, argc - 1);
        return 1;
    }

    for (int i = 0; i < thicknessDataCount; i++)
    {
        char *numberLike = argv[i + 1];
        if (!isNumber(strlen(numberLike), numberLike))
        {
            printf("[ERROR] Cannot convert to numeric value: %s\n", numberLike);
            return 1;
        }
        thicknessData[i] = atoi(numberLike);
    }
    return 0;
}

/* Check if a string is an integer value

Args:
    n (size_n): Number of characters (excluding `\0`)
    numberLike (char*): String to check

Returns:
    Returns true if numberLike is an integer value, false otherwise
*/
bool isNumber(size_t n, char *numberLike)
{
    for (size_t i = 0; i < n; i++)
    {
        if (!isdigit(numberLike[i]))
        {
            return false;
        }
    }
    return true;
}

/* Calculate sum, minimum, and maximum values */
aggregates calculateStats(int n, int thicknessData[])
{
    aggregates agg;
    agg.sum = thicknessData[0];
    agg.min = thicknessData[0];
    agg.max = thicknessData[0];
    for (int i = 1; i < n; i++)
    {
        int thickness = thicknessData[i];
        agg.sum += thickness;
        if (agg.min > thickness)
        {
            agg.min = thickness;
        }
        if (agg.max < thickness)
        {
            agg.max = thickness;
        }
    }

    return agg;
}

/* Display an integer array

Example:
    {1, 2, 3} -> "{1, 2, 3}"
*/
void showIntArray(int n, int array[])
{
    printf("{");
    for (int i = 0; i < n; i++)
    {
        printf("%d", array[i]);
        if (i < n - 1)
        {
            printf(", ");
        }
    }
    printf("}\n");
}
