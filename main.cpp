#include <iostream>
#include "MyNext_NTC.h"

using namespace std;

int main(){
    cout<<"Hello there!"<<endl;
    NTC R(3, 4673, 4960);
    //R.init(); //for Arduino boards, uncomment this line | comment or change it for other test cases
    cout<<R.read()<<endl;

    return 0;
}