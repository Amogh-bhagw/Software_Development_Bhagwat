/**
 * @file FileWriter.h
 *
 * @copyright 2020 Amogh Bhagwat, All rights reserved.
 */
#ifndef SRC_FILEWRITER_H_
#define SRC_FILEWRITER_H_

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
 * @brief The main class for the FileWriter, which helps write to a file.
 */
class FileWriter {
 public:
   /**
    * @brief Write to the inputed file.
    *
    * This method takes in a file and a vector of strings and
    * inputs it into the file.
    *
    * @param[in] file Name of the file
    * @param[in] data Vector of stings to be inputted
    *
    */
  FileWriter() {}
  void Write(std::string file, std::vector<std::string> data) {
   std::ofstream myfile;
   myfile.open(file, std::ios_base::app);  // appends to the file

   for(std::vector<std::string>::const_iterator it = data.begin();
        it != data.end(); it++) {
          if((*it) != ",") {  // helps with separating of data
          myfile << (*it) << " ";
        }
        else {
          myfile << std::endl;
        }
      }
    myfile.close();
  }

};
#endif  // SRC_FILEWRITER_H_
