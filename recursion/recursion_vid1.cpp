#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    if (n == 1){
        return 1;
    }
    return (n * factorial(n-1));
}

void print(int n){
    if (n == 0){
        return;
    }
    print(n-1);
    cout << n << " ";
}

int power(int n){
    if (n == 0){
        return 1;
    }
    return (2*power(n-1));
}

int fibonacci(int n){
    if (n <= 1){
        return n;
    }
    return (fibonacci(n-1) + fibonacci(n-2));
}

int sum(int n){
    if (n == 1){
        return 1;
    }
    return (n + sum(n-1));
}

void print_array(int arr[], int n, int i){
    if (i == n){
        return;
    }
    cout << arr[i] << " ";
    print_array(arr, n, i+1);
}

bool linear_search(int arr[], int n, int idx, int target){
    if (idx == n){
        return false;
    }
    if (arr[idx] == target){
        return true;
    }
    return linear_search(arr, n, idx+1, target);
}

int min_num_in_array(int arr[], int n, int idx, int mini){
    if (idx == n){
        return mini;
    }
    mini = min(mini, arr[idx]);
    min_num_in_array(arr, n, idx+1, mini);
}

int max_num_in_array(int arr[], int n, int idx, int maxi){
    if (idx == n){
        return maxi;
    }
    maxi = max(maxi, arr[idx]);
    max_num_in_array(arr, n, idx+1, maxi);
}

void even_num(vector<int>&nums, int idx, vector<int>&vec2){
    if (idx == nums.size()){
        return;
    }
    if (nums[idx] % 2 == 0){
        vec2.push_back(nums[idx]);
    }
    even_num(nums, idx+1, vec2);
}

void double_array(vector<int>&nums, int idx, vector<int>&vec3){
    if (idx == nums.size()){
        return;
    }
    vec3[idx] = 2*nums[idx];
    double_array(nums, idx+1, vec3);
}

void print_occurence(int arr[], int n, int idx, int target){
    if (idx == n){
        return;
    }
    if (arr[idx] == target){
        cout << idx << " ";
    }
    print_occurence(arr, n, idx+1, target);
}

void print_str_occurence(string s, int n, int idx, char target){
    if (idx == n){
        return;
    }
    if (s[idx] == target){
        cout << idx << " ";
    }
    print_str_occurence(s, n, idx+1, target);
}

void digits(int num, vector<int>&vec4){
    if (num == 0){
        return;
    }
    int digit = num%10;
    num = num/10;
    digits(num, vec4);
    vec4.push_back(digit);
}

void form_num(vector<int>& arr, int idx, int &num){
    if (idx < 0){
        return;
    }
    num += arr[idx] * pow(10, idx);
    form_num(arr, idx-1, num);
}

bool check_sorted(int arr[], int idx, int n){
    if (idx == n-1){
        return true;
    }
    if (arr[idx] > arr[idx+1]){
        return false;
    }
    return check_sorted(arr, idx+1, n);
}

int main(){
    cout << factorial(4) << endl;

    print(5);
    cout << endl;

    cout << power(10) << endl;
    cout << fibonacci(5) << endl;
    cout << sum(5) << endl;

    int n = 5;
    int arr[5] = {5,4,3,2,6};
    print_array(arr, n, 0);
    cout << endl;

    cout << linear_search(arr, n, 0, 3) << endl;

    int mini = INT_MAX;
    cout << min_num_in_array(arr, n, 0, mini) << endl;

    int maxi = INT_MIN;
    cout << max_num_in_array(arr, n, 0, maxi) << endl;

    vector<int>nums = {2,3,5,4,6,7,9,10};
    vector<int>vec2;
    even_num(nums, 0, vec2);
    for (int i = 0; i<vec2.size(); i++){
        cout << vec2[i] << " ";
    }
    cout << endl;

    vector<int>vec3(nums.size(), 0);
    double_array(nums, 0, vec3);
    for (int i = 0; i<vec3.size(); i++){
        cout << vec3[i] << " ";
    }
    cout << endl;

    int k = 5;
    int arr2[5] = {2,4,2,2,6};
    print_occurence(arr2, k, 0, 2);
    cout << endl;

    string s = "babbar";
    print_str_occurence(s, s.length(), 0, 'a');
    cout << endl;

    vector<int>vec4;
    digits(2356, vec4);
    for (int i = 0; i<vec4.size(); i++){
        cout << vec4[i] << " ";
    }
    cout << endl;

    vector<int>nums2 = {2,3,5,4};
    int num = 0;
    form_num(nums2, nums2.size()-1, num);
    cout << num << endl;

    int f = 5;
    int arr4[f] = {1,3,5,8,9};
    cout << check_sorted(arr4, 0, f);
    cout << endl;
    return 0;
}