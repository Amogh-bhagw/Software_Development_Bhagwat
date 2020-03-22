/**
 * @file bus_factory.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
 #include <vector>
 #include <random>
 #include <string>
 #include "src/bus_factory.h"


Bus * BusFactory::GenerateBus(std::string name, Route * out, Route * in){
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist1(1, 3);
  int rand_int = dist1(rng);

  Bus *busptr = NULL;
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
