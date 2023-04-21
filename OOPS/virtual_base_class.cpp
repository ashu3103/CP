#include<bits/stdc++.h>
using namespace std;

/*
Problem 
        -> B (a)
A (a) ->         -> D (a (two 'a's from B and from C))
        -> C (a)
*/

class Student{
    protected:
        int roll_no;
    public:
        void set_number(int a){
            roll_no = a;
        }
        void print_number(){
            cout << "Your Roll is " << roll_no << endl;
        }
};

class Test: virtual public Student{
    protected:
        float maths, physics;
    public:
        void set_marks(float m, float p){
            maths = m;
            physics = p;
        }
        void print_marks(){
            cout << "Maths marks - " << maths << "\n Physics marks - " << physics << endl;
        }
};

class Sports: virtual public Student{
    protected:
        float score;
    public:
        void set_score(float s){
            score = s;
        }

        void print_score(){
            cout << "PT Score - " << score << endl;
        }
};

class Result: public Test, public Sports{
    private:
        float total_marks;
    public:
        void print_total_score(){
            total_marks = maths+physics+score;
            cout << "Total Score - " << total_marks << endl;
        }
};

int main(){

    Result ashu;
    ashu.set_number(1);
    ashu.set_marks(89, 54);
    ashu.set_score(56);
    ashu.print_total_score();
    return 0;
}