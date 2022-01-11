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
    
//    Die four_die("D4", 4, 0);
//    Die six_die("D6", 6, 0);
//    Die eight_die("D8", 8, 0);
    

    
    // init dice vars
    bool keep_throwing_dice = true;
    while (keep_throwing_dice == true)
    {
        string manual_dice_input = "";
        // need to use getline because of cin ignoring chars after first whitespace.
        // see this: https://stackoverflow.com/questions/27205251/stdcin-skips-white-spaces/27205981
        cout << "manual dice input first (i.e. 1d4, 2d6 etc.): "; getline(cin, manual_dice_input);
        dice_input_collector(manual_dice_input);
        //dice_input_collector("1d4 2d6 3d10");
            
        dice_input();
        

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
                cout << "More dice, yay!" << endl;
            }
            else {
                cout << cont_interaction << " is not valid, only Y/N" << endl;
                
            }
        }
    }
    
    
    return 0;
}
