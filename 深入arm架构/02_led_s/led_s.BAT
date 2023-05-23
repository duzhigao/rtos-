SET PATH=D:\keil\ARM\ARMCC\Bin;C:\Program Files (x86)\NetSarang\Xshell 6\;C:\Program Files\Oculus\Support\oculus-runtime;D:\app\dzg\product\11.2.0\dbhome_1\bin;C:\windows\system32;C:\windows;C:\windows\System32\Wbem;C:\windows\System32\WindowsPowerShell\v1.0\;C:\windows\System32\OpenSSH\;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files\NVIDIA Corporation\NVIDIA NvDLISR;D:\enviroment\git\Git\cmd;D:\enviroment\Android\sdk\platform-tools;D:\enviroment\Android\sdk\tools;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\WINDOWS\System32\OpenSSH\;E:\;D:\enviroment\node.js\;D:\python\Scripts\;D:\python\;D:\enviroment\vc6.0\Tools\WinNT;D:\enviroment\vc6.0\MSDev98\Bin;D:\enviroment\vc6.0\Tools;D:\enviroment\VC98\bin;C:\Users\dzg\AppData\Local\Microsoft\WindowsApps;D:\enviroment\IntelliJ IDEA 2020.1\bin;D:\enviroment\JDK 1.8\bin;D:\enviroment\MAVEN\apache-maven-3.6.3-bin\apache-maven-3.6.3\bin;D:\enviroment\node.js\node_global;C:\Users\dzg\AppData\Local\GitHubDesktop\bin;D:\enviroment\JDK 1.8\jre\bin;C:\Program Files\MySQL\MySQL Server 8.0\bin;D:\enviroment\apache-tomcat-8.5.56-windows-x64\apache-tomcat-8.5.56\bin;D:\enviroment\apache-tomcat-8.5.56-windows-x64\apache-tomcat-8.5.56\lib;D:\enviroment\mongodb\bin;D:\enviroment\Redis\Redis-x64-3.2.100\;E:\Microsoft VS Code\bin;C:\Users\dzg\AppData\Local\Microsoft\WindowsApps;C:\Users\dzg\AppData\Roaming\npm;D:\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin;
SET CPU_TYPE=STM32F103ZE
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=led_s
SET CPU_CLOCK=0x00B71B00
"D:\keil\ARM\ARMCC\Bin\ArmAsm" --Via ".\objects\start._ia"
"D:\keil\ARM\ARMCC\Bin\ArmLink" --Via ".\Objects\led_s.lnp"
"D:\keil\ARM\ARMCC\Bin\fromelf.exe" ".\Objects\led_s.axf" --i32combined --output ".\Objects\led_s.hex"
fromelf  --bin  --output=Objects\led.bin  Objects\led_c.axf
fromelf  --text  -a -c  --output=Objects\led.dis  Objects\led_c.axf
