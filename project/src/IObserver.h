/**
 * @file IObserver.h
 *
 * @copyright 2020 Amogh Bhagwat, All rights reserved.
 */
 #ifndef SRC_IOBSERVER_H_
 #define SRC_IOBSERVER_H_

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <string>

#include "src/data_structs.h"


class IObserver {
 public:
  virtual void Notify(BusData * info) = 0;
};
#endif  // SRC_IOBSERVER_H_
