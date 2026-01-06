#include <iostream>
#include <cmath>

using namespace std;
int a, b, c;


long long pow(int a, int b, int c)

{
	if (b == 1)
		return a;
	else
	{
		long long temp = pow(a, b / 2, c);
		
		if (b % 2)
			return ((temp * temp) % c * a) % c;
		else
			return (temp * temp) % c;
	}
}



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b >> c;
	cout << pow(a % c, b, c) << "\n";
	return 0;

}