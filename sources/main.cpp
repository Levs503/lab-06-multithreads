//
// Created by Лев on 16.12.2020.
//
#include <picosha2.h>

#include <boost/thread.hpp>
#include <iostream>

#include "HashWorker.h"

static int threadCount = boost::thread::hardware_concurrency();

int main(int arguments_count, char const* arguments[]) {
  std::string fileName;
  if (arguments_count >= 2) {
    if (std::stoul(arguments[1]) > 0) threadCount = std::stoul(arguments[1]);
    if (arguments_count >= 3) fileName = arguments[2];
  }

  std::vector<boost::thread> threads;
  for (size_t g = 0; g < 12; g++) {
    threads.emplace_back(FindHash);
  }
  for (size_t g = 0; g < 12; g++) {
    threads[g].join();
  }
  if (!fileName.empty()) {
    std::ofstream out(fileName);
    WriteToFile(out, HashWorker::rightHash);
    out.close();
  }
}
