#include "module4.h"

void Module_4::fill_Missing_Values_With_Mean(){
	
    std::int32_t column_counter;   
    std::ofstream file("aircon1.csv", std::ios::binary);

    for(std::int32_t row_iterator = 0; CSV_Data[row_iterator].size() 
                  && row_iterator != MAX_SIZE; ++row_iterator){
        
        column_counter = 0; 
        for(const auto& column_iterator : CSV_Data[row_iterator]){
            
            if(column_iterator == "" && 
            	total_Sum_And_Average_Of_Each_Column.find(column_counter) 
            	!= total_Sum_And_Average_Of_Each_Column.end()){

            	file << total_Sum_And_Average_Of_Each_Column[column_counter].first << ',';
            }
            else{

                file << column_iterator;
                file << ',';
            }
          ++column_counter;    
        }
      file << "\n";
    }
}

void Module_4::find_Mean_For_Each_Column(){
	
    std::int32_t column_counter;
	
    for(std::int32_t row_iterator = 0; row_iterator != MAX_SIZE 
		          && CSV_Data[row_iterator].size(); ++row_iterator){

		column_counter = 0;
	    for(const auto& column_iterator : CSV_Data[row_iterator]){

	    	if(column_iterator != "" 
                && data_Types_Of_Columns[column_counter] == "double"){

	    		total_Sum_And_Average_Of_Each_Column[column_counter].first += std::stold(column_iterator);
	    	    total_Sum_And_Average_Of_Each_Column[column_counter].second++;
	    	}

	      ++column_counter;
	    }
	}

	for(const auto& iterator : total_Sum_And_Average_Of_Each_Column){

		total_Sum_And_Average_Of_Each_Column[iterator.first].first /= iterator.second.second;
	}
}