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

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for IObservable.
 */
class IObservable {
 public:
  /**
   * @brief Adding observer to vector.
   *
   * This method adds any object
   * being observed to the vector observer_
   *
   * @param[in] observer Object/item to be observed
   */
  void RegisterObserver(IObserver * observer);
  /**
   * @brief Clearing the observer_ vector
   *
   * This clears the vector of anything
   * that is currently being observed
   *
   */
  void ClearObservers();
  /**
   * @brief Notifying any changes.
   *
   * This method calls the
   * Notify method on every object
   * being observed
   *
   * @param[in] info New information/data about the object.
   */
  void NotifyObservers(BusData * info);

 private:
  /*
   * @brief Holds what is being observed.
   **/
  std::vector<IObserver*> observer_;
};

#endif  // SRC_IOBSERVABLE_H_
