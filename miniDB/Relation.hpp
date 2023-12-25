#ifndef RELATION_HPP
#define RELATION_HPP

#include "Filter.hpp"
#include "Modifier.hpp"
#include "SemaphoreController.hpp"
#include "Schema.hpp"
#include "Collection.hpp"


class Relation 
{
private:
    // attributes
    int key;
    int fd;
    int fd_backup;
    char relation_name[32];
    int rec_size;
    SemaphoreController semctrl;
public:

    // constructor [complete]
    Relation(int _key, int _rec_size, char _relation_name[]);
    
    // get the file descriptors [complete]
    int connect();

    // close the file descriptors [complete]
    int disconnect();

    // append a record to the end [complete]
    int create_record(void* _rec);

    // retrieve record according to a filter [complete]
    int retrieve_record(Filter* _filter, Collection* _collection);

    // filter record and them apply a modifier [complete]
    int update_record(Filter* _filter, Modifier* _modifier);

    // turn the deletion marker on [complete]
    int delete_record(Filter* _filter);

    // thrashing for compressing memory [complete]
    int thrash();

    // backing up [complete]
    int commit();
};

#endif // RELATION_HPP