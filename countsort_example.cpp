/* ************************************************************************
> File Name:     corrected_countsort.cpp
> Author:        whq (optimized)
> Created Time:  Fri 25 Apr 2025 08:35:50 PM CST
> Description:   全省高考成绩排名算法
************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int MAX_SCORE = 750; // 高考最高分
const int MIN_SCORE = 0;   // 高考最低分

int main() {
    // 从文件或数据库读取考生成绩（这里用模拟数据）
    vector<int> scores{581, 575, 632, 581, 750, 522, 576, 750, 581, 580, 582, 630, 710, 508, 749, 250};
    
    // 检查成绩范围合法性
    for (const auto& score : scores) {
        if (score < MIN_SCORE || score > MAX_SCORE) {
            cerr << "错误：成绩 " << score << " 超出有效范围[" << MIN_SCORE << ", " << MAX_SCORE << "]" << endl;
            return 1;
        }
    }
    
    int total_students = scores.size();
    
    // 使用动态数组避免栈溢出问题
    vector<int> frequency(MAX_SCORE + 1, 0);
    vector<int> higher_scores(MAX_SCORE + 1, 0);    // 存储"得分比当前分数高的考生数量
    
    // 统计每个分数出现的频次
    for (const auto& score : scores) {
        frequency[score]++;
    }
    
    // 计算比每个分数更高的学生数量（从高到低）
    for (int i = MAX_SCORE - 1; i >= MIN_SCORE; i--) {
        higher_scores[i] = higher_scores[i + 1] + frequency[i + 1];
    }
    
    // 查询界面
    while (true) {
        cout << "请输入考生的成绩（" << MIN_SCORE << "-" << MAX_SCORE << "），输入-1退出：";
        int query_score;
        cin >> query_score;
        
        // 输入验证
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "输入无效，请重新输入一个整数。" << endl;
            continue;
        }
        
        if (query_score == -1) {
            cout << "程序已退出。" << endl;
            break;
        }
        
        if (query_score < MIN_SCORE || query_score > MAX_SCORE) {
            cout << "成绩超出有效范围，请重新输入。" << endl;
            continue;
        }
        
        // 计算正确的排名和超过的考生比例
        int rank = higher_scores[query_score] + 1; // 比该分数高的人数 + 1
        int same_score_count = frequency[query_score];
        int rank_end = rank + same_score_count - 1;
        
        // 正确计算百分比：超过了多少人
        double percentage = higher_scores[query_score] * 100.0 / total_students;
        
        // 显示详细结果
        if (same_score_count > 1) {
            cout << "该分数有 " << same_score_count << " 名考生，排名区间：" << rank << "-" << rank_end << endl;
        } else {
            cout << "该考生全省排名是：" << rank << endl;
        }
        
        cout << "超过全省 " << percentage << "% 的考生" << endl;
        cout << "全省共有 " << total_students << " 名考生参加考试" << endl;
        cout << endl;
    }
    
    return 0;
}