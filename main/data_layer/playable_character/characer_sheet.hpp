//
//  characer_sheet.hpp
//  dungeon_master_console
//
//  Created by Sindri Dan Garðarsson on 15.1.2022.
//
//  This is a test sheet, will be modified, restructured later on

#ifndef characer_sheet_hpp
#define characer_sheet_hpp

#include <stdio.h>
#include <stdio.h>
#include<iostream>
#include <string.h>

using namespace std;
class Character {
    public:
        Character(); // Dice
        Character(string name);
        void set_name(string name);
    
        string get_name();
        friend ostream& operator << (ostream& out, const Character& Character); // overload cout to print the form

    private:
        string name;
    
};

#endif /* characer_sheet_hpp */
