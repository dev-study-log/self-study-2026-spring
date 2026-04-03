#include <stdbool.h>

/* 計算結果をまとめる構造体 */
typedef struct
{
    int sum;
    int min;
    int max;
} aggregates;

int extractThicknessData(int argc, char *argv[], int thicknessDataCount, int thicknessData[]);
bool isNumber(size_t n, char *numberLike);
aggregates calculateStats(int n, int thicknessData[]);
void showIntArray(int n, int array[]);
