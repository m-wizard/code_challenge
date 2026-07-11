#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Complete the 'getRemovableIndices' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING str1
 *  2. STRING str2
 */

/*
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static int a[5] = {1, 2, 3, 4, 5};
 *
 *     return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     int *a = malloc(5 * sizeof(int));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 */
int* getRemovableIndices(char* str1, char* str2, int* result_count) {
    
    int i = 0;
    
    char running_char = str1[0];
    
    char target_char = 0;
    int target_seq_begin = 0;
    int target_seq_end = 0;
    
    int new_seq_begin = 0;

    int detected_seq = 0;
    
    int empty_string = 0;
    
    int str_len = 0;
    
    //  FIND STRING DIFFERENCES NEXT.
    
    while (str1[i] > 63 && str1[i] < 123) {
        
        //printf("%d \n", i);
        
        if (str1[i] != running_char) {
            running_char = str1[i];
            new_seq_begin = i;
            detected_seq = 0;
        }
        
        if (str1[i] != str2[i]) {
            if (target_char == 0) {
                target_char = str1[i];
                target_seq_begin = new_seq_begin;
                detected_seq = 1;
            }
        }
        
        if (str1[i] == target_char && detected_seq == 1) {
            target_seq_end = i;
        }

        i++;
    }
    
    str_len = i;
    
    //printf("str_len: %d\n", str_len);
    
    ////  MAIN STRING COMPARISON NEXT.
    
    char* str3 = malloc(str_len);

    for (i = 0; i <= str_len; i++) {
        if (i < target_seq_begin) {
            str3[i] = str1[i];
        } else {
            str3[i] = str1[i+1];
        }
    }
    
    //printf("%s, %s, %s \n", str3, str2, str1);
    
    int mismatch_detected = 0;
    
    for (i = 0; i < str_len; i++) {
        if (str3[i] != str2[i]) {
            mismatch_detected = 1;
        }
    }
    
    
    ////  PREPARE OUTPUT NEXT.
    
    int res_len = target_seq_end - target_seq_begin + 1;
    
    int* res = malloc(4 * (res_len));
    
    if (mismatch_detected == 1) {
        res[0] = -1;
        *result_count = 1;

    } else {
   
        for (i = 0 ; i < res_len ; i++) {
            
            res[i] = target_seq_begin + i;
            
        }
        *result_count = res_len;

    }


    //printf("res: %d %d\n", res[0], *result_count);
    
    return res;

}
