func minMoves(arr []int32) int32 {
    var lhOnes int32 = 0
    var rhOnes int32 = 0
    length := int32(len(arr))

    for i := int32(0); i < length; i++ {
        if arr[i] == 1 {
            if i < length/2 {
                lhOnes++
            } else {
                rhOnes++
            }
        }
    }

    var skipSeq int32 = 0
    var mover int32 = 1

    if lhOnes < rhOnes {
        skipSeq = 1
        mover = 0
    }

    var swaps int32 = 0

    swapsOnePass := makeMoves(arr, skipSeq, mover)
    swaps += swapsOnePass

    for swapsOnePass > 0 {
        swapsOnePass = makeMoves(arr, skipSeq, mover)
        swaps += swapsOnePass
    }

    return swaps
}

func makeMoves(arr []int32, skip int32, mover int32) int32 {
    var swaps int32 = 0
    var skips int32 = 0
    length := int32(len(arr))

    for i := int32(0); i < length; i++ {
        if arr[i] == skip {
            skips++
        } else if skips > 0 {
            arr[i] = skip
            arr[i-skips] = mover
            swaps += skips

            i = i - skips
            skips = 0
        }
    }

    return swaps
}
