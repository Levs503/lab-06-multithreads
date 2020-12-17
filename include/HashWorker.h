//
// Created by levs503 on 17.12.2020.
//



#ifndef LAB_06_MULTITHREADS_HASHWORKER_H
#define LAB_06_MULTITHREADS_HASHWORKER_H

#include <string>
#include <vector>
#include <picosha2.h>
#include <string>
#include<random>
#include<mutex>
#include <boost/log/trivial.hpp>
#include <ctime>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>

boost::mutex mut;

struct RightHash{
  std::string data, hash;
  long time;
};

class HashWorker {
 public:
  static std::vector<RightHash> rightHash;

  std::string GetHesh(std::string& data2) {
    std::string ret = picosha2::hash256_hex_string(data2);
    return ret;
  }

  bool Check(std::string& Hash){
    std::string substr = Hash.substr(Hash.size() - 4, 4);
    if(substr == "0000") return true;
    return false;
  }

};

std::vector<RightHash> HashWorker::rightHash = {};

void FindHash(){
  HashWorker worker;
  srand(time(NULL));
  auto begin = std::chrono::steady_clock::now();
  for(;;){
    std::string data = std::to_string(rand());
    std::string currentHash = worker.GetHesh(data);
    if(worker.Check(currentHash)) {
      BOOST_LOG_TRIVIAL(info) << "sha256(" << data << ") = " << currentHash << " thread id: " << long(boost::this_thread::get_id) << std::endl;
      auto end = std::chrono::steady_clock::now();
      mut.lock();
      auto timeMs = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
      HashWorker::rightHash.push_back({data, currentHash, timeMs});
      mut.unlock();
      break;
    }
  }
}



#endif  // LAB_06_MULTITHREADS_HASHWORKER_H
