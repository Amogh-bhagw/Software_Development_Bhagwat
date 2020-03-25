/**
 * @file large_bus.h
 *
 * @copyright 2020 Amogh Bhagwat, All rights reserved.
 */
#ifndef SRC_LARGE_BUS_H_
#define SRC_LARGE_BUS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <list>
#include <string>

#include "src/bus.h"

class Bus;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for a large bus.
 *
 */
class LargeBus : public Bus {
 public:
    /**
     * @brief The constructor for a large bus.
     *
     *
     * @param name Is the name/Id number of the bus.
     * @param out Is the first route the bus will go along.
     * @param in Is the second route the bus willl go along.
     * @param capacity Is the number of people can fit on the bus.
     * @param speed Is how fast the bus is. How many steps it takes every update.
     */
    LargeBus(std::string name, Route * out, Route * in, int capacity = 90,
      double speed = 1);
    /**
     * @brief Prints out different aspects of the large bus.
     *
     *
     * @param std::ostream& Takes in the ostream to record the outputs
     */
    void Report(std::ostream&) override;
};
#endif  // SRC_LARGE_BUS_H_
