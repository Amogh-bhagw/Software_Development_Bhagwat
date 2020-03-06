#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>
#include <string>


#include "../src/bus.h"
#include "../src/passenger.h"
#include "../src/stop.h"

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class StopTests : public ::testing::Test {
protected:
  Stop *stop1, *stop2, *stop3;
  Passenger *passenger;

  virtual void SetUp() {
    passenger = new Passenger(1, "Tester");
    stop1 = new Stop(1, 49, 50);
    stop2 = new Stop(2, 4.0, 5.0);
    stop3 = new Stop(3, 66, 99);
  }

  virtual void TearDown() {
    delete passenger;
    delete stop1;
    delete stop2;
    delete stop3;

    passenger = NULL;
    stop1 = NULL;
    stop2 = NULL;
    stop3 = NULL;
  }
};
/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(StopTests, Constructor) {
  EXPECT_EQ(stop1->GetLongitude(), 49) << "see if long is setup correctly";
  EXPECT_EQ(stop1->GetLatitude(), 50) << "see iif lat is setup correctly";
  EXPECT_EQ(stop1->GetId(), 1) << "first stop";

  EXPECT_EQ(stop2->GetLongitude(), 4.0) << "low double numbers check";
  EXPECT_EQ(stop2->GetLatitude(), 5.0) << "checking double again";
  EXPECT_EQ(stop2->GetId(), 2) << "Second Stop";
  EXPECT_EQ((stop2->GetId()-5), -3) << "checking subtracting";
  EXPECT_EQ((stop2->GetId()+5), 7) << "checking adding";

  EXPECT_EQ(stop1->GetNumPassengersPresent(), 0);
  EXPECT_EQ(stop1->AddPassengers(passenger), 1);
  EXPECT_EQ(stop1->GetNumPassengersPresent(), 1);
  stop1->Update();
  EXPECT_EQ(passenger->GetTotalWait(), 1);

};
