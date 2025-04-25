/* ************************************************************************
> File Name:     bucketsort.cpp
> Author:        whq
> Created Time:  Fri 25 Apr 2025 09:18:27 PM CST
> Description:   桶排序
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>  
#include <cstring>  // memset

using namespace std;


// 采用两层循环实现冒泡排序的方法
// 参数arr是待排序数组的首地址，len是数组元素的个数
void bubblesort(int *arr, int len)
{
    int i, j;
    for (i = len - 1; i >= 0; i--)
    {
        bool swapped = false;
        for (j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) return;
    }
}

// 桶排序主函数，参数arr是待排序数组的首地址，len是数组元素的个数
void bucketsort(int *arr, int len)
{
    int bucket[5][5];   // 分配五个桶
    int bucketsize[5];  // 每个桶中元素个数的计数器

    // 初始化桶和桶计数器
    memset(bucket, 0, sizeof(bucket));
    memset(bucketsize, 0, sizeof(bucketsize));

    // 把数组arr的数据放入桶中
    int i = 0;
    for (i = 0; i < len; i++)
    {
        bucket[arr[i] / 10][bucketsize[arr[i] / 10]++] = arr[i];
    }

    // 对每个桶进行冒泡排序
    for (i = 0; i < 5; i++)
    {
        bubblesort(bucket[i], bucketsize[i]);
    }

    // 把每个桶中的数据填充到数组arr中
    int j = 0, k = 0;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < bucketsize[i]; j++)
        {
            arr[k++] = bucket[i][j];
        }
    }
}


int main()
{
    vector<int> vec{21,3,30,44,15,36,6,10,9,19,25,48,5,23,47};
    int len = vec.size();
    bucketsort(vec.data(), len);
    cout << "排序后的数组为：";
    for (int i = 0; i < len; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}