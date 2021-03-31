def sort1iter(arr, i, listlen):
    minval = 200
    minindex = -1
    
    for j in range(i,listlen):
        if arr[j] < minval:
            minval = arr[j]
            minindex = j
    
    arr[i:minindex+1] = arr[i:minindex+1][::-1]
    return (minindex - i)        
    

def calcCost(arr, listlen):
    cost = -1
    
    for i in range(listlen):
        cost += sort1iter(arr, i, listlen)  
     
    cost += listlen
    
    return cost
      
def main():
    runs = int(input())
    
    for i in range(runs):
        arr = []
        listlen = int(input())
        arr = list(map(int, input().split()))
        
        cost = calcCost(arr, listlen)
        
        print(f'Case #{i+1}: {cost}')
        
main()