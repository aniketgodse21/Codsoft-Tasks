#include <iostream>
using namespace std;


char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}; // [00:10:31]
int row;
int column;
char token = 'x';
bool tie = false;
string n1 = "";
string n2 = "";


void function1() {
    cout << "   |   |   \n";
    cout << " " << space[0][0] << " | " << space[0][1] << " | " << space[0][2] << " \n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << space[1][0] << " | " << space[1][1] << " | " << space[1][2] << " \n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << space[2][0] << " | " << space[2][1] << " | " << space[2][2] << " \n";
    cout << "   |   |   \n";
}


void function2() {
    int digit;
    
    
    if (token == 'x') {
        cout << n1 << ", please choose your move (1-9): "; 
        cin >> digit;
    }
    if (token == '0') {
        cout << n2 << ", please choose your move (1-9): "; 
        cin >> digit;
    }
    
    
    if (digit == 1) { row = 0; column = 0; }
    else if (digit == 2) { row = 0; column = 1; }
    else if (digit == 3) { row = 0; column = 2; }
    else if (digit == 4) { row = 1; column = 0; }
    else if (digit == 5) { row = 1; column = 1; }
    else if (digit == 6) { row = 1; column = 2; }
    else if (digit == 7) { row = 2; column = 0; }
    else if (digit == 8) { row = 2; column = 1; }
    else if (digit == 9) { row = 2; column = 2; }
    else if (digit < 1 || digit > 9) {
        cout << "Oops! That's not a valid number. Try again." << endl; 
    }

    
    if (token == 'x' && space[row][column] != 'x' && space[row][column] != '0') {
        space[row][column] = 'x';
        token = '0';
    }
    else if (token == '0' && space[row][column] != 'x' && space[row][column] != '0') {
        space[row][column] = '0';
        token = 'x';
    }
    else {
        
        cout << "That spot is already taken! Please choose an empty one." << endl; 
        function2();
    }
}


bool function3() {
    
    for (int i = 0; i < 3; i++) {
        if ((space[i][0] == space[i][1] && space[i][0] == space[i][2]) || 
            (space[0][i] == space[1][i] && space[0][i] == space[2][i])) {
            return true;
        }
    }
   
    if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) || 
        (space[0][2] == space[1][1] && space[1][1] == space[2][0])) {
        return true;
    }
    
   
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'x' && space[i][j] != '0') {
                return false;
            }
        }
    }
    
    
    tie = true;
    return false;
}


int main() {
    
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "       WELCOME TO TIC-TAC-TOE!        \n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

    
    cout << "Enter the name of Player 1 (X): \n";
    getline(cin, n1);
    cout << "Enter the name of Player 2 (O): \n";
    getline(cin, n2);
    
    cout << "\nAwesome! " << n1 << " is Player 1 and will play first.\n";
    cout << n2 << " is Player 2 and will play second. \n Let's begin the Game!\n\n\n";
    
    
    while (!function3()) {
        function1();
        function2();
        function3(); 
    }
    
   
    function1();
    
    
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    
    if (token == 'x' && tie == false) {
        cout << " Congratulations " << n2 << "! You win the Game!! " << endl; 
    }
   
    else if (token == '0' && tie == false) {
        cout << " Congratulations " << n1 << "! You win the Game!! " << endl; 
    }
    else {
        cout << " It's a draw! Well played both of you. " << endl; 
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Thanks for playing the Game!\n\n";
    
    return 0;
}