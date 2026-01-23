#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &nums, int &start, int end){
    if (end >= nums.size()){
        return;
    }
    for (int i = start; i <= end; i++){
        cout << nums[i] <<" ";
    }
    cout << endl;
    end++;
    print(nums, start, end);
}

void print_subarrays(vector<int> &nums, int &start){
    while (start < nums.size()){
        print(nums, start, start);
        start++;
    }
    return;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    int start = 0;
    print_subarrays(nums, start);
    return 0;
}