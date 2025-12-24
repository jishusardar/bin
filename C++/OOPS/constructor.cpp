// // //constructor
// // #include<iostream>
// // using namespace std;
// // class Customer
// // {
// //     string name;
// //     int account_number;
// //     int balance;
// //     public:
// //     Customer(string name,int account_number,int balance)
// //     {
// //         this->name=name;
// //         this->account_number=account_number;
// //         this->balance=balance;
// //     }
// //     void printall()
// //     {
// //         cout<<this->name<<" "<<this->account_number<<" "<<this->balance<<endl;
// //     }
// // };
// // int main()
// // {
// //     string name;
// //     int balance;
// //     int account_num;
// //     cout<<"Entre The Name: ";
// //     cin>>name;
// //     cout<<"Entre The Account Number: ";
// //     cin>>account_num;
// //     cout<<"Entre The Balance: ";
// //     cin>>balance;
// //     Customer *c1=new Customer(name,account_num,balance);
// //     c1->printall();
// // }
// //inline constructor
// #include<iostream>
// using namespace std;
// class Customer
// {
//     string name;
//     int account_number;
//     int balance;
//     public:
//     inline Customer(string a,int b,int c):name(a),account_number(b),balance(c){}
//     void printall()
//     {
//         cout<<this->name<<" "<<this->account_number<<" "<<this->balance<<" "<<endl;
//     }
// };
// int main()
// {
//     Customer *c1=new Customer("jishu",345,100);
//     c1->printall();
// }
//copy constructor
#include<iostream>
using namespace std;
class Customer
{
    string name;
    int account_number;
    int balance;
    public:
    Customer(string name,int account_number,int balance){
        this->name=name;
        this->account_number=account_number;
        this->balance=balance;
    }
    //copy constructor
    Customer(Customer* c){
        this->name=c->name;
        this->account_number=c->account_number;
        this->balance=c->balance;
    }
    void printall()
    {
        cout<<this->name<<" "<<this->account_number<<" "<<this->balance<<" "<<endl;
    }
};
int main()
{
    Customer *c1=new Customer("JishuSardar",2346,1000);
    c1->printall();
    Customer *c2=new Customer(c1);
    c2->printall();
}