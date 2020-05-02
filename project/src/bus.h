/**
 * @file bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_H_
#define SRC_BUS_H_

#include <iostream>
#include <list>
#include <string>

#include "src/IObservable.h"
#include "src/data_structs.h"
#include "src/passenger.h"
#include "src/passenger_loader.h"
#include "src/passenger_unloader.h"
#include "src/route.h"
#include "src/stop.h"



class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;

/**
 * @brief The main class for bus
 * The bus inherits from IObsevable
 *
 */
class Bus : public IObservable<BusData*> {
 public:
  Bus(std::string name, Route * out, Route * in, int capacity = 60,
      double speed = 1);
  bool IsTripComplete();

  /**
   * @brief Loading a Passenger
   * The function lets you know if
   * the passenger you passed in
   * has been loaded on the bus.
   *
   * @param passenger The passenger you want to load
   *
   * @return True if loaded or False if not.
   */
  bool LoadPassenger(Passenger *);  // returning revenue delta
  bool Move();
  void Update();
  virtual void Report(std::ostream&);

  // Vis Getters
  void UpdateBusData();
  BusData GetBusData() const;
  std::string GetName() const { return name_; }
  Stop * GetNextStop() const { return next_stop_; }
  size_t GetNumPassengers() const { return passengers_.size(); }
  int GetCapacity() const { return passenger_max_capacity_; }
  int GetTotalNumberPass() { return total_passenger;}

  /**
   * @brief Set the color for bus
   * The function lets you
   * set the color of the bus
   *
   * @param r red color
   * @param b blue color
   * @param g green color
   * @param a alpha color
   *
   * @return True if loaded or False if not.
   */
  void SetColor(int r, int g, int b, int a);
  /*
   * @brief Get the color struct for the bus
   *
   * The function returns the current busses color
   * struct
   */
  Color GetColor();

 protected:  // Might need to change back to private depanding on Piazza post
  int UnloadPassengers();  // returning revenue delta
  // bool Refuel();
  PassengerUnloader * unloader_;
  PassengerLoader * loader_;
  std::list<Passenger *> passengers_;
  int passenger_max_capacity_;
  // double revenue_; // revenue collected from passengers, doesn't include
                      // passengers who pay on deboard
  // double fuel_;   // may not be necessary for our simulation
  // double max_fuel_;
  std::string name_;
  double speed_;  // could also be called "distance travelled in one time step"
  Route * outgoing_route_;
  Route * incoming_route_;
  double distance_remaining_;  // when negative?, unload/load procedure occurs
                              // AND next stop set
  Stop * next_stop_;
  // bool trip_complete_;  // [DERIVED data] when BOTH routes are at end, trip
  // is complete
  // Vis data for bus
  BusData bus_data_;
  int total_passenger = 0;
};
#endif  // SRC_BUS_H_
