#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define PI 3.141592

int main() {
    int n = 3;   // ������ ����
    double l = 10; // �� ���� ����

    double r = l / (2 * sin(PI / n)); // �������� ������ ���

    vector<pair<double, double>> points;

    for (int i = 0; i < n; i++)
    {
        double theta = 2 * PI * i / n; // ����
        double x = r * cos(theta);
        double y = r * sin(theta);
        points.push_back({ x, y });
    }

    // ���
    for (int i = 0; i < n; i++)
    {
        cout << "Point " << i + 1 << ": (" << points[i].first << ", " << points[i].second << ")" << endl;
    }

    return 0;
}
