#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    
    srand(time(NULL));
    
    double random;
    int func, user_ans, act_ans, a, b, c;
    
    
    random = rand() * (1.0 / RAND_MAX);                 //equation 1
        func = random * 2 + 1;
        
    random = rand() * (1.0 / RAND_MAX);                 //equation 1
        a = random * 10 + 1;
        
    random = rand() * (1.0 / RAND_MAX);                 //equation 1
        b = random * 10 + 1;
        
    random = rand() * (1.0 / RAND_MAX);                 //equation 1
        c = random * 10 + 1;
        
        
    if (func == 1){
        
        act_ans = a-b*c;
        
        cout << "solve this following equation and round to the neaarest whole number\n";
        cout << a << "-" << b << "*" << c  << " = ";
        cin >> user_ans;
        
    } else if (func == 2){
        
        act_ans = c*a-b;
        
        cout << "solve this following equation and round to the neaarest whole number\n";
        cout << c << "*" << a << "-" << b << " = ";
        cin >> user_ans;
        

    } else {
        
        if (a % 2 == 0 && c % 2 == 0){
            
            act_ans = a/c+b;
        
        cout << "solve this following equation and round to the neaarest whole number\n";
        cout << a << "/" << b << "+" << b << " = ";
        cin >> user_ans;
            
        }else{
            
            act_ans = a*c+b;
        
        cout << "solve this following equation and round to the neaarest whole number\n";
        cout << a << "/" << b << "+" << b << " = ";
        cin >> user_ans;
            
        }
        
    }
        
        
     if (act_ans == user_ans){
            cout << "CORRECT, OPENING DOOR...";
        }
        else{
            cout << "Wrong Answer, try again...\n";
        }
        
        
        
        
        
        return 0;
        
}