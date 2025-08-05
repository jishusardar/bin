//
// Created by jishu on 05-08-2025.
//stl in cpp
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
//pairs
class Person {
public:
    string name;
    int age;
    Person() {};
    bool operator<(const Person &other) const {
        return age<other.age;
    }
};
int main() {
    // pair<int,int>p;
    // p.first=90;
    // p.second=100;
    //list
    // list<int>ll;
    // //cout<<p.first<<" "<<p.second<<" ";
    // ll.push_back(34);
    // ll.push_back(90);
    // ll.push_back(23);
    // for (auto it=ll.begin();it!=ll.end();it++) {
    //     cout<<*it<<" ";
    // }
    // for (auto it=ll.rbegin();it!=ll.rend();it++) {
    //     cout<<*it<<" ";
    // }
    // //set
    // // set<int>s;
    // // s.insert(90);
    // // s.insert(89);
    // // s.insert(23);
    // // s.insert(100);
    // // s.insert(234);
    // // for (auto it=s.begin();it!=s.end();it++) {
    // //     cout<<*it<<" ";
    // // }
    // //lets put some predefined data type in sets
    // Person p1;
    // p1.name="Jishu";
    // p1.age=21;
    // Person p2;
    // p2.name="Soumyadeep";
    // p2.age=20;
    // set<Person>s;
    // s.insert(p1);
    // s.insert(p2);
    // for (auto it=s.begin();it!=s.end();it++) {
    //     cout<<it->age<<" "<<it->name<<" ";
    // }
    // //multiset
    // //ordered sets ki tarah hota hai bus duplicate element store kar sakte hai
    // multiset<int>s;
    // s.insert(90);
    // s.insert(90);
    // s.insert(82);
    // for (auto it=s.begin();it!=s.end();it++) {
    //     cout<<*it<<" ";
    // }
    //unordered_set is where sets are stored in without any order
    //doesn't follow any order just doesn't store duplicates
    // unordered_set<int>s;
    // s.insert(90);
    // s.insert(89);
    // s.insert(90);
    // s.insert(71);
    // for (auto it=s.begin();it!=s.end();it++) {
    //     cout<<*it<<" ";
    // }
    //maps are implemented using hashing
    //map stored in first element in order
    // map<int,int>mm;
    // int n;
    // cout<<"Entre The Size: ";
    // cin>>n;
    // int num;
    // for (int i=0;i<n;i++) {
    //     cout<<"Entre The Elements: ";
    //     cin>>num;
    //     mm[num]++;
    // }
    // for (auto it=mm.begin();it!=mm.end();it++) {
    //     cout<<it->first<<" "<<it->second<<endl;
    // }
    //unordered map
    //are not adjusted in order just random order implemented using hashing
    unordered_map<int,int>mm;
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    int num;
    for (int i=0;i<n;i++) {
        cout<<"Entre The Elements: ";
        cin>>num;
        mm[num]++;
    }
    for (auto it=mm.begin();it!=mm.end();it++) {
        cout<<it->first<<" "<<it->second<<endl;
    }
}
