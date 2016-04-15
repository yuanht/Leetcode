// 题目地址：https://leetcode.com/problems/longest-palindromic-substring/
// 题目内容：
// 	Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
// 	题目翻译：
// 
// 	给定一个字符串S，找到S中最大的回文子串，你可以假设这个字符串S的最大长度为1000,而且只存在唯一的最大回文子串。
// 
// 	题目分析：
// 
// 	对于以上题目，可以用for循环，对S中的每个字符进行左右查找，看是否与左右的数据是构成回文子串，若是，接着再向左右进行扩大，看是否为回文子串。
// 	例如
// 给出:dabbac
//    ------>
//    第一步，取得下标为0的数据，为d。
//    第二步，取得d的下一个下标1的数据为a,看a是否和d相等，不相等进行第三步。
//    第三步，看d的前后一个下标和后一个下标是否越界，是放弃。
//    ------->
//    第一步，取得下标为1的数据，为a。
//    第二步，取得a的下一个下标为2的数据，为b,看b是否和a相等，不相等进行第三步，
//    第三步，看a的前后一个下标和后一个下标是否越界，否，进行第四步。
//    第四步，看a的前后下标数值d,b是否相等，不相等放弃。
//    ------->
//    第一步，取得下标为2的数据，为b。
//    第二步，取得b的下一个下标为3的数据，为b,看b是否和b相等，相等，再重复第二步，进行随后的比较，将相等的随后与下标2的数据相等的个数记录数值为1，直到不相等位置，执行三步。
//    第三步，看bb的前后一个下标和后一个下标是否越界，否，进行第四步。
//    第四步，看bb的前后下标数值a,a是否相等，相等进行最大回文字符串的统计，和第一个b的下标的记录。
//    第五步，看abba的前后一个下标和后一个下标是否越界，否，进行第四步。
//    第六步，看abba的前后下标数值d,c是否相等，不相等放弃。
//    ---------------->最后求得的子串为abba
//    代码：
//    执行时间为：60ms

class Solution {
public:
	string longestPalindrome(string s) {
		int nLongest = 0;    //The maximum of palindromic
		int nMaxSameNum = 0;

		int nLongestIndex = 0;
		int nNum = s.size();
		int i = 0;

		int nFirst = 0;     //The first data of palindromic(subscript)
		int nEnd = 0;       //The end data of palindromic(subscript)
		int nLong = 0;     //The num of palindromic
		int nSameNum = 0;  //Used to mark a value equal to the value followed by i
		for(i = 0; i < nNum; i++)
		{
			nLong = 1;
			nFirst = i -1;
			nEnd = i + 1;
			nSameNum = 0;
			while((nNum != nEnd) && (s[i] == s[nEnd]))
			{
				nEnd++; 
				nSameNum++;
			}

			while((-1 != nFirst) && (nNum != nEnd))
			{
				if(s[nFirst] != s[nEnd])
				{
					break;
				}

				//Look to both sides
				nLong += 2; 
				nFirst--;
				nEnd++;
			}

			nLong += nSameNum;
			if(nLong > nLongest)
			{
				nLongest = nLong;
				nLongestIndex = i;
				nMaxSameNum = nSameNum;
			}
		}

		int npalindromicFirst = nLongestIndex - (nLongest -1 - nMaxSameNum) / 2;
		string strRes = s.assign(s, npalindromicFirst, nLongest);    

		return strRes;

	}

};