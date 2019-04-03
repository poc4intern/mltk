#include "module3.h"

void Module_3::fill_Missing_Values_With_Mode(){
    
    std::int32_t column_counter;
    std::ofstream file("aircon1.csv", std::ios::binary);

    for(std::int32_t row_Iterator = 0; CSV_Data[row_Iterator].size() 
                  && row_Iterator != MAX_SIZE; ++row_Iterator){
        
        column_counter = 0; 
        for(const auto& column_Iterator : CSV_Data[row_Iterator]){
            
            if(column_Iterator == "" && 
               max_Occur_Value_Of_Each_Column.find(column_counter) 
               != max_Occur_Value_Of_Each_Column.end()){

              file << max_Occur_Value_Of_Each_Column[column_counter] << ',';
            }
            else{
              file << column_Iterator;
              file << ',';
            }
          ++column_counter;    
        }
      file << "\n";
    }
}

void Module_3::find_Max_Value_For_Each_Column(){

    std::int32_t column_Number;
    
    std::size_t max_count = 0;
    
    std::string value;
    
    auto iterator  = count_For_Each_Column.begin();
    auto iterator1 = count_For_Each_Column.begin();
    
    ++iterator1;

        for(;iterator1 != count_For_Each_Column.end(); ++iterator,++iterator1){

            if(iterator->first.first == iterator1->first.first){
              
              if(max_count < iterator->second){
                max_count = iterator->second;
                column_Number = iterator->first.first;
                value = iterator->first.second;
              }
            }
            else{
              max_count = 0;
              max_Occur_Value_Of_Each_Column[column_Number] = value;
            }
        }
        
    if(max_count < iterator->second){
        max_count = iterator->second;
        column_Number = iterator->first.first;
        value = iterator->first.second;
    }

  max_Occur_Value_Of_Each_Column[column_Number] = value;

//-----------------------------------------------------
     // for(auto i:max_Occur_Value_Of_Each_Column) 
     // std::cout << i.first <<" "<< i.second << "\n";
//-----------------------------------------------------
}

void Module_3::find_Count_Of_Each_Element_In_Categorical_Column(){

    std::int32_t column_counter;
       
       for(std::int32_t row_iterator = 0; row_iterator != MAX_SIZE &&
                    CSV_Data[row_iterator].size(); ++row_iterator){

            column_counter = 0;
            for(const auto& column_iterator : CSV_Data[row_iterator]){

              if(column_iterator != "" 
                 && data_Types_Of_Columns[column_counter] == "string"){

                count_For_Each_Column[{column_counter, column_iterator}]++;
              }
             ++column_counter;
            }
        }
//--------------------------------------------------------------------------------
  // for(auto i:count_For_Each_Column){
  //  std::cout<<i.first.first <<" "<<i.first.second <<" --> "<<i.second<<"\n";
  // }
//--------------------------------------------------------------------------------
  find_Max_Value_For_Each_Column();
}
