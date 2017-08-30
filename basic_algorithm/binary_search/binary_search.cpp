#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int> & array, int low, int high, int target)
{
	if(low > high) return -1;
	int mid = (low + high)/2;
	if(array[mid]>target)
		return binary_search(array, low, mid-1,target);
	if(array[mid]<target)
		return binary_search(array,mid+1,high,target);
	return mid;
}
int main()
{
	int n[]= {1,2,3,4,5,6,12,71,213}; 
	vector<int> nums = vector<int>(n, n+8);
	cout<< binary_search(nums,0,8,12)<<endl;

	return 0;
}

