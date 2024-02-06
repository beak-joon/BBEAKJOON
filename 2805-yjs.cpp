//2805 나무 자르기
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void Main(){
    int N, M;
    long long ans = 0;
    long long mid;
    cin >> N >> M;
    vector<int> v(N);
    for(int i=0; i<N; i++){cin >> v[i];}
    sort(v.begin(), v.end());
    //10 15 17 20 // 7
    long long s = 0, e = v[N-1];
    while(s <= e){
        long long sum = 0;
        mid = s+(e-s)/2;
        for(int i=0; i<N; i++){
            if(mid < v[i]){sum += v[i] - mid;}
        }
        if(sum >= M){s = mid+1; ans = mid;}
        else if(sum < M){e = mid-1;}
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Main();
    return 0;
}
