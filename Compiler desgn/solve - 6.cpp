/*Write a C/C++ program that reads text from a file, then delete the existing comment and save the output text file (without comment). 
  Also count and print the number of deletion. */


#include<bits/stdc++.h>
using namespace std;

void removeComments(string prgm)
{
    int n = prgm.length();
    string res;
    fstream newfile;
    int d=0;
    bool s_cmt = false;
    bool m_cmt = false;

    for (int i=0; i<n; i++)
    {
        if (s_cmt == true && prgm[i] == '\n')
            s_cmt = false;
 
        // If multiple line comment is on, then check for end of it
        else if  (m_cmt == true && prgm[i] == '*' && prgm[i+1] == '/')
            m_cmt = false,  i++;
 
        // If this character is in a comment, ignore it
        else if (s_cmt || m_cmt)
            continue;
        
        // Check for beginning of comments and set the approproate flags
        else if (prgm[i] == '/' && prgm[i+1] == '/')
            s_cmt = true, d++, i++;

        else if (prgm[i] == '/' && prgm[i+1] == '*')
            m_cmt = true, d++, i++;
 
        else  res += prgm[i];
    }

    newfile.open("input3.txt",ios::out);  
    if(newfile.is_open())
    {
        newfile<<res;
        newfile.close();
    }
    cout << "Number of deletion: "<<d << '\n';

}

int main()
{
    string prgm;
    fstream newfile,newfile2;

    newfile.open("input2.txt",ios::in); 
    if (newfile.is_open())
    { 
        string tp;
        while(getline(newfile, tp))
        {
            prgm += tp+'\n'; 
        }
        newfile.close(); 
    }

    removeComments(prgm);
    return 0;
}
