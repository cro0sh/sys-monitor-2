#include "ncurses_display.h"
#include "system.h"
#include "linux_parser.h"
#include <iostream>
#include "process.h"
#include <unistd.h>
#include "format.h"

int main() {
  //float LinuxParser::MemoryUtilization();
  //std::cout << "china";
  /*System system;
  system.Cpu();*/

  /*  GET CPU NAME. IE intel 3570K
  std::string pretty = "PRETTY_NAME";
  std::string empty = "";
  LinuxParser::OperatingSystem(pretty, LinuxParser::kOSPath, ""); // kOSPath, LinuxParser::kProcDirectory + LinuxParser::kVersionFilename
   */
  /* GET KERNEL. IE: 5.8.0-63-generic
   LinuxParser::Kernel(LinuxParser::kProcDirectory, LinuxParser::kVersionFilename); // kProcDirectory + kVersionFilename
   */

  /* MEMORY UTILIZATION - .93
  // used= total – free – buff/cache // memory utilization
  //  Memory Utilization = 1.0 - (free_memory / (total_memory - buffers))
  //LinuxParser::Kernel(LinuxParser::kProcDirectory, LinuxParser::kMeminfoFilename); // good compared to OS filesystem
  // LinuxParser::OperatingSystem("MemTotal:", LinuxParser::kProcDirectory, LinuxParser::kMeminfoFilename);
  //LinuxParser::MemoryUtilization();
   */

  /* Total processes -> ie. 83592
  LinuxParser::TotalProcesses("processes", LinuxParser::kProcDirectory, LinuxParser::kStatFilename); // kProcDirectory + kStatFilename
  */

  /* Number of Process Running -> ie. 2
  LinuxParser::TotalProcesses("procs_running", LinuxParser::kProcDirectory, LinuxParser::kStatFilename);
 */

  /* Linux Uptime -> just the first number. ie. 365461.27
  LinuxParser::UpTime(LinuxParser::kProcDirectory, LinuxParser::kUptimeFilename);
  */

  /* returns weird numbers. see knowledge post
   * Processor processor;
  processor.Utilization();
  "cpu", LinuxParser::kProcDirectory, LinuxParser::kStatFilename
   */

  // LinuxParser::Pids();

/*
  Process process(4);
  process.Pid();*/

  //LinuxParser::Pids();

  //pid_t getpid(void);

  // std::cout << "PID =  " << getppid();

  /*std::string file_path = LinuxParser::kProcDirectory + "2046" + LinuxParser::kStatFilename;
  std::cout << "file path" << file_path;*/

  //std::cout << "file path " <<  LinuxParser::kProcDirectory + 2046 + LinuxParser::kStatFilename;
 /* Process process;
   process.User();*/

  // to get stime, utime, cutime, etc:
  /*Process process;
  process.CpuUtilization2();*/

  /*
    Process process;
  process.Ram();
   */

 //LinuxParser::OperatingSystem("cro0sh:", "/etc/passwd", "");

/* Process process;
 process.UpTime();*/

 //Format::ElapsedTime(91);

 /*Process process;
 process.Command();*/

 // LinuxParser::UpTime(LinuxParser::kProcDirectory, LinuxParser::kUptimeFilename);

 /*Process process;
 process.CpuUtilization();*/

 //LinuxParser::ActiveJiffies();

 //LinuxParser::ActiveJiffies(getppid());

 //LinuxParser::ActiveJiffies();

 //LinuxParser::CpuUtilization();

  //Process proc;
  //proc.operator<();

  // LinuxParser::Command(2046);
  System system;
  NCursesDisplay::Display(system);

  /*System system;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  NCursesDisplay::Display(system);*/

 //NCursesDisplay::DisplaySystem(&system);
 return 0;
  //System::Cpu();

 }