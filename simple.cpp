#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    
    srand(time(NULL));
    
    double random;
    int func, user_ans, act_ans, a, b;
    
    
    random = rand() * (1.0 / RAND_MAX);                 //equation 1
        func = random * 3 + 1;
        
    random = rand() * (1.0 / RAND_MAX);                 //equation 1
        a = random * 10 + 1;
        
    random = rand() * (1.0 / RAND_MAX);                 //equation 1
        b = random * 10 + 1;
        
        
    if (func == 1){
        
        act_ans = a + b;
        
        cout << "solve this following equation and round to the neaarest whole number\n";
        cout << a << "+" << b << " = ";
        cin >> user_ans;
        
    } else if (func == 2){
        
        act_ans = a - b;
        
        cout << "solve this following equation and round to the neaarest whole number\n";
        cout << a << "-" << b << " = ";
        cin >> user_ans;
        

    } else {
        
         act_ans = a*b;
        
        cout << "solve this following equation and round to the neaarest whole number\n";
        cout << a << "*" << b << " = ";
        cin >> user_ans;
        
    }
        
        
     if (act_ans == user_ans){
            cout << "CORRECT, OPENING DOOR...";
        }
        else{
            cout << "Wrong Answer, try again...\n";
        }
        
        
        
        
        
        return 0;
        
}


