// ��Ŀ��ַ��https://leetcode.com/problems/median-of-two-sorted-arrays/
// ��Ŀ���ݣ�
// 	There are two sorted arrays nums1 and nums2 of size m and n respectively. 
// 	Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
// 	��Ŀ���룺
// 
// 	����������������nums1��nums2��Сm��n�ֱ�Ϊ���������������������λ�����ܵ�����ʱ�临�Ӷ�Ӧ����O��log��m + n������
// 	��Ŀ������
// 
// 	����ʱ�临�Ӷ���log��Ҫ��һ��Ҫ�õ����ε�˼�롣
// 
// 	һ��
// 	���ڴ����⣬��򵥺�������ķ����ǽ�nums1��nums2������������ϲ���һ��������ٽ��������λ��������ʱ��ʱ�临�Ӷ���O(m+n)��������Ҫ��
// 	���룺
// 	ִ��ʱ��Ϊ��48ms
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
	{
		vector<int> nums;

		int m = nums1.size();
		int n = nums2.size(); 
		int i = 0;
		int j = 0;
		//Merge into one array 
		while((i < m) || (j < n))
		{
			if(i == m)
			{
				nums.push_back(nums2[j++]);
				continue;
			}
			if(j == n)
			{
				nums.push_back(nums1[i++]);
				continue;
			}

			if (nums1[i] > nums2[j])
			{
				nums.push_back(nums2[j++]);
			}
			else
			{
				nums.push_back(nums1[i++]);   
			}
		}
		//To find the median 
		if (((1 == (n + m)%2)
		{//Determine the parity 
			return nums[(n+m)/2];  
		}
		else 
		{
			return (nums[(n+m)/2 - 1] + nums[(n+m)/2]) / 2.0;  
		}
	}
};

// ����
// 	�ö��ֵ�˼·ȥ�����о���Щ�鷳�����������������еĵ� K ����������ת��һ������ĽǶȣ��ȽϺ�����
// 	��Ҫ��K�����Կ��Բ������ơ����ֲ��ҡ��ķ������в��ҡ�
// 	���磺��������sum1��sum2��Ԫ�ظ���������k/2�����sum1[k/2-1]��sum2[k/2-1]��Ԫ�ؽ��бȽϣ�
// 	�����һ�����������
// 	sum1[k/2-1] == sum2[k/2-1]��
// 	sum1[k/2-1] > sum2[k/2-1]��
// 	sum1[k/2-1] < sum2[k/2-1]��
// 	�� sum1[k/2-1] < sum2[k/2-1]ʱ��˵��sum1[0]��sum1[k/2-1]�϶�С��sum1��sum2����������kλ�õ����ݡ�
// 	��ˣ����Խ�sum1��������k��Ԫ��ȥ����
// 	�� sum1[k/2-1] > sum2[k/2-1]ʱ��˵��sum2[0]��sum2[k/2-1]�϶�С��sum1��sum2����������kλ�õ����ݡ�
// 	��ˣ����Խ�sum2��������k��Ԫ��ȥ����
// 	�� sum1[k/2-1] = sum2[k/2-1]ʱ��˵���ҵ��˵�k��Ԫ�أ���sum1[k/2-1]��sum2[k/2-1]��
// 	���룺
// 	ִ��ʱ��Ϊ��44ms
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
	{
		int m = nums1.size();
		int n = nums2.size(); 
		if(!(m||n))
		{
			return 0.0;
		}
		if ( 0 == m )
		{
			return ((n&1) ? nums2[n/2] : (nums2[n/2-1] + nums2[n/2])/2.0); 
		}
		if ( 0 == n )
		{
			return ((m&2) ? nums1[m/2] : (nums1[m/2-1] +nums1[m/2])/2.0);  
		}

		if ((n + m)&1)
		{
			return findKthSortedArrays(&nums1[0], m, &nums2[0], n, (n + m) / 2 + 1);
		}
		else
		{
			return (findKthSortedArrays(&nums1[0], m, &nums2[0], n, (n + m) / 2 + 1) +  findKthSortedArrays(&nums1[0], m, &nums2[0], n, (n + m) / 2)) / 2.0;  
		}
	}
private:
	double findKthSortedArrays(int *pnums1, int m, int *pnums2, int n, int k) 
	{  
		if (m < n) 
		{  
			swap(m, n);  
			swap(pnums1, pnums2);  
		}  
		if (n == 0)
		{
			return pnums1[k - 1];   
		}
		if (k == 1)
		{
			return min(pnums1[0], pnums2[0]);
		}
		int pb = min(k / 2, n), pa = k - pb;  
		if (pnums1[pa - 1] > pnums2[pb - 1]) 
		{
			return findKthSortedArrays(pnums1, m, pnums2 + pb, n - pb, k - pb); 
		}
		else if (pnums1[pa - 1] < pnums2[pb - 1]) 
		{
			return findKthSortedArrays(pnums1 + pa, m - pa, pnums2, n, k - pa);   
		}
		else 
		{
			return pnums1[pa - 1];  
		}
	}  
};

// ����
// 	����ֱ�ӽ��в���λ�����ҵĻ������������ڶ��ֲ��ҵķ�����
// 	������һ���ϴ��������ȡ���м�ֵ���ڽ�С�������в����м�ֵҪ�����λ�á�
// 	����A{1,3,5}��B{2,4}���ϴ��������A�м�ֵ��λ��ΪMid=1�� ��B��Ҫ�����λ����pose=1������������{1,2,3,4,5}�е�λ�øպ���Mid+Pose=2����Ϊ����
// 	��Mid+Pose==��m+n��/2,��λ��ΪA[Mid]��
// 	��Mid+Pose<(m+n)/2,��������A{Mid+1�� High},��B{Pose, High}�еݹ���ҡ�
// 	��Mid+Pose>(m+n)/2,��������A{Low�� Mid - 1},��B{Low ,Pose - 1}�еݹ���ҡ�
// 	���룺
// 	ִ��ʱ��Ϊ��44ms
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
	{
		int m = nums1.size();
		int n = nums2.size(); 

		if(!(m||n))
		{
			return 0.0;
		}

		if ( 0 == m )
		{
			return ((n&1) ? nums2[n/2] : (nums2[n/2-1] + nums2[n/2])/2.0); 
		}
		if ( 0 == n )
		{
			return ((m&1) ? nums1[m/2] : (nums1[m/2-1] +nums1[m/2])/2.0);  
		}
		if ( m > n )
		{
			return findMedianSortedArraysNotZore(&nums1[0], m, 0, m-1, &nums2[0], n, 0, n-1);
		}
		else
		{
			return findMedianSortedArraysNotZore(&nums2[0], n, 0, n-1, &nums1[0], m, 0, m-1);
		}

	}
private:

	//��һ�����������У������ƶ��ֲ��ҵķ������ҵ�key��������keyҪ��������λ��
	int binarySearch(int *pnums, int low, int high, int key)
	{//����keyֵ��λ��Ҫô��ȣ�Ҫôһ����keyֵ��
		while(low<=high)
		{
			int mid = low + (high - low)/2;
			if (key == pnums[mid]) return mid;
			if (key > pnums[mid])
			{
				low = mid + 1;
			}
			else 
			{
				high = mid -1;
			}
		}
		return low;
	}

	//���������鶼��Ϊ����Ҫ�ҵ���λ��,��m>n
	double findMedianSortedArraysNotZore(int *pnums1, int m, int lowNum1, int highNum1, int *pnums2, int n, int lowNum2, int highNum2) 
	{  
		int nMid = (highNum1 + lowNum1) / 2;//ȡ��pNums1���м�ֵ�±�
		int nPose = binarySearch(pnums2, lowNum2, highNum2, pnums1[nMid]);//pNums1���м�ֵ,Ӧ����pnums2�в����λ�����ֵ�±�
		int nNum = nMid + nPose;//��ʱΪkeyҪ�����λ�����磺pnums1={1,3,5},pnums2={2,4},��nMid=1,nPose=1,����key������{1,2,3,4,5}�е�2λ��

		if(nNum == (m+n)/2)
		{//�������뵽˵��nNum�պ��Ǻϲ���������м�λ��
			if((m+n)&1)
			{//����Ϊ����
				return pnums1[nMid];
			}
			else
			{//������Ϊż������Ҫ�ҵ�nMid��ǰһ����
				int nPre = 0;
				if((nMid > 0)&&(nPose > 0))
				{
					nPre = max(pnums1[nMid - 1], pnums2[nPose - 1]);
				}
				else if(nMid > 0)
				{
					nPre = pnums1[nMid - 1];
				}
				else if (nPose > 0)
				{
					nPre =  pnums2[nPose - 1];
				}

				return (pnums1[nMid] + nPre)/2.0;
			}
		}

		if(nNum < (m+n)/2)
		{//��С�ڣ���lowNum1�ƶ���pnums1���м�����һλ,����pNums2��lowNum1�ŵ�nPose��λ�ã������µĵ�������
			lowNum1 = nMid + 1;
			lowNum2 = nPose;
		}
		else
		{
			highNum1 = nMid - 1;
			highNum2 = nPose - 1;
		}

		if((highNum1 - lowNum1) > (highNum2 - lowNum2))
		{
			return findMedianSortedArraysNotZore(pnums1, m, lowNum1, highNum1, pnums2, n, lowNum2, highNum2);  
		}
		else
		{
			return findMedianSortedArraysNotZore(pnums2, n, lowNum2, highNum2, pnums1, m, lowNum1, highNum1);   
		}
	}  
};