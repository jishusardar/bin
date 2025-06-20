#include<iostream>
using namespace std;
string intostr(int &n)
{
    if(n>=1&&n<5){
        if(n>=4){
            n-=4;
            return "IV";
        }
        n-=1;
        return "I";
    }
    else if(n>=5&&n<10){
        if(n>=9){
            n-=9;
            return "IX";
        }
        n-=5;
        return "V";
    }
    else if(n>=10&&n<50){
        if(n>=40){
            n-=40;
            return "XL";
        }
        n-=10;
        return "X";
    }
    else if(n>=50&&n<100){
        if(n>=90){
            n-=90;
            return "XC";
        }
        n-=50;
        return "L";
    }
    else if(n>=100&&n<500){
        if(n>=400){
            n-=400;
            return "CD";
        }
        n-=100;
        return "C";
    }
    else if(n>=500&&n<1000){
        if(n>=900){
            n-=900;
            return "CM";
        }
        n-=500;
        return "D";
    }
    else{
        n-=1000;
        return "M";
    }
}
string integertoroman(int n)
{
    string ans="";
    while(n!=0){
        ans+=intostr(n);
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Entre The number: ";
    cin>>n;
    cout<<integertoroman(n);

}