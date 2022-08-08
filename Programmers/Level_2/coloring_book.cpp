#include <vector>
#include <algorithm>
#include <cstring> //memset

//DFS

using namespace std;

int M,N;
int dy[4] = {0,-1,0,1};
int dx[4] = {-1,0,1,0};
bool visited[100][100];

int dfs (int y, int x , int pic , const vector<vector<int>> &picture)
{
    visited[y][x] = true;
    int result = 1;
    for(int i = 0 ; i < 4 ; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny < 0 || nx < 0 || ny >= M || nx >= N || visited[ny][nx]) 
            continue;
        if(picture[ny][nx] != pic) 
            continue;
        result += dfs(ny,nx,pic,picture);
    }
    return result;
}
    


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    M = m;
    N = n;
    
    memset(visited,0,sizeof(visited));
    
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(!visited[i][j] && picture[i][j] !=0){
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area,dfs(i,j,picture[i][j],picture));
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
