# Codsoft Tasks
 Task 1: Number Guessing Game.

## Description:
A simple C++ program where the computer generates a random number and the player has to guess it. The program provides feedback if the guess is "Too High" or "Too Low" and tracks the number of attempts.

## Features:
- **Dynamic Randomization:** Uses `time(0)` as a seed for `srand`.
- **User Input Validation:** Ensures the game continues until the correct guess is made.
- **Interactive Feedback:** Real-time hints to guide the player.


## Sample Output of:(task1_guessing_game.cpp)

 Welcome to the Number Guessing Game #1

==========================================
   NEW GAME STARTED: Guess (1 to 100)    
==========================================
Enter your guess: 50
>> Too LOW! Try a larger number.
Enter your guess: 85
>> Too HIGH! Try a smaller number.
Enter your guess: abc
[!] Invalid input. Please enter a number.
Enter your guess: 70
>> Too LOW! Try a larger number.
Enter your guess: 78

[SUCCESS] You nailed it! The number was 78.
[STATS] Total attempts: 4

Would you like to play another round? (Yes/No): No



