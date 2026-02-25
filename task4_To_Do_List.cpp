#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    
    struct TodoItem {
        string name;
        bool isDone;
    };

    
    vector<TodoItem> myTasks;
    
    int choice = 0;
    
    
    cout << "\n============================================\n";
    cout << "   WELCOME TO PERSONAL TO-DO LIST!   \n";
    cout << "============================================\n\n";
    cout << "Hey Dear! I'm your task assistant. I'll help you keep track of everything you need to do.\n";
    cout << "Let's begin & organized together!\n";
    
   
    while (choice != 5) {
        
       
        cout << "\n----- WHAT WOULD YOU LIKE TO DO TODAY? -----\n";
        cout << "  1. Add a new task to your list\n";
        cout << "  2. Take a look at all your tasks present in the list\n";
        cout << "  3. Mark the task as completed\n";
        cout << "  4. Remove a task you don't need anymore in the list\n";
        cout << "  5. Exit and save your list\n";
        cout << "-------------------------------------------\n";
        cout << "please, type a number (1-5): ";
        
        
        cin >> choice;
        
        
        cin.ignore(); 
        
        if (choice == 1) {
            
            cout << "\n--- ADDING A NEW TASK ---\n";
            
            TodoItem newTask;
            
            cout << "What's the task you want to remember? ";
            getline(cin, newTask.name);
            
            
            while (newTask.name.empty()) {
                cout << "Oops! You didn't type anything. Tell me what you need to do: ";
                getline(cin, newTask.name);
            }
            
            
            newTask.isDone = false;
            
            
            myTasks.push_back(newTask);
            
            cout << "Great! \"" << newTask.name << "\" has been added to your list Successfully.\n";
            cout << "You now have " << myTasks.size() << " task" << (myTasks.size() > 1 ? "s" : "") << " in your list.\n";
        } 
        
        else if (choice == 2) {
           
            cout << "\n--- HERE'S WHAT'S IN YOUR TO-DO LIST ---\n";
            
            
            if (myTasks.size() == 0) {
                cout << "Your list is empty right now. Time to add some tasks!\n";
                cout << "  Go to option 1 and let's get started!\n";
            } else {
                cout << "You have " << myTasks.size() << " task" << (myTasks.size() > 1 ? "s" : "") << ":\n\n";
                
                
                for (int i = 0; i < myTasks.size(); i++) {
                    cout << "  " << (i + 1) << ". ";
                    
                   
                    if (myTasks[i].isDone == true) {
                        cout << "[TASK COMPLETED] ";
                    } else {
                        cout << "[TASK PENDING] ";
                    }
                    
                    cout << myTasks[i].name << "\n";
                }
                
                cout << "\nTip: Use option 3 to mark tasks as done when you finish them!\n";
            }
            cout << "----------------------------------------\n";
        }
        
        else if (choice == 3) {
            
            if (myTasks.size() == 0) {
                cout << "\nYour list is empty! Add some tasks first before marking them as done.\n";
            } else {
                cout << "\n--- LET'S CELEBRATE YOUR PROGRESS! ---\n";
                
                
                for (int i = 0; i < myTasks.size(); i++) {
                    cout << "  " << (i + 1) << ". ";
                    if (myTasks[i].isDone) {
                        cout << "[DONE] " << myTasks[i].name << " (already completed!)\n";
                    } else {
                        cout << "[TODO] " << myTasks[i].name << "\n";
                    }
                }
                
                cout << "\nWhich task did you finish? Type the task number: ";
                int taskNum;
                cin >> taskNum;
                
                
                if (taskNum > 0 && taskNum <= myTasks.size()) {
                    
                    if (myTasks[taskNum - 1].isDone) {
                        cout << "You already marked this as done! But hey, doing it twice is even better, right?\n";
                    } else {
                        myTasks[taskNum - 1].isDone = true;
                        cout << "WONDERFUL! Great job completing \"" << myTasks[taskNum - 1].name << "\"!\n";
                        
                    }
                } else {
                    cout << "Oops, I don't see a task with that number. Want to try again?\n";
                }
            }
        }
        
        else if (choice == 4) {
           
            if (myTasks.size() == 0) {
                cout << "\nNothing to delete here! Your list is already empty.\n";
            } else {
                cout << "\n--- LET'S CLEAN UP YOUR LIST ---\n";
                
                
                for (int i = 0; i < myTasks.size(); i++) {
                    cout << "  " << (i + 1) << ". ";
                    if (myTasks[i].isDone) {
                        cout << "[DONE] " << myTasks[i].name << "\n";
                    } else {
                        cout << "[TODO] " << myTasks[i].name << "\n";
                    }
                }
                
                cout << "\nWhich task number would you like to remove? ";
                int taskNum;
                cin >> taskNum;
                
                
                if (taskNum > 0 && taskNum <= myTasks.size()) {
                    
                    cout << "Are you sure you want to remove \"" << myTasks[taskNum - 1].name << "\"? (y/n): ";
                    char confirm;
                    cin >> confirm;
                    
                    if (confirm == 'y' || confirm == 'n') {
                        
                        string deletedTask = myTasks[taskNum - 1].name;
                        
                        
                        myTasks.erase(myTasks.begin() + (taskNum - 1));
                        
                        cout << "\"" << deletedTask << "\" has been removed from your list Successfully.\n";
                        if (myTasks.size() > 0) {
                            cout << "  You now have " << myTasks.size() << " task" << (myTasks.size() > 1 ? "s" : "") << " remaining.\n";
                        } else {
                            cout << "  Your list is now empty. Time to add new tasks!\n";
                        }
                    } else {
                        cout << "Okay, I'll keep it on your list!\n";
                    }
                } else {
                    cout << "That number doesn't match any task. Try again?\n";
                }
            }
        }
        
        else if (choice == 5) {
           
            cout << "\n--- TIME TO SAY BYE ---\n";
            
            if (myTasks.size() > 0) {
                
                int doneCount = 0;
                for (int i = 0; i < myTasks.size(); i++) {
                    if (myTasks[i].isDone) doneCount++;
                }
                
                cout << "Quick summary before you go:\n";
                cout << "  * Total tasks: " << myTasks.size() << "\n";
                cout << "  * Completed: " << doneCount << "\n";
                cout << "  * Still to do: " << (myTasks.size() - doneCount) << "\n";
                
                if (doneCount == myTasks.size()) {
                    cout << "WOW! You've completed EVERYTHING! You're amazing!\n";
                } else if (doneCount > 0) {
                    cout << "Great progress! Keep it up next time!\n";
                } else {
                    cout << "You've got some tasks waiting. You'll crush them next time!\n";
                }
            } else {
                cout << "Your list is empty. Hope you'll have some tasks to add next time!\n";
            }
            
            cout << "\nThank you for using your To-Do List today!\n";
            cout << "Take care and have a wonderful day!\n";
            cout << "\nBye for today dear friend!\n";
        }
        
        else {
            
            cout << "\nOops! That's not one of the options.\n";
            cout << "  Please type a number between 1 and 5.\n";
        }
    }

    return 0;
}