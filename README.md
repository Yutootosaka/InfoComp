HINT : PLEASE REVIEW THIS DOCUMENT IN ITS ENTIRETY!!!

INFO ABOUT THIS PROGRAM :
This program collects system information such as the hostname, OS version, registered owner, processor architecture, system model, and IPv4 address. The information is then saved into a file called "Info.txt".

NOTE :
- this program only work on Windows Environment
- before run this program maksure get rid of useless files like .vscode test.txt
- after run this program, the program generated info.txt, Inside the info.txt there is:
     SYSTEM INFORMATION
     ==================
     Host name              : MyComputerName
     OS Name                : Windows 10
     System Model           : Windows 10 Pro
     Processor architecture : x64 (AMD or Intel)
     IPv4 Address           : 192.168.1.100 192.168.1.101
     Registered Owner       : MyUsername

  - console output:
      Host name              : Successfully get Host Name
      Os Name                : Successfully get Os Name
      System Model           : Successfully get System Model
      Processor architecture : Successfully get Processor architecture
      IPv4 Address           : Successfully retrieved IPv4 Address
      Registered Owner       : Successfully get registered Owner
      
      Enter to exit...

HOW TO RUN THIS PROGRAM :
- TO RUN THIS PROGRAM MAKE SURE ADD THIS COMMAND -lws2_32, for example :
    g++ main.cpp -o out -lws2_32 
