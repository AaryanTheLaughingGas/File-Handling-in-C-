//Aaryan Sinha
//2021A7PS0183U

#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
using namespace std;

const int MAX_LEN = 30;


class Employee
{
public:
    char emp_id[100];
    char emp_name[100];
    int pay;
    //char read_file[100];
    //Q1
    void getdata(char read_file[100]){
        //read data from file and populate variables with them
        ifstream infile;
        ofstream outfile;
        infile.open(read_file);
        outfile.open("Output File.dat", ios_base::app);
        outfile << "Output 1: \n\n";
        while (infile >> emp_id >> emp_name>> pay) {
        outfile << "Employee = " << emp_id << " " << "Pay = " << pay << "\n";
        cout << "Inserted into output";
 }
    outfile.close();}


};


class Student
{
public:
    string s_id;
    char s_name[100];
    int fees;
    char c1[100];
    char c2[100];
    char c3[100];

    void getdata(char read_file[100]){
        ifstream infile;
        infile.open(read_file);
        ofstream outfile;
        outfile.open("Output File.dat", ios_base::app);
        outfile << "\n\nOutput 4:\n\n";
        while (infile >> s_id >> s_name >> fees >> c1 >> c2 >> c3) {
                outfile << "Student ID = " << s_id << " " << "Student Name = " << s_name << " " << "Fees Paid = " << fees << "Courses Studying = " << c1 << "|" << c2 << "|" << c3 << "\n";
                cout << "Inserted into output file";
 }
outfile.close();}
};


class Instruc : public Employee
{
public:
    string instruc_id;
    char course_teaching[100];


};


class TA : public Employee, public Instruc, public Student
{
public:
    //char course_studying[100];
    //char course_teaching[100];
    //int pay;
    //int fees;

    void ta_getdata(char read_file_1[100], char read_file_2[100]){
        //read data from file and populate variables with them
        ifstream infile_1;
        ifstream infile_2;
        ofstream outfile;
        string strs, strs2;
        infile_1.open(read_file_1);
        infile_2.open(read_file_2);
        outfile.open("Output File.dat", ios_base::app);
        outfile << "\n\nOutput 2:\n\n";
        while (getline(infile_2, strs)) {

                string s_id, s_name;
                int fees;
                string c1, c2, c3;
                istringstream ss(strs);
                ss >> s_id >> s_name >> fees >> c1 >> c2 >> c3;

                while(getline(infile_1, strs2))
                {
                    string instruc_id, courseteaching1, courseteaching2;
                    istringstream ss2(strs2);
                    ss2 >> instruc_id >> courseteaching1 >> courseteaching2;


                /*string instruc_id, courseteaching;
                istringstream ss2(strs2);
                ss2 >> instruc_id >> courseteaching;*/
                        if (s_id == instruc_id) {
                            // process column 3
                        //if(strs == instruc_id){
                            //infile_2 >> s_id >> s_name >> fees >> c1 >> c2 >> c3
                            outfile << "Student ID = " << s_id << " " << "Student name = " << s_name << " " << "Courses Teaching = " << courseteaching1 << " | "<< courseteaching2 << "\n";
                            cout << "Inserted into output";
                    //}
                        }
                        else{
                            break;
                        }
                break;}



 }
 outfile.close();}

    void not_ta_getdata(char read_file_1[100], char read_file_2[100]){
        //read data from file and populate variables with them
        ifstream infile_1;
        ifstream infile_2;
        ofstream outfile;
        string strs, strs2;
        infile_1.open(read_file_1);
        infile_2.open(read_file_2);
        outfile.open("Output File.dat", ios_base::app);
        outfile << "\n\nOutput 3:\n\n";
        while (getline(infile_2, strs)) {

                string s_id, s_name;
                int fees;
                string c1, c2, c3;
                istringstream ss(strs);
                ss >> s_id >> s_name >> fees >> c1 >> c2 >> c3;

                while(getline(infile_1, strs2))
                {
                    string instruc_id, courseteaching1, courseteaching2;
                    istringstream ss2(strs2);
                    ss2 >> instruc_id >> courseteaching1 >> courseteaching2;


                /*string instruc_id, courseteaching;
                istringstream ss2(strs2);
                ss2 >> instruc_id >> courseteaching;*/
                        if (s_id != instruc_id) {
                            // process column 3
                        //if(strs == instruc_id){
                            //infile_2 >> s_id >> s_name >> fees >> c1 >> c2 >> c3
                            outfile << "Student ID = " << s_id << " " << "Student name = " << s_name << "\n";
                            cout << "Inserted into output";
                    //}
                        }
                        else{
                            break;
                        }
                break;}



 }
 outfile.close();}


};


/*
int main(){
    //cout << "Hello World" << endl;

    int num;
    char name[MAX_LEN];
    int marks;

    ifstream infile;
    ofstream outfile;

    infile.open("Input File.dat");
    outfile.open("Output File.dat");

 while (infile >> num >> name >> marks) {
        outfile << "Number = " << num << " " << "Name = " << name << " " << "Marks = " << marks << "\n" << endl ;
 }
 outfile.close ();
 infile.close ();

    return 0;
}
*/

int main(){
    char emp_id[100];
    char emp_name[100];
    int pay;

    //ifstream infile;
    //ofstream outfile;

    //infile.open("Input File.dat");
    //outfile.open("Output File.dat");

    Employee empl;
    empl.getdata("Employee.dat");

    //Add a print statement after this line in the output file to
    //mark the different answers


    TA t;
    t.ta_getdata("Instructor.dat", "Student.dat" );

    //TA t;
    //cout << "These students are not instructors \n\n";
    t.not_ta_getdata("Instructor.dat", "Student.dat" );

    Student s;
    s.getdata("Student.dat");


return 0;

}

