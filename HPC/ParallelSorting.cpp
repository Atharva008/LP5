#include<bits/stdc++.h>
using namespace std;


void ParallelBubble(vector<int> &v){
    int n = v.size();
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n - i - 1 ; j++){
            if(v[j] > v[j+1]){
                swap(v[j] , v[j+1]);
            }
        }
    }
}

void merge(vector<int> &v , int low , int mid , int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;


    while(left <= mid and right <= high){
        if(v[left] <= v[right]){
            temp.push_back(v[left]);
            left++;
        }
        else{
            temp.push_back(v[right]);
            right++;
        }
    }


    while(left <= mid){
        temp.push_back(v[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(v[right]);
        right++;
    }

    for(int i = low ; i <= high ; i++){
        v[i] = temp[i - low];
    }
}

void ParallelMerge(vector<int> &v , int low , int high){
    if(low >= high) return;
    int mid = (high + low) / 2;
    ParallelMerge(v , low , mid);
    ParallelMerge(v , mid + 1 , high);
    merge(v , low , mid , high);
}

int main(){

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i];
    // ParallelBubble(v);
    ParallelMerge(v , 0 , n - 1);

    for(int i = 0 ; i < n ; i++) cout << v[i] << ' ';

    return 0;
}