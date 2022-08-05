#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {

    int arr[5] = {1,2,3,4,5}; //5
    int arr2[8] = {2,1,2,3,2,4,2,5};  //8
    int arr3[10] = {3,3,1,1,2,2,4,4,5,5}; //10 
    int correct = 0;
    int correct2 = 0;
    int correct3 = 0;

    vector<int> answer_return;
    for(int i = 0 ; i < answers.size() ; i++){
        if(answers[i] == arr[i%5]){
            correct++;
        }
        if(answers[i] == arr2[i%8]){
            correct2++;
        }
        if(answers[i] == arr3[i%10]){
            correct3++;
        }
    }

    vector<pair <int,int>> v;
    v.push_back(make_pair(correct,1));
    v.push_back(make_pair(correct2,2));
    v.push_back(make_pair(correct3,3));
    sort(v.begin(),v.end());
    answer_return.push_back(v[2].second);
    if(v[2].first == v[1].first){
        answer_return.push_back(v[1].second);
    }
    if(v[2].first == v[0].first){
        answer_return.push_back(v[0].second);
    }


    sort(answer_return.begin(),answer_return.end());
    return answer_return;
}
