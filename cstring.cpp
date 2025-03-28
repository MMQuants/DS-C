#include <iostream>

using namespace std;

const int CAPACITY = 51;

bool allocateString(char*& str, int n)
{
    str = new(nothrow) char[n+1];
    return str != nullptr;

}

void deallocateString(char*& str )
{
    delete[] str;
    str = nullptr;
}

int length(char* str)
{
    int cnt = 0;
    if(str==nullptr) return 0;
    while(*str)
    {
        cnt++;
        str++;

    }
    return cnt;

}


bool isEmpty(char* str)
{

    //return length(str)==0;

    return str == nullptr || *str=='0';

}


char charAt(char* str, int index)
{

    if(index < 0 || index >=length(str)) return '\0';
    return *(str+index);

}

void copyString(char*& dest, char* src)
{
    if(src==nullptr){
        deallocateString(dest);
        return;
    }
    char* temp = dest;
    while(*src){
        *temp = *str;
        temp++;
        src++;
    }
    *temp = *src;
}


char* duplicateString(char* src)
{
    char* dest;
    if(allocateString(dest, CAPACITY)){
        copyString(dest, src);
        return dest;

    }
    return nullptr;
}

bool concat(char*& str1, int& capacity, char* str2)
{
    if (length(str1)+length(str2)>= capacity ){
        char* temp;
        if(allocateString(temp, length(str1)+length(str2)+1)){
            copyString(temp, str1);
            deallocateString(str1);
            str1 = temp;
            capacity = length(str1)+length(str2)+1;
        }
        else return false;
    }
    copyString(str1+length(str1), str2);
    return true
}



int main()
{
    char* str;
    cin.getline(str, 50);
    if (allocateString(str, 50)){
        cout<<str<<endl;
        cout<<charAt(str, 50)<<endl;
        cout<<length(str)<<endl;
        while(*str){

        }
    }

}
