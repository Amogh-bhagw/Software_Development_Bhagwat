/**
 * @file bus_factory.cc
 *
 * @copyright 2020 Amogh Bhagwat, All rights reserved.
 */
#include <vector>
#include <random>
#include <string>
#include <ctime>
#include <iostream>
#include "src/bus_factory.h"

// This is the morning strat which deploys only Small and Regular Busses
Bus * BusFactory::Strat1(std::string name, Route * out, Route * in) {
  static int count1 = 0;  // Keeps track of state
  if (count1 == 0) {
      count1++;
      std::cout << "SmallBus is being deployed" << std::endl;
      return new SmallBus(name, out, in);
  } else {
    count1 = 0;
    std::cout << "RegularBus is being deployed" << std::endl;
    return new RegularBus(name, out, in);
  }
}
// This is this the afternoon strat which deploys Regular and Large
Bus * BusFactory::Strat2(std::string name, Route * out, Route * in) {
  static int count2 = 0;  // Keeps track of state
  if (count2 == 0) {
      count2++;
      std::cout << "RegularBus is being deployed" << std::endl;
      return new RegularBus(name, out, in);
  } else {
    count2 = 0;
    std::cout << "LargeBus is being deployed" << std::endl;
    return new LargeBus(name, out, in);
  }
}
// This is this the evening strat which deploys all three busses
Bus * BusFactory::Strat3(std::string name, Route * out, Route * in) {
  static int count3 = 0;  // Keeps track of state
  if (count3 == 0) {
      count3++;
      std::cout << "SmallBus is being deployed" << std::endl;
      return new SmallBus(name, out, in);
  } else if (count3 == 1) {
    count3++;
    std::cout << "RegularBus is being deployed" << std::endl;
    return new RegularBus(name, out, in);
  } else {
    count3 = 0;
    std::cout << "LargeBus is being deployed" << std::endl;
    return new LargeBus(name, out, in);
  }
}

// The generate function takes in name and only two routes
// because small, regular, and large have fixed capacity and
// speed.
// The generate function returns a Bus pointer, which will be
// determined based on the time of day
Bus * BusFactory::GenerateBus(std::string name, Route * out, Route * in) {
  // Below is how we get our current time
  struct tm newtime;
  time_t ltime;
  ltime = time(&ltime);
  localtime_r(&ltime, &newtime);
  int hour = newtime.tm_hour;
  std::cout << "The current time is: " << hour <<
  ":" << newtime.tm_min << ":" << newtime.tm_sec << std::endl;

  // A bunch of statments to determine which strategy to call
  if (hour >= 6 && hour < 8) {
    std::cout << "Strategy 1 is being implemented" << std::endl;
    return Strat1(name, out, in);
  } else if (hour >= 8 && hour < 15) {
    std::cout << "Strategy 2 is being implemented" << std::endl;
    return Strat2(name, out, in);
  } else if (hour >= 15 && hour < 20) {
    std::cout << "Strategy 3 is being implemented" << std::endl;
    return Strat3(name, out, in);
  } else {
    std::cout << "Strategy small bus is being implemented" << std::endl;
    std::cout << "SmallBus is being deployed" << std::endl;
    return new SmallBus(name, out, in);
  }
}
