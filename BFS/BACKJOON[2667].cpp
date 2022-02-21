#include <bits/stdc++.h>
using namespace std;

int N;
int arr[25][25];
bool visited[25][25];
int cnt = 0;
int dx[4] = { -1,1,0,0};
int dy[4] = { 0,0,1,-1};

vector <int> vec;

void DFS(int x,int y){
    cnt++;
    visited[x][y] = true;
    
    for(int i=0;i<4;i++){
        int nx = x +dx[i];
        int ny = y +dy[i];
        if(nx<0||nx>=N||ny<0||ny>=N) continue;
        if(arr[nx][ny] ==1 && visited[nx][ny] == false){
            DFS(nx,ny);
        }
    }
}

int main() {
	// your code goes here
	cin >> N;
	
	for(int i=0;i<N;i++)
	{
	    for(int j=0;j<N;j++){
	         scanf("%1d", &arr[i][j]); //scanf, scanf_s error
	    }
	}
	
	for(int i=0;i<N;i++)
	{
	    for(int j=0;j<N;j++){
	         if(arr[i][j] == 1 && visited[i][j] == false){
	             cnt = 0;
	             DFS(i,j);
	             vec.push_back(cnt);
	         }
	    }
	}
	
	sort(vec.begin(),vec.end());
	cout << vec.size() <<endl;
	
	for(int i = 0 ; i < vec.size(); i++){
	    cout << vec[i] <<endl;
	}
	
	return 0;
}
//https://www.acmicpc.net/problem/2667
