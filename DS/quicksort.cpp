#include<iostream>
#include<vector>
#include<algorithm>
class Solution {
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        
        quicksort(nums, 0, nums.size()-1 );
        return nums;
    }

    void quicksort(std::vector<int>& nums, int l, int r)
    {
        if(l<r)
        {
            int pi = parition(nums, l, r);
            quicksort(nums, l, pi-1);
            quicksort(nums, pi+1, r);
        }
    }

    int parition(std::vector<int>& nums, int l, int r)
    {
        int pivot = nums[r];
        int i=l-1; // use for partition index
        for(int j=l; j<r; j++)
        {
            if(nums[j]<pivot)
            {
                i++;
                swap(nums, i, j);
            }
        }
        swap(nums, i+1, r);
        return i+1;
    }

    void swap(std::vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};

int main()
{
    std::vector<int> vec{2,5,1,554,6,1,9,58,-23,10000,7};
        for_each(vec.begin(), vec.end(), [](int it){
        std::cout<<it<<"    ";
    });
    Solution obj;
    std::cout<<"\n Sorted Array: ";
    std::vector<int> resvec = obj.sortArray(vec);
    for_each(resvec.begin(), resvec.end(), [](int it){
        std::cout<<it<<"    ";
    });

}