#ifndef FILTER_HPP
#define FILTER_HPP

class Filter 
{
public:
    // simple pure virtual method for some filtering [complete]
    virtual bool filter(void* _rec) = 0;
};

#endif // FILTER_HPP