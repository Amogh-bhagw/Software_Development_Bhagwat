/**
 * @file IObservable.cc
 *
 * @copyright 2020 Amogh Bhagwat, All rights reserved.
 */

#include "src/IObservable.h"

void IObservable::RegisterObserver(IObserver * observer) {
  observer_.push_back(observer);
}

void IObservable::ClearObservers() {
  observer_.clear();
}

void IObservable::NotifyObservers(BusData * info) {
  for (std::vector<IObserver*>::const_iterator iter = observer_.begin();
  iter != observer_.end(); ++iter) {
           if (*iter != 0) {
             (*iter)->Notify(info);
           }
         }
}
