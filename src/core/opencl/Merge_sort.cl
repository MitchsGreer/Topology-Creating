
void mergeSort(float arr[], float arr2[], int l, int r);
void merge(float arr[], float arr2[], int l, int m, int r);


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

    mergeSort(outDists, outInds, 0, geneSize - 1);
}


/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(float arr[], float arr2[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, arr2, l, m); 
        mergeSort(arr, arr2, m+1, r); 
  
        merge(arr, arr2, l, m, r); 
    } 
} 

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(float arr[], float arr2[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    float *L = (float *) malloc(sizeof(float) * n1);
    float *R = (float *) malloc(sizeof(float) * n2);
    float *L2 = (float *) malloc(sizeof(float) * n1);
    float *R2 = (float *) malloc(sizeof(float) * n2);

  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
        L2[i] = arr2[l + i];
    } 
         
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1+ j];
        R2[j] = arr2[m + 1+ j];
    }
         
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i];
            arr2[k] = L2[i];
            i++; 
        } 
        else
        { 
            arr[k] = R[j];
            arr2[k] = R2[j];
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i];
        arr2[k] = L2[i];
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j];
        arr2[k] = R2[j];
        j++; 
        k++; 
    } 
    free(L);
    free(R);
    free(L2);
    free(R2);
}
