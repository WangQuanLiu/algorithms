/*给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。

请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。



示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0

示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是(2 + 3) / 2 = 2.5

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {

public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int total = (nums1.size() + nums2.size()), i, j;//总计数量
		bool flag = total % 2;//数组奇偶
		int posi = flag ? (total / 2) + 1 : total / 2;//位置
		vector<int>nums3;
		for (i = 0, j = 0; i<nums1.size() && j<nums2.size();) {
			if (nums1[i]<nums2[j])
			{
				nums3.push_back(nums1[i]);
				i++;
			}
			else {
				nums3.push_back(nums2[j]);
				j++;
			}
			if (nums3.size() >= posi + 1)break;
		}
		if (nums3.size()<posi + 1) {
			if (i<nums1.size()) {
				while (i<nums1.size())
					nums3.push_back(nums1[i++]);
			}
			else {
				while (j<nums2.size())
					nums3.push_back(nums2[j++]);
			}
		}

		return flag ? nums3[posi - 1] : ((double)nums3[posi - 1] + nums3[posi]) / 2;
	}

};
