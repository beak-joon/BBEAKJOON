#include<bits/stdc++.h>

using namespace std;

bool compare(pair<int,int>& v1, pair<int,int>& v2){
    return v1.second < v2.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, C=0;
    cin >> N;
    vector<pair<int,int>> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i].first;
        v[i].second = i;
    }
    // 숫자기준 정렬
    sort(v.begin(), v.end());

    for(int i=0; i<N; i++){
        if(v[i].first != v[i+1].first){
            v[i].first = C++;
        }
        else{
            v[i].first = C;
        }
    }
    // index 기준정렬
    sort(v.begin(), v.end(), compare);

    for(int i=0; i<N; i++){
        cout << v[i].first << ' ';
    }
    return 0;
}
