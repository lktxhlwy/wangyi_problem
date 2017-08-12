#include<iostream>
#include<vector>
#include<set>
using namespace std;
using std::vector;

int gcd(int a, int b)
{
	if (a < b) {
		swap(a, b);
	}
	int c = a%b;
	while (a%b) {
		a = b;
		b = c;
		c = a%b;
	}

	return b;
}

int main(void)
{
	int w, x, y, z;
	cin >> w >> x >> y >> z;
	vector<int> res;
	set<pair<int, int> > s;

	for (int i = w; i <= x; i++) {
		for (int j = y; j <= z; j++) {
			int ii = i, jj = j;
			int di= gcd(i, j);
			ii /= di;
			jj /= di;
			s.insert(make_pair(ii, jj));
		}
	}

	cout << s.size()<<endl;

	return 0;
}