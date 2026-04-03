#include <stdio.h>
#include "calc.h"

#define DATA_COUNT 5

/* 鋼板のセンサーデータ集計プログラム

鋼板の「板厚（ミリ）」データを引数として複数受け取り、その合計値や最大値・最小値を算出する。
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
