# CB-Clock
Clock for Models, to show your follow count &amp; tokens

# Required
To make the clock work you will need the following:

USA - D1 Mini or compatible
https://www.amazon.com/MakerFocus-NodeMcu-Development-ESP8266-Compatible

UK - D1 Mini £5.99
https://www.amazon.co.uk/AZDelivery-D1-Mini-Development-Compatible/dp/B01N9RXGHY

USA - Max7219 $8.79 - 1 for basic clock / 2 x displays linked for better reading
https://www.amazon.com/HiLetgo-MAX7219-Arduino-Microcontroller-Display/dp/B07FFV537V

UK - Max7219 £7.99 - 1 for basic clock / 2 x displays linked for better reading
https://www.amazon.co.uk/ARCELI-MAX7219-Arduino-Microcontroller-Display/dp/B07J2QTK57


# EDIT THE FOLLOWING SECTIONS IN *marquee-CBFollow.ino* FILE:

============================ *Your WIFI Network Details* =================================

const char* ssid     = "***YOUR_SSID***";          // Your SSID / WiFi Network

const char* password = "***YOUR_WIFI_PASSWORD***";  // Your SSID / WiFi Password

================================ *TimezoneDB Settings* ================================

String TIMEDBKEY = "***YOUR_API_KEY_FROM_TIMEZONEDB***"; // Your API Key from https://timezonedb.com/register

String LAT = "***YOUR_LAT***";          // Latitude

String LON = "***YOUR_LON***";          // Longitude

*Here you can choose how many displays you have - Displays come in a set of 4, so double would be 8 etc
So if you have 2 Displays the HorizontalDisplays would be 8 !!*

const int numberOfHorizontalDisplays = ***4***; // default 4 for standard 4 x 1 display

const int numberOfVerticalDisplays = ***1***; // default 1 for a single row height

//================================ *Chaturbate Settings* ================================

boolean CHATURBATE_ENABLED = ***false***;            // change to true if you want it enabled

//=============================================================================

String CBFollowUsername = "***YOUR_USERNAME***";      // enter Your username from Chaturbate

// Get your Chaturbate Token from - https://chaturbate.com/statsapi/authtoken/

String CBFollowToken = ***YOUR_CHATURBATE_TOKEN***;  // Your Chaturbate token

boolean CHATURBATE_FOLLOWERS = ***true***;  // To show how many followers you have

boolean CHATURBATE_BALANCE = ***true***;    // To show how many tokens you have

boolean CHATURBATE_CONVERT = ***true***;    // To show tokens converted to Dollars

//=============================================================================



# Chaturbate
Required Settings:
Username - From Chaturbate (of course)
Token - From your profile settings page: https://chaturbate.com/statsapi/authtoken/

# Clock Settings
Required for Clock
API Key from timezonedb.com
Latitude & Longitude from TimeZoneDB (on the main page), just need to click on Get my current latitude and longitude & copy into the settings.

# If you require anyhelp please raise an issue or contact us on Twitter.
