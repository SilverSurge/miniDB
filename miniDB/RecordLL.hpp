#ifndef RECORD_LL_HPP
#define RECORD_LL_HPP

class RecordLL 
{
public:
    // attributes
    void* record;
    RecordLL *next;

    // constructor [complete]
    RecordLL()
    {
        record = nullptr;
        next = nullptr;
    };
};

#endif // RECORD_LL_HPP