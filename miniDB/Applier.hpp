#ifndef APPLIER_HPP
#define APPLIER_HPP

class Applier
{
public:
    // simple pure virtual method for some filtering [complete]
    virtual void apply(void* _rec) = 0;
};

#endif // APPLIER_HPP