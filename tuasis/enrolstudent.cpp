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

bool enrolstudent::enstudent(subject obj)
{
	int x;
	bool flag = false;
	for (x = 0; x < chosensubject.size(); x++)
	{
		if (chosensubject[x].getsubjectid() == obj.getsubjectid())
		{
			flag = true;
			break;
		}
	}
	if (flag == true)
	{
		return false;
	}
	else
	{
		chosensubject.push_back(obj);
		return true;
	}
}
bool enrolstudent::denstudent(subject obj)
{
	int x, idx;
	bool flag = false;
	for (x = 0; x < chosensubject.size(); x++)
	{
		if (chosensubject[x].getsubjectid() == obj.getsubjectid())
		{
			idx = x;
			flag = true;
			break;
		}
	}
	if (flag == false)
	{
		return false;
	}
	else
	{
		chosensubject.erase(chosensubject.begin() + idx);
		return true;
	}
}
vector<subject>enrolstudent::getsub()
{
	return course.getsubjectlist();
}