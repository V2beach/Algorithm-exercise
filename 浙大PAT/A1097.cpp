#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Node{
    int add, key, next;
} nodes[100001];

int main(int argc, char* argv[]){
    //存成静态链表->遍历存入vector并将重复值存入另一个vector->根据现在的顺序改变next值并输出
    int add, add0, N;
    scanf("%d %d", &add0, &N);
    
    for (int i = 0; i < N; i++){
        scanf("%d", &add);
        nodes[add].add = add;
        scanf("%d %d", &nodes[add].key, &nodes[add].next);
    }
    
    vector<Node> valid;
    vector<Node> invalid;
    bool flag[100001] = {0};
    do {
        if (flag[abs(nodes[add0].key)])
            invalid.push_back(nodes[add0]);
        else {
            flag[abs(nodes[add0].key)] = 1;
            valid.push_back(nodes[add0]);
        }
        add0 = nodes[add0].next;
    } while(add0 != -1);
    
    for (int i = 0; i < valid.size(); i++){
        if (i == valid.size() - 1) printf("%05d %d -1\n", valid[i].add, valid[i].key);
        else printf("%05d %d %05d\n", valid[i].add, valid[i].key, valid[i + 1].add);
    }
        
    for (int i = 0; i < invalid.size(); i++){
        if (i == invalid.size() - 1) printf("%05d %d -1\n", invalid[i].add, invalid[i].key);
        else printf("%05d %d %05d\n", invalid[i].add, invalid[i].key, invalid[i + 1].add);
    }
    
    return 0;
}

//一小时使用xcode完成
//太慢了
//不要再傻逼下去了，我他妈刚写了三道题就又放弃了半个月。
