#include <vector>
#include <String>

void quickSort(String arr[], int left, int right) { //http://www.algolist.net/Algorithms/Sorting/Quicksort
      int i = left, j = right;
      int tmp;
      String pivot = arr[(left + right) / 2]; //takes middle number as pivot
      int plength = arr[(left + right)/2].length();
      /* partition */
      while (i <= j){
            ilength = arr[i].length();
            jlength = arr[j].length();
            while (ilength < pivot || (ilength == plength && arr[i].compare(pivot) < 0))
                i++;
            while (jlength > pivot || (jlength == plength && arr[j].compare(pivot) > 0))
                j--;
            if (i <= j) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                i++;
                j--;
            }
      	}
 
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}
void quick(vector<String> s){ //gets it rollin'
	quickSort(&s, 0, s.size());
}