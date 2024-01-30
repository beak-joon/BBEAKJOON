#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 300001
using namespace std;

struct compare{ //보석 무게순 정렬
    bool operator()(int v1, int v2){
        return v1 < v2;
    }
};

int main() {
    int N; // 보석 수
    int K; // 가방수

    pair<int, int> arrV[MAX];
    int arrB[MAX];
    priority_queue<int, vector<int>, compare> QueueB;
    
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> arrV[i].first >> arrV[i].second;
    }
    for(int i = 0; i < K; i++) {
        cin >> arrB[i];
    }
    sort(arrV, arrV+N); //오름차순
    sort(arrB, arrB+K);
    
    long long sum=0;
    int index = 0;

    for (int i = 0; i < K; i++) {
        while (index < N && arrB[i] >= arrV[index].first) {
            QueueB.push(arrV[index].second);
            index+=1;
        }
        if (!QueueB.empty()) {
            sum += QueueB.top();
            QueueB.pop();
        }
    }
    
    cout << sum << '\n';
}
