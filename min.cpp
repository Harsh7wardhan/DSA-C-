#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int mnDiff = INT_MAX, n = arr.size();
    unordered_set<int> h;
    for(int i=0;i<n-1;i++){
        mnDiff = min(mnDiff, arr[i+1] - arr[i]);
        h.insert(arr[i]);
    }
    h.insert(arr[n-1]);
    vector<vector<int>> l;
    for(int i=0;i<n;i++){
        if(h.count(arr[i]-mnDiff)){
            l.push_back({arr[i]-mnDiff, arr[i]});
        }
    }
    return l;
}
int main(){
    vector<int> sequence = {4, 3, 1, 2};
    vector<vector<int>> output = minimumAbsDifference(sequence);
    for(auto x: output){
        cout<<x[0]<<" "<<x[1]<<endl;
    }
}