/* ************************************************************************
> File Name:     countsort.cpp
> Author:        whq
> Created Time:  Fri 25 Apr 2025 07:40:30 PM CST
> Description:   计数排序（基础版）
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

// 获取待排序数组的最大元素的值
int arrmax(int *arr, int len)
{
    int i = 0;
    int max = INT_MIN;
    for (i = 0; i < len; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }

    return max;
}

// 计数排序主函数，arr-待排序数组的地址，len-数组的长度
void countsort(int *arr, int len)
{
    if (len < 2)
        return;

    int max = arrmax(arr, len); // 获取待排序数组的最大元素的值
    int arrtmp[max + 1];        // 临时数组的大小为max+1

    memset(arrtmp, 0, sizeof(arrtmp)); // 初始化临时数组

    int i, j, k;

    // 临时数组计数
    for (i = 0; i < len; i++)
        arrtmp[arr[i]]++;

    // 把临时数组计数的内容填充到arr中
    i = 0;
    for (j = 0; j <= max; j++)
    {
        for (k = 0; k < arrtmp[j]; k++)
            arr[i++] = j;
    }
}

int main()
{
    vector<int> vec{44, 3, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
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
