#pragma once
#include<iostream>
#include<vector>
#include"student.h"
#include"courses.h"
#include"subject.h"
using namespace std;
class enrolstudent
{
private:

	string enrolid, enroldate, enroltime;
	student students;
	courses course;
	
public:
	enrolstudent();
	enrolstudent(student students, courses course, string enrolid, string enroldate, string enroltime);
	string getenrolid();
	string getenroldate();
	string getenroltime();
	void setenrolid(string enrolid);
	void setenroldate(string enroldate);
	void setenroltime(string enroltime);
	student getstudents();
	courses getcourse();
	vector<subject>getsub();
	

};

