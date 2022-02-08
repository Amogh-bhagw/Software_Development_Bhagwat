/**
 * @file r_local_simulator_2.h
 *
 * @copyright 2020 Amogh Bhagwat, All rights reserved.
 */
#ifndef SRC_R_LOCAL_SIMULATOR_2_H_
#define SRC_R_LOCAL_SIMULATOR_2_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <string>
#include "src/simulator.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for rLocalSimulator2
 *
 * This class helps run the regression test
 * my_regression_driver. It works just
 * like the bus simulator instead it does it
 * without needing the visuals.
 * This test runs the route of
 * East&West bank dorms and East&St.Paul dorms.
 */
class rLocalSimulator2 : public Simulator {
 public:
  /**
   * @brief Starts the local simulator
   *
   * This sets up the local simulator
   * with the given data
   */
  bool Start() override;
  /**
   * @brief Updates the neccesary classes
   *
   * This just updates everything that needs
   * to be updated. Think of this as the
   * update function in vis_sim. It
   * updates the busses, the passengers, routes,
   * and stops.
   */
  bool Update() override;

 private:
  /**
   * @brief keeps track how how many busses.
   */
  std::vector<int> bus_counters_;
  /**
   * @brief keeps track when bus was started.
   */
  std::vector<int> bus_start_timings_;
  /**
   * @brief keeps track of the time since the last bus was created.
   */
  std::vector<int> time_since_last_bus_generation_;
  /**
   * @brief keeps track of how long the simulation has been running.
   */
  int simulation_time_elapsed_;
};

#endif  // SRC_R_LOCAL_SIMULATOR_2_H_
