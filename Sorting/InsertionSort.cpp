#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int key;

void InsertionSort(vector<int>& v) {

    

    for (int i = 1; i < v.size(); i++)
    {
        int j;
        key = v[i];

        for (j = i - 1; j >= 0; j--)
        {
            if (v[j] > key)
            {
                v[j + 1] = v[j];
            }
            else
            {
                break;
            }
        }

        v[j + 1] = key;
    }

}

int main() {
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(5);
	v.push_back(2);

	InsertionSort(v);

    for (const auto& v : v) cout << v;

	return 0;
}
