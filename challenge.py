##  WRITTEN MANUALLY IN PYTHON

def minMoves(arr):
    
    lh_ones, rh_ones = 0, 0
    
    for i,v in enumerate(arr):
        if v == 1:
            if i < len(arr) / 2:
                lh_ones += 1
            else:
                rh_ones += 1
    
    ##print(lh_ones, rh_ones)
    
    skip_seq, mover = 0, 1
    
    if lh_ones < rh_ones:
        skip_seq, mover = 1, 0
        
    ##print(arr)
        
    swaps = 0
        
    swaps_one_pass, arr = make_moves(arr, skip_seq, mover)
    
    swaps += swaps_one_pass
    
    while swaps_one_pass > 0:
        
        ##print(arr, swaps)
    
        swaps_one_pass, arr = make_moves(arr, skip_seq, mover)
        
        swaps += swaps_one_pass
            
    ##print(arr, swaps)
    
    return swaps
    

def make_moves(arr, skip, mover):
    
    swaps = 0
    
    skips = 0
    
    for i in range(len(arr)):
        
        if arr[i] == skip:
            skips += 1
            
        elif (skips > 0):
            arr[i] = skip
            arr[i-skips] = mover
            swaps += skips
            
            i = i - skips;
            
            skips = 0
            
    return swaps, arr
