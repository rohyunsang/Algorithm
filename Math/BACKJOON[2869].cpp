#include <iostream>

void test(int n) {

	std::cout << test << n << std::endl;
	return test(n - 1);
}

int main() {
	
	test(5);
	return 0;
}
