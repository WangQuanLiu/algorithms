/*

给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例:


输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
	map<char, vector<string>>m;
    vector<string> letterCombinations(string digits) {
       m['1'] = vector<string>{ "" };
		m['2'] = vector<string>{ "a","b","c" };
		m['3'] = vector<string>{ "d","e","f" };
		m['4'] = vector<string>{ "g","h","i" };
		m['5'] = vector<string>{ "j","k","l" };
		m['6'] = vector<string>{ "m","n","o" };
		m['7'] = vector<string>{ "p","q","r","s" };
		m['8'] = vector<string>{ "t","u","v" };
		m['9'] = vector<string>{ "w","x","y","z" };
		vector<string>vec{""};
		vector<string >t{""};
		int i, j, k;
		for (i = 0; i < digits.size(); i++) {
			vector<string>temp = m[digits[i]];
			vector<string>m1;
			for (k = 0; k < temp.size(); k++) {
				for (j = 0; j < vec.size(); j++) {
					m1.push_back(vec[j] + temp[k]);
				}

			}
			vec = m1;
		}
		if (vec == t)return vector<string>{};
		return vec;
    }
};
