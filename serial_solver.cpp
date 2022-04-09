/* an n-body solver to simulation motion of planets and stars */

#include <iostream>
#include <vector>
#include <string>

struct Particle {
  int x;
  int y;
};

class Solver {
  private:
    int total_timesteps;
    int output_timestep;
    std::string file_path;

    std::vector<std::vector<Particle>> pos; 
    std::vector<std::vector<int>> force;
    std::vector<std::vector<int>> vel;

    void render_state();

  public:
    Solver(std::string file_path, int total_timesteps);
    ~Solver();

    void solve();
};

void Solver::render_state() {
  //print state to output
}

Solver::Solver(std::string file_path, int total_timesteps) {
  this->file_path = file_path;
  this->total_timesteps = total_timesteps;
};

Solver::~Solver(){};

void Solver::solve(){
  for (int timestep = 0; timestep < total_timesteps; timestep ++) {
    if (timestep == output_timestep) {
      /* render to out */
      render_state();
    }

    int particle_count = pos.size();

    for (int i = 0; i < particle_count; i++) {
      /* compute total force */
    }

    for (int j = 0; j < particle_count; j++) {
      /* compute position and velocity */
    }

    render_state();
  }
}

int main () {

}
