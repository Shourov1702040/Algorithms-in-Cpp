/* Write a C/C++ program that reads text from a file, then delete the existing tabs (spaces)
and new line and save the output text file. Also count and print the number of deletion. */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string prgm,final_pgrm;
    fstream newfile,newfile2;
    int count_del = 0;
    newfile.open("input4.txt",ios::in);

    if (newfile.is_open())
    { 
        string c_l;
        while(getline(newfile, c_l))
        {
            if(c_l.empty())
            {
                count_del+=1;
                continue;
            }
            else
                prgm+=c_l+'\n';
        }
        newfile.close();
    }
    
    for (int i = 0; i < int(prgm.length()); ++i)
    {
        if (prgm[i]=='\t' ||prgm[i]=='\n' )
        {
            count_del+=1;
            continue;
        }
        else
        {
            final_pgrm+=prgm[i];
        }
    }
    
    newfile2.open("input5.txt",ios::out);
    if(newfile2.is_open())
    {
        newfile2<<final_pgrm;
        newfile2.close(); 
    }
    cout << "Number of deletion: "<<count_del << '\n';

    return 0;
}
