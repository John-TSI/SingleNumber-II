#include<numeric>
#include<algorithm>
#include"../inc/solution.hpp"


int Solution::singleNumber(std::vector<int>& nums)
{
    // --- solution one ---
    if(nums.size() == 1){ return nums[0]; }

    auto minIt = std::min_element(nums.begin(),nums.end());
    int min{*minIt}, sumOfTriplets{min}, solo{0};
    int total = std::accumulate(nums.begin(),nums.end(),0);

    do{ solo = total - 3*(sumOfTriplets++); } 
    while
    ( 
        std::find(nums.begin(), nums.end(), solo) == nums.end() || 
        std::count(nums.begin(), nums.end(), solo) > 1 
    );

    return solo; 


    // --- solution two : inconsistent, fails when tripletCount > 2 ---
/*     
    int count = nums.size(); 
    nums.erase(std::remove(nums.begin(),nums.end(), 0), nums.end() );
    if(nums.size() == count-1){ return 0; }
    if(nums.size() == 1){ return nums[0]; }
    count = nums.size();

    int tripletCount = (count-1)/3, bits{0}, tmp{0}, startIdx{0};
    while(tripletCount)
    {
        bool erased{false}; 
        for(int i{startIdx}; i<count; ++i)
        {
            tmp = bits;
            bits ^= nums[i];
            if(!bits)
            { 
                bits = tmp; nums.erase(nums.begin()+i); erased = true; 
                --count; --tripletCount; startIdx=i; 
                break; 
            }
        }
        if(!erased){ startIdx = 0; }
    }
    bits = 0;
    for(int num : nums){ bits ^= num; }
    return bits; 
*/
}