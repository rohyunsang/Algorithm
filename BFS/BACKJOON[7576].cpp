#include <bits/stdc++.h>
using namespace std;

int N,M;

int dx[] = {0,0,-1,1}; //상 하 좌 우 
int dy[] = {1,-1,0,0};  

int arr[1000][1000];
int cnt = 0;

queue<pair<int, int>> q;


void BFS(void){
    
    while(!q.empty()){
        
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0 ; i< 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if((0 <= nx && 0 <= ny && nx < M && ny < N) && arr[nx][ny] == 0)
            {
                arr[nx][ny] = arr[x][y] +1;
                q.push(make_pair(nx,ny));
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
	        if(arr[i][j] == 1){
	            q.push(make_pair(i,j));
	        }
	    }
	}
	
	BFS();
	
	for(int i = 0; i< N; i++)
	{
	    for(int j =0 ; j<M;j++)
	    {
	        if(arr[i][j] == 0){
	            cout << "-1" ;
	            return 0;
	        }
	        
	        if(cnt < arr[i][j]){
	            cnt = arr[i][j];
	        }
	    }
	}
	
	cout << cnt-1;
	
	return 0;
}
//https://www.acmicpc.net/problem/7576
