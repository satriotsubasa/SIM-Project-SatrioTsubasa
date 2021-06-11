# Balen Project SatrioTsubasa

Technology :
1. Arduino UNO
2. GPS+GSM+Bluetooth+SIM Module SIM808
3. GPS Module Neo 6M Ublox

The Build:
1. Ability to connect to the GSM Network XL
2. Display GPS and GSM Signal Strength
3. Display GPS Location coordinates
4. Establish a communication with Balen Server
5. Transmit data to the server
6. Display data in a dashboard

-----------------------------------------------------------------------------------------------------------------------------
Addtional Challange on Part 3:
1. Install Docker on Ubuntu Server
2. Build Server with Docker Container on Ubuntu Balen Server using Python

My Addtional Creation:
1. Create UI with Visual Studio C# (.NET Framework)
2. Display More Complete Data

------------------------------------------------------------------------------------------------------------------------------
Given Time : 14 Days, 
Actual Time to Finished All Task + Additional Challange in : 25 Hours-

------------------------------------------------------------------------------------------------------------------------------
PART 1 - GPS Feature
  Create a system that receives GPS Coordinates form GPS Module and display the coordinate on the console.
  The console must show the following at the minimum :
    1. GPS Location
    2. GPS Strength
  My Addtitional Creation :
    1. Create UI with Visual Studio C# (.NET Framework)
    2. Progress Bar Visualization for GPS Signal Strength
    3. Display Satellite Detected, Date and Time
    
  Given Time : 2 days,
  Actual time to finished Part 1 : 5 Hours
 
------------------------------------------------------------------------------------------------------------------------------
PART 2 - GSM Connectivity
  New requirements to display IP address to the serial console. Use web endpoint http://ipv4bot.whatismyipaddress.com
  The console must show the following at the minimum :
    1. IP Address
    2. GSM Strength
  My Addtitional Creation :
    1. Create UI with Visual Studio C# (.NET Framework)
    2. Progress Bar Visualization for GPS and GSM Signal Strength
    3. Display GPS Data from Part 1, Satellite Detected, Date and Time
    
  Given Time : 4 days,
  Actual time to finished Part 1 : 8 Hours
  
-------------------------------------------------------------------------------------------------------------------------------
PART 3 - Putting All Together to Server
  Now that GPS and GSM are connected, The task is to perform POST to Balen server.
  
  Addtional Challange on Part 3:
  1. Install Docker on Ubuntu Balen Server
  2. Build Server with Docker Container on Ubuntu Balen Server using Python

  Task:
    1. Perform GET and POST all data from part 2 and part 1 to the created server
    Endpoint : http://104.248.152.90:5000
    Method : GET and POST
    Payload : { latitude:x, logitude:x, gps:x, gsm:x, imei:x, ip:x }
    
  My Addtitional Creation :
    1. Create UI with Visual Studio C# (.NET Framework)
    2. Progress Bar Visualization for GPS and GSM Signal Strength
    3. Display GPS Data from Part 1, Satellite Detected, Date and Time
    
  Given Time : 4 days,
  Actual time to finished Part 1 : 12 Hours
 
---------------------------------------------------------------------------------------------------------------------------------

