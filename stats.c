



/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/

/**
 * @file stats.c
 * @brief definitions and the implementations of some statistical functions
 *
 * Contains: main() - The main entry point for your program
             print_statistics() - A function that prints the statistics of an array including minimum, maximum, mean, and median.
             print_array() -  Given an array of data and a length, prints the array to the screen
             find_median() - Given an array of data and a length, returns the median value
             find_mean() -  Given an array of data and a length, returns the mean
             find_maximum() -  Given an array of data and a length, returns the maximum
             find_minimum() -  Given an array of data and a length, returns the minimum
             sort_array() - Given an array of data and a length, sorts the array from largest to smallest. (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )
 *
 * @author Muhammad Wisal Khan
 * @date 18.03.2023
 *
 */

#include <stdio.h> 
//#include "stats.h"
  
#define SIZE (40)
  
// Function to sort the numbers using pointers 
void sort_array(int , unsigned char*); 
void print_array (int , unsigned char*);
unsigned char find_maximum(int , unsigned char*);
unsigned char find_minimum(int , unsigned char*);
unsigned char find_median(int , unsigned char*);
void print_statistics(double, unsigned char, unsigned char, unsigned char);
double find_mean(int , unsigned char*);

  
// Driver code 
int main() 
{ 
    
    unsigned char test[SIZE] = {34,201,190, 154,8,194,2,6,114, 88,   								 45,76,123, 87, 25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
                                
                                
    /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */    
  	double mean; 
    unsigned char max, min, median;
    /* Add other Implementation File Code Here */

  
    sort_array(SIZE, test); 
  mean = find_mean (SIZE, test);
    max = find_maximum(SIZE, test);
    min = find_minimum(SIZE, test);
    median = find_median(SIZE, test);
    print_statistics(mean, max, min, median);
    
    print_array(SIZE, test);
  
    return 0; 
} 


double find_mean (int n, unsigned char* ptr){
int i;
double mean;
for (i = 0; i < n; i++) {
mean =mean + *(ptr + i);
}

mean = mean/n;
return mean;

}

unsigned char find_maximum(int n , unsigned char* ptr){
unsigned char maximum = 0, i;

for (i=0; i<n; i++){
if (maximum < *(ptr + i)){
maximum = *(ptr + i);
}

}
return maximum;

}

unsigned char find_minimum(int n , unsigned char* ptr){
unsigned char min = 255, i;

for (i=0; i<n; i++){
if (min > *(ptr + i)){
min = *(ptr + i);
}

}
return min;

}

unsigned char find_median(int n , unsigned char* ptr){
unsigned char median;
if (n%2 ==1){
median = *(ptr + (n/2));
}
else{
median = (*(ptr + (n/2)) + *(ptr + (n/2)+1))/2;
}


return median;

}




void sort_array(int n, unsigned char* ptr) 
{ 
    int i, j, t; 
  
    // Sort the numbers using pointers 
    for (i = 0; i < n; i++) { 
  
        for (j = i + 1; j < n; j++) { 
  
            if (*(ptr + j) > *(ptr + i)) { 
  
                t = *(ptr + i); 
                *(ptr + i) = *(ptr + j); 
                *(ptr + j) = t; 
            } 
        } 
    } 
  
    
} 

void print_array (int n , unsigned char* ptr){

// print the numbers 
int i;
    for (i = 0; i < n; i++) 
        printf("%d ", *(ptr + i)); 

}

void print_statistics(double mean, unsigned char max, unsigned char min, unsigned char median){

printf("\n Mean = %lf \n max= %u \n minimum=%u \n median=%u \n", mean, max, min, median);
}

