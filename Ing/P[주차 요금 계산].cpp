#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

// fee : 기본시간, 기본 요금, 단위 시간, 단위 요금

vector<pair<int, int>> inCars;
vector<pair<int, int>> outCars;
vector<int> answer;

void SplitRecords(vector<int> fees, vector<string> records) {
    for (const auto record : records) {
        stringstream ss;
        ss << record;
        string sTime = "";
        string sCarNum = "";
        string sState = "";
        ss >> sTime;
        ss >> sCarNum;
        ss >> sState;
        cout << sTime << " " << sCarNum << " " << sState;
        int nTime = stoi("" + sTime[0] + sTime[1]) * 60 + stoi("" + sTime[3] + sTime[4]);
        if (sState == "IN")
            inCars.push_back({ nTime,stoi(sCarNum) });
        else
        {
            for (const auto inCar : inCars) {
                if (inCar.second == stoi(sCarNum))
                {
                    int sum = 0;
                    sum = stoi(sTime) - inCar.first;
                    if (sum <= fees[0]) // 기본시간 보다 작으면
                        answer.push_back(fees[1]);
                    else {
                        if ((sum - fees[0]) % fees[2] > 0)
                        {
                            answer.push_back(fees[1] + (sum - fees[0]) * fees[3] + fees[3]);
                        }
                        else {
                            answer.push_back(fees[1] + (sum - fees[0]) * fees[3]);
                        }
                    }
                }
            }
        }
    }
}


vector<int> solution(vector<int> fees, vector<string> records) {

    SplitRecords(fees, records);

    for (const auto inCar : inCars) { // 출차를 안했다면 23:59로 계산
        int sum = 0;
        sum = 23 * 60 + 59 - inCar.first;
        if (sum <= fees[0]) // 기본시간 보다 작으면
            answer.push_back(fees[1]);
        else {
            if ((sum - fees[0]) % fees[2] > 0)
            {
                answer.push_back(fees[1] + (sum - fees[0]) * fees[3] + fees[3]);
            }
            else {
                answer.push_back(fees[1] + (sum - fees[0]) * fees[3]);
            }
        }
    }

    return answer;
}