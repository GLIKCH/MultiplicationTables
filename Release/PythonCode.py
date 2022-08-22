#########################
## Joel De Alba        ##
## 8 / 17 / 22         ##
## CS-210              ##
## Week 6 Assignment   ##
#########################

import re                                                   # Default Python imports
import string


def MultiplicationTable(num):                               # Defines function that calculates multiplication values based on user input "num"
    num = int(input("\nEnter a multiplication Number : "))  # Checks for user input
    for i in range (1,11):                                  # Checks for number range between 1 and 10
        print(num, "x", i, "=", num * i);                   # Prints out calculated multiplication from user input max to 10 multiplication
    return 0;                                               # Returns 0 to aid return to c++ function with menu options

def DoubleMult(num):                                        # Defines function that calculates multiplication double based user input
    num = int(input("\nEnter a number to double : "))       # Checks for user input
    print(num * 2);                                         # Prints user input multiplied by 2
    return 0;                                               # Returns 0 to aid return to c++ function with menu options
    
