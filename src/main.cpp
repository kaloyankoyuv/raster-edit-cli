#include "Session/Session.hpp"
#include <iostream>

int main() {

  int id_num = -1;
  int curr_session_id = id_num;
  std::vector<Session *> sessions;
  std::string input;
  while (true) {
    std::cout << "Enter command > ";
    std::cin >> input;
    if (input != "load" && id_num == -1) {
      std::cout << "No loaded session" << std::endl;
      continue;
    }
    if (input == "load") {
      std::cin >> input;
      sessions.push_back(new Session(input, ++id_num));
      curr_session_id = id_num;
      std::cout << "Session with id: " << curr_session_id << " is added"
                << std::endl;
    } else if (input == "add") {
      std::cin >> input;
      if (curr_session_id != -1) {
        sessions[curr_session_id]->add_image(input);
      }
      std::cout << "Added image: " << input << std::endl;
    } else if (input == "switch") {
      int x;
      std::cin >> x;
      if (x >= 0 && x <= id_num) {
        curr_session_id = x;
        std::cout << "Switched to session with id: " << curr_session_id
                  << std::endl;
      } else {
        std::cout << "No session with id: " << x << std::endl;
      }
    } else if (input == "undo") {
      sessions[curr_session_id]->undo();
      std::cout << "Undid last operation!" << std::endl;
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
      std::cout << "Applied operations!" << std::endl;
    } else if (input == "save") {
      sessions[curr_session_id]->save();
      std::cout << "Saving images in current session!" << std::endl;
    } else if (input == "saveas") {
      std::cin >> input;
      sessions[curr_session_id]->saveas(input);
      std::cout << "Saved first image in session as: " << input << std::endl;
    } else if (input == "monochrome") {
      sessions[curr_session_id]->add_operation(input);
      std::cout << "Monochrome operation added to pending operations"
                << std::endl;
    } else if (input == "grayscale") {
      sessions[curr_session_id]->add_operation(input);
      std::cout << "Grayscale operation added to pending operations"
                << std::endl;
    } else if (input == "negative") {
      sessions[curr_session_id]->add_operation(input);
      std::cout << "Negative operation added to pending operations"
                << std::endl;
    } else if (input == "rotate") {
      std::cin >> input;
      if (input == "left") {
        sessions[curr_session_id]->add_operation("rotate left");
        std::cout << "Rotate left operation added to pending operations"
                  << std::endl;
      } else if (input == "right") {
        sessions[curr_session_id]->add_operation("rotate right");
        std::cout << "Rotate right operation added to pending operations"
                  << std::endl;
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
      std::cout << "Made collage from images: " << img1 << " and " << img2
                << std::endl;
    } else if (input == "scale") {
      int factor;
      std::cin >> factor;
      std::string img;
      std::cin >> img;
      std::string out;
      std::cin >> out;
      sessions[curr_session_id]->scale(factor, img, out);
      std::cout << "Scaled " << img << " by factor of " << factor << std::endl;
    }
  }

  for (Session *s : sessions) {
    delete s;
  }

  return 0;
}
