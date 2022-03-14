/** The MIT License (MIT)

Copyright (c) 2021 victor7376@github

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "CBFollowAPI.h"

CBFollow::CBFollow(String username, String token)
{
  myUsername = username;
  myToken = token;
}

void CBFollow::updateDetails(String username, String token){

  myUsername = username;
  myToken = token;
}

void CBFollow::getDetails(){

      WiFiClientSecure modelClient;
      modelClient.setInsecure();
      
      if (WiFi.status() == WL_CONNECTED) {
        Serial.println(F("Connecting to Chaturbate..."));
      if (!modelClient.connect("chaturbate.com", 443)) {
        Serial.println(F("Failed to connect to Chaturbate"));
//        resetCBFollowData();
        return;
      }
      Serial.println(F("Connected to Chaturbate"));
    
      Serial.println(F("Sending Follow Data request to Chaturbate..."));
      // Send HTTP request
      modelClient.println("GET /statsapi/?username=" + myUsername + "&token=" + myToken + " HTTP/1.0");
      Serial.println("GET /statsapi/?username=" + myUsername + "&token=" + myToken + " HTTP/1.1");
      modelClient.println(F("Host: chaturbate.com"));
      modelClient.println(F("User-Agent: Arduino"));
      modelClient.println(F("Connection: close"));
      modelClient.println();

  
      //Check the returning code                                                                  
        char status[32] = {0};
      modelClient.readBytesUntil('\r', status, sizeof(status));
      Serial.println("Response Header: " + String(status));
      if (strcmp(status, "HTTP/1.1 200 OK") != 0) {
        Serial.print("Unexpected HTTP status");
        Serial.println(status);
//        resetCBFollowData();
        return;
      }

      Serial.println(F("Receive Follow Data response from chaturbate..."));

      // Skip response headers
      modelClient.find("\r\n\r\n");
//      resetCBFollowData();

      // V6
      DynamicJsonDocument doc(600);
      DeserializationError error = deserializeJson(doc, modelClient);
      if (error) {
          Serial.println(F("Chaturbate Follow Data Parsing failed!"));
          return;
      }

      CBFollowData.followers = doc["num_followers"].as<long>();
      CBFollowData.balance = doc["token_balance"].as<long>();

      CBFollowData.resultPayout = CBFollowData.balance * 0.05;
      
      const char* username = doc["username"]; // "cbrules"
      int time_online = doc["time_online"]; // -1
      // doc["tips_in_last_hour"] is null
      int num_followers = doc["num_followers"]; // 0
      int token_balance = doc["token_balance"]; // 3
      int satisfaction_score = doc["satisfaction_score"]; // 100
      int num_tokened_viewers = doc["num_tokened_viewers"]; // 0
      int votes_down = doc["votes_down"]; // 0
      int votes_up = doc["votes_up"]; // 0
      int last_broadcast = doc["last_broadcast"]; // -1
      int num_registered_viewers = doc["num_registered_viewers"]; // 0
      int num_viewers = doc["num_viewers"]; // 0

      
    }
    modelClient.stop();
}
