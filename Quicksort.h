#include<iostream>
#include<algorithm>
#pragma once
template <typename T>
void Quicksort(T& List, // List of items to sort in ascending order		   
			   int Min, // Minimum Index 
			   int Max, // Maximum Index
			   int PivotIndex // Index for pivot value
);
template <typename T>
void Split(T& List, // List of items to sort in ascending order
		   int Min, // Minimum Index 
		   int Max, // Maximum Index
		   int& PivotIndex // Index for pivor
	);
//Put Implementation in header file with out it being annoying
#include "Quicksort.lib"
