#include<bits/stdc++.h>
using namespace std;

class Department
{
    string dept_name;
    string subjects[6] = {};

public:
    Department(){}

    //Department creation method
    void create_department(){
        cout<<"Enter department name: ";
        cin>>this->dept_name;
        cout<<"Enter the name of the 6 subjects of the department\n";
        for(int i=0; i<6; ++i)
        {
            cout<<"Subject "<<i+1<<": ";
            cin>>this->subjects[i];
        }

    }
};


vector<Department> Available_departments;


class Student
{
    string name;
    int roll;
    int age;
    Department department;
    float grade[6];

public:
    Student(string name,int roll,int age,Department department):
        name(name),roll(roll),age(age),department(department){
            for(int &i:grade)
                i = -1;
        }

    void change_department(Department new_department)
    {
        department = new_department;
        for(int &i:grade)
                i = -1;
    }

    void show_student_info()
    {
        cout<<"\n\nName : "<<name<<endl;
        cout<<"Roll : "<<roll<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"Department : "<<department.dept_name<<endl;

        if(grade[0] != -1)
            for(int i=0; i<6; ++i)
                cout<<department.subjects[i]<<": "<<grade[i]<<endl;
        else
            cout<<"Grade not assigned yet.\n";

        cout<<endl;
    }

    void assign_grades()
    {
        cout<<"Enter grades for the subjects:\n";
        for(int i=0; i<6; ++i)
        {
            cout<<department.subjects[i]<<": ";
            cin>>grade[i];
        }
    }
};


class Student_Management
{
    vector<Student> students;
public:
    void enroll_student()
    {
        string name;
        int age;
        int roll;
        int dept_no = 0;
    }
};

int main()
{

    return 0;
}
