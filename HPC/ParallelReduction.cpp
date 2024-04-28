#include<bits/stdc++.h>
using namespace std;

int parallelMin(vector<int> &v , int n){
    int mini = v[0];
    #pragma omp parallel for reduction(min : mini)
        for(int i = 0 ; i < n ; i++){
            mini = min(mini , v[i]);
        }
    return mini;
}

int parallelMax(vector<int> &v , int n){
    int maxi = v[0];
    #pragma omp parallel for reduction(max : maxi)
        for(int i = 0 ; i < n ; i++){
            maxi = max(maxi , v[i]);
        }
    return maxi;
}

int parallelSum(vector<int> &v , int n){
    int sum = v[0];
    #pragma omp parallel for reduction(+ : sum)
        for(int i = 0 ; i < n ; i++){
            sum += v[i];
        }
    return sum;
}

double parallelAvg(vector<int> &v , int n){
    int sum = parallelSum(v , n);
    return sum / (n * 1.0);
}


int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i];
    int sum = parallelSum(v , n);
    int maxi = parallelMax(v , n);
    double avg = parallelAvg(v , n);
    int mini = parallelMin(v , n);
    cout << mini << endl;
    cout << maxi << endl;
    cout << sum << endl;
    cout << avg << endl;
    // cout << min << endl << max << endl << sum << endl << avg << endl;
    return 0;
}