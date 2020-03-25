/**
 * @file passenger_loader.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_PASSENGER_LOADER_H_
#define SRC_PASSENGER_LOADER_H_

#include <list>
#include "./passenger.h"

class PassengerLoader {
 public:
  // LoadPassenger returns true if a passenger is added, false otherwise.
  bool LoadPassenger(Passenger * new_passenger, int max_pass,
                    std::list<Passenger *> * passengers);
};
#endif  // SRC_PASSENGER_LOADER_H_
