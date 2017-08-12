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
			if (j > height[i]) {	//��ש����ڸ���
				dp[j] = max(dp[j], temp[j - height[i]]);
			}
			else {					//�Ű�������������˸���
				dp[j] = max(dp[j], temp[height[i] - j] + height[i] - j);
			}
									
			//�Ű�������Ȼ�ǰ���
			if (j + height[i] <= sum) {
				dp[j] = max(dp[j], temp[j + height[i]] + height[i]);
			}
			//�������ש��
			dp[j] = max(dp[j], temp[j]);
		}

		//һ��ש��ĵ�����ɣ����浱ǰ��dp��temp�У������³�ʼ��dp
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