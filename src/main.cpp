// https://leetcode.com/problems/single-number-ii/

#include<iostream>
#include"../inc/solution.hpp"

int main()
{
	std::vector<int> nums{5,3,5,3,11,3,5};  // 11
	//std::vector<int> nums{0,99,1,0,0,1,1};  // 99

	Solution sol{};
	std::cout << sol.singleNumber(nums);
	return 0;
}
