#include <string.h>
#include <iostream>

#include "displacement.hpp"


namespace direction
{
    // constructor that initializing a new line
    char_array::char_array(const char* initial_string)
    // initialize the members to an empty state
        : line(nullptr),
          matrix_height(0),
          matrix_width(0)
    {
        std::size_t row = std::strlen(initial_string);
        line = new char[row];
        std::size_t i = 0; std::size_t j = 0;
        while (initial_string[i] != '\0')
        {
            if(initial_string[i] != '\n')
            {
                line[j] = initial_string[i];
                ++j;
            }
            else
            {

                if(matrix_width == 0)
                {
                    matrix_width = j;
                }
                else if (matrix_width == j - matrix_height * matrix_width)
                {
                    delete [] line;
                    line = nullptr;
                }
                ++ matrix_height;
            }
            ++i;
        }
    }


    // definition of the copy constructor
    char_array::char_array(const char_array& other)
    // initialize the members to an empty state
        : line(nullptr),
          matrix_height(0),
          matrix_width(0)
    {
        // If we are assigned to ourselves, nothing to do is necessary, just return
        if(this == &other)
        {
            return;
        }

        matrix_height = other.matrix_height;
        matrix_width = other.matrix_width;
        char* line_New = new char[matrix_height * matrix_width];

        // copy line to line_New with size of matrix_height * matrix_width
        std::memcpy(line_New, other.line, matrix_height * matrix_width);

        // delete the old block and write a new pointer to the elements
        delete [] line;
        line = line_New;
    }


    // definition of the movement constructor
    char_array::char_array(char_array&& other)
    {
        // check for self-assignment
        assert(this!=&other);

        // steal all members from another array
        matrix_height = other.matrix_height;
        matrix_width = other.matrix_width;
        line = other.line;

        // zero data
        other.matrix_height = 0;
        other.matrix_width = 0;
        other.line = nullptr;
    }


    // definition of the copy assignment operation
    char_array& char_array::operator=(const char_array& other)
    {
        // check for self-assignment
        if(this == &other)
        {
            return *this;
        }

        matrix_height = other.matrix_height;
        matrix_width = other.matrix_width;
        char* line_New = new char[matrix_height * matrix_width];

        // copy line to line_New with size of matrix_height * matrix_width
        std::memcpy(line_New, other.line, matrix_height * matrix_width);

        // delete the old block and write a new pointer to the elements
        delete [] line;
        line = line_New;

        // return the reference to the implicit parameter-object.
        return *this;
    }


    // definition of move assignment operation
    char_array& char_array::operator=(char_array&& other)
    {
        // check for self-assignment
        assert(this!=&other);

        // free your old memory
        delete [] line;

        // steal all members from another array
        matrix_height = other.matrix_height;
        matrix_width = other.matrix_width;
        line = other.line;

        // remove the ownership of the source object is similar to the move constructor.
        other.matrix_height = 0;
        other.matrix_width = 0;
        other.line = nullptr;

        // return the reference to the implicit parameter-object.
        return *this;
    }


    // definition of destructor
    char_array::~char_array()
     {
        // release the dynamic memory in which the items are stored
           delete[] line;
           matrix_height = 0;
           matrix_width = 0;
     }


    // definition of overloaded operation to write array elements
    char& char_array::operator () (std::size_t x, std::size_t y)
    {
         assert(x <= matrix_width && y <= matrix_height);
         char& character = line[matrix_width * y + x];
         return character;
    }

    // definition of matrix_expansion() function
    void char_array::matrix_expansion(char way, std::size_t number_of_steps, char character)
    {
         assert(matrix_width != 0 && matrix_height != 0);
         assert(way == 'N' || way == 'W' || way == 'S' || way == 'E');
         if(!number_of_steps)
         {
           return;
         }
         std::size_t newHeight; std::size_t newWidth;

          if(way == 'W' || way == 'E')
          {
                 newWidth = number_of_steps + matrix_width;
                 newHeight = matrix_height;
          }

          else
          {
                 newWidth = matrix_width;
                 newHeight = number_of_steps + matrix_height;
          }

          char* line_New = new char[newWidth * newHeight];

        if (way == 'N')
        {
            std::memset(line_New, character, number_of_steps * matrix_width);
            std::memcpy(line_New + number_of_steps * matrix_width, line, matrix_width * matrix_height);
        }

        if (way == 'W')
        {
            for(std::size_t i = 0; i < matrix_height; ++i)
            {
                std::memset(line_New + i*(matrix_width + number_of_steps), character, number_of_steps);
                std::memcpy(line_New + i*(matrix_width + number_of_steps) + number_of_steps, line + i*matrix_width,matrix_width);
            }
        }

        if (way == 'S')
        {
            std::memcpy(line_New, line, matrix_width * matrix_height);
            std::memset(line_New + matrix_width * matrix_height, character, number_of_steps * matrix_width);
        }

        if (way == 'E')
        {
            for(std::size_t i = 0; i < matrix_height; ++i)
            {
                std::memcpy(line_New + i*(matrix_width + number_of_steps), line + i*matrix_width,matrix_width);
                std::memset(line_New + i*(matrix_width + number_of_steps) + matrix_width, character,  number_of_steps);
            }
        }


        delete[] line;
        line = line_New;
        matrix_width = newWidth; matrix_height = newHeight;
    }


    // definition of matrix output - change for free function-overload operator <<
    std::ostream& operator<< (std::ostream& ostr, const char_array& other)
    {
         for(std::size_t i = 0; i < other.return_height(); ++i)
         {
             for(std::size_t j = 0; j < other.return_width(); ++j)
             {
                ostr << other(j, i);
             }
             ostr << '\n';
         }
         ostr << '\n';
         return ostr;
    }

    // definition of overloaded comparison operations
    bool char_array::operator == (const char_array& other2) const
    {
        if(matrix_width == other2.matrix_width && matrix_height == other2.matrix_height)
        {
            return std::memcmp(this, &other2,matrix_width * matrix_height) == 0;
        }
       else
        {
            return false;
        }
    }

    bool char_array::operator != (const char_array& other2) const
    {
        return (matrix_width != other2.matrix_width || matrix_height != other2.matrix_height);
    }
}
