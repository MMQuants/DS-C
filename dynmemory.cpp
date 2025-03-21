#include <iostream>
#include <ctime>

using namespace std;

bool allocateMemory(int*& arr, int n)
{
    arr = new(nothrow) int[n];
    return arr!=nullptr;
}

void deallocateMemory(int*& arr)
{
    delete[] arr;
    arr = nullptr;
    cout<<"Memory deallocated!"<<endl;
}

void initializeArray(int* const arr, int n)
{
    for(int i = 0; i<n; i++)
    {
        *(arr+i) = rand()%10+1;
    }
}

void printArray(const int* const arr, int n)
{
    for(int i = 0; i<n; i++)
    {
        cout<<*(arr+i)<<" ";
    }
}

bool copyArray(const int* const arr1, int n1,
               int*& arr2, int& n2, int& size2)
{
    if(size2<n1)
    {
        deallocateMemory(arr2);////!!!!
        if(allocateMemory(arr2, n1))
        {

            size2 = n1;
        }
        else
        {
            n2 = 0;
            size2 = 0;
            return false;
        }
    }
    for(int i = 0; i<n1; i++)
    {
        *(arr2+i) = *(arr1+i);
    }
    n2 = n1;
    return true;
}

bool expand(int*& arr, int n, int& size)
{
    int* temp;
    int newSize = size+size/2;
    if(allocateMemory(temp, newSize))
    {
        copyArray(arr, n, temp, n, newSize);
        deallocateMemory(arr);
        arr = temp;
        size = newSize;
        return true;
    }
    return false;
}

bool insertLast(int*& arr, int& n, int& size, int elem)
{
    if(n == size && !expand(arr, n, size)) return false;
    *(arr+n++) = elem;
    //n++;
    return true;
}

bool insertAt(int*& arr, int& n, int& size,
              int index,int elem)
{
    if((index<0 || index>=n) ||
            n == size && !expand(arr, n, size))
        return false;
    for(int i = n-1; i>=index; i--)
    {
        *(arr+i+1) = *(arr+i);
    }
    *(arr+index) = elem;
    n++;
    return true;
}

bool allocateMatrix(int**& matrix, int m, int n)
{
    matrix = new(nothrow) int*[m];
    if(!matrix) return false;
    for(int i = 0; i<m; i++)
    {
        if(!allocateMemory(*(matrix+i), n))
        {
            for(int j = i-1; j>=0; j--)
            {
                deallocateMemory(*(matrix+j));
            }
            delete[] matrix;
            matrix = nullptr;
            return false;
        }
    }
    return true;
}

void deallocateMatrix(int**& matrix, int m)
{
    for(int i = 0; i<m; i++)
    {
        deallocateMemory(*(matrix+i));
    }
    delete[] matrix;
    matrix = nullptr;
    cout<<"Memory deallocated!"<<endl;
}

void randMatrix( int**  matrix, int m, int n)
{
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            *(*(matrix+i)+j) = rand()%10+1;
        }
    }
}

void printMatrix(int** matrix, int m, int n)
{
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cout<<*(*(matrix+i)+j)<<" ";
        }
        cout<<endl;
    }
}

int minMax(int** matrix, int m, int n)
{
    int max = **matrix;
    for(int j = 1; j<n; j++)
    {
        if(*(*matrix+j)>max)
        {
            max = *(*matrix+j);
        }
    }
    int min = max;
    for(int i = 1; i<m; i++)
    {
        max = **(matrix+i);
        for(int j = 1; j<n; j++)
        {
            if(*(*(matrix+i)+j)>max)
            {
                max = *(*(matrix+i)+j);
            }
        }
        if(max<min){
            min = max;
        }
    }
    return min;
}

int main()
{
    srand(time(0));
    int** matrix;
    int m;
    cin>>m;
    int n;
    cin>>n;
    if(allocateMatrix(matrix, m, n))
    {
        randMatrix(matrix, m, n);
        printMatrix(matrix,m, n);
        cout<<endl<<minMax(matrix,m,n);
        deallocateMatrix(matrix,m);
    }
    /*
    int* arr;
    int size;
    cin>>size;
    int n;
    cin>>n;
    if(allocateMemory(arr,size))
    {
        initializeArray(arr,n);
        printArray(arr,n);
        cout<<endl;

        expand(arr,n,size);
        printArray(arr,n);
        cout<<endl;

        insertLast(arr,n,size,5);
        printArray(arr,n);
        cout<<endl;
        cout<<"Size: "<<n<<endl;
        cout<<"Capacity: "<<size<<endl;
        insertAt(arr,n,size,6,5);
        printArray(arr,n);
        cout<<endl;
        cout<<"Size: "<<n<<endl;
        cout<<"Capacity: "<<size<<endl;
        deallocateMemory(arr);
    }
    */
}
