#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include<vector>
#include<string>

using namespace std;

int main(){
    for(int i=0; i<73; i++){
        string ten_file = "";
        ten_file.push_back(char(i/10 + 48));
        ten_file.push_back(char(i%10 + 48));
        ten_file += ".txt";
        ifstream cin(ten_file.c_str());
        vector<string> s;
        while(true){
            string t;
            if(getline(cin, t)){
                s.push_back(t);
            }else{
                break;
            }
        }
        system("cls");
        int number = 0;
        for(int i=0; i<s[s.size() - 1].size(); i++){
            number = number*10 + s[s.size() - 1][i] - 48;
        }
        for(int i=0; i<s.size() - 1; i++)
            cout << s[i] << endl;
        _sleep(number);
    }
    return 0;
}