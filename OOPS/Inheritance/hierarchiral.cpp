//hierarchiral inheritance
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
    public:
    int fees;
    public:
    Student(string name,int age,int fees):Human(name,age)
    {
        this->fees=fees;
    }
};
class Teacher:public Human
{
    protected:
    int salary;
    public:
    Teacher(string name,int age,int salary):Human(name,age)
    {
        this->salary=salary;
    }
};
class Staff:public Human
{
    protected:
    int no_dept;
    public:
    Staff(string name,int age,int no_dept):Human(name,age)
    {
        this->no_dept=no_dept;
    }
};
int main()
{
}