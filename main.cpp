#include "miniDB/miniDB.hpp"
#include <stdio.h>

// creating a SCHEMA
class MySchema:public Schema
{
private:
    int price;
public:
    MySchema(int _id, bool _is_valid, int _price): Schema(_id, _is_valid)
    {
        price = _price;
    }
    int get_price()
    {
        return price;
    }
    void set_price(int _price)
    {
        price = _price;
    }
    void display() 
    {
        if(is_valid)
        {
            printf("---------------------------\n");
            printf("id: %d\n", id);
            printf("price: %d\n", price);
            printf("---------------------------\n");
        }
    }
};

// creating a DELETE APPLIER very necessary
class MySchema_DeleteApplier: public Applier
{
public:
    void apply(void *_rec)
    {
        // do it similarly for every other schema
        MySchema* ms_ptr = (MySchema*)(_rec);
        delete ms_ptr;
    }
};

// creating some Filters
class Allower: public Filter
{
public:
    bool filter(void* _rec)
    {
        return true;
    }
};

class MySchema_Filter_EvenIndex: public Filter 
{
public:
    bool filter(void* _rec)
    {
        MySchema ms = *(MySchema*)(_rec);
        // don't change above

        if(ms.get_id() % 2 == 0)
            return true;
        return false;
    }
};


// creating some modifiers
class MySchema_Modifier_Doubler: public Modifier
{
public:
    void modify(void* &_rec)
    {
        MySchema ms = *(MySchema*)(_rec);
        // don't change above

        ms.set_price(2*ms.get_price());
        
        // don't change below
        MySchema *msptr = (MySchema*)(_rec);
        *msptr = ms;
    }
};

// creating some applier
class MySchema_Applier_Printer: public Applier
{
public:
    void apply(void *_rec)
    {
        MySchema ms = *(MySchema*)(_rec);
        // dont change above

        ms.display();
    }
};


int main()
{
    //-------------------------------------------------
    // NOTE There are 8 Sections below follow them one by one
    // uncomment a section [while keeping other sections commented]
    // ONE and Only One Section should be uncommented at a time
    // build the executable using
    // $ g++ main.cpp ./miniDB/*.cpp
    // run a.out using
    // $ a.out
    //-------------------------------------------------

    //-------------------------------------------------
    // 1. create a class MySchema extending Schema
    // 2. create class MySchema_DeleteApplier extending Applier, 
    //      it is compulsory, just to free the array
    // 3. create Filters, Modifiers, Appliers for your Application
    // 4. start using miniDB.
    //-------------------------------------------------

    // creating a relation

    int key = 11;
    int rec_size = sizeof(MySchema);
    char name[] = "MySchema";
    Relation relation(key, rec_size, name);
    // connect to the database
    relation.connect(); 

    
    
    /*
    // 1. CREATE RECORDS - A

    // create some instances
    int id = 1;
    MySchema obj1(id++, true, 10);
    MySchema obj2(id++, true, 20);
    MySchema obj3(id++, true, 30);
    MySchema obj4(id++, true, 40);

    // create_records
    relation.create_record((void*)&obj1);
    relation.create_record((void*)&obj2);
    relation.create_record((void*)&obj3);
    relation.create_record((void*)&obj4);

    // note in ./relations, on looking on the file sizes using 
    // $ll relations
    // db file has 96 and backup file has 0, this means nothing has been saved
    // that is until commit()

    */
    

    /*
    // 2. CREATE RECORDS - B

    // create some instances
    int id = 1;
    MySchema obj1(id++, true, 10);
    MySchema obj2(id++, true, 20);
    MySchema obj3(id++, true, 30);
    MySchema obj4(id++, true, 40);

    // create_records
    relation.create_record((void*)&obj1);
    relation.create_record((void*)&obj2);
    relation.create_record((void*)&obj3);
    relation.create_record((void*)&obj4);

    // commit
    relation.commit();

    // note in ./relations, on looking on the file sizes
    // db file has 96 and backup also has 96,
    // this means changes have been saved
    */


    /*
    // 3. RETRIEVE RECORDS 

    // things for retireval 
    // a delete applier for the collection
    MySchema_DeleteApplier *da_ptr = new MySchema_DeleteApplier();
    // a collection
    Collection *collection = new Collection(da_ptr);
    // a filter
    Allower *allower = new Allower();

    // retrieve the records
    relation.retrieve_record(allower, collection);

    // what to do with the records
    MySchema_Applier_Printer *printer_ptr = new MySchema_Applier_Printer();
    collection->iterate(printer_ptr);
    collection->free(); // free to free the space
    */
    

    /*
    // 4. Updating Records - A

    // things for modifying
    // a filter
    MySchema_Filter_EvenIndex *ei_ptr = new MySchema_Filter_EvenIndex();
    // a modifier
    MySchema_Modifier_Doubler *dbl_ptr = new MySchema_Modifier_Doubler();

    relation.update_record(ei_ptr, dbl_ptr);
    relation.commit();
    // note if you don't commit it wont save things 
    // the changes will last until the execution completes,
    // if you disconnect and then connect again, everything will be lost.

    */
   
    // 5. Updating Records - B
    // run the Retrieving Records again. you will see a difference in the output

    /*
    // 6. Deleting Records - A

    // things for deleting
    // a filter
    MySchema_Filter_EvenIndex *msfei_ptr = new MySchema_Filter_EvenIndex();

    // delete the record
    relation.delete_record(msfei_ptr);
    relation.commit();
    // note if you don't commit it wont save things 
    // the changes will last until the execution completes,
    // if you disconnect and then connect again, everything will be lost.

    // note the sizes of files in ./relations
    // db - 96, backup - 96, it seems that nothing has been deleted,
    // as i use a deletion marker for deleting. but stay with me

    */

    // 7. Deleting Records - B
    // run the Retrieving Records again. you will see a difference in the output
    
    /*
    // 8. Thrashing
    // this slams all the records together, and
    // compresses the size of db file by removing the deleted records
    relation.thrash();
    relation.commit(); // remember the importance of commit
    */


    relation.disconnect();
    return 0;
}