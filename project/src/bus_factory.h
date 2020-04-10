/**
 * @file bus_factory.h
 *
 * @copyright 2020 Amogh Bhagwat, All rights reserved.
 */
#ifndef SRC_BUS_FACTORY_H_
#define SRC_BUS_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <list>
#include <string>
#include <ctime>
#include "src/large_bus.h"
#include "src/regular_bus.h"
#include "src/small_bus.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the generation of buses.
 */
class BusFactory{
 public:
  /**
   * @brief Generation of a bus with a randomized type
   *
   * This funciton makes a bus of type small, regular, and large
   * at random.
   *
   * @param[in] name Name/id of the bus
   * @param[in] out First route for the bus
   * @param[in] in Second route for the bus
   *
   * @return Bus object with name, two routes, capacity, and speed
   */
  Bus * GenerateBus(std::string name, Route * out, Route * in);
  Bus * Strat1(std::string name, Route * out, Route * in);
  Bus * Strat2(std::string name, Route * out, Route * in);
  Bus * Strat3(std::string name, Route * out, Route * in);
};
#endif  // SRC_BUS_FACTORY_H_
