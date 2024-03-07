#include <iostream> //백준 1789번
#include <vector>
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    long long int S;
    std::cin>>S;

    long long int currentNum=0;
    long long int Sum=0;

    while(true){
        if(Sum==S){
            break;
        }
        else if(Sum<S){
            currentNum++;
            Sum+=currentNum;
        }
        else if(Sum>S){
            if((Sum-S)<currentNum){
                Sum=S;
                currentNum--;
            }
        }
    }
    
    std::cout<<currentNum;

    return 0;
}
