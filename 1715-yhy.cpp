#include <iostream>
#include <queue>
#include <vector>

struct compare{
    bool operator()(int o1, int o2){
        return o1>o2;
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin>>N;

    std::priority_queue<int, std::vector<int>, compare> qu;
    for(int i=0; i<N; i++){
        int temp;
        std::cin>>temp;
        qu.push(temp);
    }
    int o1,o2,o3;
    int sum=0;
    for(int i=0; i<N-1; i++){
        o1=qu.top();
        qu.pop();
        o2=qu.top();
        qu.pop();
        o3=o1+o2;
        sum+=o3;
        qu.push(o3);
    }

    std::cout<<sum<<'\n';
    
    return 0;
}
