#include<string>
#include<numeric>
#include<stdio.h>
#include<iostream>
#include<fstream>
#include"student.h"
#include"courses.h"
#include"enrolstudent.h"
#include"transcript.h"
#include<vector>
using namespace std;
int x;
int totalmarks = 0;
vector<student>studentlist;
vector<courses>courselist;
vector<subject>subjectlist;
vector<enrolstudent>enrollist;
vector<transcript>transcriptlist;
vector<float>studentmarks;
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
bool checktranscriptid(string id)
{
    bool flag = false;
    for (x = 0; x < transcriptlist.size(); x++)
    {
        if (transcriptlist[x].gettranscriptid() == id)
        {
            flag = true;
            break;
        }
    }
    return flag;
}
void writedataforstudent()
{
    ofstream fw("Student_details.txt", ios::out | ios::app);
    for (x = 0; x < studentlist.size(); x++)
    {
        fw <<"Student id: "<< studentlist[x].getid() << endl;
        fw  <<"Student name: "<< studentlist[x].getname() << endl;
        fw  << "Student email: "<<studentlist[x].getemail() << endl;
        fw  << "Student phno: "<<studentlist[x].getphno() << endl;
    }
    fw.close();
}
vector<student>readdataforstudent()
{
    vector<student>studentlist;
    ifstream fr("Student_details.txt", ios::in);
    if (!fr)
    {
        cout << "File not found" << endl;
    }
    else
    {
        while (!fr.eof())
        {
            string id, name, phno, email;
            getline(fr, id);
            getline(fr, name);
            if (name.empty())
            {
                break;
            }
            getline(fr, email);
            getline(fr, phno);
            student obj(id, name, phno, email);
            studentlist.push_back(obj);
        }
        return studentlist;
    }
    fr.close();

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
        cout << "Enter the phone number of the student " << endl;
        getline(cin, studentphno);
        if (studentphno == "")
        {
            cout << "Sorry the phone number cant be blank,pls enter a valid ph no" << endl;
        }
        else if (studentphno.length() != 10)
        {
            cout << "Sorry the phone number should be of 10 digits" << endl;
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
    writedataforstudent();
    cout << "Student added successfully!!" << endl;
   
}
void modifystudent()
{
    string findid;
    int idx;
    cout << "Enter the id of the student against which u wanna modify the details" << endl;
    getline(cin, findid);
    bool flag = false;
    for (x = 0; x < studentlist.size(); x++)
    {
        if (findid == studentlist[x].getid())
        {
            idx = x;
            flag = true;
            break;
        }
    }
    if (flag == false)
    {
        cout << "Sorry the id entered is not in the list,pls enter a valid id " << endl;
    }
    else
    {
        string studentname, studentemail, studentphno;
       
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
            cout << "Enter the phone number of the student " << endl;
            getline(cin, studentphno);
            if (studentphno == "")
            {
                cout << "Sorry the phone number cant be blank,pls enter a valid ph no" << endl;
            }
            else if (studentphno.length() != 10)
            {
                cout << "Sorry the phone number should be of 10 digits" << endl;
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
        student obj(findid, studentname, studentphno, studentemail);
        studentlist[idx] = obj;
        cout << "Student details modified successfully!!" << endl;
        writedataforstudent();
    }
}
void deactivatestudent()
{
    string getid;
    int idx;
    cout << "Enter the id of the student which u wanna deactivate" << endl;
    getline(cin, getid);
    
    if (getid == "")
    {
        cout << "Sorry the id cant be blank,pls enter a valid id " << endl;
    }
    bool flag = false;
    for (x = 0; x < studentlist.size(); x++)
    {
        if (studentlist[x].getid() == getid)
        {
            idx = x;
            flag = true;
            break;
        }
    }
    if (flag == false)
    {
        cout << "Sorry the id entered is not in the list,pls enter a valid student id " << endl;
    }
    else
    {
        studentlist.erase(studentlist.begin() + idx);
        cout << "Student deactivated Successfully!!!" << endl;
        writedataforstudent();
    }
}
void writedataforcourse()
{
    ofstream fw("course_details.txt", ios::out | ios::app);
    for (x = 0; x < courselist.size(); x++)
    {
        fw << "Course Id: " << courselist[x].getcourseid() << endl;
        fw << "Course Name: " << courselist[x].getcoursename() << endl;
        fw << "Course Description: " << courselist[x].getcoursedescription() << endl;
        fw << "Course Duration: " << courselist[x].getcourseduration() << endl;
    }
    fw.close();
}
vector<courses>readdataforcourse()
{
    vector<courses>courselist;
    ifstream fr("course_details.txt", ios::in);
    if (!fr)
    {
        cout << "File not found" << endl;
    }
    else
    {
        while (!fr.eof())
        {
            string courseid, coursename, coursedescription, courseduration;
            getline(fr, courseid);
            getline(fr, coursename);
            if (coursename.empty())
            {
                break;
            }
            getline(fr, coursedescription);
            getline(fr, courseduration);
            courses obj(courseid, coursename, coursedescription, courseduration);
            courselist.push_back(obj);
        }
        return courselist;
    }
    fr.close();
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
    writedataforcourse();

}
void modifycourse()
{
    string getid;
    bool flag;
    int idx;
    cout << "Enter the id of the course which u wanna modify" << endl;
    getline(cin, getid);
    
    if (getid == "")
    {
        cout << "Sorry the id cant be blank,pls enter a valid id" << endl;
    }
    flag == false;
    for (x = 0; x < courselist.size(); x++)
    {
        if (courselist[x].getcourseid() == getid)
        {
            idx = x;
            flag = true;
            break;
        }
    }
    if (flag == false)
    {
        cout << "Sorry the id u entered is not in the list,pls enter a valid id " << endl;
    }
    else
    {
        string  coursename, coursedescription, courseduration;
      
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
        courses obj(getid, coursename, coursedescription, courseduration);
        courselist[idx] = obj;
        cout << "Course successfully modified!!!" << endl;
        writedataforcourse();
    }
}
void deactivatecourse()
{
    string findid;
    bool flag;
    int idx;
    cout << "Enter the id of the course which u wanna deactivate" << endl;
    getline(cin, findid);
    if (findid == "")
    {
        cout << "Sorry the id cant be blank,pls enter a valid id" << endl;
    }
    flag = false;
    for (x = 0; x < courselist.size(); x++)
    {
        if (courselist[x].getcourseid() == findid)
        {
            idx = x;
            flag = true;
            break;
        }
    }
    if (flag == false)
    {
        cout << "Sorry the id u entered is not in the database,pls enter a valid id" << endl;
    }
    else
    {

        courselist.erase(courselist.begin() + idx);
        cout << "Course deactivated Successfully!!!" << endl;
        writedataforcourse();
    }
}
void writedataforsubject()
{
    ofstream fw("Subject_details.txt", ios::out | ios::app);
    for (x = 0; x < subjectlist.size(); x++)
    {
        fw <<"Subject Id: "<< subjectlist[x].getsubjectid() << endl;
        fw << "Subject Name: "<<subjectlist[x].getsubjectname() << endl;
        fw << "Subject Description: " << subjectlist[x].getsubjectdescription() << endl;
        
    }
    fw.close();
}
vector<subject>readdataforsubject()
{
    vector<subject>subjectlist;
    ifstream fr("Subject_details.txt", ios::in);
    if (!fr)
    {
        cout << "File not found" << endl;
    }
    else
    {
        while (!fr.eof())
        {
            string subjectname, subjectid, subjectdescription;
            getline(fr, subjectid);
            getline(fr, subjectname);
            if (subjectname.empty())
            {
                break;
            }
            getline(fr, subjectdescription);
            subject obj(subjectid, subjectname, subjectdescription);
            subjectlist.push_back(obj);
        }
        return subjectlist;
    }
    fr.close();
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
    writedataforsubject();
}
void modifysubject()
{
    string findid;
    bool flag;
    int idx;
    cout << "Enter the id of the subject which u wanna modify" << endl;
    getline(cin, findid);
    if (findid == "")
    {
        cout << "Sorry the id cant be blank,pls enter a valid id" << endl;
    }
    flag = false;
    for (x = 0; x < subjectlist.size(); x++)
    {
        if (subjectlist[x].getsubjectid() == findid)
        {
            idx = x;
            flag = true;
            break;
        }
    }
    if (flag == false)
    {
        cout << "Sorry the id entered is not in the list,pls enter a valid id" << endl;
    }
    else
    {
        string subjectname, subjectdescription;
        
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
        subject obj(findid, subjectname, subjectdescription);
        subjectlist[idx] = obj;
        cout << "Subject successfully modified!!!" << endl;
        writedataforsubject();
    }
}
void deactivatesubject()
{
    string findid;
    int idx;
    bool flag;
    cout << "Enter the id of the subject which u wanna deactivate" << endl;
    getline(cin, findid);
    if (findid == "")
    {
        cout << "Sorry the id u entered cant be empty" << endl;
    }
    flag = false;
    for (x = 0; x < subjectlist.size(); x++)
    {
        if (subjectlist[x].getsubjectid() == findid)
        {
            idx = x;
            flag = true;
            break;
        }
    }
    if (flag == false)
    {
        cout << "Sorry the id is not in the list,pls enter a valid id" << endl;
    }
    else
    {
        subjectlist.erase(subjectlist.begin() + idx);
        cout << "Subject deactivated successfully!!!" << endl;
    }
    writedataforsubject();
}
void addsubjectincourse()
{
    string cid, sid;
    int idx1, idx2;
    cout << "Enter the id of the course which u wanna add in the course" << endl;
    getline(cin, cid);
    bool a = false;
    for (x = 0; x < courselist.size(); x++)
    {
        if (courselist[x].getcourseid() == cid)
        {
            idx1 = x;
            a = true;
            break;
        }
    }
    if (a == false)
    {
        cout << "Sorry the id entered is not in the database pls enter a correct id " << endl;

    }
    else
    {
        cout << "Enter the id of the subject which u wanna add in the course " << endl;
        getline(cin, sid);
        bool b = false;
        for (x = 0; x < subjectlist.size(); x++)
        {
            if (subjectlist[x].getsubjectid() == sid)
            {
                idx2 = x;
                b = true;
                break;
            }
        }
        if (b == false)
        {
            cout << "Sorry the id u entered is not in the database pls enter a valid id for the subject" << endl;
        }
        else
        {
            courselist[idx1].addsubject(subjectlist[idx2]);
            cout << "Subject Successfully added in the course" << endl;
        }
    }
}
void removesubjectfromcourse()
{
    
        string cid, sid;
        int idx1, idx2;
        cout << "Enter the id of the course which u wanna remove from the course" << endl;
        getline(cin, cid);
        bool a = false;
        for (x = 0; x < courselist.size(); x++)
        {
            if (courselist[x].getcourseid() == cid)
            {
                idx1 = x;
                a = true;
                break;
            }
        }
        if (a == false)
        {
            cout << "Sorry the id entered is not in the database pls enter a correct id " << endl;

        }
        else
        {
            cout << "Enter the id of the subject u wanna remove from the course " << endl;
            getline(cin, sid);
            bool b = false;
            for (x = 0; x < subjectlist.size(); x++)
            {
                if (subjectlist[x].getsubjectid() == sid)
                {
                    idx2 = x;
                    b = true;
                    break;
                }
            }
            if (b == false)
            {
                cout << "Sorry the id u entered is not in the database pls enter a valid id for the subject" << endl;
            }
            else
            {
                courselist[idx1].deletesubject(subjectlist[idx2]);
                cout << "Subject successfully deleted from the database" << endl;
            }
        }
    
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
    else
    {
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
        else
        {
            enrolstudent obj(studentlist[idx1], courselist[idx2], eid, ed, et);
            enrollist.push_back(obj);
            cout << "Student successfully enrolled in the course,Thank u for using SIS" << endl;
        }
    }
    
}
void deenrol()
{
    string findid;
    bool flag;
    int idx;
    cout << "Enter the enrollment id of the subject which u wanna deenrol from the course" << endl;
    getline(cin, findid);
    if (findid == "")
    {
        cout << "Sorry the id u entered cant be blank,pls enter a valid id" << endl;
    }
    flag = false;
    for (x = 0; x < enrollist.size(); x++)
    {
        if (enrollist[x].getenrolid() == findid)
        {
            idx = x;
            flag = true;
            break;
        }
    }
    if (flag == false)
    {
        cout << "Sorry the id u entered is not in the list,pls enter a valid id" << endl;
    }
    else
    {
        enrollist.erase(enrollist.begin() + idx);
        cout << "Student successfully deenrolled!!!" << endl;
    }
}
void writedatafortranscript()
{
    int i;
    ofstream fw("transcript_details.txt", ios::out | ios::app);
    for (x = 0; x < transcriptlist.size(); x++)
    {
        fw << "Transcript id: " << transcriptlist[x].gettranscriptid() << endl;
        fw << "Student id for transcript: " << transcriptlist[x].getstudent().getid() << endl;
        fw << "Course id in which the student is registered: " << transcriptlist[x].getcourse().getcourseid() << endl;
        for (i = 0; i < transcriptlist[x].getmarks().size(); i++)
        {
            fw << "Student marks: " << transcriptlist[x].getmarks()[i] << endl;
        }
        
    }
    fw.close();
}
vector<transcript>readdatafortranscript()
{
    vector<transcript>transcriptlist;
    ifstream fr("transcript_details.txt", ios::in);
    if (!fr)
    {
        cout << "File not found" << endl;
    }
    else
    {
        while (!fr.eof())
        {
            string transcriptid;
            float mrks;
            student s;
            courses c;
            string sid, cid;
            sid = s.getid();
            cid = c.getcourseid();
            vector<float>marks;
            getline(fr, transcriptid);
            getline(fr, sid);
            if (sid.empty())
            {
                break;
            }
            getline(fr, cid);
            if (cid.empty())
            {
                break;
            }
            for (x = 0; x < marks.size(); x++)
            {
                cin >> mrks;
                marks.push_back(mrks);
            }
            transcript obj(transcriptid, s, c, marks);
            transcriptlist.push_back(obj);
        }
        return transcriptlist;
    }
    fr.close();

}

void addresults()
{
    string tid, sid, cid;
    int px,kx;
    float smarks;
    while (true)
    {
        cout << "Enter the transcript id" << endl;
        getline(cin, tid);
        if (tid == "")
        {
            cout << "Sorry the id entered cant be blank,pls enter a valid transcript id" << endl;
        }
        else if (checktranscriptid(tid) == true)
        {
            cout << "Sorry the id entered is already in the database,pls enter a valid transcript id" << endl;
        }
        else
        {
            break;
        }
    }
    cout << "Enter the student id against which u wanna add the results in the transcript" << endl;
    getline(cin, sid);
    bool flag = false;
    for (x = 0; x < studentlist.size(); x++)
    {
        if (studentlist[x].getid() == sid)
        {
            px = x;
            flag = true;
            break;
        }
    }
    if (flag == false)
    {
        cout << "Sorry the id entered is not in the list,pls enter a valid id " << endl;
    }
    else
    {
        cout << "Enter the id of the course " << endl;
        getline(cin, cid);
        bool l = false;
        for (x = 0; x < courselist.size(); x++)
        {
            if (courselist[x].getcourseid() == cid)
            {
                kx = x;
                l = true;
                break;
            }
        }
        if (l == false)
        {
            cout << "Sorry the id entered cant be blank,pls enter a valid id" << endl;
        }
        else
        {
            cout << "Enter the marks of the subjects" << endl;
            for (x = 0; x < courselist[px].getsubjectlist().size(); x++)
            {
                cout << "Enter the marks in subject " << courselist[kx].getsubjectlist()[x].getsubjectname() << endl;
                cin >> smarks;
                totalmarks = totalmarks + smarks;
                studentmarks.push_back(smarks);
            }
            transcript obj(tid, studentlist[px], courselist[kx], studentmarks);
            transcriptlist.push_back(obj);
            cout << "Results added successfully in the Transcript!!!!" << endl;
            writedatafortranscript();
        }
    }
}
void modifyresult()
{
    string findid;
    bool flag;
    int idx;
    cout << "Enter the transcript id against which u wanna modify the results" << endl;
    getline(cin, findid);
    if (findid == "")
    {
        cout << "Sorry the id u entered cant be blank,pls enter a valid id" << endl;
    }
    flag = false;
    for (x = 0; x < transcriptlist.size(); x++)
    {
        if (transcriptlist[x].gettranscriptid() == findid)
        {
            idx = x;
            flag = true;
            break;
        }
    }
    if (flag == false)
    {
        cout << "Sorry the id u entered is not in the list,pls enter a valid id" << endl;
    }
    else
    {
        string tid, sid, cid;
        int px, kx;
        float smarks;
       
        cout << "Enter the student id against which u wanna add the results in the transcript" << endl;
        getline(cin, sid);
        bool flag = false;
        for (x = 0; x < studentlist.size(); x++)
        {
            if (studentlist[x].getid() == sid)
            {
                px = x;
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            cout << "Sorry the id entered is not in the list,pls enter a valid id " << endl;
        }
        else
        {
            cout << "Enter the id of the course " << endl;
            getline(cin, cid);
            bool l = false;
            for (x = 0; x < courselist.size(); x++)
            {
                if (courselist[x].getcourseid() == cid)
                {
                    kx = x;
                    l = true;
                    break;
                }
            }
            if (l == false)
            {
                cout << "Sorry the id entered cant be blank,pls enter a valid id" << endl;
            }
            else
            {
                cout << "Enter the marks of the subjects" << endl;
                for (x = 0; x < courselist[px].getsubjectlist().size(); x++)
                {
                    cout << "Enter the marks in subject " << courselist[kx].getsubjectlist()[x].getsubjectname() << endl;
                    cin >> smarks;
                    totalmarks = totalmarks + smarks;
                    studentmarks.push_back(smarks);
                }
                transcript obj(findid, studentlist[px], courselist[kx], studentmarks);
                transcriptlist[idx] = obj;
                cout << "Transcript successfully modified!!!" << endl;
                writedatafortranscript();
            }
        }
    }
}
void deleteresult()
{
    string findid;
    bool flag;
    int idx;
    cout << "Enter the id against which u wanna delete the transcript" << endl;
    getline(cin, findid);
    if (findid == "")
    {
        cout << "Sorry the id u entered cant be blank,pls enter a valid id" << endl;
    }
    flag = false;
    for (x = 0; x < transcriptlist.size(); x++)
    {
        if (findid == transcriptlist[x].gettranscriptid())
        {
            idx = x;
            flag = true;
            break;
        }
    }
    if (flag == false)
    {
        cout << "Sorry the id u entered is not in the list,pls enter a valid id" << endl;
    }
    else
    {
        transcriptlist.erase(transcriptlist.begin() + idx);
        cout << "Transcript deleted successfully!!!" << endl;
        writedatafortranscript();
    }
}
void printresult()
{
    string getid;
    float tdivide;
    float percentage;
    int idx;
    string sid;
    float tmarks=0.0;
    cout << "Enter the transcript id against which u wanna print the results" << endl;
    getline(cin, getid);
    bool flag = false;
    for (x = 0; x < transcriptlist.size(); x++)
    {
        if (getid == transcriptlist[x].gettranscriptid())
        {
            idx = x;
            flag = true;
            break;
        }
    }
    if (flag == false)
    {
        cout << "Sorry the id u entered is not in the list,pls enter a valid id " << endl;
    }
    else
    {
        
        sid=transcriptlist[idx].getstudent().getid();
        cout << "Student Id : " << sid << endl;
        cout << "Student marks : " << endl;
        for (x = 0; x < transcriptlist[idx].getcourse().getsubjectlist().size(); x++)
        {
            cout << "Marks in " << transcriptlist[idx].getcourse().getsubjectlist()[x].getsubjectname() <<" are : "<<transcriptlist[idx].getmarks()[x]<< endl;
            tmarks = tmarks + transcriptlist[idx].getmarks()[x];
        }

        tdivide = transcriptlist[idx].getmarks().size() * 100;
        percentage = (tmarks / tdivide) * 100;
        cout << "The Percentage obtained by the student is : " << percentage << endl;
        if (percentage >= 90)
        {
            cout << "The grade of the Student is : A" << endl;
        }
        else if (percentage >= 80 && percentage < 90)
        {
            cout << "The grade of the Student is: B" << endl;
        }
        else if (percentage >= 70 && percentage < 80)
        {
            cout << "The grade of the Student is: C" << endl;
        }
        else if (percentage >= 60 && percentage < 70)
        {
            cout << "The grade of the Student is: D" << endl;
        }
        else if (percentage >= 50 && percentage < 60)
        {
            cout << "The grade of the Student is: E" << endl;
        }
        else
        {
            cout << "The grade of the Student is: F" << endl;
        }
        writedatafortranscript();
    }
}
    
    


int main()
{
    int choice;
    while (true)
    {
        cout << "****WELCOME TO STUDENT INFORMATION SYSTEM****" << endl;
        cout << "1.Add student in the database" << endl;
        cout << "2.Add courses in the database" << endl;
        cout << "3.Add subjects in the database" << endl;
        cout << "4.Add subjects in the course " << endl;
        cout << "5.Enrol a student into a course" << endl;
        cout << "6.Add results in transcript" << endl;
        cout << "7.Print results in transcript" << endl;
        cout << "8.Modify student details" << endl;
        cout << "9.Deactivate student" << endl;
        cout << "10.Modify course" << endl;
        cout << "11.Deactivate course" << endl;
        cout << "12.Modify subject" << endl;
        cout << "13.Deactivate subject" << endl;
        cout << "14.De enrol a student from a course" << endl;
        cout << "15.Remove subjects from the course" << endl;
        cout << "16.Modify Transcript" << endl;
        cout << "17.Deactivate Transcript" << endl;
        cout << "18.Exit" << endl;
        cout << "Enter the choice" << endl;
        cin >> choice;
        getchar();
        switch (choice)
        {
        case 1:
        {
            addstudent();
            readdataforstudent();
            break;
        }
        case 2:
        {
            addcourse();
            readdataforcourse();
            break;

        }
        case 3:
        {
            addsubject();
            readdataforsubject();
            break;
        }
        case 4:
        {
            addsubjectincourse();
            break;
        }
        case 5:
        {
            enrol();
            break;
        }
        
        case 6:
        {
            addresults();
            readdatafortranscript();
            break;
        }
        case 7:
        {
            printresult();
            readdatafortranscript();
            break;
        }
        case 8:
        {
            modifystudent();
            readdataforstudent();
            break;
        }
        case 9:
        {
            deactivatestudent();
            readdataforstudent();
            break;
        }
        case 10:
        {
            modifycourse();
            readdataforcourse();
            break;
        }
        case 11:
        {
            deactivatecourse();
            readdataforcourse();
            break;
        }
        case 12:
        {
            modifysubject();
            readdataforsubject();
            break;
        }
        case 13:
        {
            deactivatesubject();
            readdataforsubject();
            break;
        }
        case 14:
        {
            deenrol();
            break;
        }
        case 15:
        {
            removesubjectfromcourse();
            break;
        }
        case 16:
        {
            modifyresult();
            readdatafortranscript();
            break;
        }
        case 17:
        {
            deleteresult();
            readdatafortranscript();
            break;
        }
        case 18:
        {
            return 0;
        }
        default:
        {
            cout << "Wrong choice!!!" << endl;
            break;
        }
        }
    }
}