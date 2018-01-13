#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;

using std::vector;
using std::string;


void dfs(string & s, int step) {
	if (step == static_cast<int>(s.size()) - 1) {
		cout << s << endl;
		return;
	}
	dfs(s, step + 1);
	s = s.substr(0, step + 1) + " " + s.substr(step + 1);
	dfs(s, step + 2);
	s = s.substr(0, step + 1) + s.substr(step + 2);
}

int main() {
	string s0 {"a"};
	string s1 {"abcd"};
	string s2 {"abcde"};
	string s3 {"abcdef"};

	cout << "------" << endl;
	dfs(s0, 0);
	cout << "------" << endl;
	dfs(s1, 0);
	cout << "------" << endl;
	dfs(s2, 0);
	cout << "------" << endl;
	dfs(s3, 0);
	
	return 0;
}
