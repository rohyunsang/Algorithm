#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, k;
int map[51][51];
vector<pair<int, int>> houses, chickenStores;
vector<pair<int, int>> selectedStore;
int minDistance = INT_MAX;

int CalculateDistance() {
    int totalDistance = 0;
    for (auto house : houses) {
        int houseDistance = INT_MAX;
        for (auto store : selectedStore) {
            houseDistance = min(houseDistance, abs(house.first - store.first) + abs(house.second - store.second));
        }
        totalDistance += houseDistance;
    }
    return totalDistance;
}

void Combination(int cnt, int start) {
    if (cnt == k) {
        minDistance = min(minDistance, CalculateDistance());
        return;
    }
    for (int i = start; i < chickenStores.size(); i++) {
        selectedStore.push_back(chickenStores[i]);
        Combination(cnt + 1, i + 1);
        selectedStore.pop_back();
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) houses.push_back({ i, j });
            else if (map[i][j] == 2) chickenStores.push_back({ i, j });
        }
    }
    Combination(0, 0);
    cout << minDistance << endl;

    return 0;
}