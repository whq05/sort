/* ************************************************************************
> File Name:     mergesort.cpp
> Author:        whq
> Created Time:  Fri 25 Apr 2025 02:21:40 PM CST
> Description:   采用递归的方法实现归并排序
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


// 采用递归的方法实现归并排序函数
// arr-待排序数组的首地址，arrtmp-用于排序的临时数组的首地址
// start-排序区间第一个元素的位置，end-排序区间最后一个元素的位置
void _mergesort(int *arr, int *arrtmp, int start, int end)
{
    // 如果start>=end，表示该区间的元素少于两个，递归终止
    if (start >= end) return;

    int mid = start + (end - start) / 2;    // 计算排序区间中间的位置

    int start1 = start, end1 = mid;     // 区间左边元素的第一和最后一个元素的位置
    int start2 = mid + 1, end2 = end;   // 区间右边元素的第一和最后一个元素的位置

    _mergesort(arr, arrtmp, start1, end1);  // 对区间左边元素递归排序
    _mergesort(arr, arrtmp, start2, end2);  // 对区间右边元素递归排序

    int i = start;  // 已排序数组arrtmp的计数器

    // 把区间左右两边数列合并到已排序数组arrtmp中
    while (start1 <= end1 && start2 <= end2)
    {
        arrtmp[i++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    }

    // 把左边数列其它的元素追加到已排序数组
    while (start1 <= end1) arrtmp[i++] = arr[start1++];

    // 把右边数列其它的元素追加到已排序数组
    while (start2 <= end2) arrtmp[i++] = arr[start2++];

    // 把已排序数组arrtmp中的元素复制到arr中
    memcpy(arr+start,arrtmp+start,(end-start+1)*sizeof(int));

}

// 排序主函数，arr为待排序的数组的地址，len为数组的长度
void mergesort(int *arr, int len)
{
    if (len < 2) return;    // 小于两个元素不需要排序
    vector<int> arrtmp(len);    // 分配一个与待排序数组相同大小的数组
    _mergesort(arr, arrtmp.data(), 0, len - 1);    // 调用递归函数进行排序
}

int main()
{
    vector<int> vec{44, 3, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    int len = vec.size();
    mergesort(vec.data(), len);
    cout << "排序后的数组为：";
    for (int i = 0; i < len; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}