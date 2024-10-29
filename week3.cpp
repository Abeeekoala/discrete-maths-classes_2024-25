#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int majority(vector<int> &x){
    int n = x.size();

    if(n==0){ return -1;}
    if(n==1){ return 0;}

    int mid = n/2;
    vector<int> x_L(x.begin(), x.begin() + mid);
    vector<int> x_R(x.begin() + mid, x.end());

    int L = majority(x_L);
    int R = majority(x_R);

    if(L >= 0){
        int c = 0; 
        for(int i =0; i < n; i++){
            if(x[i] == x[L]) c++;
        }
        if(c > mid) return L;
    }

    if(R >= 0){
        int c = 0; 
        for(int i =0; i < n; i++){
            if(x[i] == x[R + mid]) c++;
        }
        if(c > mid) return R + mid;
    }

    return -1;
}

#define WRONG { cout << "Nope!" << endl; return 0; }

int main(void)
{
    vector<int> x1{1,2,3,4,3,2,2,2,2,2,2,3,2,1,2,3};
    vector<int> x2{8,9,10,10};
    int maj1 = majority(x1);
    int maj2 = majority(x2);
    
    cout << maj1 << " " << maj2 << endl;
    if(maj1 == -1) WRONG;
    if(maj1 >= x1.size()) WRONG;
    if(x1[maj1]!=2) WRONG;
    if(maj2!=-1) WRONG;
    cout << "You got it !" << endl;
    return 0;

}
