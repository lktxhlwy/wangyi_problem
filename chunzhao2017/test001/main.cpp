#include<iostream>
#include<string>
using namespace std;
using std::string;

int main(void)
{
	string s;
	cin >> s;
	int max = 1;
	int ret = 1;
	for (string::iterator i = s.begin()+1; i != s.end(); i++) {
		if (*i != *(i - 1)) {
			ret++;
			if (ret > max) {
				max = ret;
			}
		}
		else {
			ret = 1;
		}
	}

	cout << max << endl;

	return 0;
}