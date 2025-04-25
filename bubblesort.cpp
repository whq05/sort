/* ************************************************************************
> File Name:     bubblesort.cpp
> Author:        whq
> Created Time:  Thu 24 Apr 2025 10:21:21 PM CST
> Description:   冒泡排序
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

// 采用两层循环实现的方法
// 参数arr是待排序数组的首地址，len是数组元素的个数
void bubblesort1(int *arr, unsigned int len)
{
    if (len < 2) return;    // 数组小于2个元素不需要排序
    // i : 排序的趟数的计数器
    // j : 每趟排序的元素位置计数器
    // swapped : 每趟排序过程中是否交换过元素 
    for (int i = len - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

// 采用递归实现的方法
// 参数arr是待排序数组的首地址，len是数组元素的个数
void bubblesort2(int *arr, unsigned int len)
{
    if (len < 2)
        return;                       // 数组小于2个元素不需要排序
    for (int i = 0; i < len - 1; i++) // 每趟只需要比较0......len-1之间的元素，len-1之后的元素是已经排序好的
    {
        if (arr[i] > arr[i + 1]) 
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    bubblesort2(arr, len - 1); 
}

int main()
{
    vector<int> vec{44, 3, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    int len = vec.size();
    // bubblesort1(vec.data(), len);
    bubblesort2(vec.data(), len); // 也可以使用递归的方法进行排序
    cout << "排序后的数组为：";
    for (int i = 0; i < len; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}
