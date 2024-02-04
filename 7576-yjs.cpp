//7576 토마토
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 1001

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int tomato[MAX][MAX];
int visited[MAX][MAX];

void Main(){
    int N,M;
    int days=-1;
    cin >> M >> N;
    queue<pair<int,int>> q; // queue는 좌표를 저장함 pair (x,y)

    //입력부
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) {
            cin >> tomato[i][j];
            //visited 초기화
            visited[i][j]=-1;
            //익은 토마토 들어왔을 때 queue에 좌표 넣기
            if(tomato[i][j] == 1) {
                q.push({i,j});
                visited[i][j]++;
            }
        }
    }

    //BFS
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int na = a + dx[i];
            int nb = b + dy[i];
            //range 안에 들어오고, 미방문이며, 토마토가 존재한다면
            if(na>=0 && nb >=0 && N > na && M > nb && visited[na][nb] == -1 && tomato[na][nb] == 0){
                q.push({na,nb});
                visited[na][nb]=visited[a][b]+1;
            }
        }
    }

    //최소날짜 찾기
    bool flag = false;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            //최대 방문횟수가 모든 토마토가 익을 때의 최소 날짜임.
            if(days <= visited[i][j]){
                days = visited[i][j];
            }
            //토마토가 있는데, 미방문이라면 바로 끝내버리기
            if(tomato[i][j] == 0 && visited[i][j] == -1){
                days = -1;
                flag = true;
                break;
            }
        }
        if(flag)
            break;
    }
    cout << days << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Main();
    return 0;
}
