#include <iostream>
#include <string>

using namespace std;

int n;

void Recursive(int i, int j, int n) {
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
	{
		cout << ' ';
	}
	else {
		if (n / 3 == 0)
			cout << '*';
		else
			Recursive(i, j, n / 3);

	}
}

int main() {
	
	cin >> n;
	
	// empty
	// 1 1
	// 4 1
	// 7 1
	// 3 3 
	// 3 4
	// 3 5
	// 4 3
	// 4 4
	// 4 5
	// 5 3
	// 5 4
	// 5 5 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Recursive(i, j, n);
		}
		cout << endl;
	}



	return 0;
}