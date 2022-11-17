#include <iostream>
#include <queue>
#include <functional>    // greater
using namespace std;

struct Student {
    int id;
    int math, eng;
    Student(int num, int m, int e) : id(num), math(m), eng(e) {}    // 생성자 정의
};

// 학번을 기준으로 학번(id) 값이 큰 것이 Top 을 유지 하도록 한다.
struct cmp {
    bool operator()(Student a, Student b) {
        return a.id < b.id;
    }
};

int main() {

    priority_queue<int> pq;  // - >  priority_queue<int, vector<int>, less<int>> pq;

    // 우선순위 큐에 원소를 삽입 (push) 한다 
    pq.push(4);
    pq.push(7);
    pq.push(3);
    pq.push(1);
    pq.push(10);

    cout << "우선순위 큐 사이즈 : " << pq.size() << "\n";
    // 우선순위 큐가 비어 있지 않다면 while 문을 계속 실행
    while (!pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
    }

    // 위에서 만든 cmp 구조체를 넣어 준다.
    priority_queue<Student, vector<Student>, cmp> pq2;


    pq2.push(Student(3, 100, 50));
    pq2.push(Student(1, 60, 50));
    pq2.push(Student(2, 80, 50));
    pq2.push(Student(4, 90, 50));
    pq2.push(Student(5, 70, 40));

    while (!pq2.empty()) {
        Student ts = pq2.top(); pq2.pop();
        cout << "(학번, 수학 , 영어 ) : " << ts.id << ' ' << ts.math << ' ' << ts.eng << '\n';
    }

    
    return 0;
}

#include <queue>
#include <iostream>
using namespace std;

int main() {
    // 우선순위 큐를 <자료형, 구현체, 비교연산자> 를 이용하여 선언한다.
    // 비교연산자에 greater<int>를 사용하여 int가 작은값이 우선한다.
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
    // 출력결과
    // 3567
    return 0;
}
