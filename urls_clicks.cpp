/*
You are in charge of a display advertising program. Your ads are displayed on websites all over the internet. You have some CSV input data that counts how many times that users have clicked on an ad on each individual domain. Every line consists of a click count and a domain name, like this:
 
counts = [ "900,google.com",
     "60,mail.yahoo.com",
     "10,mobile.sports.yahoo.com",
     "40,sports.yahoo.com",
     "300,yahoo.com",
     "10,stackoverflow.com",
     "2,en.wikipedia.org",
     "1,es.wikipedia.org",
     "1,mobile.sports",
     "1,google.co.uk"]
 
Write a function that takes this input as a parameter and returns a data structure containing the number of clicks that were recorded on each domain AND each subdomain under it. For example, a click on "mail.yahoo.com" counts toward the totals for "mail.yahoo.com", "yahoo.com", and "com". (Subdomains are added to the left of their parent domain. So "mail" and "mail.yahoo" are not valid domains. Note that "mobile.sports" appears as a separate domain near the bottom of the input.)
 
Sample output (in any order/format):
 
calculateClicksByDomain(counts)
1320    com
 900    google.com
 410    yahoo.com
  60    mail.yahoo.com
  10    mobile.sports.yahoo.com
  50    sports.yahoo.com
  10    stackoverflow.com
   3    org
   3    wikipedia.org
   2    en.wikipedia.org
   1    es.wikipedia.org
   1    mobile.sports
   1    sports
   1    uk
   1    co.uk
   1    google.co.uk
 
*/
 
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
 
using namespace std;
 
map<string, int> calcClicksByDomain(const vector<vector<string>>& counts) {
  
  map<string, int> results;
  
  for (unsigned int i {}; i < counts.size(); ++i) {
    // count = cout << counts[i][0] << endl;
    
    // URL = cout << counts[i][1] << endl;
    
    string url = counts[i][1];
    int clicks = stoi(counts[i][0]);
    
    results[url] = clicks;
    
    // how many more are there?
    
    // additional valid URL
    
    //===
    // while there are more dots.. do the below
    
    string remaining_string = url;
    while(keep_going) {
    
      int dot_position = remaining_string.find_first_of('.');
      // url should be "remaining string"
    
      string additional_url = remaining_string.substr(dot_position+1, remaining_string.size() - dot_position);
      results[additional_url] += clicks;
      
      // keep going is based on whether "remaining string" has a dot
    
    }
    //===
    
    //cout << additional_url << endl;
    // wikipedia.org
    //results[additional_url] = clicks;
    
    
    
  }
  
  
  return results;
  
  
}
 
// process vector
 
// init map of above domains and their counts
 
 
// process each entry
 
// split entry into relevant items based on find .
// i.e. en.wiki.org becomes en.wiki.org > wiki.org > org
 
// for each unique domain, update its map value.. ensure you ++ instead of overwrite
 
// return map
 
 
// To execute C++, please define "int main()"
int main() {
  vector<vector<string>> counts = {
    {"900","google.com"},
    {"60","mail.yahoo.com"},
    {"10","mobile.sports.yahoo.com"},
    {"40","sports.yahoo.com"},
    {"300","yahoo.com"},
    {"10","stackoverflow.com"},
    {"2","en.wikipedia.org"},
    {"1","es.wikipedia.org"},
    {"1","mobile.sports"},
    {"1","google.co.uk"}
  };
  
  auto result = calcClicksByDomain(counts);
  
  cout << result["com"];
  
  return 0;
}
