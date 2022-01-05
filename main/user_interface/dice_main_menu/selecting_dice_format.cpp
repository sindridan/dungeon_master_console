//
//  selecting_dice_format.cpp
//  dungeon_master_console
//
//  Created by Sindri Dan Garðarsson on 24.12.2021.
//

#include "selecting_dice_format.hpp"

int input_manager()
{
    int value = 0;
    
    cin >> value;
    //While the input entered is not an integer, prompt the user to enter an integer.
    while(!cin || value <= 0) // TODO: replace other block with this code, much better
    {
        cout << "Please enter a valid integer higher than 0: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> value;
    }
    return value;
}

// this func returns an array of 2 numbers
int* get_dice_input() // TODO: Simple validation like this is OK in UI layer I believe. Minimize this code block.
{
    int *dice_array = new int[2];
    dice_array[0] = 0;
    dice_array[1] = 0;
    
    
    cout << "Amount of dice: " << endl;
    dice_array[0] = input_manager();
    
    cout << "Faces on dice: " << endl;
    dice_array[1] = input_manager();

    return dice_array;
}

void dice_input ()
{
    try {
        int* dice_variables = get_dice_input();
        
        vector<Die> dice = start_dice(dice_variables[0], dice_variables[1]);
        //cout << "size of dice: " << dice.size();
        int ttl = dice_result(dice);
        cout << ttl << endl;
    } catch (const char* msg) {
      cerr << msg << endl;
    }
    
}

