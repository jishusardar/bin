// //static data member
// #include<iostream>
// using namespace std;
// class Customer
// {
//     string name;
//     int account_number;
//     int balance;
//     public:
//     static int total_account;
//     Customer(string name,int account_number,int balance)
//     {
//         this->name=name;
//         this->account_number=account_number;
//         this->balance=balance;
//         total_account++;
//     }
//     void Printall()
//     {
//         cout<<this->name<<" "<<this->account_number<<" "<<this->balance<<endl;
//     }
//     //static memeber function
//     static void TotalCustomer()
//     {
//         cout<<total_account<<endl;
//     }
// };
// int Customer::total_account=0;
// int main()
// {
//     Customer *c1=new Customer("Jishu",345,1000);
//     c1->Printall();
//     c1->TotalCustomer();
// }