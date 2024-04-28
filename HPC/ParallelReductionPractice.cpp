#include<bits/stdc++.h>
using namespace std;

int Min(vector<int> &v){
    int mini = v[0] , n = v.size();
    #pragma omp parallel for reduction(min : mini)
    for(int i = 0 ; i < n ; i++){
        if(v[i] < mini){
            mini = v[i];
        }
    } 
    return mini;
}

int Max(vector<int> &v){
    int maxi = v[0] , n = v.size();
    #pragma omp parallel for reduction(max : maxi)
    for(int i = 0 ; i < n ; i++){
        #pragma omp critical
        if(v[i] > maxi){
            maxi = v[i];
        }
    } 
    return maxi;
}

int Sum(vector<int> &v){
    int sum = 0 , n = v.size();
    #pragma omp parallel for 
    for(int i = 0 ; i < n ; i++){
        sum += v[i];
    } 
    return sum;
}

int Avg(vector<int> &v){
    int sum = Sum(v);
    return sum / (v.size() * 1.0);
}

int main(){

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i];
    int mini = Min(v);
    int maxi = Max(v);
    int sum = Sum(v);
    double avg = Avg(v);

    cout << mini << ' ' << maxi << ' ' << sum << ' ' << avg << endl;

    return 0;
}