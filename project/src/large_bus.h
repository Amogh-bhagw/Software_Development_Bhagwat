/**
 * @file large_bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef LARGE_BUS_H_
#define LARGE_BUS_H_

#include <iostream>
#include <list>
#include <string>

#include "src/bus.h"

class Bus;

class LargeBus : public Bus {
  public:
    LargeBus(std::string name, Route * out, Route * in, int capacity = 90,
      double speed = 1);
    void Report(std::ostream&) override;
};
#endif  // LARGE_BUS_H_
