#include<bits/stdc++.h>
using namespace std;





void merge(vector<int> &v , int low , int mid , int high){
    int left = low , right = mid + 1;
    vector<int> temp;

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


void MergeSort(vector<int> &v , int low , int high){
    if(low >= high){
        return;
    }

    int mid = (low + high) / 2;
    MergeSort(v , low , mid);
    MergeSort(v , mid + 1 , high);
    merge(v , low , mid , high);
}


void BubbleSort(vector<int> &v){
    int n = v.size();
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n - i - 1 ; j++){
            if(v[j] > v[j+1]){
                swap(v[j] , v[j+1]);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i];

    MergeSort(v,0,n-1);
    for(auto it : v) cout << it << ' ';
    cout << endl;
    return 0;
}