#pragma once
#include "Quicksort.h"

template <typename T>
void Quicksort(T& List, int Min, int Max, int PivotIndex) 
{
	// Stop if List has 0-1 elements
	if (!(Min < Max))
		return;
	// SplitList around pivot
	Split(List, Min, Max, PivotIndex);
	//Sort List that is smaller than index
	Quicksort(List, Min, PivotIndex-1, PivotIndex);
	//Sort List that is greater than index
	Quicksort(List, PivotIndex+1, Max, PivotIndex);

}

template <typename T>
void Split(T& List, int Min, int Max, int& PivotIndex) 
{
	int Left = Min, Right = Max - 1, PivIn = Min;
	while (Left < Right && Max-Min > 1) 
	{
		while (Left < Right && List.at(PivIn) >= List.at(Right))
			Right--;

		while (Left < Right && List.at(PivIn) < List.at(Left))
			Left++;

		if (Left < Right)
			std::swap(List.at(Left), List.at(Right));
	}
	std::swap(List.at(PivIn), List.at(Right));
	PivotIndex = Right;

}
