// Exercise 15-5  DB_RAII.h
// RAII classes for handles returned by DB.h C interface functions

/*
  In this solution we have the RAII classes accept the resource handle in their destructor.
  In doing so, it is of course critical that the constructor does not throw any exceptions:
  hence the noexcept modifiers.
  
  Alternatively, you could also acquire the resources inside the constructors of the RAII class.
  For instance: you could call db_connect() from within the DBConnectionRAII() contructor.
*/

#ifndef DB_RAII_H
#define DB_RAII_H

#include "DB.h"

class DBConnectionRAII
{
public:
  DBConnectionRAII(DB_CONNECTION* connection) noexcept
    : theConnection(connection)
  {
  }
  
  ~DBConnectionRAII() // implicitly noexcept
  {
	db_disconnect(theConnection);
  }
  
  operator DB_CONNECTION*() const noexcept { return theConnection; }
  operator bool() const noexcept { return theConnection != nullptr; }
  
private:
  DB_CONNECTION* theConnection;
};

class DBQueryResultRAII
{
public:
  DBQueryResultRAII(DB_QUERY_RESULT* result) noexcept 
    : theResult(result)
  {
  }
  
  ~DBQueryResultRAII() // implicitly noexcept
  {
	db_free_result(theResult);
  }
  
  operator DB_QUERY_RESULT*() const noexcept { return theResult; }
  operator bool() const noexcept { return theResult != nullptr; }

private:
  DB_QUERY_RESULT* theResult;
};

#endif