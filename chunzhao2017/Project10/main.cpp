#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;
using std::set;
using std::string;
using std::vector;


int main(void)
{
	int n, m;
	cin >> n >> m;
	set<string> answer;
	set<string> question;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		answer.insert(str);
	}

	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		question.insert(str);
	}

	int res = 0;

	for (set<string>::iterator i=answer.begin(); i != answer.end(); i++) {
		if (question.find(*i) != question.end()) {
			res += ((*i).size())*((*i).size());
		}
	}

	cout << res << endl;

	return 0;
}