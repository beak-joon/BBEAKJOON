//1935 후위 표기식2
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define PRECISION 2

int arr[26];

void Main(){
    int n;
    double ans = 0;
    string str;
    cin >> n >> str;
    stack<double> s;
    for(int i = 0; i < n; i++){cin >> arr[i];}

    for(int i = 0; i < str.size(); i++){
        double o1, o2;
        switch(str[i]){
        case '+':
            o1 = s.top(); s.pop();
            o2 = s.top(); s.pop();
            s.push(o2+o1);
            break;
        case '-':
            o1 = s.top(); s.pop();
            o2 = s.top(); s.pop();
            s.push(o2-o1);
            break;
        case '*':
            o1 = s.top(); s.pop();
            o2 = s.top(); s.pop();
            s.push(o2*o1);
            break;
        case '/':
            o1 = s.top(); s.pop();
            o2 = s.top(); s.pop();            
            s.push(o2/o1);
            break;
        default:
            s.push(arr[str[i]-'A']);
            break;
        }
    }
    cout << s.top() << endl;
    


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(PRECISION);
    Main();
    return 0;
}
