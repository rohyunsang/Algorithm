#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;



int AddCleaningTime(int n) { // 12 50 => 13 00

    n = n + 10;
    if (n % 100 >= 60)
        n = n + 100 - 60;
    return n;
}

priority_queue<int, vector<int>, less<int>> q;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    int bookSize = book_time.size();

    vector<pair<int, int>> v;

    for (int i = 0; i < book_time.size(); i++) {
        book_time[i][0].erase(2, 1);
        book_time[i][1].erase(2, 1);

        v.push_back({ stoi(book_time[i][0]),stoi(book_time[i][1]) });
    }

    sort(v.begin(), v.end());

    q.push(AddCleaningTime(v[0].second));
    answer++;

    for (int i = 1; i < book_time.size(); i++) {


        if (q.top() <= v[i].first) {
            for (int j = 0; j < answer; j++)
                q.pop();
        }

        else {
            answer++;
            cout << i << " " << q.top() << " " << v[i].first << " " << v[i].second << "plus answwer;" << endl;
            break;
        }

        q.push(AddCleaningTime(v[i].second));

    }




    return answer;
}