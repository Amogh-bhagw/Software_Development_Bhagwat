/**
 * @file bus_factory.cc
 *
 * @copyright 2020 Amogh Bhagwat, All rights reserved.
 */
#include <vector>
#include <random>
#include <string>
#include "src/bus_factory.h"

// The generate function takes in name and only two routes
// because small, regular, and large have fixed capacity and
// speed.
// The generate function returns a Bua pointer, which will be
// a random type of bus.
Bus * BusFactory::GenerateBus(std::string name, Route * out, Route * in) {
  // This is to produce a random
  // number between 1-3
  // which will be used to
  // determine which bus will be
  // made.
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist1(1, 3);
  int rand_int = dist1(rng);

  // a NULL pointer which will point the bus produced
  Bus *busptr = NULL;

  // Takes in the rand int and creates
  // one of the three buses
  switch (rand_int) {
    case 1:
      busptr = new SmallBus(name, out, in);
      break;
    case 2:
      busptr = new RegularBus(name, out, in);
      break;
    case 3:
      busptr = new LargeBus(name, out, in);
      break;
    default:
      break;
  }
  return busptr;
}
