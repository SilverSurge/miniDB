#ifndef MODIFIER_HPP
#define MODIFIER_HPP

class Modifier 
{
public:
    // simple pure virtual method for some filtering [complete]
    virtual void modify(void* &_rec) = 0;
};

#endif // MODIFIER_HPP