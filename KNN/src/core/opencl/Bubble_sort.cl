void bubbleSort(float arr[], float arr2[], float n);

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

	bubbleSort(outDists, outInds, geneSize - 1);	

}

void bubbleSort(float arr[], float arr2[], float n) 
{ 
   int i, j; 
   float temp; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
   for (j = 0; j < n-i-1; j++)  
	if (arr[j] > arr[j+1])
	{
		temp = arr[j];
		arr[j] = arr[j+1];
		arr[j+1] = temp;

		temp = arr2[j];
		arr2[j] = arr2[j+1];
		arr2[j+1] = temp; 
	}
              
} 
