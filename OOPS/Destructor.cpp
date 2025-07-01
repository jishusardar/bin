//Destructor
#include<iostream>
using namespace std;
class Customer
{
    public:
    string name;
    int account_number;
    int balance;
    Customer(string name,int account_number,int balance)
    {
        this->name=name;
        this->account_number=account_number;
        this->balance=balance;
        cout<<"Constructor is called"<<endl;
    }
    ~Customer(){
        cout<<"Destructor is called"<<endl;
    }
    void printall(){
        cout<<this->name<<" "<<this->account_number<<" "<<this->balance<<endl;
    }
};
int main()
{
    Customer* c1=new Customer("Jishu",2345,100);
    c1->printall();
    delete c1;

}