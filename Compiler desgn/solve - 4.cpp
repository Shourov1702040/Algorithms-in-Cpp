#include<bits/stdc++.h>
using namespace std;

int main()
{
    string text_c;
    int total_char = 0, n;
    fstream newfile;
    newfile.open("input.txt", ios::in);
    
    while(getline(newfile, text_c))
    {
        if(text_c == "") break;
        n = text_c.length();
        total_char+=n;
    }
    cout<<"Total number of characters = "<<total_char;
    newfile.close();

    return 0;
}

