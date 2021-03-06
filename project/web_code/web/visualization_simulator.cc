/**
 * @file visualization_simulator.cc
 *
 * @copyright 2020 Amogh Bhagwat, All rights reserved.
 */
#include "web_code/web/visualization_simulator.h"

#include "src/bus.h"
#include "src/route.h"
#include "src/bus_factory.h"
#include "src/IObservable.h"

VisualizationSimulator::VisualizationSimulator(WebInterface* webI,
  ConfigManager* configM) {
    webInterface_ = webI;
    configManager_ = configM;
}

VisualizationSimulator::~VisualizationSimulator() {}

void VisualizationSimulator::Start(const std::vector<int>& busStartTimings,
  const int& numTimeSteps) {
    busStartTimings_ = busStartTimings;
    numTimeSteps_ = numTimeSteps;

    timeSinceLastBus_.resize(busStartTimings_.size());
    for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {
        timeSinceLastBus_[i] = 0;
    }

    simulationTimeElapsed_ = 0;

    prototypeRoutes_ = configManager_->GetRoutes();
    for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
        prototypeRoutes_[i]->Report(std::cout);

        prototypeRoutes_[i]->UpdateRouteData();
        webInterface_->UpdateRoute(prototypeRoutes_[i]->GetRouteData());
    }
}

void VisualizationSimulator::TogglePause() {
    // if the sim is already pause
    // we change the variable to false,
    // so we can continue to run the sim.
    if (ispaused == true) {
        ispaused = false;
    } else {
       ispaused = true;
    }
}

void VisualizationSimulator::ClearBusListeners() {
  // we go through the bus vector callin ClearObservers
  // seems redundant to go through all the observers
  // as the ClearObservers just clears every element in
  // the observer_ vector but this is the only way
  // I found that updated the vis sim the fastest
  for (int i = 0; i < static_cast<int>(busses_.size()); i++) {
    busses_[i]->ClearObservers();
  }
}

void VisualizationSimulator::AddBusListener(std::string * id,
  IObserver<BusData*> * observer) {
  // we go through the bus vector until we finnd the correct
  // id. When we find the correct id we call
  // RegisterObserver with that bus and pass
  // in the observer paramter with it
  for (std::vector<Bus *>::const_iterator iter = busses_.begin();
  iter != busses_.end();
     ++iter) {
       if ((*iter)->GetName() == *id) {
         (*iter)->RegisterObserver(observer);
       }
     }
}

void VisualizationSimulator::AddStopListener(std::string * id,
  IObserver<StopData*> * observer) {
    std::list<Stop*> v;
    for (int i ; i < static_cast<int>(prototypeRoutes_.size()); i++) {
      v = prototypeRoutes_[i]->GetStops();
      for (std::list<Stop*>::iterator it = v.begin(); it != v.end();
       it++) {
              if (std::to_string((*it)->GetId()) == *id) {
                (*it)->RegisterObserver(observer);
              }
        }
      }
  }



void VisualizationSimulator::ClearStopListeners() {
  std::list<Stop*> v;
  for (int i ; i < static_cast<int>(prototypeRoutes_.size()); i++) {
    v = prototypeRoutes_[i]->GetStops();
    for (std::list<Stop*>::iterator it = v.begin(); it != v.end(); it++) {
       (*it)->ClearObservers();
      }
    }
}
Util x;
void VisualizationSimulator::Update() {
  std::ostringstream report2;
// This for loop incases the whole update
// method. This is how the pause
// function is implemented.
if(ispaused != true) {
    simulationTimeElapsed_++;

    std::cout << "~~~~~~~~~~ The time is now " << simulationTimeElapsed_;
    std::cout << "~~~~~~~~~~" << std::endl;

    std::cout << "~~~~~~~~~~ Generating new busses if needed ";
    std::cout << "~~~~~~~~~~" << std::endl;

    // Check if we need to generate new busses
    for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {
        // Check if we need to make a new bus
        if (0 >= timeSinceLastBus_[i]) {
            Route * outbound = prototypeRoutes_[2 * i];
            Route * inbound = prototypeRoutes_[2 * i + 1];

            // Add generate bus factory here
            BusFactory bFactory;
            busses_.push_back(bFactory.GenerateBus(std::to_string(busId),
            outbound->Clone(), inbound->Clone()));
            busId++;

            timeSinceLastBus_[i] = busStartTimings_[i];
        } else {
            timeSinceLastBus_[i]--;
        }
    }

    std::cout << "~~~~~~~~~ Updating busses ";
    std::cout << "~~~~~~~~~" << std::endl;

    // Update busses
    for (int i = static_cast<int>(busses_.size()) - 1; i >= 0; i--) {
        busses_[i]->Update();

        if (busses_[i]->IsTripComplete()) {
            webInterface_->UpdateBus(busses_[i]->GetBusData(), true);
            // We call report function to get the bus data
            busses_[i]->Report(report2);
            report2 << "Total Num of Passengers "
            // Call the counter for total passengers
            << busses_[i]->GetTotalNumberPass() << std::endl;
            report2 << "," << std::endl;

            // Set up for processing and writing to the bus file
            std::string infos2 = report2.str();
            std::vector<std::string> v2 = x.processOutput(infos2);
            FileWriter* w2 = FileWriterManager::Getinstance();
            w2->Write(bus_stats_file_name, v2);

            busses_.erase(busses_.begin() + i);
            continue;
        }

        webInterface_->UpdateBus(busses_[i]->GetBusData());

        busses_[i]->Report(std::cout);
    }

    std::cout << "~~~~~~~~~ Updating routes ";
    std::cout << "~~~~~~~~~" << std::endl;
    // Update routes
    for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
        prototypeRoutes_[i]->Update();

        webInterface_->UpdateRoute(prototypeRoutes_[i]->GetRouteData());

        prototypeRoutes_[i]->Report(std::cout);
    }
  }
}
