#include <string>
#include <vector>
#include <map>

using namespace std;

int ansTmp = 0;
map<string, int> m;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;

    for (int i = 0; i < name.size(); i++) {
        m[name[i]] = yearning[i];
    }

    for (int i = 0; i < photo.size(); i++) {
        int ansTmp = 0;
        for (int j = 0; j < photo[i].size(); j++) {
            ansTmp += m[photo[i][j]];
        }
        answer.push_back(ansTmp);

    }


    return answer;
}