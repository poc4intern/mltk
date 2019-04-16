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
    //     std::cout<<i.first<<" "<<i.second<<"\n";
    // }
    // std::cout<<"\n";
    // for(const auto& i : upper_Bound_Of_Ith_Column){
    //     std::cout<<i.first<<" "<<i.second<<"\n";
    // }
//------------------------------------------------------
}

struct Strategy : public Module_7{

    public:
        Strategy() {}
        virtual ~Strategy() = default;
        virtual void justify_strategy(std::map<std::int32_t, 
                                      std::vector<long double>>::const_iterator,
                                      Module_7&) = 0;
};

struct odd_Odd_Strategy : public Strategy{
    
    public:
        void justify_strategy(std::map<std::int32_t, 
                              std::vector<long double>>::const_iterator map_iterator, 
                              Module_7& obj) {

            obj.lower_index = obj.middle / 2 - 1;
            obj.upper_index = obj.lower_index + obj.middle;

            obj.lower_Bound_Of_Ith_Column[map_iterator->first] = map_iterator->second[obj.lower_index];
            obj.upper_Bound_Of_Ith_Column[map_iterator->first] = map_iterator->second[obj.upper_index];
        }
};

struct odd_Even_Strategy : public Strategy{
    
    public:
        void justify_strategy(std::map<std::int32_t, 
                              std::vector<long double>>::const_iterator map_iterator,
                              Module_7& obj) {

            obj.lower_index  = obj.middle / 2;
            obj.lower_index1 = obj.middle / 2 - 1;
            obj.upper_index  = obj.lower_index  + obj.middle;
            obj.upper_index1 = obj.lower_index1 + obj.middle; 

            obj.lower_Bound_Of_Ith_Column[map_iterator->first] 
            = (map_iterator->second[obj.lower_index] + map_iterator->second[obj.lower_index1]) / 2.0;
            
            obj.upper_Bound_Of_Ith_Column[map_iterator->first] 
            = (map_iterator->second[obj.upper_index] + map_iterator->second[obj.upper_index1]) / 2.0;   
        }
};

struct even_Odd_Strategy : public Strategy{
    
    public:
        void justify_strategy(std::map<std::int32_t, 
                              std::vector<long double>>::const_iterator map_iterator,
                              Module_7& obj) {

            obj.lower_index = obj.middle / 2;
            obj.upper_index = obj.lower_index + obj.middle;

            obj.lower_Bound_Of_Ith_Column[map_iterator->first] = map_iterator->second[obj.lower_index];
            obj.upper_Bound_Of_Ith_Column[map_iterator->first] = map_iterator->second[obj.upper_index]; 
        }
};

struct even_Even_Strategy : public Strategy{
    
    public:
        void justify_strategy(std::map<std::int32_t,
                              std::vector<long double>>::const_iterator map_iterator,
                              Module_7& obj) {
            
            obj.lower_index  = obj.middle / 2;
            obj.lower_index1 = obj.middle / 2 - 1;

            obj.upper_index  = obj.lower_index  + obj.middle;
            obj.upper_index1 = obj.lower_index1 + obj.middle;

            obj.lower_Bound_Of_Ith_Column[map_iterator->first] 
            = (map_iterator->second[obj.lower_index] + map_iterator->second[obj.lower_index1]) / 2.0;

            obj.upper_Bound_Of_Ith_Column[map_iterator->first]
            = (map_iterator->second[obj.upper_index] + map_iterator->second[obj.upper_index1]) / 2.0;   
        }
};

void Module_7::find_Quartile_Range_For_Each_Columns(Module_7& obj){

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
    
    for(auto map_iterator = temp_Data.begin(); 
         map_iterator != temp_Data.end(); ++map_iterator){
        
        Strategy *strategy_Obj = nullptr;

        middle = (map_iterator->second.size() + 1) / 2;

        if(map_iterator->second.size() & 1){ //n is odd

            if((middle-1) & 1){ //n/2 is odd
                strategy_Obj = new odd_Odd_Strategy();
                strategy_Obj->justify_strategy(map_iterator, obj);
            }

            else{ //n/2 is even
                strategy_Obj = new odd_Even_Strategy();
                strategy_Obj->justify_strategy(map_iterator, obj);
            }
        }

        else{ //n is even

            if(middle & 1){
                strategy_Obj = new even_Odd_Strategy();
                strategy_Obj->justify_strategy(map_iterator, obj);
            }

            else{
                strategy_Obj = new even_Even_Strategy();
                strategy_Obj->justify_strategy(map_iterator, obj);
            } 
        }
       delete strategy_Obj; 
    }
//------------------------------------------------
    // for(const auto& i : lower_Bound_Of_Ith_Column){
    //     std::cout<<i.first<<" "<<i.second<<"\n";
    // }
    // std::cout<<"\n";
    // for(const auto& i : upper_Bound_Of_Ith_Column){
    //     std::cout<<i.first<<" "<<i.second<<"\n";
    // }
    // std::cout<<"\n";
//-----------------------------------------------
}
