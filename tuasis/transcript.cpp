#include "transcript.h"
transcript::transcript()
{
	transcriptid = "";

}
transcript::transcript(string transcriptid, student s,courses c,vector<float>marks)
{
	this->transcriptid = transcriptid;
	this->s = s;
	this->c = c;
	this->marks = marks;
}
string transcript::gettranscriptid()
{
	return this->transcriptid;
}
void transcript::settranscriptid(string transcriptid)
{
	this->transcriptid = transcriptid;
}

vector<float>transcript::getmarks()
{
	return marks;
}
student transcript::getstudent()
{
	return this-> s;
}
courses transcript::getcourse()
{
	return this->c;
}