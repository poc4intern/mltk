#include "module5.h"

void Module_5::store_Nth_Column(){

    std::size_t  nth_column = CSV_Data[0].size() - 1;
    std::int32_t column_counter;

    for(std::int32_t row_iterator = 0; row_iterator != MAX_SIZE
                  && CSV_Data[row_iterator].size(); ++row_iterator){
        
        column_counter = 0;
        for(const auto& column_iterator : CSV_Data[row_iterator]){

            if(column_counter == nth_column){
                nth_Column_Data.push_back(column_iterator);
            }

         ++column_counter;
        }
    }
}

void Module_5::fill_Nominal_Values_With_Sparse_Matrix(){

    std::int32_t index = 0;
    std::size_t total_Columns = CSV_Data[0].size();

    columns_To_Remove.insert(total_Columns - 1);

    store_Nth_Column();
    write_To_Csv();
     
    std::ofstream file("data.csv", std::ios::binary);
    std::ifstream file1("aircon1.csv", std::ios::binary);

    std::string line;

    for(const auto& row_iterator : nominal_Elements_Of_Each_Row){

        if(rows_To_Remove.find(row_iterator.first) != rows_To_Remove.end()) continue;

        std::getline(file1, line);

        for(const auto& column_counter : unique_Elements_Of_Nominal_Columns){

            for(const auto& column_iterator : column_counter.second){

                if(find(row_iterator.second.begin(), row_iterator.second.end(),
                        column_iterator) != row_iterator.second.end()){

                    line += "1,";
                    //file << '1';
                    //file << ',';
                }
                else{
                    line += "0,";
                    //file << '0';
                    //file << ',';
                }
            }
        }
        file << line;
        file << nth_Column_Data[index++];
        file << "\n";
    }
}

void  Module_5::remove_Nominal_Columns(){

    for(const auto& column_iterator : nominal_Column_Indexes){

        columns_To_Remove.insert(column_iterator.first);
    }
}

void Module_5::store_The_Values_Of_Nominal_Columns(){

    std::int32_t column_counter;

    for(std::int32_t row_iterator = 0; CSV_Data[row_iterator].size()
               && row_iterator != MAX_SIZE; ++row_iterator){

        column_counter = 0;
        for(const auto& column_iterator : CSV_Data[row_iterator]){

            if(nominal_Column_Indexes.find(column_counter) != nominal_Column_Indexes.end()){

                nominal_Elements_Of_Each_Row[row_iterator].push_back(column_iterator);

                unique_Elements_Of_Nominal_Columns[column_counter].insert(column_iterator);
            }
         ++column_counter;
        }
    }
}

void Module_5::replace_Ordinal_Columns_Value_With_Labels(){
    
    std::int32_t column_counter;
    
    std::ofstream file("aircon1.csv", std::ios::binary);

    for(std::int32_t row_iterator = 0; CSV_Data[row_iterator].size() 
               && row_iterator != MAX_SIZE; ++row_iterator){
        
        column_counter = 0; 
        for(const auto& column_iterator : CSV_Data[row_iterator]){
            
            if(rank_Of_Unique_Elements_Of_Ordinal_Columns.find(column_counter) 
            	!= rank_Of_Unique_Elements_Of_Ordinal_Columns.end()){

            	for(auto iterator = rank_Of_Unique_Elements_Of_Ordinal_Columns.find(column_counter);
            		      iterator != rank_Of_Unique_Elements_Of_Ordinal_Columns.end(); ++iterator)
            	{
            		if(iterator->first != column_counter) break;

            	    else if(iterator->second.first == column_iterator){

            	    	file << iterator->second.second << ',';
            	    }
            	}
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

void Module_5::label_Encoding_Of_Ordinal_Columns(){

	std::int32_t rank;

	for(const auto& iterator : unique_Elements_Of_Ordinal_Columns){

		std::cout << "Rank The Column " << iterator.first + 1 << " Elements : \n\n"; 

		for(auto iterator1 = iterator.second.begin(); 
			 iterator1 != iterator.second.end(); ++iterator1){

			std::cout << "Rank Of '" << *iterator1 <<"' Element ?\n";
			std::cin >> rank;

            try{
                if(rank <= 0)
                     throw error_Rank_Not_Natural_Number;
            }

            catch(const std::string& error_Rank_Not_Natural_Number){
                std::cout << error_Rank_Not_Natural_Number << "\n";
                --iterator1;
            }
            
            try{
            	if(find(rank_Keeper.begin(), rank_Keeper.end(), rank) != rank_Keeper.end())
            		throw error_Rank_Repeat;

            	else{
            		rank_Of_Unique_Elements_Of_Ordinal_Columns.insert({iterator.first, {*iterator1, rank}});
            		rank_Keeper.push_back(rank);
            	}
            }
            catch(const std::string& error_Rank_Repeat){
            	std::cout << error_Rank_Repeat << "\n";
            	--iterator1;
            }
            std::cout << "\n";
		}
		rank_Keeper.clear();
	}

//-------------------------------------------------------------------
	// for(auto i : rank_Of_Unique_Elements_Of_Ordinal_Columns){
	// 	std::cout<<i.first<<" ---> ";
	// 	std::cout<<i.second.first<<" "<<i.second.second<<"\n";
	// }
//------------------------------------------------------------------
}

void Module_5::find_Unique_Values_For_The_Ordinal_Columns(){

	std::int32_t column_counter;

	for(std::int32_t row_iterator = 0; row_iterator != MAX_SIZE && 
		       CSV_Data[row_iterator].size(); ++row_iterator){
         
        column_counter = 0;
		for(const auto& column_iterator : CSV_Data[row_iterator]){

			if(ordinal_Column_Indexes.find(column_counter) != ordinal_Column_Indexes.end()){

				unique_Elements_Of_Ordinal_Columns[column_counter].insert(column_iterator);
			}
		 ++column_counter;
		}
	}
}

void Module_5::distinguish_Between_Ordinal_And_Nominal(){

    bool flag;
	std::cout << "Distinguish Which Are Ordinal And Which Are Nominal\n\n";

	for(const auto& iterator : data_Types_Of_Columns){

		if(iterator.second == "string"){

			std::cout << "Column Number " << iterator.first + 1;
			std::cout << " Is Nominal Or Ordinal ?\n";
			std::cout << "Press 1 For Ordinal and 0 Nominal\n";

			std::cin >> flag;

			if(flag) ordinal_Column_Indexes[iterator.first] = 1;
			else     nominal_Column_Indexes[iterator.first] = 1;

            std::cout << "\n";
		}
	}
}