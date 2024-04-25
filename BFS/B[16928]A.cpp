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
            if (nPos == 100) {  // ��Ȯ�� 100�� ��ġ�� �����ϸ� ��� �� �Լ� ����
                cout << ans + 1;  // �ֻ����� �� �� �� ���� ������ ���
                return;
            }
            if (nPos > 100) continue;  // 100�� �Ѿ�� ���� ����
            while (teleport[nPos] && !visit[teleport[nPos]]) {
                nPos = teleport[nPos];  // �ڷ���Ʈ ���� ��ġ�� �缳��
            }
            if (!visit[nPos]) {
                visit[nPos] = true;
                q.push({ nPos, ans + 1 });  // �̵� Ƚ���� 1 �������Ѽ� ť�� ����
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