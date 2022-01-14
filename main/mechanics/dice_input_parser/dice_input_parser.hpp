//
//  dice_input_parser.hpp
//  dungeon_master_console
//
//  Created by Sindri Dan Garðarsson on 6.1.2022.
//

#ifndef dice_input_parser_hpp
#define dice_input_parser_hpp

#include <stdio.h>
#include "../../mechanics/dice/dice_throw.hpp"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
#include <map>
#include <list>
#include <utility>


using namespace std;
    vector<pair<int,int>> adjacent_dice_values_parser(vector<string> parsed_dice);
    vector<vector<Die>> parse_and_roll(vector<string> parsed_input);
    void dice_input_collector(string dice_input); // TODO: will be vector<Die> return function


#endif /* dice_input_parser_hpp */
