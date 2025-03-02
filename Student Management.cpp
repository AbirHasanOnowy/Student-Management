#include<bits/stdc++.h>
using namespace std;

class Department
{
public:

    string dept_name;
    string subjects[6] = {};


    //Department creation method
    void create_department()
    {
        cout<<"Enter department name: ";
        cin>>this->dept_name;
        cout<<"Enter the name of the 6 subjects of the department\n";
        cin.ignore();
        for(int i=0; i<6; ++i)
        {
            cout<<"Subject "<<i+1<<": ";
            getline(cin,subjects[i]);
        }
    }

    void viewSubjects()
    {
        cout<<"The subjects of this department are as follows:\n";
        for(int i=0; i<6; ++i)
            cout<<i+1<<". "<<subjects[i]<<endl;
    }

};


vector<Department> Available_departments;


class Student
{
public:
    string name;
    int roll;
    int age;
    Department department;
    float grade[6];

    Student()
    {
        for(float &i:grade)
            i = -1;
    }

    Student(string name,int roll,int age,Department department):
        name(name),roll(roll),age(age),department(department)
    {
        for(float &i:grade)
            i = -1;
    }

    void change_department()
    {
        int id = -1;
        cout<<"Choose from available departments\n";
        for(int i=0; i<Available_departments.size(); ++i)
            cout<<i+1<<". "<<Available_departments[i].dept_name<<endl;
        while(id<1 && id>Available_departments.size())
        {
            cout<<"Select a department using id: ";
            cin>>id;
        }
        department = Available_departments[id-1];
        for(float &i:grade)
            i = -1;
    }

    void show_student_info()
    {
        cout<<"\n\nName : "<<name<<endl;
        cout<<"Roll : "<<roll<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"Department : "<<department.dept_name<<endl;

        if(grade[0] != -1)
        {
            cout<<"The grades are as follows:\n";
            for(int i=0; i<6; ++i)
                cout<<department.subjects[i]<<": "<<grade[i]<<endl;
        }
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
        Student new_student;
        cout<<"Enter student name : ";
        cin.ignore();
        getline(cin,new_student.name);
        cout<<"Enter student roll : ";
        cin>>new_student.roll;
        cout<<"Enter student age : ";
        cin>>new_student.age;
        int dept_cnt=Available_departments.size(),i=1;
        while(true)
        {
            cout<<"Select student department by entering department no."<<endl;
            for(int j=1; j<=dept_cnt; ++j)
            {
                cout<<j<<". "<< Available_departments[j-1].dept_name<<endl;
            }
            cout<<"Department no : ";
            cin>>i;
            if(i < 1 || i > dept_cnt)
                cout<<"Invalid selection. Try again.\n\n";
            else
            {
                new_student.department = Available_departments[i-1];
                break;
            }
        }
        students.push_back(new_student);
        cout<<"Given student Info : \n";
        new_student.show_student_info();
    }

    void changeStudentDepartment()
    {
        int roll;
        while(true)
        {
            cout<<"Enter a valid Student roll: ";
            cin>>roll;
            for(auto &stu:students)
            {
                if(stu.roll == roll)
                {
                    stu.change_department();
                    return;
                }
            }
        }
    }

    void assignStudentGrades()
    {
        int roll;
        while(true)
        {
            cout<<"Enter a valid Student roll: ";
            cin>>roll;
            for(auto &stu:students)
            {
                if(stu.roll == roll)
                {
                    stu.assign_grades();
                    return;
                }
            }
        }
    }

    void viewStudentInfo()
    {
        int roll;
        while(true)
        {
            cout<<"Enter a valid Student roll: ";
            cin>>roll;
            for(auto &stu:students)
            {
                if(stu.roll == roll)
                {
                    stu.show_student_info();
                    return;
                }
            }
        }
    }
};

void Department_info()
{
    int id = -1;
    cout<<"Choose from available departments\n";
    for(int i=0; i<Available_departments.size(); ++i)
        cout<<i+1<<". "<<Available_departments[i].dept_name<<endl;
    while(id<1 && id>Available_departments.size())
    {
        cout<<"Select a department using id: ";
        cin>>id;
    }
    Available_departments[id-1].viewSubjects();
}

int main()
{
    Department new_dept;
    new_dept.create_department();
    Available_departments.push_back(new_dept);
    Student_Management class_10;
    int choice=0;
    while(1)
    {
        cout<<"\n\nEnter choice number 0-5 to select desired operation\n";
        cout<<"0. Add department"<<endl;
        cout<<"1. Enroll student"<<endl;
        cout<<"2. Change Department of a student"<<endl;
        cout<<"3. Assign Grades of a student"<<endl;
        cout<<"4. View Info of a student"<<endl;
        cout<<"5. Department Subjects"<<endl;
        cout<<"6. End Programm"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 0:
            new_dept.create_department();
            Available_departments.push_back(new_dept);
            break;
        case 1:
            class_10.enroll_student();
            break;
        case 2:
            class_10.changeStudentDepartment();
            break;
        case 3:
            class_10.assignStudentGrades();
            break;
        case 4:
            class_10.viewStudentInfo();
            break;
        case 5:
            Department_info();
            break;
        case 6:
            return 0;
        default:
            cout<<"Make a valid choice\n";
        }
    }


    return 0;
}
