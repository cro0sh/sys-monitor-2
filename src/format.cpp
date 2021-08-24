#include "format.h"

#include <iostream>
#include <string>
#include <iomanip>

using std::string;

/*
string Format::ElapsedTime(long sec) {
  int hour;
  int min;
  std::cout << std::setfill('0') << std::setw(2) << hour << ":";
  std::cout << std::setfill('0') << std::setw(2) << min << ":" ;
  std::cout << std::setfill('0') << std::setw(2) << sec;
}
*/

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long sec) {
  long time, hour, min;
  //string hour;
  //string min;
  time = sec;
  hour = time/3600;
  min = (time%3600) / 60;
  sec = (time%3600) % 60;
  std::ostringstream stream;
  stream << std::setw(2) << std::setfill('0') << hour << ":"
  << std::setw(2) << std::setfill('0') << min << ":"
  << std::setw(2) << std::setfill('0') << sec;
  std::cout << "\n steam.str() \n" << stream.str();
  return stream.str();
}

/*string Format::ElapsedTime(long seconds) {
  int SEC_IN_MIN = 60;
  int MIN_IN_HR = 60;
  int SEC_IN_HR = SEC_IN_MIN * MIN_IN_HR;
  long hours, minutes;
  hours = seconds/SEC_IN_HR;
  seconds.insert(0, 2 - seconds.length(), '0');
  seconds = seconds%SEC_IN_HR;


  // seconds = std::to_string(seconds);

  minutes = seconds/SEC_IN_MIN;
  seconds = seconds%SEC_IN_MIN;

  std::cout << (std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(seconds));
  return (std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(seconds));
}*/


/*string Format::ElapsedTime(long seconds) {
  long minutes = seconds / 60;
  *//*if (seconds > 59) {
    std::cout << "zeroing out seconds ";
    return 0;
  }*//*
  string seconds_ = std::to_string(seconds);

  seconds_.insert(0, 2 - seconds_.length(), '0');
  std::cout << "\n SECONDS OUTPUT \n " << seconds;

string minutes_ = std::to_string(minutes);
minutes_.insert(0, 2 - minutes_.length(), '0');
std::cout << "\n minutes OUTPUT \n " << minutes_;
  long hours = minutes / 60;
  string hours_ = std::to_string(hours);
  hours_.insert(0, 2 - hours_.length(), '0');
  string output = hours_ + ":" + minutes_ + ":" + seconds_;
  std::cout << "\n OUTPUT \n " << output;
  //return output;

return "china";
}*/
