#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int LOVE[4] = {0,};

int n;
vector<pair<string,int>> vTeam;
string yName;

int main() {
	cin >> yName;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string sTmp;
		cin >> sTmp;
		vTeam.push_back({ sTmp,0 });
	}
	
	while (n--) {
		for (int i = 0; i < vTeam[0].first.size(); i++) {
			if (vTeam[0].first[i] == 'L') {
				LOVE[0]++;
			}
			else if (vTeam[0].first[i] == 'O') {
				LOVE[1]++;
			}
			else if (vTeam[0].first[i] == 'V') {
				LOVE[2]++;
			}
			else if (vTeam[0].first[i] == 'E') {
				LOVE[3]++;
			}
		}

		for (int i = 0; i < yName.size(); i++) {
			if (yName[i] == 'L') {
				LOVE[0]++;
			}
			else if (yName[i] == 'O') {
				LOVE[1]++;
			}
			else if (yName[i] == 'V') {
				LOVE[2]++;
			}
			else if (yName[i] == 'E') {
				LOVE[3]++;
			}
		}

		int score = ((LOVE[0] + LOVE[1]) * (LOVE[0] + LOVE[2])
			* (LOVE[0] + LOVE[3]) * (LOVE[1] + LOVE[2])
			* (LOVE[1] + LOVE[3]) * (LOVE[2] + LOVE[3])) % 100;

		//init
		for (int i = 0; i < 4; i++) {
			LOVE[i] = 0;
		}
	}


	return 0;
}