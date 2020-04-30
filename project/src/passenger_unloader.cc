/**
 * @file passenger_unloader.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <sstream>
#include <iostream>
#include "src/passenger_unloader.h"


Util u;
int PassengerUnloader::UnloadPassengers(std::list<Passenger *>* passengers,
                                        Stop * current_stop) {  // Changed
  // TODO(wendt): may need to do end-of-life here
  // instead of in Passenger or Simulator
  int passengers_unloaded = 0;
  std::ostringstream report;

  for (std::list<Passenger *>::iterator it = passengers->begin();  // Changed
      it != passengers->end();  // Changed
      it++) {
    if ((*it)->GetDestination() == current_stop->GetId()) {
      // get passenger data
      (*it)->Report(report);
      report << "," << std::endl;


      // could be used to inform scheduler of end-of-life?
      // This could be a destructor issue as well.
      // *it->FinalUpdate();
      it = passengers->erase(it);  // changed
      // getting seg faults, probably due to reference deleted objects
      // here
      it--;
      passengers_unloaded++;
    }
  }
  // processing strings to write to the passenger file
  std::string infos = report.str();
  std::vector<std::string> v = u.processOutput(infos);
  FileWriter* w = FileWriterManager::Getinstance();
  w->Write(passenger_file_name, v);
  return passengers_unloaded;
}
