#pragma once

#include "module3.h"

class Module_4 : public Module_3{

   public:
   	  std::map<std::int32_t, std::pair<long double, std::int32_t>>  total_Sum_And_Average_Of_Each_Column;

   	  void find_Mean_For_Each_Column();
   	  void fill_Missing_Values_With_Mean();
};
