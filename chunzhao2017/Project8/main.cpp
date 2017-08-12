#include<iostream>
#include<string>
using namespace std;
using std::string;

int main(void)
{
	string s;
	cin >> s;
	string::iterator p = s.begin();
	int result = *p - '0';
	while (p < s.end() - 1) {
		char op = *(p + 1);
		int num2 = *(p + 2) - '0';
		if (op == '+')
			result += num2;
		else if (op == '-')
			result -= num2;
		else
			result *= num2;

		p += 2;
	}

	cout << result << endl;

	return 0;
}