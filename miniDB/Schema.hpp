#ifndef SCHEMA_HPP
#define SCHEMA_HPP

#include <stdio.h>
#include <string.h>

class Schema
{
protected:
    int id;
    bool is_valid;
public:

    // constructor [complete]
    Schema(int _id, bool _is_valid);

    // method for deletion [complete]
    void set_validity(bool _is_valid);

    // method for checking if deleted [complete]
    bool get_validity();

    // method to get id [complete]
    int get_id();

    // display is like to_string [complete in the implementation]
    virtual void display();
};


#endif // SCHEMA_HPP