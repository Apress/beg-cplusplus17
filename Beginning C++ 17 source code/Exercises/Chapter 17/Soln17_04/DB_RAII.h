// Exercise 17-4  DB_RAII.h
// Uncopyable, yet movable RAII classes for handles returned by DB.h C interface functions

/*
  Allowing DBConnectionRAII to be copied would mean the database connection is closed twice;
  allowing DBQueryResultRAII to be copied would result in the memory for the query's result to be freed twice.
  Both, and in particular the second one, are bound to end in disaster.
  
  Moving is safe though, as long as the destructors are updated as well!
  For completeness, we also added default constructors, though this is not strictly required.
*/

#ifndef DB_RAII_H
#define DB_RAII_H

#include "DB.h"

class DBConnectionRAII
{
public:
  DBConnectionRAII() = default;
  
  DBConnectionRAII(DB_CONNECTION* connection) noexcept
    : theConnection(connection)
  {
  }
  
  ~DBConnectionRAII() // implicitly noexcept
  {
	if (theConnection) db_disconnect(theConnection);
  }
  
  // Disallow copying (always delete both copy members together)
  DBConnectionRAII(const DBConnectionRAII&) = delete;
  DBConnectionRAII& operator=(const DBConnectionRAII&) = delete;
  
  // Do allow moving
  DBConnectionRAII(DBConnectionRAII&& src) noexcept
    :  theConnection{ src.theConnection }
  {
    src.theConnection = nullptr;	// Prevent connection from being disconnected twice (see destructor)
  }
  DBConnectionRAII& operator=(DBConnectionRAII&& src) noexcept
  {
    theConnection = src.theConnection;
    src.theConnection = nullptr;	// Prevent connection from being disconnected twice (see destructor)
    return *this;
  }
  
  operator DB_CONNECTION*() const noexcept { return theConnection; }
  operator bool() const noexcept { return theConnection != nullptr; }
  
private:
  DB_CONNECTION* theConnection {};
};

class DBQueryResultRAII
{
public:
  DBQueryResultRAII() = default;
  
  DBQueryResultRAII(DB_QUERY_RESULT* result) noexcept 
    : theResult(result)
  {
  }
  
  ~DBQueryResultRAII() // implicitly noexcept
  {
	if (theResult) db_free_result(theResult);
  }
  
  // Disallow copying (always delete both copy members together)
  DBQueryResultRAII(const DBQueryResultRAII&) = delete;
  DBQueryResultRAII& operator=(const DBQueryResultRAII&) = delete;
  
    // Do allow moving
  DBQueryResultRAII(DBQueryResultRAII&& src) noexcept
    :  theResult{ src.theResult }
  {
    src.theResult = nullptr;	// Prevent result from being freed twice (see destructor)
  }
  DBQueryResultRAII& operator=(DBQueryResultRAII&& src) noexcept
  {
    theResult = src.theResult;
    src.theResult = nullptr;	// Prevent result from being freed twice (see destructor)
	return *this;
  }
  
  operator DB_QUERY_RESULT*() const noexcept { return theResult; }
  operator bool() const noexcept { return theResult != nullptr; }

private:
  DB_QUERY_RESULT* theResult {};
};

#endif