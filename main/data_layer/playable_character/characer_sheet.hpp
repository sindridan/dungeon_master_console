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
// TODO: this should be a parent class which smaller classes inherit
// The main purpose of this class is to be the header of the character sheet, it should include child classes
// so that code can be more reuseable, playable characters, NPCs and monsters alike might share same classes

// TODO: dndClass, dndRace and alignment might need to be classes on their own
class Character {
    public:
        Character();
        Character(string characterName,string dndClass, int level, string background, string dndRace, string alignment, int experiencePoints, string playerName);
        void set_name(string playerName);
    
        string get_name();
        friend ostream& operator << (ostream& out, const Character& Character); // overload cout to print the form

    private:
        string playerName;
    
};

#endif /* characer_sheet_hpp */
