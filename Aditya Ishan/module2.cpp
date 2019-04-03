#include "module2.h"

void Module_2::detect_Data_Type(){

    std::regex Regex_1("[a-zA-Z]");
    std::smatch flag;
    std::int32_t column_counter;

    for(std::int32_t row_iterator = 0; row_iterator != MAX_SIZE 
               && CSV_Data[row_iterator].size(); ++row_iterator){
        
        column_counter = 0;
        for(const auto& column_iterator : CSV_Data[row_iterator]){

            if(column_iterator != ""){

	            if(regex_search(column_iterator, flag, Regex_1) == true){
	                data_Types_Of_Columns[column_counter] = "string";
	            }

	            else data_Types_Of_Columns[column_counter] = "double";
            }
          ++column_counter;
        }  
    }

    for(const auto& iterator : data_Types_Of_Columns) 
        std::cout << iterator.first << " " << iterator.second << "\n";

    std::cout << "\n";
}

void Module_2::count_Number_Of_Rows(){

   number_Of_Rows = 0;

    for(std::int32_t row_iterator = 0; row_iterator != MAX_SIZE 
                  && CSV_Data[row_iterator].size(); ++row_iterator){
              
        number_Of_Rows++;
    }
}

void Module_2::remove_Columns_Greater_Than_Threshold(){
    
    count_Number_Of_Rows();

    std::unordered_map<std::int32_t, std::int32_t> columns_Count;
    std::int32_t column_counter;

    for(std::int32_t row_iterator = 0; row_iterator != MAX_SIZE 
                  && CSV_Data[row_iterator].size(); ++row_iterator){
    	
        column_counter = 0;
        for(const auto& column_iterator : CSV_Data[row_iterator]){
            
            if(column_iterator != ""){
                columns_Count[column_counter]++;
            }
          ++column_counter;
        }
    }

    threshold = number_Of_Rows * 0.75;

    for(const auto& iterator : columns_Count){
        if(iterator.second < number_Of_Rows - threshold){
            columns_To_Remove.insert(iterator.first);
        }
    }

    std::cout << "Removed Those Columns Whose Missing Values Less Than Threshold\n";
}