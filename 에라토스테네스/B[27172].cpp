#include <iostream>
#include <vector>

using namespace std;

int Players[1000001];
vector<int> Cards;
vector<int> Scores;


int main() {

	for (int i = 1; i <= 1000000; i++)
	{
		Players[i] = -1;
	}

	int N;
	cin >> N;

	Cards.reserve(N);
	Scores.reserve(N);

	for (int i = 0; i < N; i++)
	{
		int Card;
		cin >> Card;
		Players[Card] = i;
		Cards.emplace_back(Card);
		Scores.emplace_back(0);
	}

	for (const int& Card : Cards)
	{
		for (int i = 2; Card * i <= 1000000; i++)
		{
			int OpponentCard = Card * i;
			if (Players[OpponentCard] >= 0)
			{
				++Scores[Players[Card]];
				--Scores[Players[OpponentCard]];
			}
		}
	}




	return 0;
}