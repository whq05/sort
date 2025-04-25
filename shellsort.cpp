/* ************************************************************************
> File Name:     shellsort.cpp
> Author:        whq
> Created Time:  Fri 25 Apr 2025 01:39:18 AM CST
> Description:   希尔排序
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void groupsort(int *arr, int len, int pos, int step)
{
    int i;  // 需要排序元素的计数器
    int j;  // 插入排序时，需要后移元素的计数器
    int temp;   // 当前需要排序的元素的值

    // 从已排序的最右边开始，把大于当前排序的元素后移。
    for (i = pos + step; i < len; i += step)
    {
        temp = arr[i];  // 待排序元素
        for (j = i - step; j >= 0; j -= step)
        {
            if (arr[j] <= temp) break;
            arr[j + step] = arr[j]; // 逐个元素后移
        }
        arr[j + step] = temp;   // 插入当前排序元素
    }
}


// 希尔排序，arr是待排序数组的首地址，len是数组的大小
void shellsort(int *arr, unsigned int len)
{
    int i, step;

    // step为步长，每次减为原来的一半取整数，最后一次必定为1
    for (step = len / 2; step > 0; step /= 2)
    {
        // 共step个组，对每一组都执行插入排序
        for (i = 0; i < step; i++)
        {
            groupsort(arr, len, i, step);
        }
    }
}


int main()
{
    vector<int> vec{44, 3, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    int len = vec.size();
    shellsort(vec.data(), len);
    cout << "排序后的数组为：";
    for (int i = 0; i < len; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}