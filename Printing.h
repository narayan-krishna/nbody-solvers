#ifndef PRINTING_H_
#define PRINTING_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

namespace printing {

  template <class T>
  inline const void marker(const T note) {
    std::cout << "reached ->" << note << std::endl;
  }

  template <class T>
  inline const void eval(const std::string label, const T val) {
    std::cout << label << " ->" << val << std::endl;
  }

  template <class T>
  inline const void std_print(const std::vector<T> &vec) {
    for(auto i : vec) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }

  //print 2d vectors
  template <class T>
  inline const void std_print(const std::vector<std::vector<T>> &vec) {
    for (auto sub_vec : vec) {
      for (auto i : sub_vec) {
        std::cout << i << " ";
      }
      std::cout << std::endl;
    }
  }

  template <class K, class V>
  inline const void std_print(const std::unordered_map<K,V> &map) {
    for (auto i : map) {
      std::cout << i->first << ", " << i->second << std::endl;
    }
    std::cout << std::endl;
  }

}

#endif // UTILS_PRINTING_H_
