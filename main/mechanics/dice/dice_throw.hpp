//
//  dice_throw.hpp
//  dungeon_master_console
//
//  Created by Sindri Dan Garðarsson on 14.12.2021.
//

#ifndef dice_throw_hpp
#define dice_throw_hpp

#include <stdio.h>
#include <iostream>
#include <string.h>
#include "dice_form.hpp"
#include <vector>

using namespace std;
    vector<Die> start_dice(int dice_amount, int faces);
    int dice_result(vector<Die> &dice);

    
//TODO class for dice statistics? Median, medium, lowest, highest
#endif /* dice_throw_hpp */
