/* Write a C/C++ program that reads text from a file and prints on the terminal each input 
line, preceded by the line number. The output will look like -

        1 This is the first trial line in the file,
        2 and this is the second line.
        
Try the problem once using fgetc() function and once using fgets() function for reading 
the input. Why is fread() not suitable for this purpose? */


#include <bits/stdc++.h> 
using namespace std;

int main()
{
    FILE *file1 = fopen("input.txt", "r");
    int line = 1, flag=1;
    char c;
    cout << "Using fgetc method:" << "\n\n";

    while((c = fgetc(file1)) != EOF)
    {
        if(flag==1) cout<<line++<<". ";
        cout<<c;
        
        if(c == '\n')  flag = 1;
        else  flag = 0;
    }
    fclose(file1);

    int len = 1000;
    char str[len];

    cout << "\n\nUsing fgets method:" <<" \n\n";
    FILE *file2 = fopen("input.txt" , "r");
    line = 1;
    while(fgets(str, len, file2) != NULL){
        cout<<line++<<". "<<str;
    }
    fclose(file2);

    return 0;
}
