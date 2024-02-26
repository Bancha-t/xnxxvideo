#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    int sum = 0 ;
    if(argc >= 2){
        for(int i = 0; i < argc ; i++) sum += atoi(argv[i]) ;
        cout << "---------------------------------\n" ;
        cout << "Average of "<< argc-1 <<" numbers = " << sum/(argc-1) <<"\n" ;
        cout << "---------------------------------";
    }
    else{
        cout << "Please input numbers to find average." ;
        return 0 ;
    }

}

