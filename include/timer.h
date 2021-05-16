#ifndef INCLUDE_TIMER_H_
#define INCLUDE_TIMER_H_

#include <chrono>
#include <iostream>

using Clock = std::chrono::high_resolution_clock;

class Timer {

 public:
  Timer() { m_start = Clock::now(); }
  ~Timer(){
  m_end = Clock::now();
  m_duration = m_end - m_start;
  std::cerr << "Timer took : " << m_duration.count() << " s." << std::endl;
}

 protected:
  std::chrono::time_point<Clock> m_start;
  std::chrono::time_point<Clock> m_end;
  std::chrono::duration<double> m_duration;

};


#endif