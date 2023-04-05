#include <iostream>
#include <vector>

using namespace std;

int parent[100];

//Union Find 
// 1-1 2-2 3-3 4-4 5-5 

// DisJointSet�� ǥ���Ҷ� Union Find 

int find_parent(int x) {
    if (parent[x] != x)
        return parent[x] = find_parent(parent[x]);
    return x;
}
void merge(int a, int b) {
    int x = find_parent(a);
    int y = find_parent(b);

    if (x != y) {
        if (x < y) // �׷��ȣ�� �� ���� ������ ��ġ��
            parent[y] = x;
        else
            parent[x] = y;
    }
}