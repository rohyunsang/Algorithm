#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define PI 3.141592

int main() {
    int n = 3;   // 꼭짓점 개수
    double l = 10; // 한 변의 길이

    double r = l / (2 * sin(PI / n)); // 외접원의 반지름 계산

    vector<pair<double, double>> points;

    for (int i = 0; i < n; i++)
    {
        double theta = 2 * PI * i / n; // 각도
        double x = r * cos(theta);
        double y = r * sin(theta);
        points.push_back({ x, y });
    }

    // 출력
    for (int i = 0; i < n; i++)
    {
        cout << "Point " << i + 1 << ": (" << points[i].first << ", " << points[i].second << ")" << endl;
    }

    return 0;
}
