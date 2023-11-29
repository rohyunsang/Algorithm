#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int map[51][51];
int r, c, t;
vector<pair<int, int>> v;
vector<pair<int, int>> airCleanerPoint;

void CheckMap() {
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] >= 5)
				v.push_back({ i,j });
		}
	}
}
void Spread() {
	int spreadMap[51][51] = {0,};

	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;

		vector<pair<int, int>> spreadPoint;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c)
				continue;
			if (map[nx][ny] == -1)
				continue;
			spreadPoint.push_back({ nx,ny });
		}

		for (int i = 0; i < spreadPoint.size(); i++) {
			spreadMap[spreadPoint[i].first][spreadPoint[i].second] += map[x][y] / 5;
		}
		map[x][y] -= (map[x][y] / 5) * (int)spreadPoint.size();

	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			map[i][j] += spreadMap[i][j];
		}
	}

}
void AirCleaner() {
	// Up
	int x = airCleanerPoint[0].first;  // airCleanerPoint[0].first == 0 
	int y = airCleanerPoint[0].second;
	
	for (int i = 1; i < y ; i++) {
		map[x][y - i] = map[x][y - i - 1];
	}
	// ...etc 

	//Down
}

int main() {
	
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				airCleanerPoint.push_back({ i,j });
			}
		}
	}

	for (int i = 0; i < t; i++) {
		CheckMap();
		Spread();
		AirCleaner();
	}

	// Debug
	cout << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout <<  map[i][j] << " ";
		}
		cout << endl;
	}
	// Debug End

	return 0;
}