#pragma once

#include <iostream>
#include <algorithm> 
#include <unordered_map>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include <regex>
#include <map>
#include <set>

const int MAX_SIZE = 1e5;

class CSV{

    public:
        std::vector<std::string>  CSV_Data[MAX_SIZE];
        std::set<std::int32_t>    columns_To_Remove;
        const std::string         error_Range = " <---Entered number should be in range value.";
        const std::string         error_Target_Column = "Target Column Can't Be Removed.";
        const std::string         error_Empty_CSV = "CSV is empty.";
        static std::int32_t       row;
        std::int32_t              target_Column;   

        void open_Csv(std::string&, CSV&);
        void read_From_Csv(std::istream&);
        void print_Csv(std::string&, CSV&);
        void check_Csv_Empty();
        void remove_Columns();
        void write_To_Csv();
        void empty_2Dvector();
        void set_Target_Column();        
};

