/**
 * @file regular_bus.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/regular_bus.h"

// Calls the Bus constructor, which
// sets the variiables with the users inputs.
// One thing that is set is the capacity being 60 and
// The speed being 1.
RegularBus::RegularBus(std::string name, Route * out, Route * in, int capacity,
  double speed) : Bus(name, out, in, capacity, speed) {}

// The report function is exactly like the bus Report()
// One line of code was added to show what type of bus
// was being produced. In this case a small bus
// All the print statments are recorded in
// the parameter out, which is a ostream.
void RegularBus::Report(std::ostream& out) {
  out << "Name: " << name_ << std::endl;
  out << "Bus Type: RegularBus" << std::endl;  // prints the type here
  out << "Speed: " << speed_ << std::endl;
  out << "Distance to next stop: " << distance_remaining_ << std::endl;
  out << "\tPassengers (" << passengers_.size() << "): " << std::endl;
  for (std::list<Passenger *>::iterator it = passengers_.begin();
  it != passengers_.end(); it++) {
    (*it)->Report(out);
  }
}
