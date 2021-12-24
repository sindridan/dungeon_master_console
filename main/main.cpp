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

using namespace std;
int main(int argc, const char * argv[]) {
    
    // Opening message when program is initiated
    openingMessage();
    
    Die four_die("D4", 4, 0);
    Die six_die("D6", 6, 0);
    Die eight_die("D8", 8, 0);
    
    cout << four_die << endl;
    

    
    // init dice vars
    bool keep_throwing_dice = true;
    while (keep_throwing_dice == true)
        {
            try {
                start_dice(4,6);
            } catch (const char* msg) {
              cerr << msg << endl;
            }
            
            try {
                start_dice(1,0);
            } catch (const char* msg) {
              cerr << msg << endl;
            }
            
            try {
                start_dice(10,10);
            } catch (const char* msg) {
              cerr << msg << endl;
            }
            try {
                int amount = 0; int faces = 0;
                cout << "input amount and then faces" << endl;
                cin >> amount;
                cin >> faces;
                vector<Die> dice = start_dice(amount, faces);
                //cout << "size of dice: " << dice.size();
                int ttl = dice_result(dice);
                cout << ttl << endl;
            } catch (const char* msg) {
              cerr << msg << endl;
            }
    //        int dice_amount = 0;
    //        int dice_type = 0;
    //        int random_dice_digit = 0;
    //        int dice_throw_total = 0;
    //        // create temporary instances of dice to throw
    //        vector<Die> dice;
    //
    //
    //        cout << "How many dice? ";
    //        cin >> dice_amount;
    //
    //        cout << "Enter dice face: ";
    //        cin >> dice_type;
    //
    //
    //        for(int i = 0; i < dice_amount; i++)
    //            {
    //                random_dice_digit = rand() % dice_type + 1;
    //                Die temp_die("D" + to_string(dice_type), dice_type, random_dice_digit);
    //
    //                dice.push_back(temp_die);
    //                cout << "Dice #" << to_string(i+1) + ": " << temp_die.get_dice_throw() << endl; // búa til child klasa með kastinu sem param
    //
    //                //total_dice_throw += random_dice_digit;
    //            }
    //
        // results of total dices thrown
        //int sum_of_elems = std::accumulate(dice.dice_throw.begin(), dice.dice_throw.end(), 0);
        //std::accumulate (begin(dice), end(dice), 0, [](int i, const Die& die){ return die.get_dice_throw() + i; });

    //        for (int i = 0; i < dice.size(); i++)
    //        {
    //            dice_throw_total += dice[i].get_dice_throw();
    //        }
    //
    //        cout << "Result: " << to_string(dice_throw_total) << endl;
        //cout << endl;
        
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
