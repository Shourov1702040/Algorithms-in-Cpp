// Write a C/C++ program to identify whether a given input line is a comment or not.

#include<bits/stdc++.h>
using namespace std;

int main(){
    string test_c;
    cout<<"Enter a string: ";
    getline(cin, test_c);
    int len = test_c.length();

    if(test_c[0] == '/' && test_c[1] == '/')
    {
        cout<<"The given string is a comment\n";
    }
    else if(test_c[0] == '/' && test_c[1] == '*' && test_c[len-2] == '*' && test_c[len-1] == '/' )
    {
        cout<<"The given string is a comment\n";
    }
    
    else
        cout<<"The given sting is NOT a comment\n";
    return 0;
}
