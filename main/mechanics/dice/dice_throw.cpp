//
//  dice_throw.cpp
//  dungeon_master_console
//
//  Created by Sindri Dan Garðarsson on 14.12.2021.
//

#include "dice_throw.hpp"

vector<Die> start_dice(int dice_amount, int faces)
{
    // Try/Catch handling here: https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm
    
    if(dice_amount == 0 || dice_amount < 0)
    {
        throw "Dice amount input is invalid";
    }
    
    if(faces == 0 || faces < 0)
    {
        throw "Dice faces input is invalid";
    }
    
    vector<Die> dice; //init a new dice set, this only takes in fixed face, no variety of faces yet
    
    for(int i = 0; i < dice_amount; i++)
        {
            int random_dice_digit = 0;
            random_dice_digit = rand() % faces + 1;
            Die temp_die("D" + to_string(faces), faces, random_dice_digit);
            
            dice.push_back(temp_die);
            cout << "Dice #" << to_string(i+1) + ": " << temp_die.get_dice_throw() << endl; // búa til child klasa með kastinu sem param
            
            //total_dice_throw += random_dice_digit;
        }
            
    // results of total dices thrown
    //int sum_of_elems = std::accumulate(dice.dice_throw.begin(), dice.dice_throw.end(), 0);
    //std::accumulate (begin(dice), end(dice), 0, [](int i, const Die& die){ return die.get_dice_throw() + i; });


    return dice;
}

int dice_result(vector<Die> &dice)
{
    int dice_throw_total = 0;
    for (int i = 0; i < dice.size(); i++)
    {
        dice_throw_total += dice[i].get_dice_throw();
    }
    return dice_throw_total;
}
