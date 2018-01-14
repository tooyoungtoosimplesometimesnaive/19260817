#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>

using std::cout;
using std::endl;

using std::vector;
using std::string;

using std::istringstream;
using std::istream_iterator;

// Split the input string using space as the delimiter.
vector<string> split(string s) {
	istringstream iss(s);
	vector<string> result(istream_iterator<string> {iss}, istream_iterator<string>());
	return result;
}
//Do the partition of the string.
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

void test_partition() {
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
	
	string s {"19260817"};
	cout << "------" << endl;
	dfs(s, 0);
	
}

// step starts from 1
// cr: current result
void calc(vector<string> vs, string & s, int step, int cr, int hor) {
	if (step == static_cast<int>(vs.size())) {
		cout << s << "=" << cr << endl;
		return;
	}
	int n = stoi(vs[step]);
	// The length of the number:
	int nl = static_cast<int> (vs[step].size());
	// add '+'
	s += "+";
	s += vs[step];
	calc(vs, s, step + 1, cr + n, 0);
	s = s.substr(0, s.size() - 1 - nl);
	// add '-'
	s += "-";
	s += vs[step];
	calc(vs, s, step + 1, cr - n, 0); 
	s = s.substr(0, s.size() - 1 - nl);

}

void do_calc() {
	string s = "1 2 3 45";
	vector<string> result(split(s));
	int m = 0;
	for (auto a: result) {
		m += stoi(a);
	}
	cout << m << endl;
	string ss{result[0]};
	calc(result, ss, 1, stoi(result[0]), 0);
}

int main() {
	// test_partition();
	do_calc();
	return 0;
}

