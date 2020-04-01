/**
 * @file r_local_simulator_2.cc
 *
 * @copyright 2020 Amogh Bhagwat, All rights reserved.
 */
#include "src/r_local_simulator_2.h"

#include <vector>
#include <list>

#include "src/bus.h"
#include "src/stop.h"
#include "src/route.h"
#include "src/rtest_passenger_generator.h"

bool rLocalSimulator2::Start() {
  simulation_time_elapsed_ = 0;  // init, but also allows restart

  // int num_round_trips = 10;
  int num_round_trips = 1;
  for (int i = 0; i < num_round_trips; i++) {
    time_since_last_bus_generation_.push_back(0);
  }
  // East and West bank dorms (in config text)
  Stop ** CC_EWD_stops = new Stop *[7];
  // St.Paul and East bank Dorms
  Stop ** CC_SED_stops = new Stop *[4];
  std::list<Stop *> CC_EWD_stops_list;
  std::list<Stop *> CC_SED_stops_list;

  //Staticly defined objects get destroyed at end of Start()!
  //Must be dynamic...

  // CC East and West bank dorm stops
  Stop * stop_CC_EWD_1 = new Stop(0, 44.969365, -93.240627);
  // Middlebrook Hall
  Stop * stop_CC_EWD_2 = new Stop(1, 44.980800, -93.239972);
  // Stanford Hall
  Stop * stop_CC_EWD_3 = new Stop(2, 44.978686, -93.231454);
  // 17th Ave
  Stop * stop_CC_EWD_4 = new Stop(3, 44.972436, -93.227462);
  // Territorial Hall
  Stop * stop_CC_EWD_5 = new Stop(4, 44.972246, -93.230186);
  // Centennial Hall
  Stop * stop_CC_EWD_6 = new Stop(5, 44.970673, -93.230281);
  // Pioneer Hall
  Stop * stop_CC_EWD_7 = new Stop(6, 44.970310, -93.228122);
  // Frontier Hall


  // CC St.Paul and East bank dorm stops
  Stop * stop_CC_SED_1 = new Stop(7, 44.970310, -93.228122);
  // Frontier Hall
  Stop * stop_CC_SED_2 = new Stop(8, 44.985047, -93.184806);
  // Bailey Hall
  Stop * stop_CC_SED_3 = new Stop(9, 44.972748, -93.237090);
  // Comestock Hall
  Stop * stop_CC_SED_4 = new Stop(10, 44.969365, -93.240627);
  // Middlebrook Hall


  CC_EWD_stops_list.push_back(stop_CC_EWD_1);
  CC_EWD_stops[0] = stop_CC_EWD_1;
  CC_EWD_stops_list.push_back(stop_CC_EWD_2);
  CC_EWD_stops[1] = stop_CC_EWD_2;
  CC_EWD_stops_list.push_back(stop_CC_EWD_3);
  CC_EWD_stops[2] = stop_CC_EWD_3;
  CC_EWD_stops_list.push_back(stop_CC_EWD_4);
  CC_EWD_stops[3] = stop_CC_EWD_4;
  CC_EWD_stops_list.push_back(stop_CC_EWD_5);
  CC_EWD_stops[4] = stop_CC_EWD_5;
  CC_EWD_stops_list.push_back(stop_CC_EWD_6);
  CC_EWD_stops[5] = stop_CC_EWD_6;
  CC_EWD_stops_list.push_back(stop_CC_EWD_7);
  CC_EWD_stops[6] = stop_CC_EWD_7;

  CC_SED_stops_list.push_back(stop_CC_SED_1);
  CC_SED_stops[0] = stop_CC_SED_1;
  CC_SED_stops_list.push_back(stop_CC_SED_2);
  CC_SED_stops[1] = stop_CC_SED_2;
  CC_SED_stops_list.push_back(stop_CC_SED_3);
  CC_SED_stops[2] = stop_CC_SED_3;
  CC_SED_stops_list.push_back(stop_CC_SED_4);
  CC_SED_stops[3] = stop_CC_SED_4;


  double * CC_EWD_distances = new double[6];
  double * CC_SED_distances = new double[3];
  CC_EWD_distances[0] = 4;
  CC_EWD_distances[1] = 4;
  CC_EWD_distances[2] = 2;
  CC_EWD_distances[3] = 19;
  CC_EWD_distances[4] = 1;
  CC_EWD_distances[5] = 1;


  CC_SED_distances[0] = 2;
  CC_SED_distances[1] = 1;
  CC_SED_distances[2] = 2;


  std::list<double> CC_EWD_probs;
  CC_EWD_probs.push_back(.1);  // Middlebrook Hall
  CC_EWD_probs.push_back(.3);  // Stanford Hall
  CC_EWD_probs.push_back(.05);  // 17th Ave
  CC_EWD_probs.push_back(.08);  // Territorial Hall
  CC_EWD_probs.push_back(.025);  // Centennial Hall
  CC_EWD_probs.push_back(.01);  // Pioneer Hall
  CC_EWD_probs.push_back(.25);  // Frontier Hall
  //TODO: is this always true? If so, we may want to reduce the length of probs to_char_type
  //        remove possibility of generating passengers with nowhere to go

  std::list<double> CC_SED_probs;
  CC_SED_probs.push_back(.25);  // Frontier Hall
  CC_SED_probs.push_back(.1);  // Bailey Hall
  CC_SED_probs.push_back(.03);  // Comestock Hall
  CC_SED_probs.push_back(.1);  // Middlebrook Hall


  //Staticly defined objects get destroyed at end of Start()!
  //Must be dynamic...
  //RandomPassengerGenerator CC_EWD_generator(CC_EWD_probs, CC_EWD_stops_list);
  //RandomPassengerGenerator CC_SED_generator(CC_SED_probs, CC_SED_stops_list);

 RtestPassengerGenerator * CC_EWD_generator = new RtestPassengerGenerator (CC_EWD_probs, CC_EWD_stops_list);
 RtestPassengerGenerator * CC_SED_generator = new RtestPassengerGenerator (CC_SED_probs, CC_SED_stops_list);

  //Test to ensure generators are working
  //Helpful for debugging
  //CC_EWD_generator.GeneratePassengers();
  //CC_SED_generator.GeneratePassengers();

  //Again, MUST be dynamic...
  //Route CC_EWD("Campus Connector - Eastbound", CC_EWD_stops, CC_EWD_distances, 7, &CC_EWD_generator);
  //Route CC_SED("Campus Connector - Westbound", CC_SED_stops, CC_SED_distances, 4, &CC_SED_generator);

  Route * CC_EWD = new Route("Campus Connector - East & West bank dorms",
  CC_EWD_stops, CC_EWD_distances, 7, CC_EWD_generator);
  Route * CC_SED = new Route("Campus Connector - St.Paul & East Bank dorms",
  CC_SED_stops, CC_SED_distances, 4, CC_SED_generator);

  prototype_routes_.push_back(CC_EWD);
  prototype_routes_.push_back(CC_SED);

  prototype_routes_[0]->Report(std::cout);
  prototype_routes_[1]->Report(std::cout);

  bus_counters_.push_back(10000);

  //This will eventually be replaced by configuration/command line argument
  bus_start_timings_.push_back(10);

  // Do we want a bus on start? Or let the update handle this?
  // active_buses_.push_back(new Bus(std::to_string(bus_counters_[0]),
  //   prototype_routes[0].Clone(), prototype_routes[1].Clone(), 60, 1));
  // bus_counters_[0]++;

  return true;
}

bool rLocalSimulator2::Update() {
  // increase time
  simulation_time_elapsed_++;
  std::cout << "~~~~~~~~~~~~~ The time is now " << simulation_time_elapsed_;
  std::cout << " ~~~~~~~~~~~~~" << std::endl;

  // various route-indexed list iterators
  std::vector<int>::iterator bus_gen_timing_iter = bus_start_timings_.begin();
  std::vector<int>::iterator bus_counter_iter = bus_counters_.begin();
  std::vector<Route *>::iterator prototype_route_iter =
                                                     prototype_routes_.begin();

  // increase each time since last bus
  // various iterators parallel the time_since_last iterator
  for (std::vector<int>::iterator it = time_since_last_bus_generation_.begin();
      it != time_since_last_bus_generation_.end();
      it++, bus_gen_timing_iter++, bus_counter_iter++) {
    (*it)++;

    // if time since last [index] == bus gen timing[index]
    if (0 >= (*bus_gen_timing_iter)) {
      // create a new bus! routes are:
      // prototype_routes_[index * 2] & prototype_routes_[index * 2 + 1]
      Route * outbound = (*prototype_route_iter);
      prototype_route_iter++;
      Route * inbound = (*prototype_route_iter);
      prototype_route_iter++;

      active_buses_.push_back(new Bus(std::to_string((*bus_counter_iter)),
                                  outbound->Clone(), inbound->Clone(), 60, 1));
      (*bus_counter_iter)++;
      (*bus_gen_timing_iter) = 10;
    } else {
      prototype_route_iter++;
      prototype_route_iter++;
      (*bus_gen_timing_iter)--;
    }
  }

  // for each bus
  for (std::list<Bus *>::iterator bus_iter = active_buses_.begin();
      bus_iter != active_buses_.end(); bus_iter++) {
    // update bus
    (*bus_iter)->Update();
    // bus report
    (*bus_iter)->Report(std::cout);

    //REQUIRES USE OF IsTripComplete, which was not required
    //Buses which are "done" will just keep having Update() called
    //  Students MAY need to deal with this, not sure yet...
    // remove bus if trip is complete
    //if ((*bus_iter)->IsTripComplete()) {
    //  bus_iter = active_buses_.erase(bus_iter);
    //  bus_iter--;
    //}
  }

  // for each stop
  for (std::vector<Route *>::iterator route_iter = prototype_routes_.begin();
      route_iter != prototype_routes_.end(); route_iter++) {
    // update stop
    (*route_iter)->Update();
    (*route_iter)->Report(std::cout);
  }

  return true;
}
