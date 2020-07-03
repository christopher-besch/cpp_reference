#include <iostream>

#define LOG(msg) std::cout << msg << std::endl


int main()
{
	// just allocating memory
	int* array = new int[50];
	// storing a buffer of pointers
	int** a2d = new int*[50];

	for (int i = 0; i < 50; i++)
	{
		// allocate memory for 50 integers and store the pointer to those in this entry of a2d
		a2d[i] = new int[50];
	}

	// 3D array of 50 2d arrays of 40 arrays each of 20 integers (=42) each
	int*** a3d = new int**[50];
	for (int a3d_idx = 0; a3d_idx < 50; a3d_idx++)
	{
		a3d[a3d_idx] = new int* [40];
		for (int a2d_idx = 0; a2d_idx < 40; a2d_idx++)
		{
			a3d[a3d_idx][a2d_idx] = new int[20];
			for (int a1d_idx = 0; a1d_idx < 20; a1d_idx++)
			{
				a3d[a3d_idx][a2d_idx][a1d_idx] = 42;
			}
		}
	}

	LOG(a3d[40][3][13]);

	// delete by iterating
	for (int a3d_idx = 0; a3d_idx < 50; a3d_idx++)
	{
		for (int a2d_idx = 0; a2d_idx < 40; a2d_idx++)
		{
			delete[] a3d[a3d_idx][a2d_idx];
		}
		delete[] a3d[a3d_idx];
	}
	delete[] a3d;

	std::cin.get();
}

/*
 * array of arrays of array -> 3D array
 * when deleting heap allocated multidimensional arrays you have to iterate over them
 * arrays of arrays lead to memory fragmentation -> iteration is a lot slower than single dimensional arrays
 */
