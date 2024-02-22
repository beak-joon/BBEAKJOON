#include <iostream> //백준 1565번, 계속 시간 초과 뜨는 데 이유를 모르겠음.
#include <vector>
#include <algorithm>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}//두 수의 최대 공약수 구하기



long long multipleLCM(std::vector<long long>& numbers) {
    int result = numbers[0];
    long long current_gcd=1;
    for (int i = 1; i < numbers.size(); ++i) {
        current_gcd = gcd(result, numbers[i]);
        result=(result*numbers[i])/current_gcd;
    }
    return result;
}//여러 수의 최소 공배수 구하기

long long multipleGCD(std::vector<long long>& numbers){
    int result = numbers[0];
    for (int i=1; i<numbers.size(); i++){
        result=gcd(result,numbers[i]);
    }
    return result;
}

long long Min(std::vector<long long> ve,size_t length){
    long long min=ve[0];
    for(int i=1; i<length; i++){
        if(min>ve[i]){
            min=ve[i];
        }
    }

    return min;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int D,M;
    std::cin>>D>>M;

    std::vector<long long> ve_D(D);
    std::vector<long long> ve_M(M);
    std::vector<long long> ve;
    ve.clear();

    for(int i=0; i<D; i++){
        std::cin>>ve_D[i];
    }
    
    for(int i=0; i<M; i++){
        std::cin>>ve_M[i];
    }

    long long gcd_M;
    long long min_M=Min(ve_M,M);

    gcd_M=multipleGCD(ve_M);

    long long lcm_D=multipleLCM(ve_D); //ve_D의 최소공배수
    //std::cout<<"lcm_D : "<<lcm_D<<"\n";
    int copy_lcm_D=lcm_D;
    int result=0;

    while(lcm_D<=gcd_M){
        if(gcd_M%lcm_D==0){
            result++;
        }
        lcm_D+=copy_lcm_D;
    }

    std::cout<<result;

    return 0;
}
