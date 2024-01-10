#include<string>
#include <iostream>
#include"student.h"
#include"courses.h"
#include"enrolstudent.h"
#include<vector>
using namespace std;
int x;
vector<student>studentlist;
vector<courses>courselist;
vector<subject>subjectlist;
vector<enrolstudent>enrollist;
bool checkstudentid(string id)
{
    bool flag = false;
    for (x = 0; x < studentlist.size(); x++)
    {
        if (id == studentlist[x].getid())
        {
            flag = true;
            break;
        }
    }
    return flag;
}
bool checkphone(string id)
{
    bool flag = false;
    for (x = 0; x < id.length(); x++)
    {
        if (!isdigit(id[x]))
        {
            flag = true;
            break;
        }
    }
    return flag;
}
bool checkemail(string id)
{
    bool flag = false;
    for (x = 0; x < id.length(); x++)
    {
        if (id[x] == '@')
        {
            flag = true;
            break;
        }
    }
    return flag;
}
bool checkcourseid(string id)
{
    bool flag = false;
    for (x = 0; x < courselist.size(); x++)
    {
        if (id == courselist[x].getcourseid())
        {
            flag = true;
            break;
        }
    }
    return flag;
}
bool checksubjectid(string id)
{
    bool flag = false;
    for (x = 0; x < subjectlist.size(); x++)
    {
        if (id == subjectlist[x].getsubjectid())
        {
            flag = true;
            break;
        }
    }
    return flag;
}
bool checkenrolid(string id)
{
    bool flag = false;
    for (x = 0; x < enrollist.size(); x++)
    {
        if (id == enrollist[x].getenrolid())
        {
            flag = true;
            break;
        }
    }
    return flag;
}
void addstudent()
{
    string studentid, studentname, studentemail, studentphno;
    while (true)
    {
        cout << "Enter the id of the student" << endl;
        getline(cin, studentid);
        if (studentid == "")
        {
            cout << "Sorry the id cant be blank,pls enter a valid id " << endl;
        }
        else if (checkstudentid(studentid) == true)
        {
            cout << "Sorry the id u entered is already in the database,pls enter a new id " << endl;
        }
        else
        {
            break;
        }

    }
    while (true)
    {
        cout << "Enter the name of the student " << endl;
        getline(cin, studentname);
        if (studentname == "")
        {
            cout << "Sorry the student name u entered cant be blank,pls enter a valid student name" << endl;
        }
        else
        {
            break;
        }
    }
    while (true)
    {
        cout << "Enter the email id of the student " << endl;
        getline(cin, studentphno);
        if (studentphno == "")
        {
            cout << "Sorry the phone number cant be blank,pls enter a valid ph no" << endl;
        }
        else if (checkphone(studentphno) == true)
        {
            cout << "Sorry the phone number cant contain anything other than digits,pls enter a valid phone number" << endl;
        }
        else
        {
            break;
        }
    }
    while (true)
    {
        cout << "Enter the email id of the student " << endl;
        getline(cin, studentemail);
        if (studentemail == "")
        {
            cout << "Sorry the email id cant be blank,pls enter a valid email id" << endl;
        }
        else if (checkemail(studentemail) == false)
        {
            cout << "Sorry the email id should contain @ pls enter a valid email id " << endl;
        }
        else
        {
            break;
        }
    }
    student obj(studentid, studentname, studentphno, studentemail);
    studentlist.push_back(obj);
    cout << "Student added successfully!!" << endl;
}
void addcourse()
{
    string courseid, coursename, coursedescription, courseduration;
    while (true)
    {
        cout << "Enter the id of the course" << endl;
        getline(cin, courseid);
        if (courseid == "")
        {
            cout << "Sorry the course id cant be blank,pls enter a valid course id" << endl;
        }
        else if (checkcourseid(courseid) == true)
        {
            cout << "Sorry the email id u entered is already in the database,pls enter a correct email id" << endl;
        }
        else
        {
            break;
        }
    }
    while (true)
    {
        cout << "Enter the name of the course" << endl;
        getline(cin, coursename);
        if (coursename == "")
        {
            cout << "Sorry the course name cant be blank,pls enter a valid name" << endl;
        }
        else
        {
            break;
        }

    }
    while (true)
    {
        cout << "Enter the description of the course" << endl;
        getline(cin, coursedescription);
        if (coursedescription == "")
        {
            cout << "Sorry the description cant be blank,pls enter a valid description" << endl;
        }
        else
        {
            break;
        }
    }
    while (true)
    {
        cout << "Enter the duration of the course" << endl;
        getline(cin, courseduration);
        if (courseduration == "")
        {
            cout << "Sorry the duration cant be blank,pls enter a valid duration" << endl;
        }
        else
        {
            break;
        }
    }
    courses obj(courseid, coursename, coursedescription, courseduration);
    courselist.push_back(obj);
    cout << "Course successfully added" << endl;

}
void addsubject()
{
    string subjectid, subjectname, subjectdescription;
    while (true)
    {
        cout << "Enter the id of the subject " << endl;
        getline(cin, subjectid);
        if (subjectid == "")
        {
            cout << "Sorry the subject id cant be blank,pls enter a valid subject id" << endl;
        }
        else if (checksubjectid(subjectid) == true)
        {
            cout << "Sorry the subject id u entered is already in the database,pls enter a new id " << endl;
        }
        else
        {
            break;
        }
    }
    while (true)
    {
        cout << "Enter the name of the subject " << endl;
        getline(cin, subjectname);
        if (subjectname == "")
        {
            cout << "Sorry the name of the subject u entered cant be blank,pls enter a valid name for the subject " << endl;
        }
        else
        {
            break;
        }

    }
    while (true)
    {
        cout << "Enter the description of the subject " << endl;
        getline(cin, subjectdescription);
        if (subjectdescription == "")
        {
            cout << "Sorry the description of the subject u entered cant be blank,pls enter a valid subject description" << endl;
        }
        else
        {
            break;
        }
    }
    subject obj(subjectid, subjectname, subjectdescription);
    subjectlist.push_back(obj);
    cout << "Subject successfully added " << endl;
}
void enrol()
{
    string eid, ed, et;
    string sid, cid;
    while (true)
    {
        cout << "Enter the id for the enrollment " << endl;
        getline(cin, eid);
        if (eid == "")
        {
            cout << "Sorry the enrollment id u entered is blank,pls enter a valid enrollment id " << endl;
        }
        else if (checkenrolid(eid) == true)
        {
            cout << "Sorry the id u entered is already in the database,pls enter a new id " << endl;
        }
        else
        {
            break;
        }
    }
    while (true)
    {
        cout << "Enter the date of enrollment " << endl;
        getline(cin, ed);
        if (ed == "")
        {
            cout << "Sorry the enrollment date u entered cant be blank,pls enter a valid date" << endl;
        }
        else
        {
            break;
        }
    }
    while (true)
    {
        cout << "Enter the time of the enrollment " << endl;
        getline(cin, et);
        if (et == "")
        {
            cout << "Sorry the time cant be blank,pls enter a valid enrollment time" << endl;
        }
        else
        {
            break;
        }
    }
    cout << "Enter the id of the student which u wanna enrol in the course" << endl;
    getline(cin, sid);
    bool a = false;
    int idx1, idx2;
    for (x = 0; x < studentlist.size(); x++)
    {
        if (studentlist[x].getid() == sid)
        {
            idx1 = x;
            a = true;
            break;
        }
    }
    if (a == false)
    {
        cout << "Sorry the id entered is not in the database,pls enter a valid student id " << endl;
    }
    cout << "Enter the id of the course in which the student wants to get enrolled " << endl;
    getline(cin, cid);
    bool b = false;
    for (x = 0; x < courselist.size(); x++)
    {
        if (cid == courselist[x].getcourseid())
        {
            idx2 = x;
            b = true;
            break;
        }
    }
    if (b == false)
    {
        cout << "Sorry the id entered is not in the database,pls enter a valid id " << endl;
    }
    enrolstudent obj(studentlist[idx1], courselist[idx2], eid, ed, et);
    enrollist.push_back(obj);
    cout << "Student successfully enrolled in the course,Thank u for using SIS" << endl;
}

int main()
{
    
}