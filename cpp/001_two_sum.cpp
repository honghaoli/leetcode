#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

// 1
class Solution {

public:

//vector<int> twoSum(vector<int> &nums, int target) {
//    for (int i = 0; i < nums.size(); i++) {
//        for (int j = i + 1; j < nums.size(); j++) {
//            if (nums[j] == target - nums[i]) {
//                return vector<int>{ i, j };
//            }
//        }
//    }
//  return vector<int>{};
//}

  // O(N) hash table version
  vector<int> twoSum(vector<int> &nums, int target) {
      unordered_map<int, int> map;
      for (int i = 0; i < nums.size(); i++) {
          auto search = map.find(target - nums[i]);
          if(search != map.end()) {
              return vector<int>{search->second, i};
          }
          map[nums[i]] = i;
      }
      return vector<int>{};
  }

};

// 7
int reverse(int x) {
    int y = 0;
    int x_copy = x;
    while(abs(x_copy) > 0) {
        int new_y = y * 10 + x_copy % 10;
        printf("old y: %d,  new_y: %d\n", y, new_y);
        // overflow
        if ((new_y - x_copy % 10 ) / 10 != y ) {
//        if ((new_y < y && y > 0) || (new_y > y && y < 0)) {
          printf("Overflow!!! old y: %d,  new_y: %d\n", y, new_y);
            return 0;
        }
        y = new_y;
        x_copy = x_copy / 10;
    }
    return y;
}

// 9
bool isPalindrome(int x) {
    if (x == 0)
        return true;
    else if (x < 0 || x % 10 == 0)
        return false;
    int rev = 0;
    while(x > 0) {
        if (rev == x || rev == x / 10)
            return true;
        rev = rev * 10 + x % 10;
        x = x / 10;
    }
    return false;
}

// 13
int romanToInt(string s) {
    map<char, int> dict = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000} };
    int pre=0;
    int num=0;
    char c;
    int result = 0;
    for(int i=0; i<s.length(); ++i) {
        pre = num;
        c = s[i];
        num = dict[c];
        result += num;
        if(num == 10 * pre || num == 5 * pre) {
            result = result - pre - pre;
        }
    }
    return result;
}


template <typename T>
void printVector(vector<T> vec) {
    for(auto &v : vec) {
        std::cout << v << " ";
    }
    std::cout << endl;
}

int unitTest(vector<int> nums, int target, vector<int> expected) {
    Solution s = Solution();
    vector<int> result = s.twoSum(nums, target);
    // printf("%s\n", expected == result ? "True" : "False");
    if (expected != result) {
        printf("============ Test failed!!! =============\n");
        printf("input numbers:\n");
        printVector(nums);
        printf("target: %d\n", target);
        printf("expected result:\n");
        printVector(expected);
        printf("your result:\n");
        printVector(result);
        printf("========================================\n");
        return 1;
    }
    return 0;
}

void simpleTest() {
    int fail_index = 0;
    fail_index += unitTest({3, 2, 4}, 6, {1, 2});
    fail_index += unitTest({1, 2, 4, 6, 10, 23, 11, 5, 8, 9}, 21, {4, 6});
    fail_index += unitTest({-1, 1, 0, 2, 3}, 0, {0, 1});
    if (fail_index == 0) {
        printf("Congratulation! Basic Test passed!\n");
    }
}

int main() {

    simpleTest();
    // Solution s = Solution();
    // vector<int> nums = vector<int>{3,2,4};
    // int target = 6;
    // auto result = s.twoSum(nums, target);
    // for (auto &r : result) {
        // printf("%d\t", nums[r]);
    // }

//    int test = 1534236469;
//    int result = reverse(test);
//    printf("input: %d, result: %d", test, result);

//  printf("isPalindrome: %s", isPalindrome(101) ? "true" : "false");

    // string s = "CM";
    // printf("Roman: %s to Int: %d", s.c_str(), romanToInt(s));

}



