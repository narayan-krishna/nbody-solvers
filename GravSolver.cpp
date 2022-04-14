#include "GravSolver.h"
#include "Printing.h"

GravSolver::GravSolver(std::string file_path, int total_timesteps) {
  this->file_path = file_path;
  this->total_timesteps = total_timesteps;

  read_file();
  test_print();
};

GravSolver::~GravSolver(){};

void GravSolver::read_file(){
    //open input stream
    std::ifstream input_stream (file_path);

    //check for file existence
    if (!input_stream.is_open()) {
        std::cerr << "coudn't find/open file..." << std::endl;
        exit(EXIT_FAILURE);
    }

    for(std::string line; getline(input_stream, line);) {
        if (line[0] == '#') continue; //skip commented lines
        if (line == "") continue; //skip empty lines

        std::stringstream ss(line); //open string stream
        std::string valid_line_segment; //segment being processed
        int count = 0; //segment processing directive

        // file formatting:
        //  line: px py vx vy m

        float px, py, vx, vy, m;

        //process line, divided by spaces into segments
        while(getline(ss, valid_line_segment, ' ')) {
            if (count == 0) px = (float)std::atof(valid_line_segment.c_str());
            if (count == 1) py = (float)std::atof(valid_line_segment.c_str());
            if (count == 2) vx = (float)std::atof(valid_line_segment.c_str());
            if (count == 3) vy = (float)std::atof(valid_line_segment.c_str());
            if (count == 4) m = (float)std::atof(valid_line_segment.c_str());
            count ++;
        }

        state_pos.push_back(std::vector<float>{px,py});
        state_vel.push_back(std::vector<float>{vx,vy});
        state_mass.push_back(m);
    }

    particle_count = state_mass.size();
    forces = std::vector<std::vector<float>> (particle_count, 
                                              std::vector<float> (2,0));

    input_stream.close(); //close input stream
}

const void GravSolver::test_print() {
  std::cout << "state pos" << std::endl;
  printing::std_print(state_pos);

  std::cout << "state vel" << std::endl;
  printing::std_print(state_vel);

  std::cout << "state mass" << std::endl;
  printing::std_print(state_mass);
}

void GravSolver::solve(){
  for (int timestep = 0; timestep < total_timesteps; timestep ++) {
    if (timestep == output_timestep || 1) {
      // render to out
      render_state();
    }

    //calculate forces on each particle
    for (int i = 0; i < particle_count; i++) {
      // compute total force
      compute_total_force_full(i);
    }

    for (int j = 0; j < particle_count; j++) {
      // compute position and velocity
      compute_position(j);
      compute_velocity(j);
    }
  }

  // render final timestep
  render_state();
  printing::std_print(forces);
}

// calculate the force of particle id in the x direction and they y direction
// NOTE: i.e. Fx = 3, Fy = 4 means that particle_id is being pushed 3 to right, 4 left
// PERF: this more force values than neccessary (newton's third law)

inline void GravSolver::compute_total_force_full(int particle_id) {
  // printing::marker("force");
  for (size_t k = 0; k < particle_count; k ++) {
    if (k != particle_id) {
      int x_diff = state_pos[particle_id][X] - state_pos[k][X];
      int y_diff = state_pos[particle_id][Y] - state_pos[k][Y];

      //distance between particles
      int dist = sqrt(x_diff * x_diff + y_diff * y_diff);
      int dist_cubed = dist*dist*dist;

      forces[particle_id][X] -= grav * (state_mass[particle_id])/dist_cubed * x_diff;
      forces[particle_id][Y] -= grav * (state_mass[particle_id])/dist_cubed * y_diff;
    }
  }
}

// TODO: implement computation of force
inline void GravSolver::compute_total_force_perf(int particle_id) {
  //for 
}

// TODO: implement acceleration computation
inline void GravSolver::compute_acceleration (int particle_id) {
}


inline void GravSolver::compute_position (int particle_id) {
}

inline void GravSolver::compute_velocity (int particle_id) {
}

const void GravSolver::render_state() {
  // print state to output
}
