/* ************************************************************************
> File Name:     countsort_better.cpp
> Author:        whq
> Created Time:  Fri 25 Apr 2025 08:07:16 PM CST
> Description:   计数排序（优化版）
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

// 获取待排序数组的最小和最大元素的值
void arrminmax(int *arr, int len, int &min, int &max)
{
    int i = 0;
    min = INT_MAX;
    max = INT_MIN;
    for (i = 0; i < len; i++)
    {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
}

// 计数排序主函数，arr-待排序数组的地址，len-数组的长度
void countsort(int *arr, int len)
{
    if (len < 2) return;

    // 获取待排序数组的最小和最大大元素的值
    int min, max;
    arrminmax(arr, len, min, max);

    int arrtmp[max - min + 1]; // 临时数组的大小为max-min+1
    memset(arrtmp, 0, sizeof(arrtmp));  // 初始化临时数组

    int i, j, k;
    
    // 临时数组计数
    for (i = 0; i < len; i++) arrtmp[arr[i] - min]++;

    // 把临时数组计数的内容填充到arr中
    i = 0;
    for (j = 0; j < max - min + 1; j++)
    {
        for (k = 0; k < arrtmp[j]; k++) arr[i++] = j + min;
    }
}

int main()
{
    // vector<int> vec{44, 3, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    vector<int> vec{102,103,108,107,101,102,102,102,107,103,109,108,102,101,104,102,104,106,109,102};
    int len = vec.size();
    countsort(vec.data(), len);
    cout << "排序后的数组为：";
    for (int i = 0; i < len; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}