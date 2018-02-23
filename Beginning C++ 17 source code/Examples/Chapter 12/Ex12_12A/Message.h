#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <string_view>

class Message
{
public:
  explicit Message(std::string_view message = "") : pText{new std::string(message)} {}
  ~Message() { delete pText; }
  Message(const Message& src)
	  : pText{ new std::string(*src.pText) }
  {
  }
  
  std::string_view getText() const { return *pText; }
  
  Message& operator=(const Message& message) 
  {
    if (this != &message)
    {
      delete pText;                             // Delete the previous text
      pText = new std::string(*message.pText);  // Duplicate the object in the heap
    }
    return *this;                               // Return the left operand
  }
  
private:
  std::string* pText;
};

#endif