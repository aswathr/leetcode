#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, vector<int>> numLocationMap;
        vector<int> vc;
        
        for(size_t i = 0; i < nums.size(); i++) {
            if (numLocationMap.find(nums[i]) != numLocationMap.end()) {
                numLocationMap[nums[i]].push_back(i);
            } else {
                vector<int> temp_vec;
                temp_vec.push_back(i);
                numLocationMap.insert(pair<int, vector<int>>(nums[i], temp_vec));
            }
        }

        for(auto i: numLocationMap) {
            int target1 = target - i.first;
            if(i.first == target1 && i.second.size() > 1) {
                vc.push_back(i.second[0]);
                vc.push_back(i.second[1]);
                break;
            } 
            if (numLocationMap.find(target1) != numLocationMap.end()) {
                vc.push_back(i.second[0]);
                vc.push_back(numLocationMap[target1][0]);
                break;
            }
        }
        return vc;
    }
};

int main() {
    vector<int> list;
    list.push_back(2);
    list.push_back(3);
    list.push_back(6);
    list.push_back(7);
    list.push_back(9);
    auto res = Solution().twoSum(list, 10);
    cout << res[0] << res[1];
}