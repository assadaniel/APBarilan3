#include "KSmallestElements.hpp"
#include <vector>
#include <limits>
#include <map>
/**
 * @brief copied from:
 * https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-3-worst-case-linear-time/?ref=rp
 * modified to fit IrisComp instead of int and not using sort.
 */
// Start copy.

// C++ implementation of worst case linear time algorithm
// to find k'th smallest element
#include<iostream>

using namespace std;


// A simple function to find median of arr[]. This is called
// only for an array of size 5 in this program.
IrisComp& findMedian(IrisComp arr[], int n)
{
    for (int i = 0; i < n; i++){
            IrisComp smallest = arr[i];
            for (int j = i; j < n; j++){
                if (smallest > arr[j]){
                    swap(arr[0],arr[j]);
                    smallest = arr[j];
                }
            }
        }
	return arr[n/2]; // Return middle element

}

// Returns k'th smallest element in arr[l..r] in worst case
// linear time. ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT
IrisComp kthSmallest(IrisComp arr[], int l, int r, int k)
{
	// If k is smaller than number of elements in array
	if (k > 0 && k <= r - l + 1)
	{
		int n = r-l+1; // Number of elements in arr[l..r]

		// Divide arr[] in groups of size 5, calculate median
		// of every group and store it in median[] array.
		int i;
        IrisComp median[(n+4)/5]; // There will be floor((n+4)/5) groups;
		for (i=0; i<n/5; i++)
			median[i] = findMedian(arr+l+i*5, 5);
		if (i*5 < n) //For last group with less than 5 elements
		{
			median[i] = findMedian(arr+l+i*5, n%5);
			i++;
		}	

		// Find median of all medians using recursive call.
		// If median[] has only one element, then no need
		// of recursive call
		IrisComp medOfMed = (i == 1)? median[i-1]:
								kthSmallest(median, 0, i-1, i/2);

		// Partition the array around a random element and
		// get position of pivot element in sorted array
		int pos = partition(arr, l, r, medOfMed);

		// If position is same as k
		if (pos-l == k-1)
			return arr[pos];
		if (pos-l > k-1) // If position is more, recur for left
			return kthSmallest(arr, l, pos-1, k);

		// Else recur for right subarray
		return kthSmallest(arr, pos+1, r, k-pos+l-1);
	}

	// If k is more than number of elements in array
    Iris iris;
    IrisComp irisMAX = IrisComp(iris,numeric_limits<double> :: max());
	return irisMAX;
}

void swap(IrisComp& a, IrisComp& b)
{
	IrisComp temp = a;
	a = b;
	b = temp;
}

// It searches for x in arr[l..r], and partitions the array
// around x.
int partition(IrisComp arr[], int l, int r, const IrisComp& x)
{
	// Search for x in arr[l..r] and move it to end
	int i;
	for (i=l; i<r; i++)
		if (arr[i] == x)
		break;
	swap(arr[i], arr[r]);

	// Standard partition algorithm
	i = l;
	for (int j = l; j <= r - 1; j++)
	{
		if (arr[j] <= x)
		{
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[r]);
	return i;
}

// End copy.

/**
 * @brief Function returing the array of all the Iris smaller then the kth.
 *
 * @param kth The place of the kth iris.
 * @param arr The array of iris.
 * @param size The size of the array.
 * @return A vector holding all the all the iris smaller then the kth iris.
 */
vector<IrisComp> ArrayOfIris(int kth, IrisComp arr[], int size){
    kthSmallest(arr,0,size-1,kth);
    vector<IrisComp> kSmallest;
    for (int i = 0; i < kth; i++) {
        kSmallest.push_back(arr[i]);
    }
    return kSmallest;
}

/**
 * @brief Function putting the distances into an array.
 *
 * @param iris A constesnt iris which we calculate the distance with.
  * @param v The array of iris we find the distances from  iris.
  * @param func The function we use to find the distances.
  * @return A vector holding all the all the iris distances then the iris.
 */
IrisComp* DistancesToArray(const Iris& iris,std::vector<Iris> v, std::function<double(const Iris, const Iris)>& func) {
    size_t n = v.size();
    auto *irisComps = new IrisComp[n];
    for (int i = 0; i < n; i++) {
        double d = func(iris,v[i]);
        irisComps[i] = IrisComp(v[i],d);
    }
    return irisComps;
}

/**
 * @brief Function finding the most frequent type of iris in the array.
 *
 * @param v The vector we check on.
 * @return The iris type that appear the most in the vector.
 */
irisType mostFrequentType(const vector<IrisComp>& v) {
    std::map<irisType,int> countMap = {{setosa,0}, {virginica,0}, {versicolor,0}};
    for(const IrisComp& irisComp : v) {
        countMap[irisComp.getIris().getType()]++;
    }
    irisType irisType = maxTypeInMap(countMap);
    return irisType;
}


/**
 * @brief Function finding the most probable type of iris for the given iris.
 *
 * @param kth The amount of iris we want to compare to from the given array.
 * @param arr The array of iris we use to compare.
 * @param size The size of the array.
 * @return The iris type that is  the most probable to be the given iris.
 */
irisType determineType(int kth,IrisComp arr[],int size) {
    return mostFrequentType(ArrayOfIris(kth,arr,size));
}

/**
 * @brief Function finding the type of the iris from the array.
 *
 * @param iris The iris we want to find the type of.
 * @param irisVector The array of iris we use to compare.
 * @param kth The amount of iris we want to compare to from the given array.
 * @return The iris type that is  the most probable to be the given iris.
 */
irisType typeFromIrises(const Iris& iris, const vector<Iris>& irisVector, int kth,
                        std::function<double(const Iris, const Iris)> distanceFunction) {
    int size = irisVector.size();
    IrisComp* irisComp = DistancesToArray(iris,irisVector,distanceFunction);
    irisType t = determineType(kth, irisComp,size);
    delete[] irisComp;
    return t;
}
/**
 * @brief Finds max value in map and returns its key.
 * @param countMap The map of types and their count
 * @return The key that corresponds to maximum value in map.
 */
irisType maxTypeInMap(std::map<irisType,int>& countMap) {
    irisType maxType;
    int maxCount = 0;
    for(auto const& x : countMap) {
        if(x.second >= maxCount) {
            maxType = x.first;
            maxCount = x.second;
        }
    }
    return maxType;
}
