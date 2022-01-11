//
//  dice_input_parser.cpp
//  dungeon_master_console
//
//  Created by Sindri Dan Garðarsson on 6.1.2022.
//

#include "dice_input_parser.hpp"

vector<Die> parse_and_roll(vector<pair<int,int>> &parsed_input)
{
    //TODO: takes in the vector from adjacent_dice_values_parser and throws them into the dice rolles
    cout << "parse_and_roll: " << endl;
    for (auto it = begin (parsed_input); it != end (parsed_input); ++it)
    {
        cout << "start dice: " << endl;
        start_dice(it->first, it->second);
        //cout << "first: " << it->first << " second: " << it->second << endl;
    }
    
    return {};
}

vector<pair<int,int>> adjacent_dice_values_parser(vector<string> parsed_dice)
{
    // pair<amount_of_dice,faces_of_dice> needs to be encapsulated below for dynamic insert into a vector of pairs. TODO: Change from map to pair in function!
    vector<pair<int,int>> dice_ready_to_roll;
    char delimiter = 'd';
    for (auto it = begin (parsed_dice); it != end (parsed_dice); ++it)
    {
        pair<int,int> paired_dice;
        stringstream sstream(*it);
        string word;
        
        // List is used as a simple data structure for each individual dice set with always only two elements after parsing
        list<string> amount_and_faces = {};
        
        while(getline(sstream,word,delimiter))
        {
            //cout << *it << " amount and faces: " << word << endl;
            amount_and_faces.push_back(word);
            
        }
        int amount = stoi(amount_and_faces.front());
        int faces = stoi(amount_and_faces.back());
        paired_dice.first = amount;
        paired_dice.second = faces;
        //cout << "Mapped dice amount: " << mapped_dice.first << ", faces: " << mapped_dice.second << endl;
        dice_ready_to_roll.push_back(paired_dice);
    }
    return dice_ready_to_roll;
}

void dice_input_collector(string dice_input)
{
    //4d6 3d4 7d7 1d0 0d0 -1d-1 -testing for later with different inputs
    // TODO: first start parsing input by space as delimeter, insert into vector or other similar data structure
    // then parse each individual dice set with 'd' as delimeter
    
    
    char delimeter = ' ';
    vector<string> parsed_input;
    vector<pair<int,int>> dice_set_parsed;
    stringstream sstream(dice_input);
    string word;
    while (getline(sstream, word, delimeter))
    {
        parsed_input.push_back(word);
    }
    cout << "adjacent_dice_values_parser: ";
    dice_set_parsed = adjacent_dice_values_parser(parsed_input);
    parse_and_roll(dice_set_parsed);

}
