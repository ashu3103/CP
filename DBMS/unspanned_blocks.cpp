#include<bits/stdc++.h>
#include <ctype.h>
using namespace std;

bool isNumber(string str){
    for(int i=0;i<str.size();i++){
        if(!isdigit(str[i])){
            return false;
        }
    }
    return true;
}

class record{
    protected:
        vector<pair<string, string>> data;
    public:
        virtual int getDataSize(){
            return 0;
        }

        vector<pair<string, string>> getData(){
            return data;
        }
};

class fixed_length_record: virtual public record{
    int record_length;
    public:
        fixed_length_record(vector<pair<string, string>> data){
            this->data = data;
            record_length = -1;
        }
        int getDataSize(){
            if(record_length != -1){
                return record_length;
            }
            int size = 0;
            for(int i=0;i<data.size();i++){
                if(isNumber(data[i].second)){
                    size+=4;
                }else{
                    size+=8;
                }
            }
            return record_length = size;
        }
};

class variable_length_record: virtual public record{
    public:
        variable_length_record(vector<pair<string, string>> data){
            this->data = data;
        }
        int getDataSize(){
            int size = 0;
            for(int i=0;i<data.size();i++){
                if(isNumber(data[i].second)){
                    size+=4;
                }else{
                    size+=8;
                }
            }
            return size;
        }
};

class seperator: virtual public record{
    int size;
    public:
        seperator(){
            pair<string, string> pr = {"SEP", "$"};
            data = {pr};
            size = 1;
        }
        int getDataSize(void){
            return size;
        }
};

class block_implementation{
    int max_size;
    int curr_size;
    block_implementation* nxt_block_ptr;
    public:
        vector<record*> records;
        block_implementation(int N){
            records.clear();
            max_size = N;
            curr_size = 0;
            nxt_block_ptr = NULL;
        }
        bool checkSpace(record* r){
            if((curr_size + r->getDataSize() + 1) > max_size){
                return false;
            }
            return true;
        }
        int addRecord(record* r){
            if((curr_size + r->getDataSize() + 1) > max_size){
                records.pop_back();
                return 0;
            }
            curr_size += r->getDataSize() + 1;
            record* sep = new seperator();
            records.push_back(r);
            records.push_back(sep);
            return 1;
        }
        void setNxtPointer(block_implementation* bl){
            nxt_block_ptr = bl;
        }
        block_implementation* getNxtPointer(){
            return nxt_block_ptr;
        }
};

class file{
    int block_size;
    block_implementation* curr_block_ptr;
    public:
        block_implementation* head;

        file(int N){
            block_size = N;
            head = NULL;
            curr_block_ptr = NULL;
        }

        int runQuery(string query){
            vector<vector<pair<string, string>>> query_data = {{{"A","23"}, {"B", "hello"}}, {{"C", "23"}}};

            for(int i=0;i<query_data.size();i++){
                record* rec = new variable_length_record(query_data[i]);
                if(head == NULL){
                    block_implementation* block = new block_implementation(block_size);
                    this->head = block;
                    curr_block_ptr = block;
                    if(!curr_block_ptr->checkSpace(rec)){
                        cout << "Record Size Exceeds" << endl;
                        return 0;
                    }
                    curr_block_ptr->addRecord(rec);
                }else{
                    if(!curr_block_ptr->checkSpace(rec)){
                        block_implementation* new_block = new block_implementation(block_size);
                        curr_block_ptr->setNxtPointer(new_block);
                        curr_block_ptr = new_block;
                    }
                    int ans = curr_block_ptr->addRecord(rec);
                    if(ans == 0){

                        return 0;
                    }
                }
            }
            return 1;
        }

        void displayInMemory(){
            block_implementation* temp = this->head;
            while(temp){
                cout << "|";
                vector<record*> records = temp->records;
                for(int i=0;i<records.size();i++){
                    vector<pair<string, string>> data = records[i]->getData();
                    if(data[0].first == "SEP"){
                        cout << "$";
                        continue;
                    }
                    cout << "{";
                    for(int j=0;j<data.size();j++){
                        if(j==0){
                            cout << data[j].first << ":" << data[j].second;
                        }else{
                            cout << ", " << data[j].first << ":" << data[j].second;
                        }
                    }
                    cout << "}";
                }
                cout << "|-------->" << endl;
                temp = temp->getNxtPointer();
            }
        }
};


int main(){
    int block_size;
    cin >> block_size;
    file f(block_size);

    f.runQuery("e");
    f.displayInMemory();
    return 0;
}