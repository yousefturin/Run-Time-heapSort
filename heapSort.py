from timeit import default_timer as timer
from numpy.random import randint


def heapify(arr, n, i):
    # Find largest among root and children
    largest = i
    # walking around the index to the left child
    left = 2 * i + 1
    # walking around the index to the right child
    right = 2 * i + 2
    # assigning the left of the roots as largest
    if left < n and arr[i] < arr[left]:
        largest = left
    # assigning the right of the roots as largest
    if right < n and arr[largest] < arr[right]:
        largest = right

    # Swapping and continue heapify if the root is not largest
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)



def heapSort(arr):
    n = len(arr)

    # making the max heap by using the n/2-1 =i,where the n = number of index
    for i in range(n // 2, -1, -1):
        heapify(arr, n, i)

    for i in range(n - 1, 0, -1):
        # Swap
        arr[i], arr[0] = arr[0], arr[i]

        # Heapify root element to get highest element at root again
        heapify(arr, i, 0)


arr = randint(1, 1000000, 1000000)
# arr = [2310, 122, 436, 15, 239, 101, 22, 234, 34344, 123, 11, 23322, 34424, 2231, 223, 20095, 4344]
start = timer()
heapSort(arr)
n = len(arr)
end = timer()
print("Sorted array is {1000000} \n")

for i in range(n):

    print("%d" % arr[i], end=' ')
print('\n')

print("time elapse is :", end - start)

# end_time = time.time()
# time_elapsed_heapify = end_time - start_time
# print("  ""Elapsed time for heapify:", time_elapsed_heapify)
# heapify_time = timeit(lambda : heapify(arr,n,i),number=1)
# heapSort_time = timeit(lambda : heapSort(arr),number=1)
# print(f"heapify_time={heapify_time:.3f}")
# print(f"heapSort_time={heapSort_time:.3f}")
