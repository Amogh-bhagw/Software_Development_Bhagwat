/**
 * @file regular_bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef REGULAR_BUS_H_
#define REGULAR_BUS_H_

#include <iostream>
#include <list>
#include <string>

#include "src/bus.h"

class Bus;

class RegularBus : public Bus {
  public:
    RegularBus(std::string name, Route * out, Route * in, int capacity = 60,
      double speed = 1);
    void Report(std::ostream&) override;
};
#endif  // REGULAR_BUS_H_
