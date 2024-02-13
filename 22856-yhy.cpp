#include <iostream> //22856번, 아직 수정 중, 가능한 예시 다 되는 데 틀렸다고 나와요
#include <vector>

int count=0;
int endflag;
bool endcheck=false;

typedef struct Node{
    int key=0;
    struct Node* left=NULL;
    struct Node* right=NULL;
} Node; //tree에서 각 노드 구조 정의

static std::vector<Node> tree; //트리 생성
static std::vector<bool> visited;
void inorder(Node* N);
int findendflag(Node* N);

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin>>N;

    tree=std::vector<Node>(N+1);
    visited.resize(N+1,false);

    int n1,n2,n3;
    for(int i=1; i<N+1; i++){
        std::cin>>n1>>n2>>n3;
        tree[i].key=i;
        if(n2==-1){
            tree[i].left=NULL;
        }
        else if(n2!=-1){
            tree[i].left=&tree[n2];
        }
        if(n3==-1){
            tree[i].right=NULL;
        }
        else if(n3!=-1){
            tree[i].right=&tree[n3];
            }
    }
    
    endflag=findendflag(&tree[1]); //트리의 끝 점 구하기
    //std::cout<<endflag;

    inorder(&tree[1]);

    std::cout<<count;

    return 0;
}

void inorder(Node* N){
    if(N!=NULL){

        if(N->left!=NULL && !endcheck && !visited[N->left->key]){
            visited[N->left->key]=true;
            count++;
            inorder(N->left);
        }
        if(N->key==endflag){
            endcheck=true;
        }
        
        if(N->right!=NULL && !endcheck && !visited[N->right->key]){
            visited[N->right->key]=true;
            count++;
            inorder(N->right);
        }
        
        if((N->left==NULL || visited[N->left->key]) &&(N->right==NULL || visited[N->right->key]) && (!endcheck)){
            count++;
        }
    }
    
}

int findendflag(Node* N){
    if(N->right==NULL){
        return N->key;
    }
    else if(N->right!=NULL){
        return findendflag(N->right);
    }
    
} //트리의 유사중회순회시 끝점을 찾음
