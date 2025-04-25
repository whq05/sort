/* ************************************************************************
> File Name:     heapsort.cpp
> Author:        whq
> Created Time:  Fri 25 Apr 2025 03:56:01 PM CST
> Description:   堆排序
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 采用循环实现heapify（元素下沉）
// arr-待排序数组的地址，start-待heapify节点的下标，end-待排序数组最后一个元素的下标
void heapify(int *arr, int start, int end)
{
    // 确定父节点和左子节点的数组下标
    int dad = start;
    int son = 2 * dad + 1;

    // 如果子节点的下标没有超出范围，循环继续
    while (son <= end)
    {
        // 先比较两个子节点大小，选择最大的
        if ((son + 1 <= end) && (arr[son] < arr[son + 1]))
            son++;

        // 如果父节点大于等于子节点代表调整完毕，直接跳出函数
        if (arr[dad] >= arr[son])
            break;

        // 否则交换父子內容再继续子节点和孙节点比较
        swap(arr[dad], arr[son]);
        dad = son;
        son = 2 * dad + 1;
    }
}

// 采用递归实现heapify
void heapify1(int *arr, int start, int end)
{
    // 确定父节点和左子节点的数组下标
    int dad = start;
    int son = 2 * dad + 1;

    // 如果子节点的下标没有超出范围，循环继续
    if (son > end)
        return;

    // 先比较两个子节点大小，选择最大的
    if ((son + 1 <= end) && (arr[son] < arr[son + 1]))
        son++;

    // 如果父节点大于子节点代表调整完毕，直接跳出函数
    if (arr[dad] >= arr[son])
        return;

    // 否则交换父子內容再继续子节点和孙节点比较
    swap(arr[dad], arr[son]);

    heapify1(arr, son, end);
}

void heapsort(int *arr, int len)
{
    int i;

    // 初始化堆，从最后一个父节点开始调整
    for (i = (len - 1 - 1) / 2; i >= 0; i--)
        // heapify(arr, i, len - 1);
        heapify1(arr, i, len - 1);

    /*
    也可写成这样来初始化堆
    for (i = (len - 1 - 1) / 2; i >= 0; i--)   heapify(arr, i, len - 1);
    为什么写成这样可以呢？
    例子1：数组长度为10

    数组索引范围：0到9
    最后一个元素的索引：9
    使用 (len-2)/2 计算：(10-2)/2 = 8/2 = 4
    使用 (len-1)/2 计算：(10-1)/2 = 9/2 = 4（整数除法结果相同）

    例子2：数组长度为9

    数组索引范围：0到8
    最后一个元素的索引：8
    使用 (len-2)/2 计算：(9-2)/2 = 7/2 = 3
    使用 (len-1)/2 计算：(9-1)/2 = 8/2 = 4

    在例子2中，我们得到了不同的结果。
    0
   / \
  1   2
 / \ / \
3  4 5  6
/ \
7  8
    索引3是节点7和8的父节点，索引4是一个没有子节点的叶子节点。
    使用 (len-2)/2 我们获得索引3，这是最后一个有子节点的父节点。
    使用 (len-1)/2 我们获得索引4，这是一个没有子节点的节点。
    但是，即使我们从索引4开始调整，因为它没有子节点，heapify函数会立即返回，不会进行任何操作。然后我们继续处理索引3,2,1,0。
    因此，两种写法在功能上是等价的，因为额外处理没有子节点的节点不会影响最终结果（在hearify中不会进入while循环）。

    使用 (len-1)/2 作为起点可能包含一些没有子节点的节点，但不会影响算法的正确性，并且这种写法更简洁。实际上，这已经成为许多堆排序实现中的常见做法。
    */

    // 把第一个元素和堆最后一个元素交换，然后重新调整，直到排序完毕
    for (i = len - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        // heapify(arr, 0, i - 1);
        heapify1(arr, 0, i - 1);
    }
}

int main()
{
    vector<int> vec{44, 3, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    int len = vec.size();
    heapsort(vec.data(), len);
    cout << "排序后的数组为：";
    for (int i = 0; i < len; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}
