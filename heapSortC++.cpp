#include <chrono>
#include <iostream>

using namespace std;
  
  void heapify(int arr[], int n, int i)
   {

    
    int largest = i;
    int left = 2 * i + 1;//walking around the index to the left child
    int right = 2 * i + 2;//walking around the index to the right child 
  // searching for largest root 
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    // Swaping and continue heapifying if the root is not largest
    if (largest != i) {
      swap(arr[i], arr[largest]);
      heapify(arr, n, largest);
    }
  }
  

  void heapSort(int arr[], int n) 
  {
    // making the max heap by using the n/2-1 =i,where the n = number of index 

    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(arr[0], arr[i]);
  
      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
  }
  
  void printArray(int arr[], int n)
   {
    for (int i = 0; i < n; ++i)
      cout << arr[i] << " ";
    cout << "\n";
  }
  



  int main() 
  {
 

   //get the time start
    
    //my operation 

    int arr[1000000]; //= {2310, 122, 436, 15, 239, 101, 22, 234, 34344, 123, 11, 23322, 34424, 2231, 223, 20095, 4344};
    for (int i = 0;i<1000000;i++)
      arr[i]=rand()%1000000;

    int n = sizeof(arr) / sizeof(arr[0]);
    auto start_time = chrono::steady_clock::now(); 
    heapSort(arr, n);
    auto end_time = chrono::steady_clock::now(); 
    //elapsed time
    double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count());
    cout << "Sorted array is: \n";
    printArray(arr, n);
    //get the time end

    cout<<"1000000 array"<<endl;
    cout<<"Elapsed time is :"<<elapsed_time / 1e7<<endl;
    system("pause;");
    return 0;
  
  }