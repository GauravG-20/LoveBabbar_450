# Test Input:

```
4
1 5 500
3 5 250
6 19 250
2 19 251
````

# Approach 1: Using dp O(N^2)

```
#include<bits/stdc++.h>
using namespace std;

struct Job{
    int start;
    int end;
    int profit;
};

int f(int ind,int prev_ind,vector<Job>&jobs){
    if(ind==0) return 0;

    int n=jobs.size();
    if(prev_ind==n or jobs[prev_ind].start>=jobs[ind-1].end){
        int take=jobs[ind-1].profit+f(ind-1,ind-1,jobs);
        int ntake=f(ind-1,prev_ind,jobs);
        return max(take,ntake);
    } 
    else return f(ind-1,prev_ind,jobs);
}

int main()
{
    int n;
    cin >> n;
    vector<Job>jobs(n);
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    
    for(int i=0;i<n;i++){
        int start,end,profit;
        cin>>start>>end>>profit;

        jobs[i]={start,end,profit};
    }

    sort(jobs.begin(),jobs.end(),[](Job &a,Job &b){
        return a.end<b.end;
    });

    for(int ind=1;ind<=n;ind++){
        for(int prev=n;prev>=ind;prev--){
            if(prev==n or jobs[prev].start>=jobs[ind-1].end){
            int take=jobs[ind-1].profit+dp[ind-1][ind-1];
            int ntake=dp[ind-1][prev];

            dp[ind][prev]=max(take,ntake);
            } 
            else dp[ind][prev]=dp[ind-1][prev];
        }
    }

    cout << dp[n][n] << endl;
//     cout << f(n,n,jobs) << endl;
}
```

# Approach 2: Using dp: O(NlogN)

```
#include<bits/stdc++.h>
using namespace std;

struct Job{
    int start;
    int end;
    int profit;
};

int findNext(int end,vector<Job>&jobs){
    int low=0,high=end-1;

    while(low<=high){
        int mid=low+high>>1;
        if(jobs[mid].end<=jobs[end].start) low=mid+1;
        else high=mid-1;
    }

    return low-1;
}

int f(int ind,vector<Job>&jobs){
    if(ind==-1) return 0;
    if(ind==0) return jobs[0].profit;

    int nxtInd=findNext(ind,jobs);
    int take=jobs[ind].profit+f(nxtInd,jobs);
    int ntake=f(ind-1,jobs);

    return max(take,ntake);
}

int main()
{
    int n;
    cin >> n;
    vector<Job>jobs(n);
  
    for(int i=0;i<n;i++){
        int start,end,profit;
        cin>>start>>end>>profit;

        jobs[i]={start,end,profit};
    }

    sort(jobs.begin(),jobs.end(),[](Job &a,Job &b){
        if(a.end==b.end) return a.profit<b.profit;
        else return a.end<b.end;
    });

    vector<int>dp(n,0);
    dp[0]=jobs[0].profit;

    for(int ind=1;ind<n;ind++){
        int nxtInd=findNext(ind,jobs);
        int take=jobs[ind].profit,ntake=dp[ind-1];

        if(nxtInd>-1) take+=dp[nxtInd];
        dp[ind]=max(take,ntake);
    }

    cout << dp[n-1] << endl;
//     cout << f(n-1,jobs) << endl;

}
```
