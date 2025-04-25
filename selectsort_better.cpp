/* ************************************************************************
> File Name:     selectsort_better.cpp
> Author:        whq
> Created Time:  Fri 25 Apr 2025 12:18:42 AM CST
> Description:   优化后的选择排序
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

// 采用两层循环实现的方法
void selectsort1(int *arr, int len)
{
    if (len < 2) // 数组小于2个元素不需要排序
        return;
    int left, right;    // 每趟排序的最左和最右的位置
    int minpos, maxpos; // 每趟循环选出的最小值和最大值的位置（数组的下标）

    left = 0, right = len - 1;
    while (left < right)
    {
        minpos = left, maxpos = right;
        for (int i = left; i <= right; i++)
        {
            if (arr[i] < arr[minpos])
                minpos = i;
            if (arr[i] > arr[maxpos])
                maxpos = i;
        }

        // 如果本趟循环的最小的元素不是最左边的元素，则交换它们的位置
        if (minpos != left)
            swap(arr[left], arr[minpos]);

        // 如果maxpos的位置是left，在上面的代码中left已被交换到了minpos的位置。
        // 所以maxpos的值要修改为minpos
        if (maxpos == left)
            maxpos = minpos;

        // 如果本趟循环的最大的元素不是最右边的元素，则交换它们的位置
        if (maxpos != right)
            swap(arr[right], arr[maxpos]);

        left++, right--;
    }
}

// 采用递归实现的方法
void selectsort2(int *arr, int len)
{
    if (len < 2)
        return;
    int left = 0, right = len - 1;
    int minpos = 0, maxpos = len - 1;
    for (int i = left; i <= right; i++)
    {
        if (arr[i] < arr[minpos])
            minpos = i;
        if (arr[i] > arr[maxpos])
            maxpos = i;
    }

    if (minpos != left)
        swap(arr[left], arr[minpos]);

    if (maxpos == left)
        maxpos = minpos;

    if (maxpos != right)
        swap(arr[right], arr[maxpos]);

    selectsort2(arr + 1, len - 2);
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
