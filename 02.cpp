#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>

std::vector<int> copy_sort(std::vector<int> vec) {
    std::sort(vec.begin(), vec.end());
    return vec;
}

std::vector<int> copy_rsort(std::vector<int> vec) {
  std::sort(vec.begin(), vec.end(), std::greater<int>());
  return vec;
}

bool check_line(std::vector<int> lista) {
  if (lista == copy_sort(lista)) {
    int previous = -1;
    for (int nmb : lista) {
      if (previous != -1) {
        if (previous >= nmb || nmb - previous > 3) {
          return false;
          
        }
      }
      previous = nmb;
    }
    return true;

  } else if (lista == copy_rsort(lista)) {
    int previous = -1;
    for (int nmb : lista) {
      if (previous != -1) {
        if (previous <= nmb || previous - nmb > 3) { 
          return false;
        }
      }
      previous = nmb;
    }
  return true;

  }
return false;
}

void part_one() {
  std::ifstream f("input-02-2.txt");
  std::string str_line;
  int sum = 0;
  while(getline(f, str_line)) {
  
    std::cout << str_line << std::endl;
    std::stringstream ss(str_line);
    int nmb;
    std::vector<int> lista;
    while(ss >> nmb) {
      lista.push_back(nmb);
    }
    if (check_line(lista)) {
      sum += 1;
    }

  }
std::cout << "sum: " << sum << std::endl;
  
}

void part_two() {
  std::ifstream f("input-02-2.txt");
  std::string str_line;
  int sum = 0;
  while(getline(f, str_line)) {
    std::stringstream ss(str_line);
    int nmb;
    std::vector<int> lista;
    while(ss >> nmb) {
      lista.push_back(nmb);
    }
    int i=0;
    bool trying = true;
    while (trying && i < lista.size()) {
      std::vector<int> vec;
      for (int j=0;j < lista.size();j++) {
        if (i!=j) {
          vec.push_back(lista[j]);
        }
      }
      if (check_line(vec)) {
        sum += 1;
        trying = false;
      }
      i++;
    }
  }
  std::cout << "sum: " << sum << std::endl;
}




int main(int argc, char* argv[]) {
  // part_one();
  part_two();
}
