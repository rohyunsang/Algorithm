#include <iostream>
#include <vector>

using namespace std;

long long arr[1000001]; // �Է� �迭
long long segtree[4000001]; // ���׸�Ʈ Ʈ�� �迭

// ���׸�Ʈ Ʈ�� �ʱ�ȭ �Լ�
long long Init(int start, int end, int nodeNum) {
    if (start == end) { // ���� ���
        return segtree[nodeNum] = arr[start];
    }
    int mid = (start + end) / 2;
    return segtree[nodeNum] = Init(start, mid, nodeNum * 2) + Init(mid + 1, end, nodeNum * 2 + 1);
}

// ���� ���� ���ϴ� �Լ�
long long query(int idx, int start, int end, int left, int right) {
    if (right < start || end < left) return 0; // ������ ��ġ�� ����
    if (left <= start && end <= right) return segtree[idx]; // ������ ������ ���ԵǴ� ���
    int mid = (start + end) / 2;
    return query(idx * 2, start, mid, left, right) + query(idx * 2 + 1, mid + 1, end, left, right);
}

// ���� �����ϴ� �Լ�
void update(int idx, int start, int end, int target, long long diff) {
    if (target < start || target > end) return; // ���� ��
    segtree[idx] += diff; // ��ȭ�� ����ŭ Ʈ�� ����
    if (start != end) { // ���� ��尡 �ƴ� ��� �ڽĵ鵵 ����
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

    // ���׸�Ʈ Ʈ�� �ʱ�ȭ
    Init(1, n, 1);  // nodeNum�� 1�� �־��ִ� ������ ����Ʈ������ rootNode�� ù��°�� ��ġ���ִ�.

    // �� M + K ���� ��� ó��
    for (int i = 0; i < m + k; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;

        if (a == 1) {
            // �� ����: b��° ���� c�� ����
            long long diff = c - arr[b]; // ��ȭ�� ���
            arr[b] = c; // �迭 �� ����
            update(1, 1, n, b, diff); // ���׸�Ʈ Ʈ�� �� ����
        }
        else if (a == 2) {
            // ���� �� ���: b���� c������ ��
            cout << query(1, 1, n, b, c) << '\n';
        }
    }

    return 0;
}