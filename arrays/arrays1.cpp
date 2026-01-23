#include<bits/stdc++.h>
using namespace std;

int left_rotate(int arr[], int n){
    int temp= arr[0];
    for (int i=1; i<n; i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
    return 0;
}

//brute
int rotate(int arr[], int n, int d){
    d=d%n;
    int temp[d];
    for (int i=0; i<d; i++){
        temp[i]=arr[i];
    }
    for (int i=d; i<n; i++){
        arr[i-d]=arr[i];
    }
    for (int i=0; i<d; i++){
        arr[n-d+i]=temp[i];
    }
    return 0;
}

//optimal
int rotate1(int arr[], int n, int d){
    reverse(arr, arr+d);
    reverse(arr+d, arr+n);
    reverse(arr, arr+n);
}

//brute
int right_rotate(int arr[], int n, int d){
    d=d%n;
    int k=0;
    int temp[d];
    for (int i=n-d; i<n; i++){
        temp[k]=arr[i];
        k++;
    }
    for (int i=n-d-1; i>=0; i--){
        arr[i+d]=arr[i];
    }
    for (int i=0; i<d; i++){
        arr[i]=temp[i];
    }
    return 0;
}

//optimal
int right_rotate1(int arr[], int n, int d){
    reverse(arr, arr+n-d);
    reverse(arr+n-d, arr+n);
    reverse(arr, arr+n);
}

//brute
int move_zeroes(int arr[], int n){
    vector<int>v;
    for (int i=0; i<n;i++){
        if (arr[i]!=0){
            v.push_back(arr[i]);
        }
    }
    for (int i=0; i<v.size(); i++){
        arr[i]=v[i];
    }
    for (int i=v.size(); i<n; i++){
        arr[i]=0;
    }
}

//optimal
void m_zeroes(int arr[], int n){
    int j=0;
    for (int i=0; i<n; i++){
        if (arr[i]!=0){
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int linear_search(int arr[], int n, int num){
    for(int i=0; i<n; i++){
        if (arr[i]==num){
            return i;
        }
    }
    return -1;
}

//brute
void union_of_arrays(int arr1[], int n1, int arr2[], int n2){
    set<int>st;
    for (int i=0; i<n1; i++){
        st.insert(arr1[i]);
    }
    for (int i=0; i<n2; i++){
        st.insert(arr2[i]);
    }
    for (auto it:st){
        cout<<it<<" ";
    }
}

//optimal
void union_optimal(int arr1[], int n1, int arr2[], int n2){
    int i=0,j=0,k=0;
    vector<int>union_vector;
    while (i<n1 && j<n2){
        if (arr1[i]<=arr2[j]){
            if (union_vector.size()==0 || union_vector.back()!=arr1[i]){
                union_vector.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if (union_vector.size()==0 || union_vector.back()!=arr2[j]){
                union_vector.push_back(arr2[j]);
            }
            j++;
        }
    }
    while (i<n1){
        if (union_vector.size()==0 || union_vector.back()!=arr1[i]){
                union_vector.push_back(arr1[i]);
            }
            i++;
    }
    while (j<n2){
        if (union_vector.size()==0 || union_vector.back()!=arr2[j]){
                union_vector.push_back(arr2[j]);
            }
            j++;
    }
    for (k=0; k<union_vector.size(); k++){
        cout<< union_vector[k]<< " ";
    }
}

//brute
void intersection_of_arrays(int arr1[], int n1, int arr2[], int n2){
    vector<int>ans;
    for (int i=0; i<n1; i++){
        for (int j=0; j<n2; j++){
            if (arr1[i]==arr2[j]){
                if (ans.size()==0 || ans.back()!=arr1[i]){
                    ans.push_back(arr1[i]);
                    break;
                }
            }
            if (arr1[i]<arr2[j]){
                break;
            }
        }
    }
    for (auto it:ans){
        cout<<it<<" ";
    }
}

//optimal
void intersection2(int arr1[], int n1, int arr2[], int n2){
    vector<int>ans;
    int i=0, j=0;
    while (i <n1 && j<n2){
        if (arr1[i]<arr2[j]){
            i++;
        }
        else if (arr2[j]<arr1[i]){
            j++;
        }
        else {
            if (ans.size()==0 || ans.back()!=arr1[i]){
                ans.push_back(arr1[i]);
            }
            i++;
            j++;
        }
        }
    for (auto it:ans){
        cout<<it<<" ";
    }
}


int main(){
    int n1=8;
    int n2=7;
    int arr1[n1]={1,2,2,3,3,4,5,6};
    int arr2[n2]={2,3,3,5,6,6,7};
    intersection2(arr1, n1, arr2, n2);
    return 0;
}