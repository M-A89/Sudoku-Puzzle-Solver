//
//  class : MIAE 215 Assignment 2
//  Student name: Mira Alanzarouti
//  Student ID: 40195605
//  December 2022
//

#include <string>
#include <iostream>

using namespace std;
//function prototypes
//returns a boolean false if there is a missing/repeated number in the array row
bool check_row(int a[][9], int which_row);
//returns a boolean false if there is a missing/repeated number in the array column
bool check_col(int* a, int which_col);
//checks the array by dividing it into 3x3 matrix and checking if any numbers are missing
bool check_region(int a[] [9], int which_row, int which_col );


int main()
{
//initializing our sudoku puzzle
int suduko[9][9] = { 2, 7, 1,    9, 5, 4,    6, 8, 3,
                     5, 9, 3,    6, 2, 8,    1, 4, 7,
                     4, 6, 8,    1, 3, 7,    2, 5, 9,

                     7, 3, 6,    4, 1, 5,    8, 9, 2,
                     1, 5, 9,    8, 6, 2,    3, 7, 4,
                     8, 4, 2,    3, 7, 9,    5, 6, 1,

                     9, 8, 5,    2, 4, 1,     7, 3, 6,
                     6, 1, 7,    5, 9, 3,     4, 2, 8,
                     3, 2, 4,    7, 8, 6,     9, 1, 5 };

cout << "Checking all the rows for Sudukoness:" << endl << endl;

//start of for loop tha will check thr rows for sudukoness
for(int row = 0; row <  9 ; row++)
{
  cout << "Checking row " << row << " of the array : " ;
   
    if ( check_row(suduko, row) )//invoking function to check every row
   {
     cout << " TRUE " << endl;
   }
   else
   {
    cout << " FALSE " << endl;
   }
}

cout << endl;
cout << "Checking all the columns for Sudukoness:" << endl << endl;
//for loop to check every column for sudukoness
for(int col = 0; col <  9 ; col++)
{
  cout << "Checking col " << col << " of the array : " ;
   if ( check_col(&suduko[0][0], col) )//invokinga function to check every column in every iteration of the loop but this time passing the array's base address each time
   {
     cout << " TRUE " << endl;
   }
   else
   {
    cout << " FALSE " << endl;
   }
}

cout << endl;
cout << "Checking all the  regions for Sudukoness:" << endl << endl;
//checking every region in loop
for ( int row = 0 ; row < 9 ; row = row + 3 )
{
  for ( int col = 0 ; col  < 9 ; col = col + 3 )
  {
     cout <<  "Checking region defined by row = " << row << " and column = " << col ;
     if ( check_region(suduko, row, col )  )
     {
        cout << " TRUE " << endl;
     }
     else
     {
      cout << " FALSE " << endl;
     }
   } // col
 } // row




return 0;
}//end of main


bool check_row(int a[][9], int which_row)//passing array by reference and the row by value
{
    bool all_found = true;
    bool number_found = false;
    
    //nested for loop to check if number found in index of row array is equal to a number between 1 and 9
    
    for (int number = 1; number <= 9; number++){
        //second for loop to test each value in the row
        for (int j = 0; j < 9; j++)
        {
            //if number from row is equal to a number between 1 and 9, break and set number found to true
            if (a[which_row][j] == number){
                
                number_found = true;
                
                break;
                
            }
            else number_found = false;
        }
        if ( false == number_found){
            
            all_found = false;
            cout << "The missing number in this row = " << number;
            }
       }
    return all_found; //return false or true
}//end of function definition

bool check_col(int* a, int which_col)  //passing the pointer to the array and the column value
{
    
    bool all_found = true;
    
    bool number_found = false;
    
    
    for (int number = 1; number <= 9; number++){
        //second for loop to test each value in the column
        for (int j = 0; j < 9; j++){
            //variable used to store the column value found using the 2D translational formula
            int number_to_test = a[j * 9 + which_col];
            //if number from column is equal to a number between 1 and 9, break and set number found to true
            if (number_to_test == number)
            {
                number_found = true;
                
                break;
            }
            else {number_found = false;}   //else set it to false
        }
        //if its false print the number thats missing
            if (number_found == false){
                
                cout << "The missing number in this column = " << number;
                
            }
            all_found = all_found && number_found;
        }
    
        return all_found;  //return the boolean result
    }
    
//this function checks the region by recieving a suduko array
    bool check_region(int a[][9], int which_row, int which_col )
   {
        
        bool all_found = true;
        
        bool number_found ;
        
        for (int number = 1; number <= 9; number++){
            
            number_found = false;
            
            for (int row = 0; row < 3; row++)//iterate through the loop three times since we are checking region
            {
                for (int col = 0; col < 3; col++)
                {
                    //checking if number is equal to the term of the array with
                    //row = row + row passed to function parameter
                    //column = column + column passed by parameter
                    if ( number == a[row + which_row][col + which_col]){
                        number_found = true;
                        break;
                    }
                }
                //if number found is true break
                if ( number_found )
                    break;
                
            }//end of row loop
            //if all numbers are found in this region it will be true else it will be false
            all_found = all_found && number_found;   //both need to be true
            
            if ( false == number_found )
            {
                cout << "The missing number in this region = " << number;
            }
        }// do this for numbers 1->9 (end of first for loop)
        return all_found;
    }//end of function definition

