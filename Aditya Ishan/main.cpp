#include "module1.h"
#include "module2.h"
#include "module3.h"
#include "module4.h"
#include "module5.h"
#include "module6.h"
#include "module7.h"
#include "module8.h"

int CSV::row = -1;
int main()
{
    Module_8 obj;

    std::string file_Name = "aircon.csv"; 

    bool remove_Columns_print_Flag = false;
    bool print_Flag                = true;  
    
    obj.print_Csv(file_Name, obj, print_Flag);

    obj.set_Target_Column();


    
    std::cout << "\n-----Do You Want To Remove Columns?"
                 "\nPress 1 For Yes Or 0 For No-----\n"; 
    
    std::cin >> remove_Columns_print_Flag;

    while(std::cin.fail()){
        
        std::cout << "-----Enter The Correct Choice.-----\n";

        std::cout << "\n-----Do You Want To Remove Columns?"
                     "\nPress 1 For Yes Or 0 For No.-----\n"; 
        
        std::cin.clear();
        std::cin.ignore(256,'\n');
        
        std::cin >> remove_Columns_print_Flag;
    }

    if(remove_Columns_print_Flag) obj.remove_Columns();

    obj.write_To_Csv();
  
    file_Name = "aircon1.csv";

    obj.print_Csv(file_Name, obj, print_Flag);

    obj.remove_Columns_Greater_Than_Threshold();

    obj.write_To_Csv();

    obj.print_Csv(file_Name, obj, print_Flag);

    obj.detect_Data_Type();

    obj.find_Count_Of_Each_Element_In_Categorical_Column();

    obj.fill_Missing_Values_With_Mode();

    obj.print_Csv(file_Name, obj, print_Flag);

    obj.find_Mean_For_Each_Column();

    obj.fill_Missing_Values_With_Mean();

    obj.print_Csv(file_Name, obj, print_Flag);
    
    obj.distinguish_Between_Ordinal_And_Nominal();

    obj.find_Unique_Values_For_The_Ordinal_Columns();

    obj.label_Encoding_Of_Ordinal_Columns();

    obj.replace_Ordinal_Columns_Value_With_Labels();

    obj.print_Csv(file_Name, obj, print_Flag);

    obj.store_The_Values_Of_Nominal_Columns();

    obj.remove_Nominal_Columns();

    obj.write_To_Csv();

    print_Flag = false;
    obj.print_Csv(file_Name, obj, print_Flag);

    obj.find_The_Min_And_Max_Of_Ith_Column();

    obj.normalization_Of_The_Data_Set();

    print_Flag = false;
    obj.print_Csv(file_Name, obj, print_Flag);

    obj.find_Quartile_Range_For_Each_Columns();

    obj.calculate_Iqr();

    obj.calculate_Upper_Bound_Lower_Bound();

    obj.detect_Outliers_Rows_To_Remove();

    obj.remove_Outliers_Rows();
    
    print_Flag = false;
    obj.print_Csv(file_Name, obj, print_Flag);

    obj.fill_Nominal_Values_With_Sparse_Matrix();

    file_Name = "data.csv";
    
    print_Flag = true;
    obj.print_Csv(file_Name, obj, print_Flag);
    
    return 0;
}
