//1946 신입 사원
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void Main(){
    int T, N;
    cin >> T;
    for(int i=0; i<T; i++){
        int ans=1;
        cin >> N;
        vector<pair<int, int>> v(N);
        for(int j=0; j<N; j++){cin >> v[j].first >> v[j].second;}
        sort(v.begin(), v.end());

        int curMin=v[0].second;
        for(int j=0; j<N; j++){
            if(curMin>v[j].second){curMin = v[j].second; ans++;}
        }

        cout << ans << endl;
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Main();
    return 0;
}