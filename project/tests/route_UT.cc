#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>



#include "../src/data_structs.h"
#include "../src/passenger_generator.h"
#include "../src/stop.h"

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class RouteTests : public ::testing::Test {
protected:
  Stop *stop1, *stop2, *stop3;
  int num_stops;
  double dis1, dis2, dis3;
  string name;

  Stop ** stop_;
  double *distance_;
  PassengerGenerator * generator;
  Route *route_;

  virtual void SetUp(){
    dis1 = 8;
    dis2 = 1;
    dis3 = 1;

    stop1 = new Stop(1, 10, 10);
    stop2 = new Stop(2, 20, 20);
    stop3 = new Stop(3, 30, 30);

    num_stops = 3;
    name = "Magic Route";


    stop_ = new Stop*[3];
    stop_[0] = stop1;
    stop_[1] = stop2;
    stop_[2] = stop3;

    distance_ = new double[3];
    distance_[0] = dis1;
    distance_[1] = dis2;
    distance_[2] = dis3;


    route_ = new Route(name, stop_, distance_, num_stops, generator);
  }

  virtual void TearDown(){
    for (int i = 0; i < 3; i++) {
      delete stop_[i];

    }
    delete[] stop_;
    delete[] distance_;
    delete route_;
  };


};
/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(RouteTests, Constructor){
  EXPECT_EQ(route_->PrevStop(), stop1);
  EXPECT_EQ(route_->GetTotalRouteDistance(), 10) << "check to see total distance";
  EXPECT_EQ(route_->GetDestinationStop(), stop1);
  EXPECT_EQ(route_->GetName(), "Magic Route");
  route_->NextStop();
  EXPECT_EQ(route_->PrevStop(), stop1);
  EXPECT_EQ(route_->GetDestinationStop(), stop2);
  EXPECT_EQ(route_->IsAtEnd(), false);
  route_->NextStop();
  EXPECT_EQ(route_->PrevStop(), stop2);
  EXPECT_EQ(route_->GetDestinationStop(), stop3);
  EXPECT_EQ(route_->IsAtEnd(), false);
  route_->NextStop();
  EXPECT_EQ(route_->IsAtEnd(), true);

};

TEST_F(RouteTests, IsAtEnd){
  EXPECT_EQ(route_->IsAtEnd(), false);
  route_->NextStop();
  EXPECT_EQ(route_->IsAtEnd(), false);
  route_->NextStop();
  EXPECT_EQ(route_->IsAtEnd(), false);
  route_->NextStop();
  EXPECT_EQ(route_->IsAtEnd(), true);
  route_->NextStop();
  EXPECT_EQ(route_->IsAtEnd(), true) << "check to see what happens after all stops";

};
