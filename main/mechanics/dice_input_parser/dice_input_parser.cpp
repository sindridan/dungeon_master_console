//
//  dice_input_parser.cpp
//  dungeon_master_console
//
//  Created by Sindri Dan Garðarsson on 6.1.2022.
//

#include "dice_input_parser.hpp"

vector<Die> parse_and_roll(vector<string> parsed_input)
{
    // TODO: need to iterate each vector item and reparse to gather adjacent integers between the 'd' delimeter.
    // Then do roll stuff
    /*
     HOWTO:
     First you take each part of the iterator and parse it, then place the two adjacent values
     into a key/value map where key is amount and value is faces.
     Then we insert each map instance into a vector<map> and send it off into the dice_throw (dice thrower).
     */
    
    // 1. create a map:
    map<int,int> dice_mapped;
    cout << "parse_and_roll: " << endl;
    for (auto it = begin (parsed_input); it != end (parsed_input); ++it) {
        // cout << dice_mapped.insert() << endl;
        
    }
    return {};
}

pair<int,int> adjacent_dice_values_parser(vector<string> parsed_dice)
{
    pair<int,int> mapped_dice; // pair<amount_of_dice,faces_of_dice> needs to be encapsulated below for dynamic insert into a vector of pairs. TODO: Change from map to pair in function!
    char delimiter = 'd';
    for (auto it = begin (parsed_dice); it != end (parsed_dice); ++it)
    {
        stringstream sstream(*it);
        string word;
        
        // List is used as a simple data structure for each individual dice set with always only two elements after parsing
        list<string> amount_and_faces = {};
        
        while(getline(sstream,word,delimiter))
        {
            cout << *it << " amount and faces: " << word << endl;
            amount_and_faces.push_back(word);
            
        }
        int amount = stoi(amount_and_faces.front());
        int faces = stoi(amount_and_faces.back());
        mapped_dice.first = amount;
        mapped_dice.second = faces;
        //cout << "Mapped dice amount: " << mapped_dice.first << ", faces: " << mapped_dice.second << endl;
              
    }
    return {};
}

void dice_input_collector(string dice_input)
{
    //4d6 3d4 7d7 1d0 0d0 -1d-1 -testing for later with different inputs
    // TODO: first start parsing input by space as delimeter, insert into vector or other similar data structure
    // then parse each individual dice set with 'd' as delimeter
    
    
    char delimeter = ' ';
    vector<string> parsed_input;

    stringstream sstream(dice_input);
    string word;
    while (getline(sstream, word, delimeter))
    {
        parsed_input.push_back(word);
    }
    cout << "adjacent_dice_values_parser: ";
    adjacent_dice_values_parser(parsed_input);
    parse_and_roll(parsed_input);
//    std::cout << "parsed input size: " << parsed_input.size() << std::endl;
//    for(int i = 0; i < parsed_input.size(); i++)
//    {
//        cout << i <<":"<< parsed_input[i];
//    }
}
