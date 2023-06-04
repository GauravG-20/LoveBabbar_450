#include<bits/stdc++.h>
using namespace std;

int calculate(int r,int mid){
    double d=pow(r,2)+4*r*(2*mid);
    double n=(sqrt(d)-r)/(2.0*r);

    return floor(n);
}

int main()
{
    while(true){
        int n,m;
        cin >> n;
        if(!n) break;
        vector<int>arr1(n,0);
        for(auto &it:arr1) cin >> it;
        cin >> m;
        vector<int>arr2(m,0);
        for(auto &it:arr2) cin >> it;


        long long i=0,j=0,sum1=0,sum2=0,result=0;

        while(i<n and j<m){
            if(arr1[i]<arr2[j]) sum1+=arr1[i++];
            else if(arr1[i]>arr2[j]) sum2+=arr2[j++];
            else result+=max(sum1,sum2),sum1=arr1[i++],sum2=arr2[j++];
        }

        while(i<n) sum1+=arr1[i++];
        while(j<m) sum2+=arr2[j++];

        result+=max(sum1,sum2);

        cout << result << "\n";
    }
}
