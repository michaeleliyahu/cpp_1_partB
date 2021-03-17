/**
 * Demo program for snowman exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-02
 */

#include "snowman.hpp"
#include <iostream>
#include <array>
#include <stddef.h>
#include <stdbool.h>
using namespace std;
using namespace ariel;
using std::string;

namespace ariel
{
    string had_fun(std::array<int, 8> str);
    string body_fun(std::array<int, 8> str);
    bool check_number(int number);
}
const int MAX = 4;
const int MIN = 1;
const int NUMBER_UP_ARMS = 2;
const int ARMS_PLACE_IN_ARR = 4;
const int TORSO_PLACE = 6;
const int NUMBER_SIZE = 8;
const int MODULO = 10;
const bool BAD_NUMBER = false;

array<string, 5> hat_arr = {" ", "     \n _===_\n", "  ___\n .....\n", "   _\n  /_\\\n", "  ___\n (_*_)\n"};
array<string, 5> nose_arr = {" ", ",", ".", "_", " "};
array<string, 5> eye = {" ", ".", "o", "O", "-"};
array<string, 5> larm = {" ", "<", "\\", "/", ""};
array<string, 5> rarm = {" ", ">\n", "/\n", "\\\n", "\n"};
array<string, 5> torso1 = {" ", "( : )", "(] [)", "(> <)", "(   )"};
array<string, 5> base1 = {" ", " ( : )", " (\" \")", " (___)", " (   )"};

namespace ariel
{

    string snowman(int number)
    {
        bool BAD_NUMBER = false;
        array<int, NUMBER_SIZE> str;
        int temp = number;
        for (int i = NUMBER_SIZE - 1; i >= 0; i--)
        {
            str[i] = temp % MODULO;
            temp = temp / MODULO;
        }
        if (check_number(number) == BAD_NUMBER)
        {
            throw invalid_argument("bad number");
        }

        string output = hat_arr[str[0]] + had_fun(str) + body_fun(str) + base1[str[NUMBER_SIZE - 1]];

        return output;
    }
    bool check_number(int number)
    {
        int counter = 0;
        if (number < 0)
        {
            return BAD_NUMBER;
        }

        while (number > 0)
        {
            if ((number % MODULO) > MAX || (number % MODULO) < MIN)
            {
                return BAD_NUMBER;
            }
            counter++;
            number = number / MODULO;
        }

        if (counter != NUMBER_SIZE)
        {
            return BAD_NUMBER;
        }

        return true;
    }
    string had_fun(array<int, NUMBER_SIZE> str)
    {
        int place = 1;
        string output = nose_arr[str[place]];
        output = "(" + eye[str[place + 1]] + output + eye[str[place + 2]] + ")";
        place = ARMS_PLACE_IN_ARR;
        if (str[place] == NUMBER_UP_ARMS)
        {
            output = larm[str[place]] + output;
        }
        if (str[place + 1] == NUMBER_UP_ARMS)
        {
            output += rarm[str[place + 1]];
        }
        else
        {
            output = output + "\n";
        }
        return output;
    }
    string body_fun(array<int, NUMBER_SIZE> str)
    {
        string output = torso1[str[TORSO_PLACE]];

        if (str[ARMS_PLACE_IN_ARR] != NUMBER_UP_ARMS)
        {
            output = larm[str[ARMS_PLACE_IN_ARR]] + output;
        }
        if (str[ARMS_PLACE_IN_ARR + 1] != NUMBER_UP_ARMS)
        {
            output += rarm[str[ARMS_PLACE_IN_ARR + 1]];
        }

        return output;
    }

}