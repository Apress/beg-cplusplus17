// Exercise 16-5 LinkedList.h
/*
The LinkedList template below follows some (not all) conventions of Standard Library containers:
some member function names are analogous, 
as is the choice not to work with exceptions in case you do something wrong 
(such as calling back() or pop_front() on an empty list).
The latter has the implication that if you mis-use the container,
your program will likely crash...

New in this version are the move constructor / assignment operators (mind the noexcepts, as always),
and the fact that the push_back() and push_front() members have been updated 
to allow new T values to be moved in.
The latter was done by passing values in by value. 
Given that this is a class template the might be used by legacy, non-moveable types,
a perfectly sensible alternative would be to provide both overloads:

	void push_front(const T& value);             // Add an object to the head (object is copied)
	void push_back(const T& value);              // Add an object to the tail (object is copied)
	
	void push_front(T&& value);                  // Add an object to the head (object is moved)
	void push_back(T&& value);                   // Add an object to the tail (object is moved)

Do not forget to update the / add a Node constructor to prevent any unnecessary copies there!
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstddef>        // for the size_t typedef
#include <utility>        // for std::swap()

template<typename T> class LinkedList
{
public:
	LinkedList() = default;
	~LinkedList();

	LinkedList(const LinkedList& list);          // Copy constructor
	LinkedList& operator=(const LinkedList& list); // Copy assignment operator

	LinkedList(LinkedList&& list) noexcept;      // Move constructor
	LinkedList& operator=(LinkedList&& list);    // Move assignment operator
	
	void push_front(T value);                    // Add an object to the head
	void push_back(T value);                     // Add an object to the tail

	void pop_back();                             // Removes the last element from the list (undefined behavior for empty lists)
	void pop_front();                            // Removes the first element from the list (undefined behavior for empty lists)

	T& front();                                  // Get the object at the head (undefined behavior for empty lists)
	T& back();                                   // Get the object at the tail (undefined behavior for empty lists)
	const T& front() const;                      // Get the object at the head (undefined behavior for empty lists)
	const T& back() const;                       // Get the object at the tail (undefined behavior for empty lists)

	bool empty() const;                          // Checks whether the list is empty or not
	void clear();                                // Function to remove all elements from the list
	size_t size() const;                         // Get the number of elements from the list

	class Iterator;                              // Nested Iterator class declaration (definition below)
	Iterator front_iterator() const;             // Get an Iterator that starts at the head
	Iterator back_iterator() const;              // Get an Iterator that starts at the tail

	void swap(LinkedList& other) noexcept;       // Swap function

private:
	class Node                                   // Node class definition
	{
	public:
		Node(T&& theValue)                       // Never copy when adding a value to a Node!        
			: value{ std::move(theValue) }, next{}, previous{}
		{}

		T value;
		Node* next;
		Node* previous;
	};

	Node* head{};                               // Pointer to first node
	Node* tail{};                               // Pointer to last node
	size_t numberOfElements{};
};

// Non-member swap function.
// Convention dictates swap is present as non-member function.
// For class types it is easiest (and recommended) to implement it using a member swap function.
template<typename T>
void swap(LinkedList<T>& one, LinkedList<T>& other)
{
	one.swap(other);
}

// ---------------------------------------------
// Member definitions
// ---------------------------------------------

// Destructor
template<typename T>
LinkedList<T>::~LinkedList()
{
	clear();
}

// Copy constructor template
template<typename T>
LinkedList<T>::LinkedList(const LinkedList& list)
{
  // Use existing members (iteration, push_back()) to implement the copying
  // This avoids duplicating any code that manipulates the list's pointers / size members.
  for (auto iterator = list.front_iterator(); iterator; iterator.next())
    push_back(iterator.value());
}

// Copy assignment operator template (uses copy-and-swap idiom)
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& src)
{
	LinkedList copy(src);
	swap(copy);
	return *this;
}

// Move constructor template
template<typename T>
LinkedList<T>::LinkedList(LinkedList&& list) noexcept
	: head{ list.head }
	, tail{ list.tail }
{
  list.numberOfElements = 0;
  
  // Setting list.head and list.tail to nullptr is optional 
  // given the current implementation of the ~LinkedList() destructor.
  // No harm in doing it though (allows a moved list to be used again)
  //  list.head = list.tail = nullptr;
}

// Move assignment operator template (uses move-and-swap idiom)
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList&& src)
{
	LinkedList moved(std::move(src));
	swap(moved);
	return *this;
}

// Template function member to add an object to the head of the list
template<typename T> void LinkedList<T>::push_front(T value)
{
	Node* oldHead = head;
	head = new Node(std::move(value));

	if (oldHead)
	{
		oldHead->previous = head;
		head->next = oldHead;
	}
	else  // list was empty before, and now has one element
	{
		tail = head;
	}

	++numberOfElements;
}

// Template function member to add an object to the tail of the list
template<typename T> void LinkedList<T>::push_back(T value)
{
	Node* oldTail = tail;
	tail = new Node(std::move(value));

	if (oldTail)
	{
		oldTail->next = tail;
		tail->previous = oldTail;
	}
	else  // list was empty before, and now has one element
	{
		head = tail;
	}

	++numberOfElements;
}

// Template function member to remove an object from the head of the list
template<typename T> void LinkedList<T>::pop_front()
{
	Node* oldHead = head;
	if (oldHead == tail)
	{
		head = tail = nullptr;
	}
	else
	{
		head = oldHead->next;
		head->previous = nullptr;
	}
	delete oldHead;

	--numberOfElements;
}

// Template function member to remove an object from the tail of the list
template<typename T> void LinkedList<T>::pop_back()
{
	Node* oldTail = tail;
	if (oldTail == head)
	{
		head = tail = nullptr;
	}
	else
	{
		tail = oldTail->previous;
		tail->next = nullptr;
	}
	delete oldTail;

	--numberOfElements;
}

// Template function members to get the object at the head of the list
template<typename T> T& LinkedList<T>::front()
{
	return head->value;
}
template<typename T> const T& LinkedList<T>::front() const
{
	return head->value;
}

// Template function members to get the object at the tail of the list
template<typename T> T& LinkedList<T>::back()
{
	return tail->value;
}
template<typename T> const T& LinkedList<T>::back() const
{
	return tail->value;
}

// Check whether list is empty or not
template<typename T> bool LinkedList<T>::empty() const
{
	return numberOfElements == 0;  // (or head == nullptr, or tail == nullptr)
}

// Template to get the size of a list
template<typename T> size_t LinkedList<T>::size() const
{
	return numberOfElements;
}

// Template to clear a list
template<typename T> void LinkedList<T>::clear()
{
	// Use existing functions (avoid code duplication!)
	while (!empty()) pop_front();
}

// Member function template to swap two lists
template<typename T> void LinkedList<T>::swap(LinkedList& other) noexcept
{
	std::swap(head, other.head);
	std::swap(tail, other.tail);
	std::swap(numberOfElements, other.numberOfElements);
}

// Definition of the nested Iterator class
template<typename T>
class LinkedList<T>::Iterator
{
public:
	Iterator(Node* node) : current{ node }
	{}

	const T& value() const { return current->value; }

	bool hasValue() const { return current != nullptr; }
	operator bool() const { return current != nullptr; }

	void next() { current = current->next; }
	void previous() { current = current->previous; }

private:
	Node* current;
};

// Get an Iterator that starts at the head
template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::front_iterator() const
{
  return Iterator{ head };
}

// Get an Iterator that starts at the tail
template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::back_iterator() const
{
  return Iterator{ tail };
}

#endif //LINKEDLIST_H