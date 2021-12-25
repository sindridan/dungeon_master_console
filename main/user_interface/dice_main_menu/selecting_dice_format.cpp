//
//  selecting_dice_format.cpp
//  dungeon_master_console
//
//  Created by Sindri Dan Garðarsson on 24.12.2021.
//

#include "selecting_dice_format.hpp"

// this func returns an array of 2 numbers
int* get_dice_input() // TODO: Simple validation like this is OK in UI layer I believe. Minimize this code block.
{
    int *dice_array = new int[2];
    dice_array[0] = 0;
    dice_array[1] = 0;
    
    bool valid_amount = false;
    bool valid_faces = false;
    
    while (!valid_amount && !valid_faces) {
        int amount = 0;
        int faces = 0;
        
        cout << "Amount of dice: " << endl;
        cin >> amount;
        // TODO: try catch with a break if failed in a while loop?
        if(amount > 0 || amount != int(amount)) // is this check useless? could just use cin.fail()
        {
            valid_amount = true;
            dice_array[0] = amount;
        }
        
        cout << "Amount of faces: " << endl;
        cin >> faces;
        // TODO: try catch with a break if failed in a while loop?
        if(faces > 0 || faces != int(faces)) // is this check useless? could just use cin.fail()
        {
            valid_faces = true;
            dice_array[1] = faces;
        }

    }

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

