//binary search
int findMin(int* arr, int n) {

     int low = 0,
         high = n-1,
         mid = 0;

      while(low < high)
      {
         mid = low + (high - low) / 2;    

        if(mid!=0 && arr[mid-1] > arr[mid])
        {
          low = mid;
          break;
        }
        else if(arr[mid] > arr[high])
          low = mid + 1;
        else
          high = mid - 1;
      }
   return arr[low];
}