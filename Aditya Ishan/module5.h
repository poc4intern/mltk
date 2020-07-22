#pragma once

#include "module4.h"

class Module_5 : public Module_4{

   public:
      std::multimap<std::int32_t, std::pair<std::string, std::int32_t>> rank_Of_Unique_Elements_Of_Ordinal_Columns;
      std::map<std::int32_t, std::vector<std::string>>                  nominal_Elements_Of_Each_Row;
      std::map<std::int32_t, std::set<std::string>>                     unique_Elements_Of_Nominal_Columns;
      std::map<std::int32_t, std::set<std::string>>                     unique_Elements_Of_Ordinal_Columns;
      std::vector<std::string>                                          nth_Column_Data;
      std::map<std::int32_t, std::int32_t>                              ordinal_Column_Indexes;
      std::map<std::int32_t, std::int32_t>                              nominal_Column_Indexes;
      std::vector<std::int32_t>                                         rank_Keeper;
      std::set<std::int32_t>                                            rows_To_Remove;
      std::string                                                       error_Rank_Repeat = "Rank Already Assigned";
      std::string                                                       error_Rank_Not_Natural_Number = "Rank Should Be Greater Than Zero";

      void distinguish_Between_Ordinal_And_Nominal();
      void find_Unique_Values_For_The_Ordinal_Columns();
      void label_Encoding_Of_Ordinal_Columns();
      void replace_Ordinal_Columns_Value_With_Labels();
      void store_The_Values_Of_Nominal_Columns();
      void remove_Nominal_Columns();
      void store_Nth_Column();
      void fill_Nominal_Values_With_Sparse_Matrix();
};

