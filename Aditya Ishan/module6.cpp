#include "module6.h"

void Module_6::normalization_Of_The_Data_Set()
{
	std::int32_t column_counter;

	std::ofstream file("aircon1.csv", std::ios::binary);

	for(std::int32_t row_iterator = 0; row_iterator != MAX_SIZE &&
		       CSV_Data[row_iterator].size(); ++row_iterator){

		column_counter = 0;
	    for(const auto& column_iterator : CSV_Data[row_iterator]){
                
            if(maximum_Of_Ith_Column[column_counter] == minimum_Of_Ith_Column[column_counter]){

            	file << (1.0 / (double)number_Of_Rows);
            }
            else{

	    		file << ( (std::stold(column_iterator) - minimum_Of_Ith_Column[column_counter]) / 
	    		          (maximum_Of_Ith_Column[column_counter] - minimum_Of_Ith_Column[column_counter]) );
	    	}	

	      file << ',';
	      ++column_counter;
	    }
	    file << "\n";
	}
}

void Module_6::find_The_Min_And_Max_Of_Ith_Column(){

	std::int32_t column_counter = 0;

	for(const auto& iterator : CSV_Data[0]){

			minimum_Of_Ith_Column[column_counter] = std::stold(iterator);
			maximum_Of_Ith_Column[column_counter] = std::stold(iterator);

		++column_counter;
	}

	for(std::int32_t row_iterator = 1; row_iterator != MAX_SIZE &&
		       CSV_Data[row_iterator].size(); ++row_iterator){

		column_counter = 0;
	    for(const auto& column_iterator : CSV_Data[row_iterator]){

			minimum_Of_Ith_Column[column_counter] = std::min(minimum_Of_Ith_Column[column_counter],
			                                                 std::stold(column_iterator));

			maximum_Of_Ith_Column[column_counter] = std::max(maximum_Of_Ith_Column[column_counter],
				                                             std::stold(column_iterator));
	      ++column_counter;
	    }
	}
}
