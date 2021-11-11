#include <iostream>
using namespace std;

int main() {
	int n;
	int i{ 0 }, j{ 0 }, k{ 0 };

	cin >> n;

	for (i = 1; i < n + 1; i++) {
		for (k = n - i; k > 0; k--) {
			cout << " ";
		}
		for (j = 1; j < i + 1; j++) {
			cout << "*";
		}
		cout << endl;
	}

}