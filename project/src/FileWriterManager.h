/**
 * @file FileWriterManager.h
 *
 * @copyright 2020 Amogh Bhagwat, All rights reserved.
 */
#ifndef SRC_FILEWRITERMANAGER_H_
#define SRC_FILEWRITERMANAGER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "src/FileWriter.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the FileWriterManager. The singleton pattern
 *
 */
class FileWriterManager {
 public:
   /**
    * @brief returns a instance to FileWriter.
    *
    * @return a FileWriter pointer
    */
   static FileWriter* Getinstance();
};
#endif  // SRC_FILEWRITERMANAGER_H_
