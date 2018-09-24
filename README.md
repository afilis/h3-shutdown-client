AllWinner H2+/H3 CPU shutdown (client part)
---

No description yet.

Build
---
Run these commands on target device (requires: git, gcc, make):  
  git clone https://github.com/afilis/h3-cpu-shutdown-client.git  
  cd h3-cpu-shutdown-client  
  make  

Install
---
Run this command on target device (requires: systemd):  
  make install

Info
---
This program based on these projects:  
https://github.com/orangecnc/h3_arisc_firmware  
https://github.com/orangecnc/h3_arisc_api  
https://github.com/Icenowy/h3-arisc-shutdown  
