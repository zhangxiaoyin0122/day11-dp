#include <iostream>
using namespace std;


//方法一:递归实现
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0)
			return 0;
		if (n <= 2)
			return 1;
		return Fibonacci(n - 2) + Fibonacci(n - 1);
	}
};
//方法二:动态规划
class Solution {
public:
	int Fibonacci(int n) {
		//开数组
		int* dp = new int[n + 1];
		//初始化
		dp[0] = 0;
		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			//状态转移方程
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		int ret = dp[n];
		delete[] dp;
		return ret;
	}
};
//方法三:迭代
class Solution {
public:
	int Fibonacci(int n) {
		int first = 0;
		int second = 1;
		int third = n;
		for (int i = 2; i <= n; i++) {
			third = first + second;
			first = second;
			second = third;
		}
		return third;
	}
};


class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		if (s.length() == 0 || dict.size() == 0)
			return false;
		vector<bool> can_break(s.size() + 1, false);
		can_break[0] = true;
		for (int i = 1; i <= s.size(); i++) {
			for (int j = i; j >= 0; j--) {
				if (can_break[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
					can_break[i] = true;
					break;
				}
			}
		}
		return can_break[s.size()];
	}
};




class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		if (triangle.empty())
			return 0;
		vector<vector<int> > min_sum(triangle);
		int len = triangle.size();
		for (int i = 1; i < len; i++) {
			for (int j = 0; j <= i; j++) {
				if (j == 0) {
					min_sum[i][j] = min_sum[i - 1][j] + triangle[i][j];
				}
				else if (j == i) {
					min_sum[i][j] = min_sum[i - 1][j - 1] + triangle[i][j];
				}
				else {
					min_sum[i][j] = min(min_sum[i - 1][j - 1], min_sum[i - 1][j]) + triangle[i][j];
				}
			}
		}
		int result = min_sum[len - 1][0];
		for (int i = 0; i < len; i++) {
			result = min(min_sum[len - 1][i], result);
		}
		return result;
	}
};

