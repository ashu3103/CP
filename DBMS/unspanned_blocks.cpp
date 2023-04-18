#include<bits/stdc++.h>
using namespace std;

class org{

};

class unspanned_blocks{
    int max_cap;
    vector<record> records; 
    unspanned_blocks* nxt;

    unspanned_blocks(int n){
        max_cap = n;
        nxt = NULL;
    }
    ~unspanned_blocks(){
        records.clear();
        return;
    }

};

class record{
public:
   int record_size;
};

class record_data: public record{
private:
    vector<pair<int, int>> data;
public:
    record_data(){
        record_size = 0;
    }
    void insert_data(string str){

    }
};

class seperator: private record{
    
};

int main(){
    
    return 0;
}
