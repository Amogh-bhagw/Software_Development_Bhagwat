/**
 * @file bus_factory.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef BUS_FACTORY_H_
#define BUS_FACTORY_H_

#include <iostream>
#include <list>
#include <string>

#include "src/large_bus.h"
#include "src/regular_bus.h"
#include "src/small_bus.h"

class BusFactory{
public:
  static Bus * GenerateBus(std::string name, Route * out, Route * in);
};
#endif  // BUS_FACTORY_H_
