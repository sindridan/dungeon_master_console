//
//  dice_form.cpp
//  dungeon_master_console
//
//  Created by Sindri Dan Garðarsson on 14.12.2021.
//

#include "dice_form.hpp"

Die::Die()
{
    this->name = "";
    this->faces = 0;
    this->dice_throw = 0;
}

Die::Die(string name, int faces, int dice_throw)
{
    this->name = name;
    this->faces = faces;
    this->dice_throw = dice_throw;
}

void Die::set_name(string name)
{
    this->name = name;
}

void Die::set_faces(int faces)
{
    this->faces = faces;
}

void Die::set_dice_throw(int dice_throw)
{
    this->dice_throw = dice_throw;
}

string Die::get_name()
{
    return this->name;
}

int Die::get_faces()
{
    return this->faces;
}

int Die::get_dice_throw()
{
    return this->dice_throw;
}

ostream& operator << (ostream& out, const Die& die)
{
    out << to_string(die.faces) << " sided die."<< endl;
    return out;
}
