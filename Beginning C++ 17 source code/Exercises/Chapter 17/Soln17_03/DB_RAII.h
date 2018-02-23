// Exercise 17-3  DB_RAII.h
// Uncopyable RAII classes for handles returned by DB.h C interface functions

/*
  Allowing DBConnectionRAII to be copied would mean the database connection is closed twice;
  allowing DBQueryResultRAII to be copied would result in the memory for the query's result to be freed twice.
  Both, and in particular the second one, are bound to end in disaster.
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
  
  // Disallow copying (always delete both copy members together)
  DBConnectionRAII(const DBConnectionRAII&) = delete;
  DBConnectionRAII& operator=(const DBConnectionRAII&) = delete;
  
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
  
  // Disallow copying (always delete both copy members together)
  DBQueryResultRAII(const DBQueryResultRAII&) = delete;
  DBQueryResultRAII& operator=(const DBQueryResultRAII&) = delete;
  
  operator DB_QUERY_RESULT*() const noexcept { return theResult; }
  operator bool() const noexcept { return theResult != nullptr; }

private:
  DB_QUERY_RESULT* theResult;
};

#endif