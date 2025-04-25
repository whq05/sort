/* ************************************************************************
> File Name:     quicksort.cpp
> Author:        whq
> Created Time:  Fri 25 Apr 2025 02:01:38 AM CST
> Description:   快速排序
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

// 挖坑填数 + 分治
void quicksort(int *arr, int len)
{
    if (len < 2)
        return; // 数组的元素小于2个就不用排序了

    int temp = arr[0];   // 选取最左边的数作为中心轴
    int left = 0;        // 左下标
    int right = len - 1; // 右下标
    int moving = 2;      // 1表示从左向右移动，2表示从右向左移动

    while (left < right)
    {
        if (moving == 2) // 移动右下标的情况
        {
            // 如果右下标位置元素的值大于等于中心轴，继续移动右下标
            if (arr[right] >= temp)
            {
                right--;
                continue;
            }

            // 如果右下标位置元素的值小于中心轴，把它填到左下标的坑中
            arr[left] = arr[right];
            left++;     // 左下标向右移动
            moving = 1; // 下次循环将移动左下标
            continue;
        }

        if (moving == 1) // 移动左下标的情况
        {
            // 如果左下标位置元素的值小等于中心轴，继续移动左下标
            if (arr[left] <= temp)
            {
                left++;
                continue;
            }

            // 如果左下标位置元素的值大于中心轴，把它填到右下标的坑中
            arr[right] = arr[left];
            right--;    // 右下标向左移动
            moving = 2; // 下次循环将移动右下标
            continue;
        }
    }

    // 如果循环结束，左右下标重合，把中心轴的值填进去
    arr[left] = temp;

    quicksort(arr, left);                      // 对中心轴左边的序列进行排序（不包括中心轴）
    quicksort(arr + left + 1, len - left - 1); // 对中心轴右边的序列进行排序（不包括中心轴）
}

int main()
{
    vector<int> vec{44, 3, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    int len = vec.size();
    quicksort(vec.data(), len);
    cout << "排序后的数组为：";
    for (int i = 0; i < len; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}