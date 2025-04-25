/* ************************************************************************
> File Name:     radixsort.cpp
> Author:        whq
> Created Time:  Fri 25 Apr 2025 10:44:20 PM CST
> Description:   基数排序（LSD（Least Significant Digit）基数排序）
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h> // INT_MIN
#include <cstring>  // memcpy
#include <iomanip>  // std::setw

using namespace std;

// 获取数组arr中最大值，arr-待排序的数组，len-数组arr的长度
int arrmax(int *arr, int len)
{
    int imax = INT_MIN;
    for (int i = 0; i < len; i++)
        imax = max(imax, arr[i]);
    return imax;
}

// 对数组arr按指数位进行排序。
// arr-待排序的数组，len-数组arr的长度。
// exp-排序指数，exp=1：按个位排序；exp=10：按十位排序；......
void _radixsort(int *arr, int len, int exp)
{
    int i;
    int result[len];       // 存放从桶中收集后数据的临时数组
    int buckets[10] = {0}; // 初始化10个桶（注意这里没用二维数组，这正是基数排序的精妙所在）

    // 遍历arr，将数据出现的次数存储在buckets中
    for (i = 0; i < len; i++)
        buckets[(arr[i] / exp) % 10]++;

    // 调整buckets各元素的值，调整后的值就是arr中元素在result中的位置
    for (i = 1; i < 10; i++)
        buckets[i] += buckets[i - 1];

    // 将arr中的元素填充到result中
    // for (i = 0; i < len; i++) 如果写成这样就不稳定了
    /*
    whq@whq:~/github/sort$ ./radixsort   ------> 使用了for (i = len - 1; i >= 0; i--)的写法
    exp=1      750 602 203 144 504 905 215 836 26 946 347 527 738 848 219
    exp=10     602 203 504 905 215 219 26 527 836 738 144 946 347 848 750
    exp=100    26 144 203 215 219 347 504 527 602 738 750 836 848 905 946
    排序后的数组为：26 144 203 215 219 347 504 527 602 738 750 836 848 905 946
    whq@whq:~/github/sort$ make
    g++ -g -o radixsort radixsort.cpp
    whq@whq:~/github/sort$ ./radixsort  ------> 使用了for (i = 0; i < len; i++)的写法
    exp=1      750 602 203 504 144 215 905 946 26 836 527 347 848 738 219
    exp=10     905 504 203 602 219 215 527 26 738 836 848 347 946 144 750
    exp=100    26 144 215 219 203 347 527 504 602 750 738 848 836 946 905
    排序后的数组为：26 144 215 219 203 347 527 504 602 750 738 848 836 946 905
    */
    for (i = len - 1; i >= 0; i--)
    {
        int iexp = (arr[i] / exp) % 10;
        result[buckets[iexp] - 1] = arr[i];
        buckets[iexp]--;
    }

    // 将排序好的数组result复制到数组arr中
    memcpy(arr, result, len * sizeof(int));
}

// 基数排序主函数，arr-待排序的数组，len-数组arr的长度
void radixsort(int *arr, int len)
{
    int imax = arrmax(arr, len); // 获取数组arr的最大值

    int iexp; // 排序指数，iexp=1：按个位排序；iexp=10：按十位排序；......

    // 从个位开始，对数组arr按指数位进行排序
    for (iexp = 1; imax / iexp > 0; iexp *= 10)
    {
        _radixsort(arr, len, iexp);
        std::cout << "exp=" << std::left << std::setw(5) << iexp << "  ";
        for (int i = 0; i < len; ++i)
            std::cout << std::setw(2) << arr[i] << " ";
        cout << endl;
    }
}

int main()
{
    vector<int> vec{144, 203, 738, 905, 347, 215, 836, 26, 527, 602, 946, 504, 219, 750, 848};
    int len = vec.size();
    cout << "原始数组：";
    for (int i = 0; i < len; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    radixsort(vec.data(), len);
    cout << "排序后的数组为：";
    for (int i = 0; i < len; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}

/*

# MSD（Most Significant Digit）基数排序 ---->

#include <iostream>     // 输入输出流库
#include <vector>       // 向量容器库
#include <algorithm>    // 算法库，提供max等函数
#include <limits.h>     // 包含INT_MIN等常量
#include <cstring>      // 提供memcpy等内存操作函数
#include <iomanip>      // 提供setw等输出格式化函数

using namespace std;

// 求数组中的最大值
int arrmax(int *arr, int len) {
    int imax = INT_MIN;  // 初始化为最小整数
    for (int i = 0; i < len; i++) imax = max(imax, arr[i]);  // 遍历找最大值
    return imax;
}

// 计算一个数字的位数
int getDigitCount(int num) {
    if (num == 0) return 1;  // 0的位数为1
    int count = 0;
    while (num > 0) {
        count++;
        num /= 10;  // 每次除以10，直到num为0
    }
    return count;
}

// 获取数字在指定位置上的数字（从个位开始算）
int getDigit(int num, int position) {
    for (int i = 1; i < position; i++) num /= 10;  // 将数字右移到目标位置
    return num % 10;  // 返回最右边的数字
}

// MSD基数排序的递归辅助函数
void msdRadixSortHelper(int* arr, int len, int currentDigit, int* originalArr, int originalLen) {
    if (currentDigit < 1 || len <= 1) return;  // 基本情况：没有更多位数或数组长度为1

    vector<vector<int>> buckets(10);  // 创建10个桶（对应0-9）

    // 根据当前位数将元素分配到桶中
    for (int i = 0; i < len; ++i) {
        int d = getDigit(arr[i], currentDigit);
        buckets[d].push_back(arr[i]);
    }

    vector<int> temp;  // 临时数组，用于合并桶中的元素
    for (auto &bucket : buckets) {
        for (int num : bucket) {
            temp.push_back(num);
        }
    }

    memcpy(arr, temp.data(), len * sizeof(int));  // 将临时数组的内容复制回原数组

    // 打印当前排序状态
    int startIdx = arr - originalArr;  // 计算当前子数组在原数组中的起始位置
    cout << "位数=" << setw(5) << left << currentDigit << "  ";
    for (int i = 0; i < originalLen; ++i) {
        if (i >= startIdx && i < startIdx + len)
            cout << setw(3) << arr[i - startIdx] << " ";  // 打印当前子数组元素
        else
            cout << setw(3) << originalArr[i] << " ";     // 打印原数组其他元素
    }
    cout << endl;

    // 对每个非空桶递归应用MSD基数排序
    int idx = 0;
    for (auto &bucket : buckets) {
        int bucketSize = bucket.size();
        if (bucketSize > 1) {
            // 递归排序当前桶（使用下一个较低位）
            msdRadixSortHelper(arr + idx, bucketSize, currentDigit - 1, originalArr, originalLen);
        }
        idx += bucketSize;  // 更新下一个桶的起始索引
    }
}

// MSD基数排序的主函数
void msdRadixSort(int* arr, int len) {
    int imax = arrmax(arr, len);          // 找出数组中的最大值
    int maxDigits = getDigitCount(imax);  // 计算最大值的位数
    msdRadixSortHelper(arr, len, maxDigits, arr, len);  // 从最高位开始排序
}

int main() {
    vector<int> vec{144,203,738,905,347,215,836,26,527,602,946,504,219,750,848};  // 初始化数组
    int len = vec.size();  // 获取数组长度

    cout << "原始数组：";
    for (int num : vec) cout << num << " ";  // 打印原始数组
    cout << endl;

    msdRadixSort(vec.data(), len);  // 调用MSD基数排序函数

    cout << "排序后的数组为：";
    for (int num : vec) cout << num << " ";  // 打印排序后的数组
    cout << endl;

    return 0;
}
*/