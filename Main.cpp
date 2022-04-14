/* 
 * an n-body solver to simulation motion of planets and stars
 * we want to calculate the position and velocity of a body at any point in time
 *
*/

#ifndef MAIN_H_
#define MAIN_H_

#include "Printing.h"
#include "GravSolver.h"

#include <iostream>
#include <vector>
#include <string>

// command line arguments should be file path
int main (int argc, char **argv) {
  if (argc != 3) {
    std::cerr << "requires file path, timesteps as cmd line arg.\nexiting..." << std::endl;
    exit(EXIT_FAILURE);
  }

  // test printing
  // std::vector<int> x{1,2,3};
  // printing::std_print(x);
  //
  // std::vector<std::vector<int>> y{{1,2}, {1,2}, {1,3}};
  // printing::std_print(y);

  std::string file_path = argv[1];
  int total_timesteps = std::stoi(argv[2]);

  std::cout << "file name is: " << file_path << std::endl;
  std::cout << "total timesteps is: " << total_timesteps << std::endl;

  GravSolver s(file_path, total_timesteps);
  s.solve();

  return 0;
}

#endif
