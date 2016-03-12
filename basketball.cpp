#include <iostream>
#include "competition.h"

using namespace std;

int main() {
    cout << "Input a basketball competition results' file name:" << endl;
    string file_name;
    cin>>file_name;
    //c://Users/Qun/ClionProjects/lab2/results.txt
    Result result;
    result.load(file_name);
    result.sort();
    result.print();
    return 0;
}