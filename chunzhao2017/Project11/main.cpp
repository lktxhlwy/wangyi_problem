#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using std::vector;

#define INT_MIN -2147483647

int main(void)
{
	int n;
	cin >> n;
	vector<int> height(n, 0);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> height[i];
		sum += height[i];
	}

	vector<int> temp(sum + 1, INT_MIN);
	temp[0] = 0;
	vector<int> dp(sum + 1, INT_MIN);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (j > height[i]) {	//新砖块放在高塔
				dp[j] = max(dp[j], temp[j - height[i]]);
			}
			else {					//放矮塔，矮塔变成了高塔
				dp[j] = max(dp[j], temp[height[i] - j] + height[i] - j);
			}
									
			//放矮塔，仍然是矮塔
			if (j + height[i] <= sum) {
				dp[j] = max(dp[j], temp[j + height[i]] + height[i]);
			}
			//不放这个砖块
			dp[j] = max(dp[j], temp[j]);
		}

		//一个砖块的迭代完成，保存当前的dp到temp中，并重新初始化dp
		for (int j = 0; j <= sum; j++) {
			temp[j] = dp[j];
			dp[j] = INT_MIN;
		}
	}

	if ((temp[0] != INT_MIN)&&(temp[0]!=0)) {
		cout << temp[0] << endl;
	}
	else {
		cout << -1 << endl;
	}


	return 0;
}