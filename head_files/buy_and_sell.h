#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "../head_files/GridCalculating.h"

void buy(const Grid a,int number,std::vector<int>grid);//number，grid存储使用者目前各个网格的持有数,目前未接入软件故仅无法真正买入卖出，资产均由四则运算得到
void sell(const Grid a,int number,std::vector<int>grid);