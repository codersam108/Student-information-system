#include "enrolstudent.h"
enrolstudent::enrolstudent()
{
	enrolid = "";
	enroldate = "";
	enroltime = "";
}
enrolstudent::enrolstudent(student students, courses course, string enrolid, string enroldate, string enroltime)
{
	this->students = students;
	this->course = course;
	this->enrolid = enrolid;
	this->enroldate = enroldate;
	this->enroltime = enroltime;
}
string enrolstudent::getenrolid()
{
	return this->enrolid;
}
string enrolstudent::getenroldate()
{
	return this->enroldate;
}
string enrolstudent::getenroltime()
{
	return this->enroltime;
}
void enrolstudent::setenrolid(string enrolid)
{
	this->enrolid = enrolid;

}
void enrolstudent::setenroldate(string enroldate)
{
	this->enroldate = enroldate;
}
void enrolstudent::setenroltime(string enroltime)
{
	this->enroltime = enroltime;
}
student enrolstudent::getstudents()
{
	return students;
}
courses enrolstudent::getcourse()
{
	return course;
}

vector<subject>enrolstudent::getsub()
{
	return course.getsubjectlist();
}
