// 题目地址：https://leetcode.com/problems/two-sum/
// 题目内容：
// 	Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// 
// 	You may assume that each input would have exactly one solution.
// 
// Example:
// 
// Given nums = [2, 7, 11, 15], target = 9,
// 
// 	Because nums[0] + nums[1] = 2 + 7 = 9,
// 	return [0, 1].
// 
// 
// 
// 	UPDATE (2016/2/13):
// The return format had been changed to zero-based indices. Please read the above updated description carefully. 
// 
// 
// 
// 	Subscribe to see which companies asked this question
// 
// 	题目翻译：
// 
// 	给定一个整数数组，找到两个数，使得它们的和等于一个特定的目标数。
// 	函数twoSum应返回两个数的索引（包括索引0和索引1 ）是从零开始的。
// 	可以假设每个输入有且仅有一个答案。
// 	输入：数字 = {2,7,11,15}，目标 = 9
// 	输出：索引0 = 0，索引1 = 1
// 
// 	题目分析：
// 
// 	最简单的办法是双重循环，时间复杂度为：O(n^2)，以下只写出其算法的伪代码
// 
// 	for(x1属于数组)
// 	{
// 		for(x2属于不等于x1位置的数值)
// 		{
// 			if(target == x1+x2)
// 			{
// 				reruen result;
// 			}
// 		}
// 	}
// 
// 	而对于内层寻找我们可以用哈希hash_map,将时间复杂度变为O(n)*O(1)
// 		此处我没有使用map由于考虑到数组数值中存储的数据有可能是重复的。
// 		具体算法如下：
// 		遍历数组的每一个元素，用num[i]在hash_map查找,看是否存在hash_map中，若在，这个两个只就是
// 		如不在就存储如map，其中key为 target-num[i], value值为下标
// 
// eg:
// 	array:[12,8,1,4] taget:9
// 
// 		（1）12,hash_map中不存在12，将9-12存入 hash_map<9-12,0>
// 		（2）8，hash_map中不存在8，将9-8存入hash_map<9-8,1>
// 		(3) 1,hash_map中存在,则，此key对应的value值为所求，此遍历的数组下标也为所求    
// 
// 		代码：
// 
// 		运行时间0ms
class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			unordered_map<int, int> m;
			vector<int> result;
			for(int i=0; i<nums.size(); i++){
				//没有找到第二个数
				if (m.find(nums[i])==m.end() )
				{
					// 在第一个位置存储第二个数的key
					m[target - nums[i]] = i;
				}
				else
				{
					// 找到第二个数
					result.push_back(m[nums[i]]);
					result.push_back(i);
					break;
				}
			}
			return result;
		}
	};