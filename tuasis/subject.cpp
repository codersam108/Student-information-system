#include "subject.h"
subject::subject()
{
	subjectid = "";
	subjectname = "";
	subjectdescription = "";
}
subject::subject(string subjectid, string subjectname, string subjectdescription)
{
	this->subjectid = subjectid;
	this->subjectname = subjectname;
	this->subjectdescription = subjectdescription;
}
string subject::getsubjectid()
{
	return this->subjectid;
}
string subject::getsubjectname()
{
	return this->subjectname;
}
string subject::getsubjectdescription()
{
	return this->subjectdescription;
}
void subject::setsubjectid(string subjectid)
{
	this->subjectid = subjectid;
}
void subject::setsubjectname(string subjectname)
{
	this->subjectname = subjectname;
}
void subject::setsubjectdescription(string subjectdescription)
{
	this->subjectdescription = subjectdescription;
}