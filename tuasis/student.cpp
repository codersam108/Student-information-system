#include "student.h"
student::student()
{
	id = "";
	name = "";
	phno = "";
	email = "";
}
student::student(string id, string name, string phno, string email)
{
	this->name = name;
	this->id = id;
	this->phno = phno;
	this->email = email;
}
string student::getid()
{
	return this->id;
}
string student::getname()
{
	return this->name;
}
string student::getphno()
{
	return this->phno;
}
string student::getemail()
{
	return this->email;
}
void student::setid(string id)
{
	this->id = id;
}
void student::setname(string name)
{
	this->name = name;
}
void student::setphno(string phno)
{
	this->phno = phno;
}
void student::setemail(string email)
{
	this->email = email;
}
