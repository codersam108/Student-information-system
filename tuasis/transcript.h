#pragma once
#include<iostream>
#include"enrolstudent.h"
#include<vector>
#include"subject.h"
using namespace std;
class transcript
{
private:
	enrolstudent ens;
	string transcriptid;
	vector<float>marks;
	vector<subject>su;
public:
	transcript();
	transcript(string transcriptid,enrolstudent ens);
	string gettranscriptid();
	void settranscriptid(string transcriptid);
	bool addmarks(vector<float>marks);

};

