def solve(arr, costDict):
    cost = 0
    count = 0

    for i in range(len(arr)):
        if arr[i] == '?':
            if count == 0:
                start = i

            end = i + 1
            count += 1

            if i >= len(arr) - 1:
                if arr[start - 1] == '?':
                    return 0
                arr[start:end] = [arr[start-1] for a in range(count)]
                
        
        else:
            if count != 0:
                arr[start:end] = [arr[i] for a in range(count)]
                count = 0

    for i in range(len(arr) - 1):
        cost += int(costDict.get(f'{arr[i]}{arr[i+1]}'))
        
    return cost


def main():
    runs = int(input())

    for i in range(runs):
        x, y, arr = input().split()
        x = int(x)
        y = int(y)
        arr = list(arr)

        costDict = {'CJ' : x, 'JC' : y, 'CC' : 0, 'JJ' : 0}

        cost = solve(arr, costDict)

        print(f'Case #{i+1}: {cost}')


main()
