
def solve(size, cost):
    finalCost = cost - size #Final cost should be 0 at the end
    maxCost = sum([(size-i) for i in range(size - 1)]) + size

    if cost > maxCost or finalCost < 0:
        return 'IMPOSSIBLE'

    if cost == size-1:
        return [(str(i)+' ') for i in range(1, size + 1)]
   

    arr = [i for i in range(1,size+1)]

    for i in range(size):
        flippedSize = (size - i) - 2
        if flippedSize > finalCost:
            continue

        arr[i:size+1] = arr[i:size+1][::-1]

    return ' '.join(map(str, arr))



def main():
    runs = int(input())
    
    for i in range(runs):
        size, cost = list(map(int, input().split()))

        arr = solve(size, cost)
        
        print(f'Case #{i+1}: {"".join(map(str, arr))}')
        
main()