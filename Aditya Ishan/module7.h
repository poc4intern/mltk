#pragma once

#include "module6.h"

class Module_7 : public Module_6{

   public:
       std::map<std::int32_t, std::vector<long double>> temp_Data;
      std::map<std::int32_t, long double>              upper_Bound_Of_Ith_Column;
      std::map<std::int32_t, long double>              lower_Bound_Of_Ith_Column;
      std::map<std::int32_t, long double>              iqr_container;	
      std::int32_t                                     middle, column_counter;
      std::int32_t                                     lower_index, lower_index1;
      std::int32_t                                     upper_index, upper_index1;
      
      void find_Quartile_Range_For_Each_Columns();
      void calculate_Upper_Bound_Lower_Bound();
      void calculate_Iqr();
};

