#ifndef COLLECTION_HPP
#define COLLECTION_HPP

#include "RecordLL.hpp"
#include "StatusCodes.hpp"
#include "Applier.hpp"

class Collection
{
private:
    RecordLL *head;
    RecordLL *tail;
    Applier  *delete_applier;
public:

    // constructor [complete]
    Collection(Applier* _delete_applier)
    {
        head = nullptr;
        tail = nullptr;
        delete_applier = _delete_applier;
    }

    // add record at the end [complete]
    void add(RecordLL* _rec_ll);

    // apply some method over the applier [complete]
    void iterate(Applier* _applier);
    
    // free the complete linked list [complete]
    void free();
    // NOTE we can't free a void* ptr so the user needs to create a delete applier

    // number of records
    int count();
};
#endif // COLLECTION_HPP
