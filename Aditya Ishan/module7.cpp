#include "module7.h"

void Module_7::calculate_Iqr(){
	
	for(const auto& iterator : lower_Bound_Of_Ith_Column){
		
		iqr_container[iterator.first] 
		   = upper_Bound_Of_Ith_Column[iterator.first] - iterator.second;
	}	
}

void Module_7::calculate_Upper_Bound_Lower_Bound(){

	for(const auto& iterator : upper_Bound_Of_Ith_Column){

		upper_Bound_Of_Ith_Column[iterator.first] += (1.5 * iqr_container[iterator.first]);
	}

	for(const auto& iterator : lower_Bound_Of_Ith_Column){

		lower_Bound_Of_Ith_Column[iterator.first] -= (1.5 * iqr_container[iterator.first]);
	}

//------------------------------------------------------
	// for(const auto& i : lower_Bound_Of_Ith_Column){
	// 	std::cout<<i.first<<" "<<i.second<<"\n";
	// }
	// std::cout<<"\n";
	// for(const auto& i : upper_Bound_Of_Ith_Column){
	// 	std::cout<<i.first<<" "<<i.second<<"\n";
	// }
//------------------------------------------------------
}

void Module_7::find_Quartile_Range_For_Each_Columns(){

	for(std::int32_t row_iterator = 0; row_iterator != MAX_SIZE &&
		       CSV_Data[row_iterator].size(); ++row_iterator){

		column_counter = 0;
	    for(const auto& column_iterator : CSV_Data[row_iterator]){

	    	temp_Data[column_counter].push_back(std::stold(column_iterator));

	      ++column_counter;
	    }
	}

    for(auto& i : temp_Data){
    	std::sort(i.second.begin(), i.second.end());
    }
    
    for(const auto& map_iterator : temp_Data){

		middle = (map_iterator.second.size() + 1) / 2;

		if(map_iterator.second.size() & 1){ // n is odd

			if((middle-1) & 1){ // n/2 is odd

				lower_index = middle / 2 - 1;
			    upper_index = lower_index + middle;

				lower_Bound_Of_Ith_Column[map_iterator.first] = map_iterator.second[lower_index];
				upper_Bound_Of_Ith_Column[map_iterator.first] = map_iterator.second[upper_index];
			}

			else{ // n/2 is even

				lower_index  = middle / 2;
				lower_index1 = middle / 2 - 1;
				upper_index  = lower_index  + middle;
				upper_index1 = lower_index1 + middle; 

				lower_Bound_Of_Ith_Column[map_iterator.first] 
				= (map_iterator.second[lower_index] + map_iterator.second[lower_index1]) / 2.0;
				
				upper_Bound_Of_Ith_Column[map_iterator.first] 
				= (map_iterator.second[upper_index] + map_iterator.second[upper_index1]) / 2.0;   
			}
		}

		else{ // n is even

			if(middle & 1){

				lower_index = middle / 2;
				upper_index = lower_index + middle;

				lower_Bound_Of_Ith_Column[map_iterator.first] = map_iterator.second[lower_index];
				upper_Bound_Of_Ith_Column[map_iterator.first] = map_iterator.second[upper_index]; 
			}

			else{

				lower_index  = middle / 2;
				lower_index1 = middle / 2 - 1;

				upper_index  = lower_index  + middle;
				upper_index1 = lower_index1 + middle;

				lower_Bound_Of_Ith_Column[map_iterator.first] 
				= (map_iterator.second[lower_index] + map_iterator.second[lower_index1]) / 2.0;

				upper_Bound_Of_Ith_Column[map_iterator.first]
				= (map_iterator.second[upper_index] + map_iterator.second[upper_index1]) / 2.0;   
			} 
		}	
    }
//------------------------------------------------
	// for(const auto& i : lower_Bound_Of_Ith_Column){
	// 	std::cout<<i.first<<" "<<i.second<<"\n";
	// }
	// std::cout<<"\n";
	// for(const auto& i : upper_Bound_Of_Ith_Column){
	// 	std::cout<<i.first<<" "<<i.second<<"\n";
	// }
	// std::cout<<"\n";
//-----------------------------------------------
}
