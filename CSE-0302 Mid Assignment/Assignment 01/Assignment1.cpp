#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int main()
{
    optimize();
    FILE *input;
    FILE *output;
    string s;
    char p;
    input = fopen("input.txt","r");
    output = fopen("output.txt","w");

    while(!feof(input))
    {
        p = fgetc(input);
        s+=p;
    }
    cout<<s;
    cout<<endl;

    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '/' && s[i+1] == '/')
            while(s[i] != '\n') i++;

        else if(s[i] == '*')
            while(s[i] != '/') i++;

        else if(s[i]!=32 && s[i]!=9 && s[i]!='\n' && s[i]!='/' && s[i]!='*')
        {
            if(s[i-1] == '}') continue;
           cout<<s[i];
           fputc(s[i],output);
        }
    }

    fclose(input);
    fclose(output);
    return 0;
}
