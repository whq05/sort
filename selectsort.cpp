/* ************************************************************************
> File Name:     selectsort.cpp
> Author:        whq
> Created Time:  Thu 24 Apr 2025 11:37:41 PM CST
> Description:   选择排序
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

// 采用两层循环实现的方法
// 参数arr是待排序数组的首地址，len是数组元素的个数
void selectsort1(int *arr, int len)
{
    if (len < 2) return;    // 数组小于2个元素不需要排序
    // i : 排序的趟数的计数器
    // j : 每趟排序的元素位置计数器
    // minpos : 每趟循环选出的最小值的位置（数组的下标）
    for (int i = 0; i < len - 1; i++)   // 一共进行len-1趟比较
    {
        int minpos = i;
        for (int j = i + 1; j < len; j++)   // 每趟只需要比较i+1......len-1之间的元素，i之前的元素是已经排序好的
        {
            if (arr[j] < arr[minpos]) minpos = j;
        }

        // 如果本趟循环的最小的元素不是起始位置的元素，则交换它们的位置
        if (minpos != i) swap(arr[i], arr[minpos]);
    }
}

// 采用递归实现的方法
void selectsort2(int *arr, int len)
{
    if (len < 2) return;
    int minpos = 0;
    for (int i = 1; i < len; i++)
    {
        if (arr[i] < arr[minpos]) minpos = i;
    }
    if (minpos != 0) swap(arr[0], arr[minpos]);
    selectsort2(arr + 1, len - 1);
}

int main()
{
    vector<int> vec{44, 3, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    int len = vec.size();
    // selectsort1(vec.data(), len);
    selectsort2(vec.data(), len); // 也可以使用递归的方法进行排序
    cout << "排序后的数组为：";
    for (int i = 0; i < len; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}