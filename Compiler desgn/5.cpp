#include<bits/stdc++.h>
using namespace std;

int main()
{
    string text_c;
    int line = 0;
    fstream newfile;
    newfile.open("input.txt", ios::in);
    
    while(getline(newfile, text_c))
    {
        line++;
    }
    cout<<"Total number of line =  "<<line<<"\n";
    newfile.close();

    return 0;
}

