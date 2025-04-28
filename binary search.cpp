#include <iostream>
#include <ctime>

using namespace std;

int binarySearchHelp(int arr[], int first, int last, int x)
{
    if(first>last) return -1;
    int mid = (first+last)/2;
    if(arr[mid] == x) return mid;
    if(arr[mid] < x) return binarySearchHelp(arr, mid+1, last, x);
    return binarySearchHelp(arr, first, mid-1, x);
}

int binarySearch(int arr[], int n, int x)
{
    return binarySearchHelp(arr, 0, n-1, x);
}

void readArray(int arr[], int n)
{
    for(int i = 0; i<n; i++){
        arr[i] = rand()%41-20;
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i<n; i++){
       cout<<arr[i]<<" ";
    }
}

void merge(int arr[], int n1, int n2)
{
    int first[100];
    for(int i = 0; i<n1; i++){
        first[i] = arr[i];
    }
    int second[100];
    for(int i = 0; i<n2; i++){
        second[i] = (arr+n1)[i];
    }
    int i = 0;
    int j = 0;
    //int k = 0;
    while(i<n1 && j<n2){
        if(first[i]<second[j]){
            arr[i+j]=first[i];
            i++;
        }
        else{
            arr[i+j]=second[j];
            j++;
        }
    }
    while(i<n1){
        arr[i+j]=first[i];
        i++;
    }
    while(j<n2){
        arr[i+j]=second[j];
        j++;
    }
}

void mergeSort(int arr[], int n)
{
    if(n==1) return;
    int mid = n/2;

    mergeSort(arr, mid);
    mergeSort(arr+mid, n-mid);
    merge(arr, mid, n-mid);
}

int grid(int m, int n)
{
    if(m == 1 || n == 1) return 1;
    return grid(m,n-1)+ grid(m-1,n);
}

int stairs(int n)
{
    if(n == 0) return 1;
    if(n<0) return 0;
    return stairs(n-1)+stairs(n-2);
}

int hanoiTowerHelp(int n, char first, char second, char third)
{
    if(n==1){
        cout<<"Move disk "<<n<<" from "<<first<<" to "<<third<<endl;
        return 1;
    }
    int x = hanoiTowerHelp(n-1,first, third, second);
    cout<<"Move disk "<<n<<" from "<<first<<" to "<<third<<endl;
    int y = hanoiTowerHelp(n-1, second, first, third);
    return 1+x+y;
}

int hanoiTower(int n)
{
    return hanoiTowerHelp(n,'A','B','C');
}

bool isValid(int matrix[][20], int i, int j, int n)
{
    if(i>=0 && i<n && j>=0 && j<n && matrix[i][j]==1) return true;
    return false;
}

void depthFirstSearch(int matrix[][20], int i, int j, int n)
{
    if(!isValid(matrix,i,j,n)) return;
    matrix[i][j] = 0;
    depthFirstSearch(matrix,i,j+1,n);
    depthFirstSearch(matrix,i,j-1,n);
    depthFirstSearch(matrix,i+1,j,n);
    depthFirstSearch(matrix,i+1,j-1,n);
    depthFirstSearch(matrix,i+1,j+1,n);
    depthFirstSearch(matrix,i-1,j,n);
    depthFirstSearch(matrix,i-1,j-1,n);
    depthFirstSearch(matrix,i-1,j+1,n);
}

int islands(int matrix[][20], int n)
{
    int cnt = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(matrix[i][j]==1){
                cnt++;
                depthFirstSearch(matrix, i, j, n);
            }
        }
    }
    return cnt;
}

void randMatrix(int matrix[][20], int n)
{
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            matrix[i][j] = rand()%2;
        }
    }
}

void printMatrix(int matrix[][20], int n)
{
    for(int i = 0; i<n; i++){
        printArray(matrix[i],n);
        cout<<endl;
    }
}

int main()
{

    srand(time(0));
    /*
    int arr[100];
    int n;
    cin>>n;
    readArray(arr, n);
    printArray(arr, n);
    mergeSort(arr,n);
    cout<<endl;
    printArray(arr,n);
    cout<<endl<<binarySearch(arr,n,5);
    */
    //cout<<grid(3,4);
    //cout<<hanoiTower(6);
    int matrix[20][20];
    randMatrix(matrix,7);
    printMatrix(matrix,7);
    cout<<islands(matrix, 7);
}
