/**
 * @file IObservable.h
 *
 * @copyright 2020 Amogh Bhagwat, All rights reserved.
 */
#ifndef SRC_IOBSERVABLE_H_
#define SRC_IOBSERVABLE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <string>

#include "src/data_structs.h"
#include "src/IObserver.h"


template<typename T>
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for IObservable.
 */
class IObservable {
 public:
  IObservable() : observer_() {}
  /**
   * @brief Adding observer to vector.
   *
   * This method adds any object
   * being observed to the vector observer_
   *
   * @param[in] observer Object/item to be observed
   */
  void RegisterObserver(IObserver<T> * observer) {
     observer_.push_back(observer);  // adds to the vector
  }
  /**
   * @brief Clearing the observer_ vector
   *
   * This clears the vector of anything
   * that is currently being observed
   *
   */
  void ClearObservers() {
     for (int i = 0; i < static_cast<int>(observer_.size()); i++) {
       delete observer_[i];
     }
     observer_.clear();  // clears the whole vector
  }
  /**
   * @brief Notifying any changes.
   *
   * This method calls the
   * Notify method on every object
   * being observed
   *
   * @param[in] info New information/data about the object.
   */
  void NotifyObservers(T info) {
     // we loop through the whole vector and call notify on
     // each object
     for (int i = 0; i < static_cast<int>(observer_.size()); i++) {
         observer_[i]->Notify(info);
     }
  }

 private:
  /*
   * @brief Holds what is being observed.
   **/
  std::vector<IObserver<T>*> observer_;
};

#endif  // SRC_IOBSERVABLE_H_
