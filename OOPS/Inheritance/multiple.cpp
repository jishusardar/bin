//multiple inheritance
#include<iostream>
using namespace std;
class Youtuber
{
    protected:
    int subs;
    public:
    Youtuber(int subs)
    {
        this->subs=subs;
    }
};
class Teacher
{
    protected:
    int salary;
    Teacher(int salary)
    {
        this->salary=salary;
    }
};
class Youtubeteacher:public Youtuber,public Teacher
{
    protected:
    int student;
    public:
    Youtubeteacher(int subs,int salary,int student):Teacher(salary),Youtuber(subs)
    {
        this->student=student;
    }
    void printall()
    {
        cout<<subs<<" "<<salary<<" "<<student<<endl;
    }
};
int main()
{
    Youtubeteacher * y1=new Youtubeteacher(2300,200,20);
    y1->printall();

}