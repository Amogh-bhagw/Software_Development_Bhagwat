/*
 * Students: Use this file as a guide to writing your own unit tests.
 * See the project instructions for more information on which classes
 * and methods must be tested.
 */

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

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class PassengerTests : public ::testing::Test {
protected:
  PassengerLoader* pass_loader;
  PassengerUnloader* pass_unloader;
  Passenger *passenger, *passenger1, *passenger2, *passenger3, *passenger4;

  virtual void SetUp() {
    pass_loader = new PassengerLoader();
    pass_unloader = new PassengerUnloader();
    passenger1 = new Passenger(2, "Amogh");
    passenger = new Passenger();
    passenger2 = new Passenger(100, "John");
    passenger3 = new Passenger(-5, "Negative");
    passenger4 = new Passenger(2000, "Extreme");
  }

  virtual void TearDown() {
    delete pass_loader;
    delete pass_unloader;
    delete passenger;
    delete passenger1;
    delete passenger2;
    delete passenger3;
    delete passenger4;
    pass_loader = NULL;
    pass_unloader = NULL;
    passenger = NULL;
    passenger1 = NULL;
    passenger2 = NULL;
    passenger3 = NULL;
    passenger4 = NULL;
  }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(PassengerTests, Constructor) {
  EXPECT_EQ(passenger->IsOnBus(), false);
  passenger->GetOnBus();
  EXPECT_EQ(passenger->IsOnBus(), true);
  EXPECT_EQ(passenger1->GetDestination(), 2) << "Check if set correctly";
  EXPECT_EQ(passenger2->GetDestination(), 100) << "Check to see large number";
  EXPECT_EQ(passenger3->GetDestination(), -5) << "negative number";
  EXPECT_EQ(passenger4->GetDestination(), 2000) << "larger number";
  EXPECT_EQ(passenger1->GetTotalWait(), 0);
};

TEST_F(PassengerTests, Update){
  passenger1->Update();
  passenger1->Update();
  passenger1->Update();
  passenger1->GetOnBus();
  EXPECT_EQ(passenger1->GetTotalWait(), 4);
  passenger1->Update();
  passenger1->GetOnBus();
  EXPECT_EQ(passenger1->GetTotalWait(), 4) << "check to see if time on bus resets to one";
  passenger->Update();
  passenger->Update();
  passenger->Update();
  passenger->Update();
  passenger->Update();
  passenger->Update();
  passenger->Update();
  passenger->Update();
  EXPECT_EQ(passenger->GetTotalWait(), 8) << "large numbers of update";
  passenger->GetOnBus();
  EXPECT_EQ(passenger->GetTotalWait(), 9);

};
<<<<<<< HEAD

TEST_F(PassengerTests, GetOnBus) {
  EXPECT_EQ(passenger->IsOnBus(), false);
  passenger->GetOnBus();
  EXPECT_EQ(passenger->IsOnBus(), true);
  EXPECT_EQ(passenger->GetTotalWait(), 1) << "Intial on the bus";
  passenger->Update();
  EXPECT_EQ(passenger->GetTotalWait(), 2) << "after a update";
  passenger1->GetOnBus();
  EXPECT_EQ(passenger1->IsOnBus(), true);
  EXPECT_EQ(passenger1->GetTotalWait(), 1);
  passenger1->Update();
  EXPECT_EQ(passenger1->GetTotalWait(), 2);
  passenger1->GetOnBus();
  EXPECT_EQ(passenger1->GetTotalWait(), 1) << "should reset to 1";

};

TEST_F(PassengerTests, GetTotalWait){
  passenger->Update();
  passenger->Update();
  passenger->Update();
  passenger->Update();
  passenger->Update();
  EXPECT_EQ(passenger->GetTotalWait(), 5) << "Alot of updates";
  passenger->Update();
  EXPECT_EQ(passenger->GetTotalWait(), 6);
  EXPECT_EQ(passenger1->GetTotalWait(), 0) << "Intial zero wait time";
  passenger2->Update();
  passenger2->Update();
  passenger2->GetOnBus();
  passenger2->Update();
  passenger2->Update();
  EXPECT_EQ(passenger2->GetTotalWait(), 5) << "Seeing if time at stop and on bus is added";
  EXPECT_EQ((passenger2->GetTotalWait()-3), 2) << "Subtracting time";
  EXPECT_EQ((passenger2->GetTotalWait()+100), 105) << "Adding time";
};

TEST_F(PassengerTests, IsOnBus){
    EXPECT_EQ(passenger->IsOnBus(), false);
    EXPECT_EQ(passenger->IsOnBus(), false) << "checking again";
    passenger->GetOnBus();
    EXPECT_EQ(passenger->IsOnBus(), true);
    passenger->GetOnBus();
    EXPECT_EQ(passenger->IsOnBus(), true) << "checking if calling GetOnBus throws a error";

};

TEST_F(PassengerTests, GetDestination){
  EXPECT_EQ(passenger3->GetDestination(), -5) << "Checking if negative will work";
  EXPECT_EQ((passenger3->GetDestination() + 5), 0) << "Checking if Adding will work";
  EXPECT_EQ(passenger->GetDestination(), -1) << "Intial setup number";
  EXPECT_EQ(passenger1->GetDestination(), 2) << "Some different output";
  EXPECT_EQ(passenger2->GetDestination(), 100);
  EXPECT_EQ(passenger4->GetDestination(), 2000) << "Large number";
};

 TEST_F(PassengerTests, Report){
  string expected_output = "Name: Nobody\nDestination: -1\nTotal Wait: 0\n\tWait at Stop: 0\n\tTime on bus: 0\n";
  string expected_output1 = "Name: Amogh\nDestination: 2\nTotal Wait: 0\n\tWait at Stop: 0\n\tTime on bus: 0\n";
//   passenger1 = new Passenger(2, "Amogh");
    testing::internal::CaptureStdout();
    passenger->Report(cout);
    string output = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    passenger1->Report(cout);
    string output1 = testing::internal::GetCapturedStdout();

    int p1 = output.find(expected_output);
    int p2 = output1.find(expected_output1);

    EXPECT_GE(p1, 0);
    EXPECT_GE(p2, 0);
 };
=======
>>>>>>> support-code
