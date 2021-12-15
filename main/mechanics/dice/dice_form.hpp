//
//  dice_form.hpp
//  dungeon_master_console
//
//  Created by Sindri Dan Garðarsson on 14.12.2021.
//

#ifndef dice_form_hpp
#define dice_form_hpp

#include <stdio.h>
#include<iostream>
#include <string.h>

using namespace std; // classes like these belong in the mechanics layer!
class Die {
    public:
        Die(); // Dice
        Die(string name, int faces, int dice_throw);
        void set_name(string name);
        void set_faces(int faces);
        void set_dice_throw(int dice_throw);
    
        string get_name();
        int get_faces();
        int get_dice_throw();
        friend ostream& operator << (ostream& out, const Die& Die); // overload cout to print the form

    private:
        string name;
        int faces;
        int dice_throw;
    
};
#endif /* dice_form_hpp */
