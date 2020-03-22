/**
 * @file small_bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SMALL_BUS_H_
#define SMALL_BUS_H_

#include <iostream>
#include <list>
#include <string>

#include "src/bus.h"

class Bus;

class SmallBus : public Bus {
  public:
    SmallBus(std::string name, Route * out, Route * in, int capacity = 30,
      double speed = 1);
    void Report(std::ostream&) override;
};
#endif  // SMALL_BUS_H_
