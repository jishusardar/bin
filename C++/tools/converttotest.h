//
// Created by jishu on 15-10-2025.
//

#ifndef CONVERTTOTEST_H
#define CONVERTTOTEST_H
#include <string>

class converttotest {
    std::string s;
public:
    converttotest(const std::string& s) {
        this->s=s;
    }

    std::string convert() {
        for (int i=0;i<s.size();i++) {
            if (s[i]=='[')
                s[i]='{';
            if (s[i]==']')
                s[i]='}';
        }
        return s;
    }
    ~converttotest(){}
};



#endif //CONVERTTOTEST_H
