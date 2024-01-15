#include <iostream>
#include <vector>

using namespace std;

vector<string> travel(const vector<pair<string, string>>& tickets, int routes ) {

    vector<string> cities;
    string firstCity = "Sofia";
    string secondCity;

    for (const auto& ticket : tickets) {

        if (firstCity == ticket.first) {
            cities.push_back(ticket.first);
            secondCity = ticket.second;
        }

    }

    firstCity = secondCity;

    for (int i = 0; i < routes - 1; i++) {

        for (const auto& ticket : tickets) {

            if (firstCity == ticket.first) {
                cities.push_back(ticket.first);
                secondCity = ticket.second;
            }

        }

        firstCity = secondCity;
    }

    cities.push_back(secondCity);

    return cities;
}


int main() {

    vector<pair<string, string>> tickets = {
        {"Plovdiv", "Burgas"},
        {"Sofia", "Plovdiv"},
        {"Varna", "Pleven"},
        {"Burgas", "Varna"}
    };

    int routes = 4;

    vector<string> route = travel(tickets, routes);

    cout << "Reconstructed route:" << endl;

    for (const std::string& city : route) {
        cout << city << endl;
    }

    return 0;
}