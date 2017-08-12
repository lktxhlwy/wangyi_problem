#include<iostream>
#include<string>
#include<vector>
using namespace std;
using std::string;
using std::vector;

int main(void)
{
	string s;
	cin >> s;
	int n;
	cin >> n;
	vector<vector<long long> > dp(s.size()+1, vector<long long>(n,0));
	dp[0][0] = 1;
	for (int i = 1; i <= s.size(); i++) {
		for (int j = 0; j < n; j++) {
			if (s.at(i - 1) == 'X') {
				for (int k = 0; k < 10; k++) {
					int newj = (j * 10 + k) % n;
					dp[i][newj] += dp[i - 1][j];
				}
			}
			else {
				int newj = (j * 10 + s.at(i - 1) - '0') % n;
				dp[i][newj] += dp[i - 1][j];
			}
		}
	}

	cout << dp[s.size()][0] << endl;

	return 0;
}