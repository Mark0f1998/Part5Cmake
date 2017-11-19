#include <cassert>
#include <iostream>


#include "displacement.hpp"


using namespace direction;
int main()
{

    {   const char* testString = "456786734521";
        const char* testString2 = "4567\n8673\n4521\n\0";
        char_array matrix(testString2);
        assert(matrix.return_height() == 3 && matrix.return_width() == 4);
        for(int i = 0; i<12; ++i)
        {
          assert(matrix(i % matrix.return_height(),i / matrix.return_height()) == testString[i]);
        }
    }
    {   const char* testString2 = "\0";
        char_array matrix(testString2);
        assert(matrix.return_height() == 0 && matrix.return_width() == 0);
    }
    {   const char* newTestString = "33333\n33333\n\0";
        const char* testString2 = "3\n\0";
        const char* newTestString1 = "88888\n88888\n\0";
        const char* testString3 = "8\n\0";
        char_array matrix(testString2);
        char_array matrix1(newTestString);
        char_array matrix2(testString3);
        char_array matrix3(newTestString1);
        matrix.matrix_expansion('S', 1, '3');
        matrix.matrix_expansion('E', 4, '3');
        matrix2.matrix_expansion('N', 1, '8');
        matrix2.matrix_expansion('W', 4, '8');
        assert(matrix == matrix1);
        assert(matrix2 == matrix3);
    }
    {
        const char* testString = " ^ \n ^ \n 0 \n\0";
        char_array matrix(testString);
        char_array matrix1(matrix);
        char_array matrix2(static_cast<char_array &&>(matrix));
        assert(matrix == matrix1);
        assert(matrix2 == matrix1);
    }
    {
        const char* testString = " ^ \n ^ \n 0 \n\0";
        char_array matrix(testString);
        char_array matrix1 = matrix;
        assert(matrix == matrix1);
    }

    {
        const char* testString = " ^ \n ^ \n 0 \n\0";
        char_array matrix(testString);
        char_array matrix1(testString);
        char_array matrix2 = static_cast<char_array &&>(matrix);
        assert(matrix2 == matrix1);
    }
}

