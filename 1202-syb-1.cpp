#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef int M;
typedef int V;

struct compare{ //보석 가격순 정렬
    bool operator()(pair<M,V>& v1, pair<M,V>& v2){
        return v1.second < v2.second;
    }
};

struct comp{ //가방 무게순 정렬
    bool operator()(int m1, int m2){
        return m1 < m2;
    }
};

int main() {
    priority_queue<pair<M,V>, vector<pair<M,V>>, compare> QueueV;
    priority_queue<int, vector<int>, comp> QueueB;
    
    int N,K,sum=0;
    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        int M,V;
        cin >> M >> V;
        QueueV.push({M,V}); 
    }
    for(int i = 0; i < K; i++) {
        int M;
        cin >> M;
        QueueB.push(M);
    }
    while(!QueueB.empty()) {
        if(QueueB.top() > QueueV.top().first){
            sum += QueueV.top().second;
            QueueB.pop();
            QueueV.pop();
        }
        else{
            QueueV.pop();
        }

        if(QueueV.empty()){
            break;
        }
    }
    cout << sum << '\n';
}
