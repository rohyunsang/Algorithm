#include <iostream>
#include <vector>

using namespace std;

long long arr[1000001]; // 입력 배열
long long segtree[4000001]; // 세그먼트 트리 배열

// 세그먼트 트리 초기화 함수
long long Init(int start, int end, int nodeNum) {
    if (start == end) { // 리프 노드
        return segtree[nodeNum] = arr[start];
    }
    int mid = (start + end) / 2;
    return segtree[nodeNum] = Init(start, mid, nodeNum * 2) + Init(mid + 1, end, nodeNum * 2 + 1);
}

// 구간 합을 구하는 함수
long long query(int idx, int start, int end, int left, int right) {
    if (right < start || end < left) return 0; // 구간이 겹치지 않음
    if (left <= start && end <= right) return segtree[idx]; // 구간이 완전히 포함되는 경우
    int mid = (start + end) / 2;
    return query(idx * 2, start, mid, left, right) + query(idx * 2 + 1, mid + 1, end, left, right);
}

// 값을 갱신하는 함수
void update(int idx, int start, int end, int target, long long diff) {
    if (target < start || target > end) return; // 범위 밖
    segtree[idx] += diff; // 변화된 값만큼 트리 갱신
    if (start != end) { // 리프 노드가 아닌 경우 자식들도 갱신
        int mid = (start + end) / 2;
        update(idx * 2, start, mid, target, diff);
        update(idx * 2 + 1, mid + 1, end, target, diff);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // 세그먼트 트리 초기화
    Init(1, n, 1);  // nodeNum에 1을 넣어주는 이유는 세그트리에서 rootNode는 첫번째에 위치해있다.

    // 총 M + K 번의 명령 처리
    for (int i = 0; i < m + k; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;

        if (a == 1) {
            // 값 변경: b번째 수를 c로 변경
            long long diff = c - arr[b]; // 변화량 계산
            arr[b] = c; // 배열 값 갱신
            update(1, 1, n, b, diff); // 세그먼트 트리 값 갱신
        }
        else if (a == 2) {
            // 구간 합 출력: b부터 c까지의 합
            cout << query(1, 1, n, b, c) << '\n';
        }
    }

    return 0;
}