/**
 * @file FileWriterManager.cc
 *
 * @copyright 2020 Amogh Bhagwat, All rights reserved.
 */

#include "src/FileWriterManager.h"

// We start out with the file_writer being NULL, so it gets instanated
static FileWriter* file_writer = NULL;
FileWriter* FileWriterManager::Getinstance() {
  if (!file_writer) {
     file_writer = new FileWriter;
  }
  return file_writer;
}
