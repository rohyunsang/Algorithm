#include <iostream>
#include <vector>

using namespace std;

void Bubble(vector<int> &v) // function to implement bubble sort  
{
    int i, j, temp;
    int n = v.size();
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (v[j] < v[i])
            {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }

}

int main() {
    vector<int> v;
    v.push_back(45);
    v.push_back(1);
    v.push_back(32);
    v.push_back(13);
    v.push_back(26);

    for (const auto& v : v) cout << v << " ";
    
    Bubble(v);
    cout << endl;
    for (const auto& v : v) cout << v << " ";

	return 0;
}
