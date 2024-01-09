#pragma once
#include<iostream>
using namespace std;
class student
{
private:
    string id, name, phno, email;
public:
    student();
    student(string id, string name, string phno, string email);
    string getid();
    string getname();
    string getphno();
    string getemail();
    void setid(string id);
    void setname(string name);
    void setphno(string phno);
    void setemail(string email);
};

