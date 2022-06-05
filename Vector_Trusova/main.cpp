#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
	Vector <char> a;
	a.push_back('a');
	a.push_back('b');
	cout << a.size() << endl;
	a.resize(5);
	cin >> a[2];
	for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
	
	return 0;
}