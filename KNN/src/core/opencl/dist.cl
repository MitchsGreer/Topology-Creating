__kernel void dist(__global const float *expressions, 
		  int geneSize, 
		  int sampleSize,
		  int index, 
		  int globalWorkSize,
		  __global float *outDists)
{
	//Make sure you are not operating outside of bounds
	int id = get_global_id(0);
	float dist = 0.0;
	float sum = 0.0;
	int i = 0;
	int j = 0;

	if(id >= globalWorkSize || index >= globalWorkSize)
	{
		return;
	}

	//initialize variables
	__global const float *geneIndex = &expressions[index * sampleSize];
	__global float *compareRow;

	for(i = 0; i < geneSize; i++)
	{
		dist = 0.0;
		sum = 0.0;
		compareRow = &expressions[i * sampleSize];
		for(j = 0; j < sampleSize; j++)
		{
			sum = compareRow[j] - geneIndex[j];
			if(sum < 0)
			{
				sum *= -1;
			}
			dist += sum;
		}
		
		outDists[i] = dist;
	}

	for(i = 0; i < geneSize - index; i++)
	{
		outDists[i] = outDists[i + index];
	}
}
