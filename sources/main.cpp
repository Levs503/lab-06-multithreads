//
// Created by Лев on 16.12.2020.
//
#include <picosha2.h>
#include<iostream>
#include "HashWorker.h"
#include <boost/thread.hpp>



int main(){

  std::vector<boost::thread> threads;

  for(size_t g =0; g<12; g++){
    threads.emplace_back(FindHash);
  }
  for(size_t g =0; g<12; g++){
    threads[g].join();
  }
}