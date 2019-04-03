#pragma once

#include "module2.h"

class Module_3 : public Module_2{
	
	public:
		std::map<std::int32_t, std::string>                          max_Occur_Value_Of_Each_Column;
		std::map<std::pair<std::int32_t, std::string>, std::int32_t> count_For_Each_Column;

		void find_Count_Of_Each_Element_In_Categorical_Column();
		void find_Max_Value_For_Each_Column();
		void fill_Missing_Values_With_Mode();
};