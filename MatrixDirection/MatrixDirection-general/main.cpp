#include <cassert>
#include <iostream>


#include "displacement.hpp"

using namespace direction;

void change_array (char_array& array, std::size_t& x, std::size_t& y, char way, std::size_t number_of_steps)
{
assert(way == 'N' || way == 'W' || way == 'S' || way == 'E');
if (way == 'N')
{
    if(y < number_of_steps)
    {
           array.matrix_expansion(way, number_of_steps - y, ' ');
           y += number_of_steps;
    }
    for(std::size_t i = 1; i<=number_of_steps; ++i)
    {
           array(x, y - i) = '^';
    }
    y -= number_of_steps;
}

else if (way == 'W')
{
    if (x < number_of_steps)
    {
           array.matrix_expansion(way, number_of_steps - x, ' ');
           x += number_of_steps;
    }
    for(std::size_t i = 1; i<=number_of_steps; ++i)
    {
            array(x - i, y) = '<';
    }
    x -= number_of_steps;
}

else if (way == 'S')
{
    if(y + number_of_steps >= array.return_height())
    {
           array.matrix_expansion(way,number_of_steps + y + 1 - array.return_height(), ' ');
    }
    for(std::size_t i = 1; i <= number_of_steps; ++i)
    {
           array(x, i + y) = 'v';
    }
    y += number_of_steps;
}

else if (way == 'E')
{
    if(x + number_of_steps >= array.return_width())
    {
            array.matrix_expansion(way,number_of_steps + x + 1 - array.return_width(), ' ');
    }
    for(std::size_t i = 1; i<=number_of_steps; ++i)\
    {
            array(i + x, y) = '>';
    }
    x += number_of_steps;
}
}


int main()
{
    char_array array("0\n\0");
    char way; std::size_t number_of_steps;
    std::size_t x = 0; std::size_t y = 0;
    std::cout << "Hello! Welcome to programme! Please, start to write your way and amount of steps! You will see matrix after (!) !\n";

    while (std::cin >> way)
    {
        if(way != '!')
        {
            if(std::cin >>  number_of_steps)
            {
                change_array (array, x, y, way, number_of_steps);
            }
            else
            {
                std::cerr << "WRONG!!!! NO NUMBER OF STEPS!!! BAD DATA!!!\n";
                break;
            }
        }
        else
        {
            std::cout << "Your matrix is here: \n";
            std::cout << array;
        }
    }
}
