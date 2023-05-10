#include<bits/stdc++.h>
using namespace std;

bool match(string s1, string s2){
    int n=s1.length(),m=s2.length();
    if(n!=m) return false;

    int i=0,j=0,cnt=0;
    while(cnt<2*n){
        if(j==m) return true;
        if(s1[i]==s2[j]) j++;
        else j=0;

        cnt++,i=(i+1)%n;
    }

    cnt=0;
    while(cnt<2*m){
        if(i==n) return true;
        if(s1[i]==s2[j]) i++;
        else i=0;

        cnt++,j=(j+1)%m;
    }

    return false;
}

int main()
{
    cout << match("BAA","ABA") << endl;
}
