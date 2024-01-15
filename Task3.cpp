#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<string> splitIntoTweets(const string& text, int maxTweetLength) {
    
    vector<string> tweets;
    vector<string> words;
    istringstream iss(text);
    string word;

    while (iss >> word) {
        words.push_back(word);
    }

    string currentTweet;

    for (const string& word : words) {

        if (currentTweet.length() + word.length() > maxTweetLength) {
            
            tweets.push_back(currentTweet); // Store the current tweet
            currentTweet = ""; // Start a new tweet
        }
        
        currentTweet += word + " ";
    }

    if (!currentTweet.empty()) {
        tweets.push_back(currentTweet); // Store the last tweet
    }

    return tweets;
}

int main() {
    
    string text = "Lorem ipsum dolor sit amet consectetur adipiscing elit sed do eiusmod "
        "tempor incididunt ut labore et dolore magna aliqua Ut enim ad minim veniam "
        "quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo "
        "consequat Duis aute irure dolor in reprehenderit in voluptate velit esse "
        "cillum dolore eu fugiat nulla pariatur Excepteur sint occaecat cupidatat "
        "non proident sunt in culpa qui officia deserunt mollit anim id est laborum";

    int maxTweetLength = 140;

    vector<string> tweets = splitIntoTweets(text, maxTweetLength);

    int counter = 1;
    for (const string& tweet : tweets) {
        cout << "(tweet #" << counter << ")" << endl;
        cout << tweet << endl;
        counter++;
    }

    return 0;
}
