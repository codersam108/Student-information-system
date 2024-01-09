#pragma once
#include<iostream>
using namespace std;
class subject
{
private:
	string subjectid, subjectname, subjectdescription;
public:
	subject();
	subject(string subjectid, string subjectname, string subjectdescription);
	string getsubjectid();
	string getsubjectname();
	string getsubjectdescription();
	void setsubjectid(string subjectid);
	void setsubjectname(string subjectname);
	void setsubjectdescription(string subjectdescription);
};

