#include <bits/stdc++.h>
using namespace std;

int N,M;

int dx[] = {0,0,-1,1}; //상 하 좌 우 
int dy[] = {1,-1,0,0};  

int arr[1000][1000];
int cnt = 0;


void BFS(int x, int y){
    if(arr[x][y] == 0 && arr[x][y] == -1) continue;
    if(arr[x][y] >= 1) {
        for(int i = 0 ; i< 4; i++){
            int dx = x + dx[i];
            int dy = y + dy[i];
            if(dx > 0 && dx <= N && dy > 0 && dy <= M)
            {
                arr[dx][dy] = arr[x][y] +1;
            }
        }
    }
}

int main() {
	cin >> N >> M;
	
	for(int i = 0 ; i< N ; i++)
	{
	    for(int j =0 ; j< M ; j++)
	    {
	        int x;
	        cin >> x;
	        arr[i][j] = x;
	    }
	}
	
	for(int i = 0; i< N; i++)
	{
	    for(int j =0 ; j<M;j++)
	    {
	        BFS(i,j);
	    }
	}
	
	return 0;
}
//https://www.acmicpc.net/problem/7576
