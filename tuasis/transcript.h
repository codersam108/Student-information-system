#pragma once

#include"enrolstudent.h"
#include<vector>
#include"subject.h"

class transcript
{
private:
	
	string transcriptid;
	vector<float>marks;
	student s;
	courses c;

	
public:
	transcript();
	transcript(string transcriptid, student s,courses c, vector<float>marks);
	string gettranscriptid();
	void settranscriptid(string transcriptid);
	student getstudent();
	vector<float>getmarks();
	courses getcourse();

};

