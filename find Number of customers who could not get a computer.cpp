#include<bits/stdc++.h>
using namespace std;

int runCustomerSimulation(int n, string seq){
    // 0 --> unavailable person, 1 -->  available but unoccupied 2--> available and occupied
    vector<int>seats(26,0);
    int occupied=0,res=0;

    for(char ch:seq){
        int ind=ch-'A';
        if(seats[ind]==0){
            seats[ind]=1;
            if(occupied<n){
                seats[ind]=2;
                occupied++;
            }
        }
        else{
            if(seats[ind]==2) occupied--;
            else res++;
            seats[ind]=0;
        }
    }

    return res;
}

int main()
{
    cout << runCustomerSimulation (2, "ABBAJJKZKZ") << endl;
    cout << runCustomerSimulation (3, "GACCBDDBAGEE") << endl;
    cout << runCustomerSimulation (3, "GACCBGDDBAEE") << endl;
    cout << runCustomerSimulation (1, "ABCBCA") << endl;
    cout << runCustomerSimulation (1, "ABCBCADEED") << endl;
}
