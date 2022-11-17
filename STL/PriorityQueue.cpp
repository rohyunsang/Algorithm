#include <iostream>
#include <queue>
#include <functional>    // greater
using namespace std;

struct Student {
    int id;
    int math, eng;
    Student(int num, int m, int e) : id(num), math(m), eng(e) {}    // ������ ����
};

// �й��� �������� �й�(id) ���� ū ���� Top �� ���� �ϵ��� �Ѵ�.
struct cmp {
    bool operator()(Student a, Student b) {
        return a.id < b.id;
    }
};

int main() {

    priority_queue<int> pq;  // - >  priority_queue<int, vector<int>, less<int>> pq;

    // �켱���� ť�� ���Ҹ� ���� (push) �Ѵ� 
    pq.push(4);
    pq.push(7);
    pq.push(3);
    pq.push(1);
    pq.push(10);

    cout << "�켱���� ť ������ : " << pq.size() << "\n";
    // �켱���� ť�� ��� ���� �ʴٸ� while ���� ��� ����
    while (!pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
    }

    // ������ ���� cmp ����ü�� �־� �ش�.
    priority_queue<Student, vector<Student>, cmp> pq2;


    pq2.push(Student(3, 100, 50));
    pq2.push(Student(1, 60, 50));
    pq2.push(Student(2, 80, 50));
    pq2.push(Student(4, 90, 50));
    pq2.push(Student(5, 70, 40));

    while (!pq2.empty()) {
        Student ts = pq2.top(); pq2.pop();
        cout << "(�й�, ���� , ���� ) : " << ts.id << ' ' << ts.math << ' ' << ts.eng << '\n';
    }

    
    return 0;
}

#include <queue>
#include <iostream>
using namespace std;

int main() {
    // �켱���� ť�� <�ڷ���, ����ü, �񱳿�����> �� �̿��Ͽ� �����Ѵ�.
    // �񱳿����ڿ� greater<int>�� ����Ͽ� int�� �������� �켱�Ѵ�.
    priority_queue <int, vector<int>, greater<int> > pq;

    pq.push(5);
    pq.push(3);
    pq.push(6);
    pq.push(7);

    while (!pq.empty()) {
        int temp = pq.top();
        cout << temp;
        pq.pop();
    }
    // ��°��
    // 3567
    return 0;
}
