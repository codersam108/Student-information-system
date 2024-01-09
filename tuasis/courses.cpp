#include "courses.h"
courses::courses()
{
	coursename = "";
	courseid = "";
	coursedescription = "";
	courseduration = "";
}
courses::courses(string courseid, string coursename, string coursedescription, string courseduration)
{
	this->courseid = courseid;
	this->coursename = coursename;
	this->coursedescription = coursedescription;
	this->courseduration = courseduration;
}
string courses::getcourseid()
{
	return this->courseid;
}
string courses::getcoursename()
{
	return this->coursename;
}
string courses::getcoursedescription()
{
	return this->coursedescription;
}
string courses::getcourseduration()
{
	return this->courseduration;
}
void courses::setcourseid(string courseid)
{
	this->courseid = courseid;
}
void courses::setcoursename(string coursename)
{
	this->coursename = coursename;
}
void courses::setcoursedescription(string coursedescription)
{
	this->coursedescription = coursedescription;
}
void courses::setcourseduration(string courseduration)
{
	this->courseduration = courseduration;
}
vector<subject>courses::getsubjectlist()
{
	return  subjectlist;
}
bool courses::addsubject(subject obj)
{
	bool flag = false;
	int x;
	for (x = 0; x < subjectlist.size(); x++)
	{
		if (obj.getsubjectid() == subjectlist[x].getsubjectid())
		{
			flag = true;
			break;
		}
	}
	if (flag == true)
	{
		cout << "Sorry the id already exists pls enter a different id " << endl;
		return false;
	}
	else
	{
		subjectlist.push_back(obj);
		return true;
	}
}
bool courses::deletesubject(subject obj)
{
	bool flag = false;
	int x,idx;
	for (x = 0; x < subjectlist.size(); x++)
	{
		if (obj.getsubjectid() == subjectlist[x].getsubjectid())
		{
			idx = x;
			flag = true;
			break;
		}
	}
	if (flag == false)
	{
		cout << "Sorry the id entered is not in the database pls enter a valid id " << endl;
		return false;
	}
	else
	{
		subjectlist.erase(subjectlist.begin() + idx);
		return true;
	}
}
