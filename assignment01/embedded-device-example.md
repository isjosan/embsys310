# Field Camera to Monitor Remote Industrial Operations

## 1. Introduction

Remote Industrial Sites present unique challenges to operate efficiently and effectively. Examples of these sites include construction sites, oil rigs, unmanned industrial stations, industrial farms, and weather monitoring stations. The utility power source is either non-existent or available at a premium, WiFi is not guaranteed for 24x7 Internet connection; and you have to contend with the elements of extreme weather. In addition it can be expensive to permanently station human operators at these sites; and every physical visit to the site for installation, maintenance and supervision adds to the cost of performing industrial operations. On the other hand, it is also expensive to deploy a human operator for remote and continuous video surveillance.

As shown in Figure 1. Field Camera is one example of an embedded device that addresses the challenges of Remote Industrial Operations. It is essentially a standalone Camera System that relies on solar and battery power to eliminate dependence on utility power. For Internet Connection, it uses cellular wireless connection. It is used to monitor the remote industrial operations, such as in the physical construction industry.

![Field Camera](https://github.com/isjosan/embsys310/blob/master/assignment01/images/Field-camera.png)
###### Figure 1.  Field Camera Use Case in Construction Industry



## 2. Basic Features

The Field Camera has the following features:
* Form Factor
  * Compact, solar panel < 2' x 2'
  * Portable, can be installed anywhere on site, on a pole or a wall
* Self Sustained
  * Runs on solar and battery power
  * No connection to electric utility
  * Low battery indication via SMS / email alerts
  * Remote restart capability
  * Emergency manual restart
* Quality & Reliability
  * Perform 24 x 7 unattended
  * Withstand extreme outdoor temperature and weather conditions
* Security
  * On board GPS
  * Device Id & Serial # for Unique Identification
  * Hard chip based device & network security
  * Remote device management and health monitoring
  * Automated security alarms, alerts & messaging
  * Keep Alives / beacons / alerts sent periodically to back-end cloud platform
  * Ability to disable dveice remotely
* Wireless Connectivity
  * Secure cellular wireless is primary connection mode
  * Fallback to secoondary secure WiFi connection, if available
  * Latency < 500 ms & Data Rate > 300 Kbps
  * Send & Receive Control & Text messages
* Camera Functions
  * Automated peroidic shots with programmable duration, such as one shot every minute
  * Remote operator controlled shots via cellular wireless Internet connection
  * Option to take timelapse camera shots for short periods of time
  * Local storage of shots for at leasr a 24 hour cycle
  * Programmable upload of stored images to the back-end repository in the cloud
  * Remote camera control from controlling platform; response time < 200 ms
  * 24 x 7 wide angle day and night vision
  * Infra-Red (IR) illuminator for night vision

 ## 3. Design Challenges
 
 ### 3.1   Throughput
 
The Field Camera can transmit images to the back-end system in the Cloud, only as fast as it can take the shots and then convert the image to the expected format before it can be transmitted over the wireless communication link. This will involve digitizing the image into the most efficient picture format that meets the requirements. For example, if the application expects the camera to send at least 1 picture every 15 seconds, the device should process the image fast enough, while also accomodating the transmission delay, and keeping latency less than 500 ms, as listed in the features.  
 
 ### 3.2   Response
When receiving remote control commands from the back-end Cloud, the incoming control messages must be processed in real time, so that control actions can be prioritized and responded within 200 ms, as listed in the features.
Also, the Keep Alives / Alerts / beacons / and other messaging must be processed and sent out in real time.
 
 ### 3.3   Testability
As with any embedded device, ensuring a completely tested Field Camera to cover all possible environment conditions is quite a bit of a challenge. For example, what happens if a combination of environment conditions combined with intermittent failure of network connection leads to a device malfunction. Apart from comprehensive unit testing of the program code, there must be a full suite of end to end testing that closely simluates the actual environment conditions that will be encountered when Camera is installed in a dusty construction site and extreme environment conditions.  
Other uncommon test scenarios will involve fault conditions, such as, what happens when the camera loses network connection; or what happens when the camera crashes and cannot restart; is the automatic recovery mechanism working?
 
 ### 3.4   Troubleshooting (diagnosability)
 A troubleshooting challenge is to find the Root Cause of the failure event. This typically involves a procedure called Root Cause Analysis (RCA). The RCA requires enough traces from the instant that led to the failure event. The primary source is usually the runtime logs that are created and stored while embedded program is running and includes memory core dump, that shows the contents of registers and the stack at the instant of crash. Sometimes these trace logs may not be conclusive and hard effort is required to reproduce the failure event and collect additional detailed logs.  
The Camera device does not have a on-board display or a keyboard connected. So, this will require remote connection to the device over the network connection, or if that is not possible, then local connection to the device with a console cable or bluetooth interface. 
 
 ### 3.5   Reliability
The Camera device is expected to run unattended 24x7. So, it must be robust enough to withstand all environment conditions in the field, such as extreme temperature, moisture, vibration. This requires hardening the software as well as the hardware used to construct the device. Embedded programs running inside the Camera must be hard tested to eliminate any memory leaks, dangling pointers, memory fragmentation etc.; and are usually required by safety oriented industries, such as Construction, Health Care and Automotive, to be compliant with coding standards,for example, MISRA.  
 In addition, the hardware components used to construct the Camera must be able to withstand the extreme environmental conditions at all times.
 
 ### 3.6   Memory Space
The Field Camera requires significant amount of memory storage for Program as well as Data. However, it is not practical to have a large amount of memory as in a desktop computer. So, there is a need to strike a balance between requirement and what is practical. This may include clever programming techniques, such as, data compression, or compressing the size of captured images to reduce memory footprint.  
Another technique would be, to process the images as fast as possible and transmit them to the back-end cloud, so that the precious memory space can be freed up. There is a need to arrive at how long the images can be stored locally on the device, and also what will be the compression overhead for the embedded program.

 ### 3.7   Program Installation
The Field Camera is typically shipped to the site with a starter firmware program, that is just enough for initial boot up and connection to the backend application in the Cloud. Once the initial installation is achieved, the updated version of the firmware that is customized for a typical site will be pushed to the Camera Over The Air (OTA). Any subsequent updates and bug fixes will also be installed using the same process.  
This involves the challenge of automating the software installation and configuration process, and is necessary when installing firmware to large number of Cameras installed at the field sites.
 
 ### 3.8   Power Consumption
 
 
 ### 3.9   Security
 
 
 ### 3.10  Cost
 
 
 
 


