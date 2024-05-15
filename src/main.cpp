#include "Session/Session.hpp"
#include <iostream>

int main() {

  int id_num = -1;
  int curr_session_id = id_num;
  std::vector<Session *> sessions;
  std::string input;
  while (true) {
    std::cin >> input;
    if (input == "load") {
      std::cin >> input;
      sessions.push_back(new Session(input, ++id_num));
      curr_session_id = id_num;
    } else if (input == "add") {
      std::cin >> input;
      if (curr_session_id != -1) {
        sessions[curr_session_id]->add_image(input);
      }
    } else if (input == "switch") {
      int x;
      std::cin >> x;
      if (x >= 0 && x <= id_num) {
        curr_session_id = x;
      }
    } else if (input == "undo") {
      sessions[curr_session_id]->undo();
    } else if (input == "session") {
      std::cin >> input;
      if (input == "info") {
        sessions[curr_session_id]->info();
      }
    } else if (input == "exit") {
      std::cout << "Exiting!" << std::endl;
      break;
    } else if (input == "help") {
      std::cout << "RTFM" << std::endl;
    } else if (input == "apply") {
      sessions[curr_session_id]->apply();
      std::cout << "finished" << std::endl;
    } else if (input == "save") {
      sessions[curr_session_id]->save();
    } else if (input == "saveas") {
      std::cin >> input;
      sessions[curr_session_id]->saveas(input);
    } else if (input == "monochrome") {
      sessions[curr_session_id]->add_operation(input);
    } else if (input == "grayscale") {
      sessions[curr_session_id]->add_operation(input);
    } else if (input == "negative") {
      sessions[curr_session_id]->add_operation(input);
    } else if (input == "rotate") {
      std::cin >> input;
      if (input == "left") {
        sessions[curr_session_id]->add_operation("rotate left");
      } else if (input == "right") {
        sessions[curr_session_id]->add_operation("rotate right");
      }
    } else if (input == "collage") {
      std::string direction;
      std::cin >> direction;
      std::string img1;
      std::cin >> img1;
      std::string img2;
      std::cin >> img2;
      std::string outimage;
      std::cin >> outimage;
      sessions[curr_session_id]->collage(direction, img1, img2, outimage);
    }
  }

  for (Session *s : sessions) {
    delete s;
  }

  return 0;
}
