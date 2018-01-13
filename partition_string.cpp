#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;

using std::vector;
using std::string;

/*
For a string that is n characters long, there are n - 1 positions.
*/
vector<vector<int>> vv(0);
void d(vector<int> & v, int step, int size) {
	if (step == size) {
		vector<int> v_c(v);
		vv.push_back(v_c);
		return;
	}
	v[step] = 1;
	d(v, step + 1, size);
	v[step] = 0;
	d(v, step + 1, size);
}

int main() {
	string s0 {"a"};
	string s1 {"abcd"};


	vector<int> v(0);
	decltype (s1.size()) i = 0;
	while(i < s1.size() - 1) {
		v.push_back(0);
		i++;
	}
	for (auto i: v)
		cout << i;
	cout << endl;

	d(v, 0, static_cast<int> (v.size()));
	cout << "size :" << vv.size() << endl;
	for (auto v: vv)
		cout << "P :";
		for (auto i: v)
			cout << i;	
		cout << endl;

	return 0;
}
