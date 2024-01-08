# miniDB

I made a simple database service in C/C++ using various system calls and semaphores. It provides a simple API for the fundamental CRUD operations. the core functionalities can be found below.
## Features
1. User can define their Schema.
2. The user can create records.
3. The user can retrieve records using a filter.
4. The user can modify records using a filter and a modifier.
5. The user can delete records using a filter. we use a deletion marker.
6. It has a commit functionality.
7. It has a thrash functionality which helps in reducing the memory used by tailoring all the records together.
8. It uses semaphores, for concurrency control.
9. It has a simple implementation of the concept of transactions.

## API usage
The API is quite intuitive, and the detailed guide for the API is given in the `main.cpp` file. It just needs the C/C++ to work. to use miniDB. clone the repository and copy 
the miniDB directory wherever you need miniDB. I can't stress enough to go through `main.cpp` to understand the API.
```cpp
#incude "miniDB/miniDB.hpp"
// other imports

int main()
{
  //Do whatever you want
  return 0;
}
```

   
