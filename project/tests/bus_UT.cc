/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include <string>
#include <list>
#include <string>

#include "../src/passenger_loader.h"
#include "../src/passenger_unloader.h"
#include "../src/passenger.h"
#include "../src/stop.h"
#include "../src/route.h"
#include "../src/random_passenger_generator.h"

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class BusTests : public ::testing::Test {
 protected:
   Passenger *passenger, *passenger1, *passenger2, *passenger3, *passenger4, *passenger5;

   Stop *stop1, *stop2, *stop3, *stop4, *stop5, *stop6;
   int num_stops;
   double dis1, dis2, dis3, dis4, dis5, dis6;
   string name;
   string name2;

   Stop ** stop_;
   Stop ** stop_2;
   double *distance_;
   double *distance_2;
   RandomPassengerGenerator * generator2;
   RandomPassengerGenerator * generator;
   Route *route_;
   Route *route_2;

   list<double> x;
   list<Stop *> y;
   list<double> x2;
   list<Stop *> y2;

   string bus_name;
   Bus *bus;

   virtual void SetUp() {
     passenger1 = new Passenger(2, "Amogh");
     passenger = new Passenger(5, "Help");
     passenger2 = new Passenger(4, "John");
     passenger3 = new Passenger(6, "Doe");
     passenger4 = new Passenger(3, "Sour");
     passenger5 = new Passenger(4, "Godly");

     dis1 = 2;
     dis2 = 2;
     dis3 = 2;
     dis4 = 2;
     dis5 = 2;
     dis6 = 2;

     stop1 = new Stop(1, 17, 10);
     stop2 = new Stop(2, 21, 20);
     stop3 = new Stop(3, 35, 30);
     stop4 = new Stop(4, 40, 90);
     stop5 = new Stop(5, 50, 91);
     stop6 = new Stop(6, 60, 92);

     num_stops = 3;
     name = "Magic Route";
     name2 = "Around Town";


     stop_ = new Stop*[3];
     stop_[0] = stop1;
     stop_[1] = stop2;
     stop_[2] = stop3;

     stop_2 = new Stop*[3];
     stop_2[0] = stop4;
     stop_2[1] = stop5;
     stop_2[2] = stop6;

     distance_ = new double[3];
     distance_[0] = dis1;
     distance_[1] = dis2;
     distance_[2] = dis3;

     distance_2 = new double[3];
     distance_2[0] = dis4;
     distance_2[1] = dis5;
     distance_2[2] = dis6;

     x.push_back(dis1);
     x.push_back(dis2);
     x.push_back(dis3);

     y.push_back(stop1);
     y.push_back(stop2);
     y.push_back(stop3);

     x2.push_back(dis4);
     x2.push_back(dis5);
     x2.push_back(dis6);

     y2.push_back(stop4);
     y2.push_back(stop5);
     y2.push_back(stop6);

     route_ = new Route(name, stop_, distance_, num_stops, generator);
     route_2 = new Route(name2, stop_2, distance_2, num_stops, generator2);

     bus_name = "School Bus";
     bus = new Bus(bus_name , route_, route_2, 5);
   };


   virtual void TearDown(){
     delete passenger;
     delete passenger1;
     delete passenger2;
     delete passenger3;
     delete passenger4;
     delete passenger5;

     passenger = NULL;
     passenger1 = NULL;
     passenger2 = NULL;
     passenger3 = NULL;
     passenger4 = NULL;
     passenger5 = NULL;

     for (int i = 0; i < 3; i++) {
       delete stop_[i];
       delete stop_2[i];

     }
     delete[] stop_;
     delete[] stop_2;
     delete[] distance_;
     delete[] distance_2;
     delete route_;
     delete route_2;
     delete bus;
   };
};
/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(BusTests, Constructor) {
  EXPECT_EQ(bus->GetName(), "School Bus");
  EXPECT_EQ(bus->GetCapacity(), 5);
  EXPECT_EQ(bus->GetNumPassengers(), 0);
  EXPECT_EQ(bus->IsTripComplete(), false);
  EXPECT_EQ(bus->GetNextStop(), stop1);
  bus->Update();
  EXPECT_EQ(bus->GetNextStop(), stop2);
  bus->LoadPassenger(passenger);
  EXPECT_EQ(bus->GetNumPassengers(), 1);
  bus->LoadPassenger(passenger1);
  EXPECT_EQ(bus->GetNumPassengers(), 2);
    bus->Update();
    bus->Update();
    bus->Update();
    bus->Update();
    bus->Update();
  EXPECT_EQ(bus->GetNextStop(), stop6) <<"check to see end stop reached";
    bus->Update();
    bus->Update();
  EXPECT_EQ(bus->IsTripComplete(), true) << "end of trip";
  EXPECT_EQ(bus->GetNumPassengers(), 0) << "everyone off";
};


TEST_F(BusTests, IsTripComplete){
  EXPECT_EQ(bus->IsTripComplete(), false);
  bus->LoadPassenger(passenger1);
  bus->LoadPassenger(passenger2);
  bus->LoadPassenger(passenger3);
  bus->LoadPassenger(passenger4);
  bus->LoadPassenger(passenger);
  EXPECT_EQ(bus->GetNumPassengers(), 5) << "everyone added";
  EXPECT_EQ(bus->GetNextStop(), stop1);
  bus->Update();
  EXPECT_EQ(bus->GetNextStop(), stop2);
  bus->Update();
  EXPECT_EQ(bus->GetNextStop(), stop3);
  EXPECT_EQ(bus->GetNumPassengers(), 4) << "One person off";
  bus->Update();
  bus->Update();
  EXPECT_EQ(bus->GetNextStop(), stop4);
  EXPECT_EQ(bus->GetNumPassengers(), 3);
  EXPECT_EQ(bus->IsTripComplete(), false) <<"just switching routes";
  bus->Update();
  EXPECT_EQ(bus->GetNextStop(), stop5);
  EXPECT_EQ(bus->GetNumPassengers(), 2);
  bus->Update();
  EXPECT_EQ(bus->GetNextStop(), stop6);
  bus->Update();
  bus->Update();
  EXPECT_EQ(bus->IsTripComplete(), true) << "trip has come to an end";
  EXPECT_EQ(bus->GetNumPassengers(), 0) << "everyone should be off";
  bus->Update();
  EXPECT_EQ(bus->IsTripComplete(), true) << "Making sure its still true";
};

TEST_F(BusTests, LoadPassenger){
  EXPECT_EQ(bus->GetCapacity(), 5);
  EXPECT_EQ(bus->LoadPassenger(passenger), true);
  EXPECT_EQ(bus->GetNumPassengers(), 1);
  EXPECT_EQ(bus->LoadPassenger(passenger1), true);
  EXPECT_EQ(bus->GetNumPassengers(), 2);
  EXPECT_EQ(bus->LoadPassenger(passenger2), true);
  EXPECT_EQ(bus->GetNumPassengers(), 3);
  EXPECT_EQ(bus->LoadPassenger(passenger3), true);
  EXPECT_EQ(bus->GetNumPassengers(), 4);
  EXPECT_EQ(bus->LoadPassenger(passenger4), true);
  EXPECT_EQ(bus->GetNumPassengers(), 5) << "At max cap";
  EXPECT_EQ(bus->LoadPassenger(passenger5), false) << "Not enough space";
};

TEST_F(BusTests, Move){
  EXPECT_EQ(bus->Move(), true) << "Should be moving";
  EXPECT_EQ(bus->Move(), false) << "error 1";
  EXPECT_EQ(bus->Move(), true) << "error 2";
  EXPECT_EQ(bus->Move(), false) << "error 3";
  EXPECT_EQ(bus->Move(), true) << "error4";
  EXPECT_EQ(bus->Move(), false) << "error 5";
  EXPECT_EQ(bus->Move(), true) << "error 6";
  // Not sure what move is doing. It should be moving from the starts
  // and should stop around two moves the distance from each stops
  // Need to take a closer look
};
