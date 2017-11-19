//1 var, Markov Artem

#ifndef DISPLACEMENT
#define DISPLACEMENT
#include <cstddef>
#include <cassert>


namespace direction
{
     class char_array
     {
     public:
         // default constructor
         char_array();

         // constructor that initializing a new line
         char_array(const char* initial_string);

         // copy constructor
         char_array(const char_array& other);

         // movement constructor
         char_array(char_array&& other);

         // the copy assignment operation
         char_array& operator=(const char_array& other);

         // move assignment operation
         char_array& operator=(char_array&& other);

         // destructor
         ~char_array();

         // return_width() built-in implicitly because often used and short
         std::size_t return_width() const { return matrix_width; }

         // return_height() built-in implicitly because often used and short
         std::size_t return_height() const { return matrix_height; }

         // overloaded operation to write array elements
         char& operator () (std::size_t x, std::size_t y);

         // overloaded operation to access array elements, built-in implicitly because short and simple
         char operator() (std::size_t x, std::size_t y) const { assert(x <= matrix_width && y <= matrix_height); return line[matrix_width * y + x]; }

         // matrix_expansion()
         void matrix_expansion(char way, std::size_t number_of_steps, char character);

         // matrix output() - change for free function-overload operator <<
         friend std::ostream& operator<< (std::ostream& ostr, const char_array& other);

         // overloaded comparison operations
         bool operator == (const char_array& other2) const;

         // built-in implicitly because short and simple
         bool operator != (const char_array& other2) const;

         // Explicit cast to bool built-in implicitly
         explicit operator bool() const { return line != nullptr; }

     private:
         char* line;
         std::size_t matrix_height;
         std::size_t matrix_width;
     };
}

#endif


