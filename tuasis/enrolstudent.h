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
	vector<subject>chosensubject;
public:
	enrolstudent();
	enrolstudent(student students, courses course, string enrolid, string enroldate, string enroltime);
	string getenrolid();
	string getenroldate();
	string getenroltime();
	void setenrolid(string enrolid);
	void setenroldate(string enroldate);
	void setenroltime(string enroltime);
	bool enstudent(subject obj);
	bool denstudent(subject obj);
	vector<subject>getsub();

};

