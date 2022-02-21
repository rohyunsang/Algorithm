#include <bits/stdc++.h>
using namespace std;
using namespace queue;

//육지(L) 바다(W)

int N,M;
int maxNum = 0;
int arr[50][50];
int sum[50][50];
bool visit[50][50];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

void BFS(int x, int y){
    
    visit[x][y] = true;
    queue < pair<int,int>> = q;
    q.push(make_pair(x,y));
    
    while(!q.empty()){
        int x = q.fornt().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            
        int nx = x + dx[i];
        int ny = y + dy[i];
        
            if(arr[nx][ny] == 1 && !visit[nx][ny]){
                visit[nx][ny] = true;
                q.push(make_pair(nx,ny));
                sum[nx][ny] = sum[x][y] +1;
                if(maxNum <= sum[nx][ny])
                {
                    maxNum = sum[nx][ny];
                }
            }
        }
    }
}

int main() {
	cin >> N >> M;
	
    char tmep;
	
	for(int i=0;i<N;i++)
	{
	    for(int j=0;j<M;j++)
	    {
	        cin >> tmep;
	        if(temp == 'L'){
	            arr[i][j] =1;
	        }
	    }
	}
	
	for(int i=0;i<N;i++)
	{
	    for(int j=0;j<M;j++)
	    {
	        BFS(i,j);
	        memset(visit,false,sizeof(visit)); //void* memset(void* ptr, int value, size_t num);
	        memset(sum,0,sizeof(sum));
	    }
	}
	
	cout << maxNum;
	return 0;
}
//https://www.acmicpc.net/problem/2589
