#include<bits/stdc++.h>
using namespace std;

bool check(string &s1, string &s2){
    int n=s1.length(),m=s2.length();
    if(n>m) return false;

    unordered_map<char,int>freq;
    int count=0,i=0;

    for(char &it:s1){
        // if(freq[it]==0) count++;
        freq[it]++;
    }

    while(i<m){
        char ch=s2[i];
        if(freq.count(ch)){
            if(freq[ch]==0) count--;
            else if(freq[ch]==1) count++;
        }
        freq[ch]--;

        if(i>=n){
            ch=s2[i-n];
            freq[ch]++;
            if(!freq[ch]) count++;
            else if(freq[ch]==1) count--;
        }

        if(i>=n-1){
            if(count==freq.size()) return true;
        }
        i++;
    }

    return false;
}

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    cout << check(s1,s2) << endl;
}