// 题目地址：https://leetcode.com/problems/median-of-two-sorted-arrays/
// 题目内容：
// 	There are two sorted arrays nums1 and nums2 of size m and n respectively. 
// 	Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
// 	题目翻译：
// 
// 	有两个已排序数组nums1和nums2大小m和n分别为。求两个已排序数组的中位数。总的运行时间复杂度应该是O（log（m + n））。
// 	题目分析：
// 
// 	对于时间复杂度是log的要求，一般要用到分治的思想。
// 
// 	一：
// 	对于此问题，最简单和容易想的方法是将nums1和nums2两个数组排序合并成一个数组后再进行求得中位数，而此时的时间复杂度是O(m+n)，不符合要求。
// 	代码：
// 	执行时间为：48ms
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

// 二：
// 	用二分的思路去做，感觉有些麻烦。求两个有序数组中的第 K 大数，这样转换一下问题的角度，比较好做。
// 	若要找K，可以可以采用类似“二分查找”的方法进行查找。
// 	例如：假设数组sum1和sum2的元素个数都大于k/2，随后将sum1[k/2-1]和sum2[k/2-1]个元素进行比较，
// 	会产生一下三种情况：
// 	sum1[k/2-1] == sum2[k/2-1]；
// 	sum1[k/2-1] > sum2[k/2-1]；
// 	sum1[k/2-1] < sum2[k/2-1]；
// 	当 sum1[k/2-1] < sum2[k/2-1]时，说明sum1[0]到sum1[k/2-1]肯定小于sum1和sum2排序后的数组k位置的数据。
// 	因此，可以将sum1数组中这k个元素去掉。
// 	当 sum1[k/2-1] > sum2[k/2-1]时，说明sum2[0]到sum2[k/2-1]肯定小于sum1和sum2排序后的数组k位置的数据。
// 	因此，可以将sum2数组中这k个元素去掉。
// 	当 sum1[k/2-1] = sum2[k/2-1]时，说明找到了第k个元素，即sum1[k/2-1]或sum2[k/2-1]。
// 	代码：
// 	执行时间为：44ms
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

// 三：
// 	采用直接进行查中位数查找的化可以用类似于二分查找的方法。
// 	首先在一个较大的数组中取得中间值，在交小的数组中查找中级值要插入的位置。
// 	例如A{1,3,5}，B{2,4}，较大的数组是A中级值的位置为Mid=1， 在B中要插入的位置是pose=1，这是在数组{1,2,3,4,5}中的位置刚好是Mid+Pose=2，即为所求
// 	若Mid+Pose==（m+n）/2,中位数为A[Mid]。
// 	若Mid+Pose<(m+n)/2,则将重新在A{Mid+1， High},和B{Pose, High}中递归查找。
// 	若Mid+Pose>(m+n)/2,则将重新在A{Low， Mid - 1},和B{Low ,Pose - 1}中递归查找。
// 	代码：
// 	执行时间为：44ms
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

	//在一个有序数组中，用类似二分查找的方法，找到key或最趋近key要插入的最低位置
	int binarySearch(int *pnums, int low, int high, int key)
	{//返回key值的位置要么相等，要么一定比key值大
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

	//当两个数组都不为零是要找的中位数,且m>n
	double findMedianSortedArraysNotZore(int *pnums1, int m, int lowNum1, int highNum1, int *pnums2, int n, int lowNum2, int highNum2) 
	{  
		int nMid = (highNum1 + lowNum1) / 2;//取得pNums1的中间值下标
		int nPose = binarySearch(pnums2, lowNum2, highNum2, pnums1[nMid]);//pNums1的中间值,应该在pnums2中插入的位置最低值下标
		int nNum = nMid + nPose;//此时为key要插入的位置例如：pnums1={1,3,5},pnums2={2,4},则nMid=1,nPose=1,所以key在数组{1,2,3,4,5}中的2位置

		if(nNum == (m+n)/2)
		{//若两者想到说明nNum刚好是合并后数组的中间位置
			if((m+n)&1)
			{//整体为奇数
				return pnums1[nMid];
			}
			else
			{//整体若为偶数，则要找到nMid的前一个数
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
		{//若小于，将lowNum1移动到pnums1的中间点的下一位,而将pNums2的lowNum1放到nPose的位置，进行新的迭代查找
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