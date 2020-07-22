#include "module8.h"

void Module_8::remove_Outliers_Rows(){
 
    std::ofstream file("aircon1.csv", std::ios::binary);

	std::int32_t column_counter;
	for(std::int32_t row_iterator = 0; row_iterator != MAX_SIZE
		       && CSV_Data[row_iterator].size(); ++row_iterator){

		if(rows_To_Remove.find(row_iterator) != rows_To_Remove.end()) continue;
        
        column_counter = 0;
	    for(const auto& column_iterator : CSV_Data[row_iterator]){

	    	file << column_iterator;
            file << ',';
            ++column_counter;
	    }
	 file << "\n";
	}
}

void Module_8::detect_Outliers_Rows_To_Remove(){

	std::int32_t column_counter;
	for(std::int32_t row_iterator = 0; row_iterator != MAX_SIZE
		       && CSV_Data[row_iterator].size(); ++row_iterator){

		column_counter = 0;
	    for(const auto& column_iterator : CSV_Data[row_iterator]){

	    	if(std::stold(column_iterator) > upper_Bound_Of_Ith_Column[column_counter]
	    		|| std::stold(column_iterator) < lower_Bound_Of_Ith_Column[column_counter]){

	    		rows_To_Remove.insert(row_iterator);
	    	    break;
	    	}
	     ++column_counter;	
	    }
	}
}
