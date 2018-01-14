#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>

using std::cout;
using std::endl;

using std::vector;
using std::string;

using std::istringstream;
using std::istream_iterator;

using std::ofstream;

string file_name {"magic_number.txt"};

void write_title() {
	ofstream ofs;
	ofs.open(file_name, ofstream::app);
	ofs << "# The Generated Magic Number for the Reference of True Fans!" << endl;
	ofs.close();
}

void write_to_file(string s, int result) {
	ofstream ofs;
	ofs.open(file_name, ofstream::app);
	ofs << "#### " ;
	for (auto c : s) {
		if (c == '+' || c == '-' || c == '*' || c == '/')
			ofs << " " << c << " ";
		else
			ofs << c;
	}
	ofs << " = "  << result << endl;
	ofs.close();
}

// Split the input string using space as the delimiter.
vector<string> split(string s) {
	istringstream iss(s);
	vector<string> result(istream_iterator<string> {iss}, istream_iterator<string>());
	return result;
}

// Insert operators to the generated string

// step starts from 1
// cr: current result
// hor: high order result
// pn: previous number
void calc(vector<string> vs, string & s, int step, int cr, int hor, int pn) {
	if (step == static_cast<int>(vs.size())) {
		cout << s << "=" << cr << "+" << hor << "=" << cr + hor << endl;
		write_to_file(s, cr + hor);
		return;
	}
	int n = stoi(vs[step]);
	// The length of the number:
	int nl = static_cast<int> (vs[step].size());
	// add '+'
	s += "+";
	s += vs[step];
	calc(vs, s, step + 1, cr + n + hor, 0, n);
	s = s.substr(0, s.size() - 1 - nl);
	// add '-'
	s += "-";
	s += vs[step];
	calc(vs, s, step + 1, cr - n + hor, 0, -1 * n); 
	s = s.substr(0, s.size() - 1 - nl);

	// add '*'
	s += "*";
	s += vs[step];
	calc(vs, s, step + 1, cr - pn, hor == 0 ? pn * n : hor * n, 0);
	s = s.substr(0, s.size() - 1 - nl);

	// add '/'
	if (n != 0) {
		s += "/";
		s += vs[step];
		calc(vs, s, step + 1, cr - pn, hor == 0 ? pn / n : hor / n, 0);
		s = s.substr(0, s.size() - 1 - nl);
		
	}
}

void do_calc(string s) {
	vector<string> result(split(s));
	string fns{result[0]}; // first number in string
	int fn = stoi(result[0]); // first number
	calc(result, fns, 1, fn, 0, fn);
}


//Do the partition of the string.
void dfs(string & s, int step) {
	if (step == static_cast<int>(s.size()) - 1) {
		cout << s << endl;
		do_calc(s);
		return;
	}
	dfs(s, step + 1);
	s = s.substr(0, step + 1) + " " + s.substr(step + 1);
	dfs(s, step + 2);
	s = s.substr(0, step + 1) + s.substr(step + 2);
}

void test_partition() {
	/*
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
	*/	
	string s {"19260817"};
	cout << "------" << endl;
	dfs(s, 0);
	
}

int main() {
	write_title();
	test_partition();
	return 0;
}

