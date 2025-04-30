#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class SetArgument
{
public:
    SetArgument();
    ~SetArgument();

    void show_mainpage();
    void getDATAfile();
    void show_profile(istream &);
};

