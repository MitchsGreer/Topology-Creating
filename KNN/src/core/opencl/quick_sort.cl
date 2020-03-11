int partition (float arr[], float arr2[], int low, int high);
void quickSort(int arr[], float arr2[], int low, int high);

__kernel void sort(__global const float *row, 
		  int geneSize, 
		  int index, 
		  int globalWorkSize,
		  __global float *outDists,
          	  __global float *outInds)
{
	//Make sure you are not operating outside of bounds
	int i = get_global_id(0);
	if(i >= globalWorkSize || index >= globalWorkSize)
	{
		return;
	}

    for(int i = 0; i < geneSize; i++)
    {
        outDists[i] = row[i];
        outInds[i] = i;
    }
    
    quickSort(outDists, outInds, 0, geneSize - 1);

}

//swap(&arr[i], &arr[j]);

/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition (float arr[], float arr2[], int low, int high) 
{ 
    float pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
    float temp;
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
    	    temp = arr[i];
	    arr[i] = arr[j];
	    arr[j] = temp;

	    temp = arr2[i];
	    arr2[i] = arr2[j];
	    arr2[j] = temp; 
        } 
    }  
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    temp = arr2[i + 1];
    arr2[i + 1] = arr2[high];
    arr2[high] = temp;
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(int arr[], float arr2[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, arr2, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, arr2, low, pi - 1); 
        quickSort(arr, arr2, pi + 1, high); 
    } 
} 
