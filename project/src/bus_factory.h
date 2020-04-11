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
   * @brief Generation of a bus depending on time
   *
   * This funciton makes a bus of type small, regular, and large
   * depending on the time of day.
   *
   * @param[in] name Name/id of the bus
   * @param[in] out First route for the bus
   * @param[in] in Second route for the bus
   *
   * @return Bus object with name, two routes, capacity, and speed
   */
  Bus * GenerateBus(std::string name, Route * out, Route * in);
  /**
   * @brief Strategy of deploying busses between 6 am - before 8 am
   *
   * This strategy makes Small and Regular busses
   * when called. It keeps repeating this
   * Small, Regular, Small pattern till the time is
   * 8 am
   *
   * @param[in] name Name/id of the bus
   * @param[in] out First route for the bus
   * @param[in] in Second route for the bus
   *
   * @return Bus object with name, two routes, capacity, and speed
   */
  Bus * Strat1(std::string name, Route * out, Route * in);
  /**
   * @brief Strategy of deploying busses between 8 am - before 3 pm
   *
   * This strategy makes Regular and Large busses
   * when called. It keeps repeating this
   * Regular, Large, Regular pattern till the time is
   * 3 pm
   *
   * @param[in] name Name/id of the bus
   * @param[in] out First route for the bus
   * @param[in] in Second route for the bus
   *
   * @return Bus object with name, two routes, capacity, and speed
   */
  Bus * Strat2(std::string name, Route * out, Route * in);
  /**
   * @brief Strategy of deploying busses between 3 pm - before 8 pm
   *
   * This strategy makes Small, Regular, and Large busses
   * when called. It keeps repeating this
   * Small, Regular, Large pattern till the time is
   * 8 pm
   *
   * @param[in] name Name/id of the bus
   * @param[in] out First route for the bus
   * @param[in] in Second route for the bus
   *
   * @return Bus object with name, two routes, capacity, and speed
   */
  Bus * Strat3(std::string name, Route * out, Route * in);
};
#endif  // SRC_BUS_FACTORY_H_
