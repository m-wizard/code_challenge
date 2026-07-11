
//  PORTED MANUALLY FROM PYTHON TO C.

int make_moves(int* arr, int arr_count, int skip, int mover);

int minMoves(int arr_count, int* arr) {
    
    int lh_ones = 0;
    int rh_ones = 0;
    
    int i = 0;
    
    for (i = 0; i < arr_count; i++) {
        if (arr[i] == 1) {
            if (i < arr_count / 2) {
                lh_ones += 1;
            } else {
                rh_ones += 1;
            }
        }
    }
    
    int skip_seq = 0;
    int mover = 0;
    
    if (lh_ones < rh_ones) {
        skip_seq = 1;
        mover = 0;
    }
    
    for (i = 0; i < arr_count; i++) {       
        printf("%d ", arr[i]);   
    }
    printf("\n");
    
    int swaps = 0;
    int swaps_one_pass = make_moves(arr, arr_count, skip_seq, mover);
    swaps += swaps_one_pass;
    
    printf("%d\n", swaps);

    while (swaps_one_pass > 0) {
        
        for (i = 0; i < arr_count; i++) {       
        printf("%d ", arr[i]);   
        }
        printf("\n");
        
        swaps_one_pass = make_moves(arr, arr_count, skip_seq, mover);
        swaps += swaps_one_pass;
        
        printf("%d\n", swaps);
        
    }
    
    for (i = 0; i < arr_count; i++) {       
        printf("%d ", arr[i]);   
    }
    printf("\n");
    
    return swaps;
    
}

int make_moves(int* arr, int arr_count, int skip, int mover) {
    
    int swaps = 0;
    int skips = 0;
    int i = 0;
    
    for (i = 0 ; i < arr_count; i++) {
        if (arr[i] == skip) {
            skips += 1;
        } else if (skips > 0) {
            arr[i] = skip;
            arr[i-skips] = mover;
            swaps += skips;
            
            i = i - skips;
            
            skips = 0;
        }
    }
    
    return swaps;    
    
    
    // swaps = 0
    
    // skips = 0
    
    // for i, v in enumerate(arr):
        
    //     if v == skip_seq:
    //         skips += 1
            
    //     else:
    //         arr[i] = skip_seq
    //         arr[i-skips] = mover
    //         swaps += skips
    //         skips = 0
            
    // return swaps, arr
    
}
