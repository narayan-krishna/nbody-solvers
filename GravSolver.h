#ifndef SOLVER_H_
#define SOLVER_H_

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>

#include "Printing.h"

#define X 0
#define Y 1

class GravSolver {
  private:

    const float grav = 6.673 * pow(10, -11);

    int total_timesteps;
    int output_timestep;
    int particle_count;
    std::string file_path;

    void read_file();
    const void test_print();

    // particle number -> vector index
    // particle f,v,p x -> vector [0]
    // particle f,v,p y -> vector [1]

    // state values (the current state of simulation)
    std::vector<std::vector<float>> state_pos; 
    std::vector<std::vector<float>> state_vel;
    std::vector<float> state_mass;

    std::vector<std::vector<float>> forces;

    // buffer values (working buffer)
    // std::vector<std::vector<float>> buffer_pos; 
    // std::vector<std::vector<float>> buffer_vel;


    inline void compute_total_force_full(int particle_id);
    inline void compute_total_force_perf(int particle_id);
    inline void compute_acceleration (int particle_id);
    inline void compute_position (int particle_id);
    inline void compute_velocity (int particle_id);

    const void render_state();

  public:
    GravSolver(std::string file_path, int total_timesteps);
    ~GravSolver();

    void solve();
};

#endif

