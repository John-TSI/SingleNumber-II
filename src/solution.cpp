#include<numeric>  // std::accumulate
#include<algorithm>  // std::min
#include<cmath>  // std::abs
#include"../inc/solution.hpp"


int Solution::singleNumber(std::vector<int>& nums)
{
    // --- solution one : subtraction ---
/*     
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
*/ 


    // --- solution two : bit manipulation ---
    int solo{0}, shift{1};  // 'shift' will act as the comparator for bitwise and operation 

    for(int bit{0}; bit<32; ++bit)  // iterate over the bits of the numbers
    {
        int bitCount{0}; 
        for(int num : nums){ bitCount += (num & shift) ? 1 : 0; }  // count how many numbers in nums set each bit
        // each bit will be set at least thrice if in a triplicate num, if non-zero after mod 3 then must be set in solo too  
        solo += (bitCount % 3) ? shift : 0;
        shift <<= 1;  // bitshift left the comparator value before next loop iteration
    }
    return solo;
}