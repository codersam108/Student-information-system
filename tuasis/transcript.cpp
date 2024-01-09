#include "transcript.h"
transcript::transcript()
{
	transcriptid = "";

}
transcript::transcript(string transcriptid, enrolstudent ens)
{
	this->transcriptid = transcriptid;
	this->ens = ens;
}
string transcript::gettranscriptid()
{
	return this->transcriptid;
}
void transcript::settranscriptid(string transcriptid)
{
	this->transcriptid = transcriptid;
}

