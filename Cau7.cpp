#include<iostream>
#include<cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

void convert_10(char source[], int sourceBase, char dest[], int destBase){
        int s;
        for (int i = strlen(source)-1;i>=0;i --){
        int j = strlen(source)-1-i;
        if (source[i] >= 'A')
            s = s + (source[i]-55) * pow(sourceBase,j);
        else
            s = s + (source[i]-48) * pow(sourceBase,j);
        }
        int i = 0;
        while(s!=0){
            dest[i] = (s%10) +48;
            s = s/10;
            i++;
        }
        
        dest[i] = '\0';
        cout << " Convert Base " << sourceBase << " to "<< destBase << " la :" ;
        for (int j = i - 1; j >= 0; j--) 
        cout << dest[j]; 
        cout <<endl;
    }

void convert10_others(char source[], int sourceBase, char dest[], int destBase){
    int i = 0;
    int num_in = atoi(source);
        while ( num_in != 0 ){
        if (destBase > 9)
            dest[i] = (num_in % destBase) + 55;
        else 
            dest[i] = (num_in % destBase) + 48;

        num_in  = num_in/destBase;
        i++;
        } 

        cout << " Convert Base : " << sourceBase << " to "<<destBase << " la :";
        for (int j = i - 1; j >= 0; j--) 
        cout << dest[j];
        cout <<endl;
}

int main(){
    int destBase,sourceBase,answer;
    char dest[100],source[100],container[100];
    do{
    cout<< " Enter sourceBase : ";
    cin >> sourceBase;
    cout<< " Enter destBase : ";
    cin >> destBase;
    cout<< " Enter source : ";
    cin >> source;
    if (destBase == 10)
    convert_10(source, sourceBase, dest,destBase);
    if (sourceBase == 10)
    convert10_others(source, sourceBase, dest,destBase);
    if ( destBase != 10 && sourceBase != 10){
        convert_10(source,sourceBase,container,10);
        convert10_others(container,10,dest,destBase);
    }
    cout << " Do you want to continue ?"<< endl;
    cout << " 1. YES "<< endl;
    cout << " 2. NO "<<endl;
    cin >> answer;
    }while(answer == 1);
    return 0;
}
