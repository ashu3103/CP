#include<bits/stdc++.h>
using namespace std;

class Student{
    protected:
        int roll_number;
    public:
        void set_roll_number(int);
        void get_roll_number(void);
};

void Student :: set_roll_number(int r){
    roll_number = r;
}

void Student :: get_roll_number(){
    cout << roll_number << endl;
}

class Exam: public Student{
    protected:
        float maths;
        float physics;
    public:
        void set_marks(float, float);
        void get_marks(void);
};

void Exam :: set_marks(float m1, float m2){
    maths = m1;
    physics = m2;
}

void Exam :: get_marks(){
    cout << "Maths marks - " << maths << endl;
    cout << "Physics marks - " << physics << endl;
}

class Result: public Exam{
    float percentage;
    public:
        void display(){
            cout << "Your percentage is " << (maths+physics)/2.0 << endl;
        }
};



int main(){
    Result ashu;
    ashu.set_roll_number(1);
    ashu.get_roll_number();
    ashu.set_marks(90.9, 89.92);
    ashu.get_marks();
    ashu.display();
    return 0;
}