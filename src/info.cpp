#include <iostream>
#include "httplib.h"
#include "json.hpp"

using json = nlohmann::json;
using namespace httplib;

void handlePreferences(const Request& req, Response& res) {
    // Parse JSON data from the request body
    std::string json_data = req.body;

    try {
        // Parse JSON data
        auto preferences = json::parse(json_data);

        // Print received preferences as a C++ map
        std::cout << "Received preferences:\n";

        for (auto& entry : preferences.items()) {
            std::cout << entry.key() << ": " << entry.value() << std::endl;
        }

        // Process the preferences as needed
        // You might want to store them in a database or perform some other action

        // Send a response
        res.set_content("Preferences received successfully", "text/plain");
    } catch (const json::parse_error& e) {
        std::cerr << "Error parsing JSON: " << e.what() << std::endl;
        res.set_content("Error parsing JSON", "text/plain");
    }
}

int main() {
    Server server;

    // Handle POST requests to the /preferences endpoint
    server.Post("/preferences", handlePreferences);

    // Start the server on port 8080
    server.listen("localhost", 3001);

    return 0;
}
