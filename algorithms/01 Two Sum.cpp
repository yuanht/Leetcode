// ��Ŀ��ַ��https://leetcode.com/problems/two-sum/
// ��Ŀ���ݣ�
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
// 	��Ŀ���룺
// 
// 	����һ���������飬�ҵ���������ʹ�����ǵĺ͵���һ���ض���Ŀ������
// 	����twoSumӦ��������������������������0������1 ���Ǵ��㿪ʼ�ġ�
// 	���Լ���ÿ���������ҽ���һ���𰸡�
// 	���룺���� = {2,7,11,15}��Ŀ�� = 9
// 	���������0 = 0������1 = 1
// 
// 	��Ŀ������
// 
// 	��򵥵İ취��˫��ѭ����ʱ�临�Ӷ�Ϊ��O(n^2)������ֻд�����㷨��α����
// 
// 	for(x1��������)
// 	{
// 		for(x2���ڲ�����x1λ�õ���ֵ)
// 		{
// 			if(target == x1+x2)
// 			{
// 				reruen result;
// 			}
// 		}
// 	}
// 
// 	�������ڲ�Ѱ�����ǿ����ù�ϣhash_map,��ʱ�临�Ӷȱ�ΪO(n)*O(1)
// 		�˴���û��ʹ��map���ڿ��ǵ�������ֵ�д洢�������п������ظ��ġ�
// 		�����㷨���£�
// 		���������ÿһ��Ԫ�أ���num[i]��hash_map����,���Ƿ����hash_map�У����ڣ��������ֻ����
// 		�粻�ھʹ洢��map������keyΪ target-num[i], valueֵΪ�±�
// 
// eg:
// 	array:[12,8,1,4] taget:9
// 
// 		��1��12,hash_map�в�����12����9-12���� hash_map<9-12,0>
// 		��2��8��hash_map�в�����8����9-8����hash_map<9-8,1>
// 		(3) 1,hash_map�д���,�򣬴�key��Ӧ��valueֵΪ���󣬴˱����������±�ҲΪ����    
// 
// 		���룺
// 
// 		����ʱ��0ms
class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			unordered_map<int, int> m;
			vector<int> result;
			for(int i=0; i<nums.size(); i++){
				//û���ҵ��ڶ�����
				if (m.find(nums[i])==m.end() )
				{
					// �ڵ�һ��λ�ô洢�ڶ�������key
					m[target - nums[i]] = i;
				}
				else
				{
					// �ҵ��ڶ�����
					result.push_back(m[nums[i]]);
					result.push_back(i);
					break;
				}
			}
			return result;
		}
	};