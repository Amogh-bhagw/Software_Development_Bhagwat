#include "gtest/gtest.h"

#include <iostream>
#include <math.h>
#include <ctime>

#include "date.h"


class DateTest : public ::testing::Test {
 public:
  void SetUp( ) {
    // code here will execute just before the test ensues
	first_day = Date(2018, 9, 4);
	last_day = Date(2018, 12, 11);
  new_year_eve = Date(3333,12,31);
  birth_day = Date(1999, 8, 23);
  early_day = Date(1,1,1);
  newYear_day = Date (2016, 1 , 1);
  march_day = Date (2016, 3, 1);
  random_day = Date (100000000);
//  today = Date();
  }
 protected:
  Date first_day;          // first day of classes
  Date last_day;           // last day of classes
  Date new_year_eve;
  Date birth_day;
  Date early_day;
  Date newYear_day;
  Date march_day;
  Date random_day;
//  Date today;
};



TEST_F(DateTest, PrintDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "1999-12-31\n";
  std::string expected_out_2 = "1776-07-04\n";
  std::string expected_out_3 = "2018-10-31\n";

  testing::internal::CaptureStdout();
  y2k.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";

  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

/**
  *
  * Note, this is the only provided test case which actually uses our test fixture
  *
  * However, it is illegal to mix TEST() and TEST_F() in the same test case (file).
  *
  */

TEST_F(DateTest, DaysBetweenTests) {
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "Days between is not calculated properly";
}

// Below are new Test

TEST_F(DateTest, GetDate){
  EXPECT_EQ(first_day.GetDate(), "2018-09-04") << "Check to see if first day is retrieved";
  EXPECT_EQ(last_day.GetDate(), "2018-12-11") << "Last day is correctly returned";
  EXPECT_EQ(new_year_eve.GetDate(), "3333-12-31") <<"Check Future dates";
  EXPECT_EQ(birth_day.GetDate(), "1999-08-23") <<" Check for leading zero";
  EXPECT_EQ(early_day.GetDate(), "1-01-01") <<"all 1's check";
  EXPECT_EQ(random_day.GetDate(), "1973-03-03") << "Epoch test";
    //EXPECT_EQ(today.GetDate(), "2020-20-02") << "Current day";
}
TEST_F(DateTest, DaysBetween2){
  EXPECT_EQ(first_day.DaysBetween(first_day), 0 ) << "Same day";
  EXPECT_EQ(newYear_day.DaysBetween(march_day), 60 ) << "mutate test";


}

/**
  *
  * NOPE!  Can't test PRIVATE methods
  *
  */
/*
TEST(DateTest, ConvertFromDays) {
	Date convert_first_day = ConvertToDays(2458365);
	EXPECT_STREQ(convert_first_day.GetUsDate(), "09-04-2018");
}
*/
