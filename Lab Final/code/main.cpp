#include<bits/stdc++.h>

using namespace std;

vector<string>sp,ke,ri;
map<string,string>mp,mpp;
string ans;

bool isTERMINAL (char a){
if(a>='A' && a<='Z') return true;
return false;
}

void FIRST (string key){
string val = mp[key];
if (isTERMINAL (val [0])){
    string p= "";
    p+= val(0);
    FIRST (p);

}
}
else{
    ans+= val(0);
    ans+= ",";
    int flag=0;
    for(int i=0; i<val.size(); i++){
        if(val [i]=='|'){
            flag= 1;
            continue;
        }
    }
}
if(flag){
    ans += val[i];
}

void FOLLOW (string key, int z){

int flag=0;

for(int i=0; i<ri.size(); i++)
    if (ri[i].find(key) != string::npos){
        if(key.size()==1){
            for(int j=0; j<ri[i].size(); j++){
                if (ri[i] [j]== key[0]){
                    if(j+1<ri.size() && ri[i][j+1]!='\'){
                        flag= 1;
                        if(isTERMINAL (ri[i][j+1])==false){
                            if(z==0) ans +="$,";
                            ans += ri [i][j+1];

                        }
                        else{
                            string g= ri[i];
                            g.erase(0,1);
                            FIRST (g);
                            if (z==0)ans += "$";
                            FOLLOW (mpp[ri[i],1);

                        }
                        break;
                }
            }
        }
    }
}
else{
    for(int j=0; j+1<ri[i].size(); j++){
        if(ri [i][j]== key[0] && ri[i][j+1]==key [1]){
            if(j+2>=ri[i].size()){
                FOLLOW(mpp [ri[i]],1);
                if(==0)ans += ",$";
            }
            else{
                ans="$";
            }
        }
    }
    break;
}

if(flag)break;
}
}
string remove_space(string s){
    starting p="";
for (int i=0; i<s.size(); i++){
    if (s[i]!='') p= p+ s[i];
}
return p;
}





int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
