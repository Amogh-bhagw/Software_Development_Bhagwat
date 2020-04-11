/**
 * @file visualization_simulator.h
 *
 * @copyright 2020 Amogh Bhagwat, All rights reserved.
 */
#ifndef WEB_VISUALIZATION_SIMULATOR_H_
#define WEB_VISUALIZATION_SIMULATOR_H_

#include <vector>
#include <list>
#include <iostream>
#include <string>

#include "web_code/web/web_interface.h"
#include "src/config_manager.h"
#include "src/IObservable.h"
#include "src/IObserver.h"

class Route;
class Bus;
class Stop;

class VisualizationSimulator {
 public:
  VisualizationSimulator(WebInterface*, ConfigManager*);
  ~VisualizationSimulator();

  void Start(const std::vector<int>&, const int&);
  void Update();

  /**
   * @brief Resumes or pauses the sim.
   * Everytime the pause button is pressed
   * the bool value ispaused switchs to
   * true if the sim is already paused
   * false if the sim is running.
   * The ispaused variable is then
   * used in the Update() function.
   */
  void TogglePause();
  /**
   * @brief Calls ClearObservers on all busses.
   * We iterate through the busses_
   * vector and call ClearObservers
   * because we want to add a new observer
   */
  void ClearListeners();
  /**
   * @brief Calls RegisterObserver on the bus id passed in.
   *
   * We iterate through the busses_ vector
   * until we find the matching id, then
   * we call the RegisterObserver method with the observer
   * input passed in.
   */
  void AddListener(std::string * id, IObserver * observer);

 private:
  WebInterface* webInterface_;
  ConfigManager* configManager_;

  std::vector<int> busStartTimings_;
  std::vector<int> timeSinceLastBus_;
  int numTimeSteps_;
  int simulationTimeElapsed_;

  std::vector<Route *> prototypeRoutes_;
  std::vector<Bus *> busses_;

  bool ispaused = false;

  int busId = 1000;
};

#endif  // WEB_VISUALIZATION_SIMULATOR_H_
