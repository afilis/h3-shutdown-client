AllWinner H2+/H3 system shutdown (client part)
---

The program is intended for prevention of overheating of Orange Pi 
(H2+/H3 based) after switching off. Overheating usually happens if 
you are using Armbian stretch (mainline) on it.  

Build
---
Run these commands on target device (requires: git, gcc, make):  
  git clone https://github.com/afilis/h3-shutdown-client.git  
  cd h3-shutdown-client  
  make  

Install
---
You should install the server part of the program first.
After that run this command on target device (requires: systemd):  
  make install

Info
---
This program based on these projects:  
https://github.com/orangecnc/h3_arisc_firmware  
https://github.com/orangecnc/h3_arisc_api  
https://github.com/Icenowy/h3-arisc-shutdown  
