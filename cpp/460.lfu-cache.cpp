#include<iostream>
#include<unordered_map>
#include <list>

using namespace std;

class LFUCache {
 public:
  LFUCache(int capacity) : capacity(capacity) {
    min_freq = 0;
    size = 0;
  }

  int get(int key) {
    if (capacity <= 0) return -1;
    if (vals.count(key) == 0)
      return -1;
    upgrade(key);
    return vals[key].first;
  }

  void put(int key, int value) {
    if (capacity <= 0) return;
    // already exist
    if (vals.count(key) != 0) {
      vals[key].first = value;
      upgrade(key);
      return;
    }
    // new entry
    if (size >= capacity) {
      // remove one item first
      int key = freq[min_freq].front();
      freq[min_freq].pop_front();
      if (freq[min_freq].size() == 0) {
        freq.erase(min_freq);
      }
      pos.erase(key);
      vals.erase(key);
      size--;
    }
    // add new one
    size++;
    min_freq = 1;
    vals[key] = {value, 1};
    if (freq.count(1) == 0) {
      freq[1] = list<int>();
    }
    freq[1].push_back(key);
    auto iter = freq[1].end();
    pos[key] = --iter;
  }

 private:
  int capacity;
  int min_freq;
  int size;
  unordered_map<int, pair<int, int>> vals;   // this is key -> {value, frequency}
  unordered_map<int, list<int>::iterator> pos;   // this is key -> list position
  unordered_map<int, list<int>> freq;   // this is frequency -> {all keys}

  void upgrade(int key) {
    int f = vals[key].second;
    // delete the old freq
    freq[f].erase(pos[key]);
    if (freq[f].size() == 0) {
      freq.erase(f);
      if (f == min_freq)
        min_freq++;
    }
    // insert the new freq
    if (freq.count(f + 1) == 0) {
      freq[f + 1] = list<int>();
    }
    freq[f + 1].push_back(key);
    // update freq and iterator
    vals[key].second++;
    auto iter = freq[f + 1].end();
    pos[key] = --iter;
  }

};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main() {
  LFUCache cache = LFUCache(2);
//  cout << cache.get(1) << endl;
  cache.put(1, 1);
  cache.put(2, 2);
  // cache.get(1);       // returns 1
  cout << cache.get(1) << endl;
  cache.put(3, 3);    // evicts key 2
//  cache.get(2);       // returns -1 (not found)
//  cache.get(3);       // returns 3.
  cout << cache.get(2) << endl;
  cout << cache.get(3) << endl;
  cache.put(4, 4);    // evicts key 1.
//  cache.get(1);       // returns -1 (not found)
//  cache.get(3);       // returns 3
//  cache.get(4);       // returns 4
  cout << cache.get(1) << endl;
  cout << cache.get(3) << endl;
  cout << cache.get(4) << endl;
}