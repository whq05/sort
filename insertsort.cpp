/* ************************************************************************
> File Name:     insertsort.cpp
> Author:        whq
> Created Time:  Fri 25 Apr 2025 01:15:12 AM CST
> Description:   插入排序
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

// 参数arr是待排序数组的首地址，len是数组元素的个数
void insertsort(int *arr, int len)
{
    if (len < 2) return; // 数组小于2个元素不需要排序
    int i;      // 需要排序元素的计数器
    int j;      // 插入排序时，需要后移元素的计数器
    int temp;   // 当前需要排序的元素的值
    for (i = 1; i < len; i++)
    {
        temp = arr[i]; // 待排序元素

        // 从已排序的最右边开始，把大于当前排序的元素后移
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] <= temp)
                break;
            arr[j + 1] = arr[j]; // 逐个元素后移
        }
        arr[j + 1] = temp; // 插入当前排序元素
    }
}

int main()
{
    vector<int> vec{44, 3, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    int len = vec.size();
    insertsort(vec.data(), len);
    cout << "排序后的数组为：";
    for (int i = 0; i < len; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}