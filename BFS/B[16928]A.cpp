#include <iostream>
#include <map>
#include <queue>

using namespace std;

// bfs + condition

int n, m;
bool visit[101] = { false, };
//vector<pair<int,int>> teleport;
// vector -> map 
map <int, int> teleport;

void bfs(int x, int cnt) {
    queue<pair<int, int>> q;
    q.push({ x, cnt });
    visit[x] = true;

    while (!q.empty()) {
        int pos = q.front().first;
        int ans = q.front().second;
        q.pop();

        for (int i = 1; i <= 6; i++) {
            int nPos = pos + i;
            if (nPos == 100) {  // 정확히 100번 위치에 도달하면 출력 후 함수 종료
                cout << ans + 1;  // 주사위를 한 번 더 굴린 것으로 계산
                return;
            }
            if (nPos > 100) continue;  // 100을 넘어가는 경우는 무시
            while (teleport[nPos] && !visit[teleport[nPos]]) {
                nPos = teleport[nPos];  // 텔레포트 후의 위치를 재설정
            }
            if (!visit[nPos]) {
                visit[nPos] = true;
                q.push({ nPos, ans + 1 });  // 이동 횟수를 1 증가시켜서 큐에 삽입
            }
        }
    }
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n + m; i++) {
		int u;
		int v;
		cin >> u >> v;
		teleport[u] = v;
		
	}
	bfs(1, 0);

	return 0;
}