#pragma once

#include "module5.h"

class Module_6 : public Module_5{

   public:
      std::map<std::int32_t, long double> minimum_Of_Ith_Column;
      std::map<std::int32_t, long double> maximum_Of_Ith_Column;

      void find_The_Min_And_Max_Of_Ith_Column();
      void normalization_Of_The_Data_Set();
};
