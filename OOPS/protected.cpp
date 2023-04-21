#include<bits/stdc++.h>
using namespace std;

class Base{
    int a;
    protected:
        int b; // like private but can be inherited
    public:
        int c;
};

/*
                                        Visibility Mode
                        |     Private    |   Public      |   Protected    |
                        |                |               |                |
    1 Private members   |  not inherited | not inherited | not inherited  |
    2 Public members    |      Private   |     Public    |   Protected    |
    3 Protected members |      Private   |    Protected  |   Protected    |

*/


class Derived: private Base{

};

int main(){
    Base b;
    Derived d;
    cout << b.c << endl;
    // cout << d.c << endl;
    return 0;
}