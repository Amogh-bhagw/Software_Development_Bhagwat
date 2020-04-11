/**
 * @file IObserver.h
 *
 * @copyright 2020 Amogh Bhagwat, All rights reserved.
 */
#ifndef SRC_IOBSERVER_H_
#define SRC_IOBSERVER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <string>

#include "src/data_structs.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
  * @brief The main class for IObserver
  */
class IObserver {
 public:
   /**
    * @brief Notifying any changes.
    *
    * This is a abstract method.
    * Classes inheirting have to
    * implment
    *
    * @param[in] info New information/data about the object.
    */
  virtual void Notify(BusData * info) = 0;
};
#endif  // SRC_IOBSERVER_H_
