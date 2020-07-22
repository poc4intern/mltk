#pragma once

#include "module1.h"

class Module_2 : public CSV{

   public:
   	std::map<std::int32_t, std::string> data_Types_Of_Columns;
        std::int32_t                        number_Of_Rows;
        std::int32_t                        threshold;

        void detect_Data_Type();
        void count_Number_Of_Rows();
        void remove_Columns_Greater_Than_Threshold();
};
