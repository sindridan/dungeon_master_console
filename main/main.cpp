//
//  main.cpp
//
//  The purpose of this program is to simplify the DMs life when playing DnD
//  Project Goblin Shell
//
//  Created by Sindri Dan Garðarsson on 8.12.2021.
//

#include <iostream>
#include <string.h>
#include <vector>
#include <numeric>

#include "user_interface/standard_messages/opening_messages/opening_welcome_message.hpp"
#include "mechanics/dice/dice_form.hpp"
#include "mechanics/dice/dice_throw.hpp"
#include "mechanics/dice_input_parser/dice_input_parser.hpp"

#include "user_interface/dice_main_menu/selecting_dice_format.hpp"

using namespace std;
int main(int argc, const char * argv[]) {
    
    // Opening message when program is initiated
    openingMessage();
    

    // init dice vars
    bool keep_throwing_dice = true;
    while (keep_throwing_dice == true)
    {
        string dice_user_input = "";
        // TODO: menu for choosing how to throw dice
        cout << "Dice throwing menu: " << endl;
        cout << "[0] for manual throwing" << endl;
        cout << "[1] for dice assistance" << endl;
        cout << "User input: "; getline(cin, dice_user_input); // problem here, skips getline again
        
        if(dice_user_input == "0")
        {
            string manual_dice_input = "";
            cout << "MDI (ex. 1d4 4d6): "; getline(cin, manual_dice_input);
            dice_input_collector(manual_dice_input);
        }
        else if (dice_user_input == "1")
        {
            dice_input();
        } else { break; } // TODO: better workaround for wrong input by user
        
        bool valid_cont_interaction = false;
        while(!valid_cont_interaction)
        {
            string cont_interaction = "";
            cout << "Throw more dice (Y/N): ";
            cin >> cont_interaction;
            if(cont_interaction == "N" || cont_interaction == "n")
            {
                valid_cont_interaction = true;
                keep_throwing_dice = false;
            }
            else if (cont_interaction == "Y" || cont_interaction == "y")
            {
                valid_cont_interaction = true;
                // https://stackoverflow.com/questions/6486289/how-can-i-clear-console check out for various OS terminal clears
                printf("\033c"); // Clear the console
            }
            else {
                cout << cont_interaction << " is not valid, only Y/N" << endl;
                
            }
        }
        // TODO: (Works though) Need to clean the cin buffer? Atleast needed when re-entering the while loop. Might need fixing later on
        cin.ignore(); // https://stackoverflow.com/questions/25074624/why-is-stdgetline-skipped
    }
    
    
    return 0;
}
