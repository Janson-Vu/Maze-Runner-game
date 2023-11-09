#include <chrono>
#include <string>

#include "MazeRunner.h"
#include "OOPGame.h"

int main() {
  OOPGame* mazeRunner;  // just for the sake of polymorphism
  mazeRunner = new MazeRunner(1000, 600, "Maze Runner");

  // game intro
  std::cout << "-------------------------------------------------------------"
            << std::endl;
  std::cout << "PRESS P TO PLAY "
            << "-----"
            << "S TO SAVE"
            << "------"
            << "Q TO EXIT " << std::endl;
  std::cout << "Your option: ";
  std::string key = " ";

  while (key != "P" || key != "p" || key != "Q" || key != "q") {
    std::cin >> key;
    if (key == "Q" || key == "q" || key == "P" || key == "p") {
      break;
    }
  }
  std::cout << std::endl;

  if (key == "Q" || key == "q") {
    exit(0);
  }
  std::cout << "-------------------------------------------------------------"
            << std::endl;
  std::cout << "Your are in a maze. " << std::endl;
  std::cout << "You are trapped and stuck."
            << "\n"
            << "You have to find the key and door to escape." << std::endl;
  std::cout << "-------------------------------------------------------------"
            << std::endl;
  std::cout << "HINT: the KEY is GREEN, the DOOR is BLUE." << std::endl;
  std::cout << "Press SPACE BAR to COLLECT the key and OPEN the door."
            << std::endl;

  // create an object of `steady_clock` class
  std::chrono::steady_clock sc;

  // start timer

  auto start = sc.now();

  mazeRunner->run();

  // end timer (starting & ending is done by measuring the time at the moment
  // the process started & ended respectively)
  auto end = sc.now();

  // measure time span between start & end
  auto time_span = static_cast<std::chrono::duration<double> >(end - start);

  std::string time_string =
      "Operation took: " + std::to_string(time_span.count()) + " seconds !!!";
  std::cout << time_string << std::endl;

  delete mazeRunner;

  return 0;
}
