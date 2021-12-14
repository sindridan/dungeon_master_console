//
//  main.cpp
//  Galdur
//
//  The purpose of this program is to simplify the DMs life when playing DnD
//
//  Created by Sindri Dan Garðarsson on 8.12.2021.
//

#include <iostream>
#include <string.h>

#include "user_interface/standard_messages/opening_messages/opening_welcome_message.hpp"
using namespace std;
int main(int argc, const char * argv[]) {

    
    // Opening message when program is initiated
    openingMessage();
    
    // init dice vars
    bool keep_throwing_dice = true;
    while (keep_throwing_dice == true)
    {
        int dice_amount = 0;
        int dice_type = 0;
        int total_dice_throw = 0;
        int random_dice_digit = 0;
        
        cout << "How many dice? ";
        cin >> dice_amount;
        
        cout << "Enter dice face: ";
        cin >> dice_type;
        
        
        for(int i = 0; i < dice_amount; i++)
            {
                random_dice_digit = rand() % dice_type + 1;
                cout << "Dice #" << to_string(i+1) + ": " << random_dice_digit << endl;
                total_dice_throw += random_dice_digit;
            }
                
        
        cout << "Result: " << to_string(total_dice_throw) << endl;
        cout << endl;
        string cont_interaction = "";
        cout << "Throw more dice (Y/N)";
        cin >> cont_interaction;
        if(cont_interaction == "N" || cont_interaction == "n")
        {
            keep_throwing_dice = false;
        }
        else if (cont_interaction == "Y" || cont_interaction == "y")
        {
            cout << "More dice, yay!" << endl;
        }
        
    }
    
    
    return 0;
}
