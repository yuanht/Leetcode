// ��Ŀ��ַ��https://leetcode.com/problems/longest-palindromic-substring/
// ��Ŀ���ݣ�
// 	Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
// 	��Ŀ���룺
// 
// 	����һ���ַ���S���ҵ�S�����Ļ����Ӵ�������Լ�������ַ���S����󳤶�Ϊ1000,����ֻ����Ψһ���������Ӵ���
// 
// 	��Ŀ������
// 
// 	����������Ŀ��������forѭ������S�е�ÿ���ַ��������Ҳ��ң����Ƿ������ҵ������ǹ��ɻ����Ӵ������ǣ������������ҽ������󣬿��Ƿ�Ϊ�����Ӵ���
// 	����
// ����:dabbac
//    ------>
//    ��һ����ȡ���±�Ϊ0�����ݣ�Ϊd��
//    �ڶ�����ȡ��d����һ���±�1������Ϊa,��a�Ƿ��d��ȣ�����Ƚ��е�������
//    ����������d��ǰ��һ���±�ͺ�һ���±��Ƿ�Խ�磬�Ƿ�����
//    ------->
//    ��һ����ȡ���±�Ϊ1�����ݣ�Ϊa��
//    �ڶ�����ȡ��a����һ���±�Ϊ2�����ݣ�Ϊb,��b�Ƿ��a��ȣ�����Ƚ��е�������
//    ����������a��ǰ��һ���±�ͺ�һ���±��Ƿ�Խ�磬�񣬽��е��Ĳ���
//    ���Ĳ�����a��ǰ���±���ֵd,b�Ƿ���ȣ�����ȷ�����
//    ------->
//    ��һ����ȡ���±�Ϊ2�����ݣ�Ϊb��
//    �ڶ�����ȡ��b����һ���±�Ϊ3�����ݣ�Ϊb,��b�Ƿ��b��ȣ���ȣ����ظ��ڶ������������ıȽϣ�����ȵ�������±�2��������ȵĸ�����¼��ֵΪ1��ֱ�������λ�ã�ִ��������
//    ����������bb��ǰ��һ���±�ͺ�һ���±��Ƿ�Խ�磬�񣬽��е��Ĳ���
//    ���Ĳ�����bb��ǰ���±���ֵa,a�Ƿ���ȣ���Ƚ����������ַ�����ͳ�ƣ��͵�һ��b���±�ļ�¼��
//    ���岽����abba��ǰ��һ���±�ͺ�һ���±��Ƿ�Խ�磬�񣬽��е��Ĳ���
//    ����������abba��ǰ���±���ֵd,c�Ƿ���ȣ�����ȷ�����
//    ---------------->�����õ��Ӵ�Ϊabba
//    ���룺
//    ִ��ʱ��Ϊ��60ms

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