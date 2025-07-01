// signle inheritance
// #include<iostream>
// using namespace std;
// class Human
// {
//     protected:
//     string name;
//     int age;
// };
// class Student:public Human
// {
//     int roll_no;
//     int fees;
//     public:
//     Student(string name,int age,int roll_no,int fees)
//     {
//         this->name=name;
//         this->age=age;
//         this->roll_no=roll_no;
//         this->fees=fees;
//     }
//     void printall()
//     {
//         cout<<name<<" "<<age<<" "<<roll_no<<" "<<fees<<endl;
//     }
// };
// int main()
// {
//     Student* s1=new Student("jishu sardar",20,11,6000);
//     s1->printall();
// }
//signle inheritance
#include<iostream>
using namespace std;
class Human
{
    protected:
    string name;
    int age;
    Human(string name,int age)
    {
        this->name=name;
        this->age=age;
    }
};
class Student:public Human
{
    int roll_no;
    int fess;
    public:
    Student(string name,int age,int roll_no,int fees):Human(name,age)//called the constructor Human here
    {
        this->roll_no=roll_no;
        this->fess=fees;
    }
    void display()
    {
        cout<<name<<" "<<age<<" "<<roll_no<<" "<<fess<<endl;
    }
};
int main()
{
    Student* s1=new Student("jishu",20,11,6000);
    s1->display();
}