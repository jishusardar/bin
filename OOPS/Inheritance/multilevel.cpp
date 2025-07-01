//multilevel inheritance 
#include<iostream>
using namespace std;
class person
{
    protected:
    string name;
    int age;
    public:
    person(string name,int age)
    {
        this->name=name;
        this->age=age;
    }
     void printall()
    {
        cout<<name<<" "<<age<<endl;
    }
};
class Employee:public person
{
    protected:
    int salary;
    public:
    Employee(string name,int age,int salary):person(name,age){
        this->salary=salary;
    }
    void printall()
    {
        cout<<name<<" "<<age<<" "<<salary<<endl;
    }
};
class Manager:public Employee
{
    protected:
    int No_dept;
    public:
    Manager(string name,int age,int salary,int no_dept):Employee(name,age,salary){
        this->No_dept=no_dept;
    }
    void printall()
    {
        cout<<name<<" "<<age<<" "<<salary<<""<<No_dept<<endl;
    }
};
int main()
{
    Manager *m1=new Manager("Jishu Sardar",20,2000,1);
    m1->printall();
    Employee *e1=new Employee("Jishu Sardar",20,2000);
    e1->printall();
    person *p1=new person("Jishu Sardar",20);
    p1->printall();
}