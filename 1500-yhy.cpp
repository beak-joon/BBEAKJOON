#include <iostream> //백준 1500번
#include <vector>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int S,K;
    std::cin>>S>>K;

    std::vector<int> ve(K,S/K);

    int another=S%K; //ve에 더 더해야되는 값

    for(int i=0; i<another; i++){
        ve[i]+=1;
    }

    long long result=1;

    for(int i=0; i<K; i++){
        result*=ve[i];
    }

    std::cout<<result;

    return 0;
}
