#pragma once
#include<iostream>
#include"subject.h"
#include<vector>
using namespace std;
class courses
{
private:
	string courseid, coursename, coursedescription, courseduration;
	vector<subject>subjectlist;
	
public:
	courses();
	courses(string courseid, string coursename, string coursedescription, string courseduration);
	string getcourseid();
	string getcoursename();
	string getcoursedescription();
	string getcourseduration();
	vector<subject>getsubjectlist();
	void setcourseid(string courseid);
	void setcoursename(string coursename);
	void setcoursedescription(string coursedescription);
	void setcourseduration(string courseduration);
	bool addsubject(subject obj);
	bool deletesubject(subject obj);
};

