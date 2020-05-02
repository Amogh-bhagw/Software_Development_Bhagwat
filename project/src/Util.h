/**
 * @file Util.h
 *
 * @copyright 2020 Amogh Bhagwat, All rights reserved.
 */
#ifndef SRC_UTIL_H_
#define SRC_UTIL_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

/*******************************************************************************
 * Class Definitions
******************************************************************************/
/**
 * @brief The main class for the Util. Helps the structure of the strings.
 */
class Util {
 /**
  * @brief Write to the inputed file.
  *
  * This method takes in a file and a vector of strings and
  * inputs it into the file.
  *
  * @param[in] report The statics that need to be inputted into file.
  *
  * @return Vector of stings that holds the statics.
  */
 public:
    static std::vector<std::string> processOutput(std::string report) {
      std::vector<std::string> res;
      std::string temp = "";

      for (int i = 0; i < report.size(); i++) {
        if (report[i] == ' ' || report[i] == ':' || report[i] == '\n' ||
        report[i] == '\t') {
           if (temp != "") {
             res.push_back(temp);
           }
          temp = "";
         } else {
          if (report[i] != ' ' && report[i] != '\n' && report[i] != '\t')
           temp.push_back(report[i]);
        }
      }
     if (temp != "")
       res.push_back(temp);
     return res;
    }
};
#endif  // SRC_UTIL_H_
