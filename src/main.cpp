#include "session/session.h"
#include <iostream>

/**
   @brief A help function.

   Prints all the available commands that are
   supported by the editor. This function is called
   when the user types "help" at the prompt.
*/

void help() {
  std::cout
      << "The following commands are supported:\n"
      << "help - Displays this help message\n"
      << "exit - Kills all sessions and exits the program\n"
      << "load <file> - Creates a new session and adds <file> to it\n"
      << "switch <session id> - Switches to session with id <session "
         "id>\n"
      << "session info - Displays info about the current session\n"
      << "add <file> - Adds <file> to the current session\n"
      << "remove <file> - Removes <file> from the current sessoin\n"
      << "undo - Removes last pending operation from the current session\n"
      << "apply - Applies all pending operations in the current session\n"
      << "save - Saves all the files in the current session\n"
      << "saveas <file> - Saves the first loaded image in the current "
         "session as <file>\n"
      << "monochrome - Turns all images in the current session monochrome\n"
      << "grayscale - Turns all images in the current session grayscale\n"
      << "negative - Turns all images in the current session negative\n"
      << "rotate <left/right> - Rotates all images in the current session "
         "left/right\n"
      << "collage <horizontal/vertical> <file1> <file2> <outfile> - Makes "
         "a horizontal/vertical collage from <file1> and <file2> and saves "
         "it to <outfile>. The collage is then added to the current "
         "session\n"
      << "scale <factor> <file> <outfile> - Makes a new scaled by factor "
         "of <factor> image and saves it to <outfile>. The scaled image is "
         "then added to the current session\n";
}

/**
   @brief The main function

   In the main function is the main logic of the program.
   I.e the control flow of the program.
*/

int main() {

  int id_num = -1;
  int curr_session_id = id_num;
  std::vector<Session *> sessions;
  std::string input;
  std::cout << "Welcome to raster-edit-cli!\n"
            << "Use command \"help\" to view all commands\n";
  while (true) {
    std::cout << "Enter command > ";
    std::cin >> input;
    if ((input != "load" && input != "help" && input != "exit") &&
        id_num == -1) {
      std::cout << "No loaded session\n";
      continue;
    }
    if (input == "load") {
      std::cin >> input;
      Session *s = new Session(++id_num);
      if (s->add_image(input)) {
        sessions.push_back(s);
      } else {
        delete s;
        id_num--;
        std::cout << "Failed loading session!\n";
        continue;
      }
      curr_session_id = id_num;
      std::cout << "Session with id: " << curr_session_id << " is added!\n";
    } else if (input == "add") {
      std::cin >> input;
      if (curr_session_id != -1) {
        sessions[curr_session_id]->add_image(input);
      }
    } else if (input == "remove") {
      std::cin >> input;
      sessions[curr_session_id]->remove_image(input);
    } else if (input == "switch") {
      int x;
      std::cin >> x;
      if (x >= 0 && x <= id_num) {
        curr_session_id = x;
        std::cout << "Switched to session with id: " << curr_session_id << "\n";
      } else {
        std::cout << "No session with id: " << x << "\n";
      }
    } else if (input == "undo") {
      sessions[curr_session_id]->undo();
    } else if (input == "session") {
      std::cin >> input;
      if (input == "info") {
        sessions[curr_session_id]->info();
      }
    } else if (input == "exit") {
      std::cout << "Exiting!\n";
      break;
    } else if (input == "help") {
      help();
    } else if (input == "apply") {
      sessions[curr_session_id]->apply();
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
      std::string direction, img1, img2, outimage;
      std::cin >> direction >> img1 >> img2 >> outimage;
      sessions[curr_session_id]->collage(direction, img1, img2, outimage);
    } else if (input == "scale") {
      int factor;
      std::string img, out;
      std::cin >> factor >> img >> out;
      sessions[curr_session_id]->scale(factor, img, out);
    }
  }

  for (Session *s : sessions) {
    delete s;
  }

  return 0;
}
