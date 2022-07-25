#include <iostream>
#include <map>
#include <string>
#include <vector>

void displayMenu();
void displayChannels(std::map<std::string, std::string> &channelMap);
void displaySynch(std::map<std::string, std::vector<std::string>> &synchMap);

int main() {
  // Maps for channels and synchronicity
  std::map<std::string, std::string> channelToSynch;
  std::map<std::string, std::vector<std::string>> synchToChannel;

  // Initialize channel -> synch values
  channelToSynch.insert(
      std::make_pair("Face-to-Face", "Synchronous (Instantaneous)"));
  channelToSynch.insert(
      std::make_pair("Video Chat", "Synchronous (Instantaneous)"));
  channelToSynch.insert(
      std::make_pair("Telephone", "Synchronous (Instantaneous)"));
  channelToSynch.insert(std::make_pair("Texting", "Intermediate (Both)"));
  channelToSynch.insert(std::make_pair("email", "Intermediate (Both)"));
  channelToSynch.insert(std::make_pair("Social-Media", "Intermediate (Both)"));
  channelToSynch.insert(std::make_pair("Online Forums", "Intermediate (Both)"));
  channelToSynch.insert(std::make_pair("Voice Mail", "Asynchronous"));
  channelToSynch.insert(std::make_pair("Mail (snail)", "Asynchronous"));
  channelToSynch.insert(std::make_pair("Fax", "Asynchronous"));

  // Initialize synch -> channel values
  synchToChannel["Synchronous"] = {"Face-to-Face", "Video Chat", "Telephone"};
  synchToChannel["Intermediate (Both)"] = {"Texting", "email", "Social-Media",
                                           "Online Forums"};
  synchToChannel["Asynchronous"] = {"Voice Mail", "Mail (snail)", "Fax"};

  // Display menu
  std::cout << "Welcome to the Media Synchronicity Theory Depiction!\n";
  std::cout << "Select an option by entering the corresponding number. Press q "
               "to quit"
            << '\n';

  displayMenu();

  // Get input from user
  std::string in;
  std::cin >> in;

  while (in != "q") {
    if (in == "1") {
      // display channels
      displayChannels(channelToSynch);
    } else if (in == "2") {
      // Display synchronicity
      displaySynch(synchToChannel);
    } else {
      std::cout
          << "Invalid input. Please select a menu option. Press q to quit.";
    }

    // Get next selection
    displayMenu();
    std::cin >> in;
  }

  return 0;
}
void displayMenu() {
  std::cout << "--- Menu ---" << '\n';
  std::cout << "1. Select by channel" << '\n';
  std::cout << "2. Select by synchronicity" << '\n' << '\n';
}
void displayChannels(std::map<std::string, std::string> &channelMap) {
  // Channel vector
  std::vector<std::string> channels = {
      "Face-to-Face", "Video Chat",    "Telephone",  "Texting",      "email",
      "Social-Media", "Online Forums", "Voice Mail", "Mail (snail)", "Fax"};

  // Output channels
  std::cout << "--- Communication Channels ---\n" << '\n';
  std::cout << "1. Face-to-Face\n";
  std::cout << "2. Video Chat\n";
  std::cout << "3. Telephone\n";
  std::cout << "4. Texting\n";
  std::cout << "5. email\n";
  std::cout << "6. Social-Media\n";
  std::cout << "7. Online Forums\n";
  std::cout << "8. Voice Mail\n";
  std::cout << "9. Mail\n";
  std::cout << "10. Fax\n";
  std::cout << "Select an option by entering the corresponding number: ";

  std::string in;
  std::cin >> in;
  int intIn = std::stoi(in) - 1;

  if (intIn < 0 || intIn > 10) {
    std::cout << "Invalid input!\n";
  } else {
    std::cout << '\n';
    std::cout << "Communication Channel: " << channels.at(intIn) << '\n';
    std::cout << "Synchronicity: " << channelMap[channels.at(intIn)] << '\n'
              << '\n';
  }
}
void displaySynch(std::map<std::string, std::vector<std::string>> &synchMap) {
  // Synch vector
  std::vector<std::string> synch = {"Synchronous", "Intermediate (Both)",
                                    "Asynchronous"};

  // Output Synchronicity
  std::cout << "--- Media Synchronicity ---\n" << '\n';
  std::cout << "1. Synchronous\n";
  std::cout << "2. Intermediate (Both)\n";
  std::cout << "3. Asynchronous\n";
  std::cout << "Select an option by entering the corresponding number: ";

  std::string in;
  std::cin >> in;
  int intIn = std::stoi(in) - 1;

  if (intIn < 0 || intIn > 3) {
    std::cout << "Invalid input!\n\n";
  } else {
    std::cout << "\nMedia Synchronicity: " << synch.at(intIn) << '\n';
    std::cout << "Communication Channels:\n";

    for (int i = 0; i < synchMap.at(synch.at(intIn)).size(); ++i) {
      std::cout << synchMap.at(synch.at(intIn)).at(i) << '\n';
    }
    std::cout << '\n';
  }
}