/* ************************************************************************
> File Name:     mergesort1.cpp
> Author:        whq
> Created Time:  Fri 25 Apr 2025 02:40:24 PM CST
> Description:   采用循环的方法实现归并排序函数
************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

// 采用循环实现归并排序，arr-待排序数组的首地址，len-待排序数组的长度
void mergesort(int *arr, int len) {
    if (len < 2) return; // 小于两个元素不需要排序
    
    // 分配辅助数组空间
    int *temp = new int[len];
    
    int *a = arr;   // a指向待排序的数组
    int *b = temp;  // b指向已排序的数组

    /*
    // 归并排序这样的底层算法通常追求最大的性能，使用直接的内存操作而非高级容器是更常见的做法
    vector<int> temp(len);
    
    int *a = arr;  
    int *b = temp.data();
    */
    
    int seg;    // 区间分段的计数器，1,2,4,8,16,...
    int start;  // 区间起始位置的计数器
    
    // 排序的趟数的循环
    for (seg = 1; seg < len; seg *= 2)
    {
        // 每趟排序选取区间的循环
        for (start = 0; start < len; start += seg * 2)
        {
            // 把每个区间分成两部分，low是起始位置，mid是中间位置，max是结束位置
            int low = start;
            int mid = min(start + seg, len);    // 考虑分段不均的情况，mid不能超出len
            int max = min(start + seg * 2, len);    // 考虑分段不均的情况，max也不能超出len
            
            int i = low;    // 已排序数组的计数器
            int start1 = low, end1 = mid;   // 待排序左边数列的起始和结束位置
            int start2 = mid, end2 = max;   // 待排序右边数列的起始和结束位置
            
            // 把待排序左右两边数列合并到已排序数组
            while (start1 < end1 && start2 < end2)
            {
                b[i++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            }
            
            // 把左边数列其它的元素追加到已排序数组
            while (start1 < end1) b[i++] = a[start1++];
            
            // 把右边数列其它的元素追加到已排序数组
            while (start2 < end2) b[i++] = a[start2++];
        }
        
        // 交换一下两个数组的指针，准备下一趟的排序
        /*
        初始时，a指向原始数组arr，b指向辅助数组temp。
        在第一轮归并中，算法会将原始数组a中的元素按照排序规则放入辅助数组b中。这时，b中包含了第一轮归并排序后的结果。   
        执行swap(a, b)后，a现在指向辅助数组（包含已排序的元素），而b指向原始数组。
        在下一轮归并中，算法会取a所指向的数组（现在是前一轮的结果）作为输入，然后将排序结果放入b指向的数组中。
        每轮归并后再次交换a和b，保证a始终指向当前已排序的结果，而b作为下一轮排序的输出区域。
        这种方法避免了在每轮排序后将辅助数组的内容复制回原数组的操作，提高了算法效率。只在最后确认结果是否在原数组中，如果不在（即最后一轮排序结果在辅助数组中），才执行一次性复制。
        总结：swap(a, b)是为了减少不必要的数组复制操作，通过指针交换实现数组角色的切换，使算法更加高效。
        */
        swap(a, b);
    }
    
    // 如果a指向的是临时数组，需要将结果复制回原数组
    if (a == temp)
    {
        for (int i = 0; i < len; i++) {
            arr[i] = a[i];
        }
    }
    
    // 释放临时数组
    delete[] temp;
}

int main() {
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