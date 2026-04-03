#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DATA_COUNT 5

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

/* 引数から板厚データ配列に変換する

Args:
    argc (int): 引数の要素数
    *argv[]: 引数の文字列配列
    thicknessDataCount (int): 板厚データの要素数
    thicknessData[] (int): 板厚データ
Returns:
    変換が成功した場合は 0, 失敗した場合は 1 を返す。
Raises:
    以下の場合は異常終了とする
    - thicknessData の要素数が 1未満の場合
    - thicknessData の要素数と引数の数 (argv[0] を除く) が一致しない時
    - 引数に数値でない文字列が含まれるとき (argv[0] を除く)
*/
int extractThicknessData(int argc, char *argv[], int thicknessDataCount, int thicknessData[])
{
    if (thicknessDataCount < 1)
    {
        printf("[ERROR] 要素数は1以上を指定してください。: %d\n", thicknessDataCount);
        return 1;
    }
    if (argc != thicknessDataCount + 1)
    {
        printf("[ERROR] %d 個の引数が必要です。%d 個の引数を受け取りました。\n", thicknessDataCount, argc - 1);
        return 1;
    }

    for (int i = 0; i < thicknessDataCount; i++)
    {
        char *numberLike = argv[i + 1];
        if (!isNumber(strlen(numberLike), numberLike))
        {
            printf("[ERROR] 数値に変換できません: %s\n", numberLike);
            return 1;
        }
        thicknessData[i] = atoi(numberLike);
    }
    return 0;
}

/* 文字列が整数値か判定する

Args:
    n (size_n): 文字数 (`\0` を除く)
    numberLike (char*): 判定する文字列

Returns:
    numberLike が整数値であれば true、そうでなければ false を返す
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

/* 合計、最大値、最小値を計算する */
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

/* int 配列を表示する

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
