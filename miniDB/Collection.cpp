#include "Collection.hpp"

#include <stdio.h>

void Collection::add(RecordLL *_rec_ll)
{
    if(_rec_ll == nullptr)      // trying to add nullptr
        printf("Collection -- Add -- 1");
    else 
    {
        if(head == nullptr)
        {
            head = _rec_ll;
            tail = _rec_ll;
        }
        else 
        {
            tail->next = _rec_ll;
            tail = tail->next;
        }
    }
}

void Collection::iterate(Applier *_applier)
{
    RecordLL *h = head;
    while(h)
    {
        _applier->apply(h->record);
        h = h->next;
    }
}

void Collection::free()
{
    RecordLL *p = head, *q = nullptr;
    if(p == nullptr)
        return;
    while(p != nullptr)
    {
        q = p;
        p = p->next;
        delete_applier->apply(q->record);
        delete q;
    }

    head = nullptr;
    tail = nullptr;
}