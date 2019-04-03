#include "module1.h"

void CSV::empty_2Dvector(){

    for(std::int32_t row_Iterator = 0; CSV_Data[row_Iterator].size()
                 && row_Iterator != MAX_SIZE; ++row_Iterator){

        CSV_Data[row_Iterator].clear();
    }
}

void CSV::read_From_Csv(std::istream& str){
    
    std::string       line;
    std::getline(str,line);
    std::stringstream ss(line);
    std::string       data;
    row++;
    
    while(getline(ss, data, ',')){
        CSV_Data[row].push_back(data);
    } 
}

std::istream& operator>>(std::istream& str, CSV& obj){
    obj.read_From_Csv(str);
    return str;
}

void CSV::open_Csv(std::string& file_Name, CSV& obj){
    std::ifstream file(file_Name, std::ios::binary);

    while(file >> obj){ }
}

void CSV::write_To_Csv(){
     
    std::int32_t column_counter;
    std::ofstream file("aircon1.csv", std::ios::binary);

    for(std::int32_t row_Iterator = 0; CSV_Data[row_Iterator].size() 
                  && row_Iterator != MAX_SIZE; ++row_Iterator){
        
        column_counter = 0; 
        for(const auto& column_Iterator : CSV_Data[row_Iterator]){
            
            if(columns_To_Remove.find(column_counter) == columns_To_Remove.end()){

                file << column_Iterator;
                file << ',';
            }
          ++column_counter;    
        }
      file << "\n";
    }
    
  columns_To_Remove.clear();
}

void CSV::remove_Columns(){

    std::size_t total_Columns = CSV_Data[0].size();

    std::cout << "\nYou Have Total Columns : " << total_Columns
              << "\nEnter The Columns Numbers Between 1 To " << total_Columns 
              << " To Remove Or Press 0 To Exit\n";

    std::int32_t column_Number_To_Remove;
    while(std::cin >> column_Number_To_Remove && column_Number_To_Remove != 0){
        
        try{
            if(column_Number_To_Remove < 0 || 
               column_Number_To_Remove > total_Columns){

                throw error_Range;
            }
            else{
                columns_To_Remove.insert(column_Number_To_Remove - 1);
            }
        }
        
        catch(const std::string& error_Range){
            std::cout << column_Number_To_Remove << error_Range << "\n";
        }

        try{
            if(column_Number_To_Remove == target_Column){

                columns_To_Remove.erase(target_Column - 1);
                throw error_Target_Column;
            }
        }

        catch(const std::string& error_Target_Column){
            std::cout << error_Target_Column << "\n";
        }
    }
    std::cout << "\n";
}

void CSV::set_Target_Column(){

    std::size_t nth_Column = CSV_Data[0].size();

    std::cout << "\nEnter Target Column Attribute Between 1 To " << nth_Column << " : ";

    while(std::cin >> target_Column){

        try{
            if(target_Column < 0 || target_Column > nth_Column){

                throw error_Range;
            }
            else{
                break;
            }    
        }

        catch(const std::string& error_Range){

            std::cout << target_Column << error_Range << "\n";
        }
    }
    
    for(std::int32_t row_Iterator = 0; CSV_Data[row_Iterator].size() 
                  && row_Iterator != MAX_SIZE; ++row_Iterator){
        
        if(CSV_Data[row_Iterator].size() != nth_Column){

            CSV_Data[row_Iterator].push_back(CSV_Data[row_Iterator][target_Column - 1]);

            CSV_Data[row_Iterator][target_Column - 1] = "";
        }

        else{
            swap(CSV_Data[row_Iterator][target_Column - 1], 
            CSV_Data[row_Iterator][nth_Column - 1]);
        }
    }

    std::cout << "\nTarget Column Is Now The Nth Column.\n";
    
    target_Column = nth_Column;
    
    for(std::int32_t row_Iterator = 0; CSV_Data[row_Iterator].size() 
                 && row_Iterator != MAX_SIZE; ++row_Iterator){

        for(const auto& column_Iterator : CSV_Data[row_Iterator]){

            std::cout << std::left << std::setfill(' ') << std::setw(10);  

            std::cout << column_Iterator << " ";
        }
        std::cout << "\n";
    }
}

void CSV::check_Csv_Empty()
{
    try{
        if(CSV_Data[0].empty()) throw error_Empty_CSV;
    }

    catch(const std::string& error_Empty_CSV){
        
        std::cout << error_Empty_CSV << "\n";
        
        exit(0);
    }
}

void CSV::print_Csv(std::string& file_Name, CSV& obj){
    
    row = -1;
    empty_2Dvector();
    open_Csv(file_Name, obj);

    check_Csv_Empty();

    for(std::int32_t row_Iterator = 0; CSV_Data[row_Iterator].size() 
                  && row_Iterator != MAX_SIZE; ++row_Iterator){
       
        for(const auto& column_Iterator : CSV_Data[row_Iterator]){
            
            std::cout << std::left << std::setfill(' ') << std::setw(10);  

            std::cout << column_Iterator << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

