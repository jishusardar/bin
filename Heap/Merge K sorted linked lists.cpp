#include <__iterator/iterator_traits.h>
//
// Created by Jishu Sardar on 19/08/25.
//approch optimized 1
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data=data;
        this->next=NULL;
    }
};
class compare {
public:
    //reverse in the case of heap
    bool operator()(Node* a,Node* b){
        return a->data>b->data;
    }
};
Node* mergeKLists(vector<Node*>& arr) {
    // Approach 1 using pair
    priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>>q;
    for(int i=0;i<arr.size();i++){
        q.push(make_pair(arr[i]->data,arr[i]));
    }
    Node* ans=new Node(0);
    Node* temp=ans;
    while(!q.empty()){
        pair<int,Node*>p=q.top();
        q.pop();
        temp->next=p.second;
        temp=temp->next;
        if(p.second->next){
            q.push(make_pair(p.second->next->data,p.second->next));
        }
    }
    temp->next=NULL;
    return ans->next;
}
Node* mergeKLists2(vector<Node*>& arr) {
    // Approach 2 using customized heap
    priority_queue<Node*,vector<Node*>,compare>q(arr.begin(),arr.end());
    Node* ans=new Node(0);
    Node* temp=ans;
    while (!q.empty()) {
        temp->next=q.top();
        temp=temp->next;
        if (q.top()->next)
            q.push(q.top()->next);
        q.pop();
    }
    return ans->next;
}
int main() {

}