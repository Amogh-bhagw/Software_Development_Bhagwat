/**
 * @file IObservable.h
 *
 * @copyright 2020 Amogh Bhagwat, All rights reserved.
 */
 #ifndef SRC_IOBSERVABLE_H_
 #define SRC_IOBSERVABLE_H_

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <string>

#include "src/data_structs.h"
#include "src/IObserver.h"

class IObservable {
 public:
  void RegisterObserver(IObserver * observer);
  void ClearObservers();
  void NotifyObservers(BusData * info);
private:
  std::vector<IObserver*> observer_;

};

#endif  // SRC_IOBSERVABLE_H_
