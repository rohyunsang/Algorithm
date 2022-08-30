#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>// std::vector

using namespace std;

vector<int> v;


int main() {

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i * 10);
    }
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i * 20);
    }

    sort(v.begin(), v.end());                

    vector<int>::iterator low, up;  // vector 반복자 low up 선언 
    low = std::lower_bound(v.begin(), v.end(), 20); // low는 20의 시작점을 가리킴   
    up = std::upper_bound(v.begin(), v.end(), 20); //  up은 20의 끝점을 가리킴         

    std::cout << "lower_bound at position " << (low - v.begin()) << '\n';
    std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

    for (auto& v : v)
        cout << v << " ";

    return 0;
}

/*  Console
lower_bound at position 3
upper_bound at position 5
0 0 10 20 20 30 40 40 50 60 60 70 80 80 90 100 120 140 160 180*/


/*template <class ForwardIterator, class T>
ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last,
    const T& val);*/