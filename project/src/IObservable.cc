/**
 * @file IObservable.cc
 *
 * @copyright 2020 Amogh Bhagwat, All rights reserved.
 */

#include "src/IObservable.h"

void IObservable::RegisterObserver(IObserver * observer) {
  observer_.push_back(observer);  // adds to the vector
}

void IObservable::ClearObservers() {
  observer_.clear();  // clears the whole vector
}

void IObservable::NotifyObservers(BusData * info) {
  // we loop through the whole vector and call notify on
  // each object
  for (std::vector<IObserver*>::const_iterator iter = observer_.begin();
  iter != observer_.end(); ++iter) {
           if (*iter != 0) {
             (*iter)->Notify(info);
           }
         }
}
