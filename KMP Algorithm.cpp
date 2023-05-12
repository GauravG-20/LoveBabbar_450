#include<bits/stdc++.h>
using namespace std;

int main()
{
    string patt,text;
    cin >> patt >> text;

    int n=patt.length(),m=text.length(),i=0,j=1;
    vector<int>prefix(n,0),positions;

    while(j<n){
        if(patt[i]==patt[j]){
            prefix[j]=i+1;
            i++,j++;
        }
        else if(i) i=prefix[i-1];
        else{
            prefix[j]=0;
            j++;
        }
    }

    i=0,j=0;
    while(j<=m){
        if(i==n){
            positions.push_back(j-n);
            i=prefix[i-1];
        }
        else if(j<m and patt[i]==text[j]) i++,j++;
        else if(i) i=prefix[i-1];
        else j++;
    }

    if(!positions.size()) cout << "No positions in the text found!!" << endl;
    else for(auto it:positions) cout << it << ", ";
    cout << endl; 
}
