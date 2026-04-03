#include <stdio.h>
#include "calc.h"

#define DATA_COUNT 5

/* Steel plate thickness data aggregation program

Accepts multiple "thickness (mm)" data of steel plates as arguments and calculates their sum, maximum, and minimum values.
*/
int main(int argc, char *argv[])
{
    int thicknessData[DATA_COUNT];
    if (extractThicknessData(argc, argv, DATA_COUNT, thicknessData))
    {
        return 1;
    }

    aggregates agg;
    agg = calculateStats(DATA_COUNT, thicknessData);

    /* result */
    printf("Thickness data: ");
    showIntArray(DATA_COUNT, thicknessData);
    printf("Total: %d\n", agg.sum);
    printf("Min: %d\n", agg.min);
    printf("Max: %d\n", agg.max);

    return 0;
}
