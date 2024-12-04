#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


void part_one() {
  std::ifstream f("input-01-2.txt");
  std::string str;
  int a,b;
  std::vector<int> first;
  std::vector<int> second;
  while(f >> a >> b) {
    // std::cout << "read " << a << "," << b << std::endl;
    first.push_back(a);
    second.push_back(b);
  }
  std::sort(first.begin(), first.end());  
  std::sort(second.begin(), second.end());

  int sum = 0;
  for (int i=0; i < first.size(); i++) {
    sum += abs(first[i] - second[i]);
  }
  std::cout << sum << std::endl;
}

void part_two() {
  std::ifstream f("input-01-2.txt");
  std::string str;
  int a,b;
  std::vector<int> first;
  std::vector<int> second;
  while(f >> a >> b) {
    // std::cout << "read " << a << "," << b << std::endl;
    first.push_back(a);
    second.push_back(b);
  }
  std::sort(second.begin(), second.end());
  int previous = -1;
  int cur_count = 0;
  std::unordered_map<int, int> counts;
  int nmb;
  for (int nmb : second) {
    if (nmb != previous) {
      if (previous != -1) {
        counts[previous] = cur_count;
      }
      cur_count = 1;
      previous = nmb;
    } else {
      cur_count += 1;
    }
  }
  counts[previous] = cur_count;
  for (auto kv : counts) {
    std::cout << kv.first << ": " << kv.second << std::endl;
  }
  int sum = 0;
  for (int nmb : first) {
    sum += nmb * counts[nmb];
  }
  std::cout << sum << std::endl;

}


int main(int argc, char * argv[]) {
  // part_one();
  part_two();
}
