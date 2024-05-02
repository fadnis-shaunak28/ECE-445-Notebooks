
## Week 1 (2/5)
Objective of the Week: The objective of this week was to discuss with my group members what we should design for our project. Objectively, I want to ensure that the projects will meet all the requirements for hardware and software components, as well as outline what I have demonstrated as an engineers throughout my curiculum.

Tasks Accomplished:
- This week I met with my team members Navin and Shaunak to decide on a final project. We all outlined our strengths and weaknesses to see what project goals best suit us. Since I prefer working with software and firmware, I proposed the idea of a bluetooth burner which incorperated all software, firmware, and hardware components.
- I also met with my TA, Zicheng, to discuss project goals and how the outlook of the semester will go. We also outlined meeting times and other responsibilities that my group and I am to follow, such as high level requirements, lab notebooks, and due dates. 
- Towards the end of the week, we began filling out the project proposal on the course website. While doing this, I took the time to research more about our project and sketch and brief outline of the high level component structure. Additionally, we made sure to answer any questions asked by professor.

Goals for the following week:
- Begin writing design document and researching subsystems involved with the bluetooth burner.
- Investigate parts and potential methods for design and verification, especially regarding bluetooth connectivity and heating.
## Week 2 (2/13)

Objective of the Week: The objective of this week was to contribute to writing the design document for the Bluetooth burner. This included starting the initial drafts of the design document, while also investigating potential methods for design and verification.

Tasks Accomplished:
- This week I got a chance to look at our prosal and review them with Zicheng along with some comments from Professor Gruev. Some of these comments included a higher level block diagram which included more labeling for I/O pins as well as chart labels.
- Additioanlly, I looked at parts that would be helpful for constructing our bluetooth burner. This included the arduino/microcontroller of choice: ESP32, and the test kit: ESP32- Dev Board. While doing this I also made sure to investigate alternatives such as Arduino Nano	or ESP8266, but the trade offs in bluetooth for processing power did not seem feasable.

Goals for the follow week:
- One thing that we were not able to do this week was begin working on our PCB. This was primarily due to us still figuring out what parts we want to use for the rest of the bluetooth burner.
- Gather materials such as ESP 32 dev kit so that I can begin working on software components. One responsibility that I took on was working on the control and sofware subsystems. 
## Week 3 (2/19)
Objective of the Week: My goal this week was to continue to work on our design document for the upcoming design review,. My team and I aimed to finalize the parts list that we will use and get it approved during the design document. Lastly, I also want to begin designing front-end with Navin. 

Tasks Accomplished:
- This week I spent more time working on the design document and preparing for the design review. This included spending hours with Shaunak and Navin on PCB design as well as finsihing our final list for part orders. 
- One question that Shaunak and I had to ask during office hours was the best methods of heating/cooling. Jason explained to us that the best ways to implement our heating and cooling on the PCB is using a buck converter, so we looked up parts and implementation methods for them.
- Lastly I began working on the control subsystem's circuit design which will be used in the PCB. Somethings that I had to think about while desiging this included external parts and secondary subsystems such as sensor or power subsystems. 

Goals for  the following week:
- This week I did not get as much time as I wanted to to work on the front end part of the project. After the design document, I aim to work on the software component on the dev board or in XCode desigining the app.
- Finish PCB design with Shaunak and Navin and try to get it verified.

## Week 4 (2/26)
Objective of the Week: This our week, my objective is to improve upon the design doc by incorperating the feedback that we will recieve during our design review. I also want to begin on the front-end part of our mobile application, and help Shaunak work on our PCB

Tasks Accomplished:
- This week my team and I went through a design review with Professor Gruev. In this design review we went over the goals of the projects, parts needed, and how we can accomplish these goals. One thing that Professor mentioned was using a P-Type mosfet to allow for power to pass through to our heating subsystem. He outlined that the buck converter can step down the voltage to 5V, then the ptype mosfet will be responsible for allowin voltage to go through.
- We further discussed how we can apply pwm regulation to our heating subsystem to regulate how hot or cold we want our temperature to be. 
- I began also looking into developing the software with Navin. We met up and strated outlining the design for the front-end in Xcode.
- Finally, I send the control subsystem circuit schematic to Shaunak, so that he can apply it onto the PCB and hopefully we can get it approved.

Attachments:
![image](https://github.com/fadnis-shaunak28/ECE-445-Notebooks/assets/157566074/304324dd-f61b-4c61-813a-e8c1dac82358)


Goals for the following week:
- Review Design Doc final rubric with Zicheng to discuess what we can improve upon for the design document regrade.
- Send in part order list and PCB design before spring break
- Continue to work on software development
  
## Week 5 (3/4)
Objective of the Week: Objective of this week is to order all our parts and get our front-end app done in Swift/XCode. Additionally, I want to make sure that I can order some parts such as dev kit, digikey items, and amazon items before spring break. 

Tasks Accomplished:
- This week I was not able to work on the bluetooth burner as much due to the fact that I had midterms going on. However, I was still able to review the design doc for potential improvements.
- Additionally, Navin and I added button inputs and event listeners for the Swift mobile app
- Finally, I sent out an order for all of the parts that we will need for our project.

Goals for the following week:
- Once we recieve our parts we hope to begin building out the burner on the bread board
- Continue working on software component and PCB layout with Navin and Shaunak
## Week 6 (Spring Break 3/11)

## Week 7 (3/18)
Objective of the Week: This week my objective is to finalize and send in our PCB with the help of my team so that we can order by wave 3. 

Tasks accomplished
- One task that we were able to accomplish with the this week was compleating our PCB and sending in the order for wave 3
- Parts have started to come in and I have began to pick them up. One thing that we needed was an ESP 32 Dev kit, but it was all out in the lab, so I ordered a few test kits from Amazon, and began testing with it

Goals for the following week:
- After the dev kits have arrived, write bluetooth software code and test connection with Phone.
- Begin outlining control subsystem code
  
Attachments:
![image](https://github.com/fadnis-shaunak28/ECE-445-Notebooks/assets/157566074/c7cb8a8c-2df4-481e-9822-2c4cc930e6e7)

## Week 8 (3/25)
Objective of the Week: For me the objective of this week is to work on the ESP 32 dev kit and write code for bluetooth infrastructure

Tasks accomlished
- My team and I sent in third wave orders for PCB.
- This week I was able to get bluetooth code working on the ESP32. I was able to test this via an nrfi editor that scans for blueooth signals. In my code, I utilized bluetooth low energy (BLE); however, I might switch to Bluetooth Serial as the signal cannot be seen on the normal bluetooth settings.
- In addition to this, I also worked with Navin to test out the software subsystem on iOS. We did not have much luck in deploying the code, we also thought of alternative ways to build the app, such as MIT app inventor. We decided that we will parallely work on the Software subsytem, with Navin working on the iOS side, and I will work on the MIT app inventor side. 

Goals for the following week:
- Continue to work on the control subsytem, especially bluetooth connection.
- Work on software subsystem on the MIT app inventor side
- Begin assembling IR sensor on breadboard and test IR sensor with ESP 32 Dev Kit.

Attachments:
![image](https://github.com/fadnis-shaunak28/ECE-445-Notebooks/assets/157566074/788a4cfe-ffd0-447c-98a4-76304c8ecb8c)


## Week 9 (4/1)
Objective of the Week: This week my objective is to continue working on the control subsystem features, such as bluetooth connectivity and IR sensor integration. I also plan on working with Navin to finalize our software subsystem. 

Tasks accomplished:
- This week I was able to finish up the bluetooth connectivity with Bluetooth serial. With bluetooth serial, I am able to see the bluetooth device on the device list. I also took some readings of the signal strenght and noticed that within 20 meters, the ESP32 signal strenght is relatively good.
- I also began assembling the IR sensor on the breadboard. At first some of the wires were a little bit lose, so testing it was a bit of a problem. For future use,
I think we should solder on the IR sensor to a mount.
- Finally, I also finished making the app in MIT app inventor. Navin and I decided it would be easier for us to use MIT app inventor since it provides easy to use code and testing. XCode/Swift on the other hand, would require us to continiously deploy app to iPhone, which made hte proceess a lot harder. 
Goal for the following week:
- For the following weeks, I aim to fully integrate the IR sensor with bluetooth code so that it can be displayed on the mobile application.
- Additionally, I will work in Shaunak to begin soldering our PCB in hopes that we can get it working for the final demo

Attachments:
![image](https://github.com/fadnis-shaunak28/ECE-445-Notebooks/assets/157566074/42820ef1-204e-444e-839c-dd93453b0b00)

![image](https://github.com/fadnis-shaunak28/ECE-445-Notebooks/assets/157566074/a1d05f46-7f01-4676-88cd-0320a92995ee)

![image](https://github.com/fadnis-shaunak28/ECE-445-Notebooks/assets/157566074/91b01583-1637-431a-a895-cf30b2ecd8ef)


## Week 10 (4/8)
Objective of the Week: This week I have a few things that must get done. For starters, I need to fully integrate the IR sensor and bluetooth funcionalities. I also will work with Shaunak to try to flash the ESP32 on the PCB. Lastly, I also want to write code for the capcaitative touch wire on the GPIO pins. 

Tasks accomplished:
- This week I was able to interate the IR sensor and Bluetooth connection. Using a NRFI editor, I can see the packets coming into the bluetooth channel. Using UTF-8 decoding, I can see what information is sent in the packets. This will be applied to the front end app hopefully soon.
- Additioanlly, Navin and I worked togeather to assemble capacitative touch on the ESP 32 dev kit. This was relatively quick and only required a few lines of code.
- I didn't get much done on the PCB aside from helping Shaunak stencil a mosfet onto the board.
- Lastly, Navin and I worked on assembling the power subsystem onto the bread oad. We were able to achieve power conversion from 12V power source to a 5V ouptut via a voltage converter. We also implemented a P-Type mosfet on the board to control when power should be released. 

Goal for the following week:
- Wrap up front-end code with Navin and integrate temperature settings along with event listeners to change power
- Test heating subsystem with Shaunak and integrate it with power subsystem and control subsystem
- Continue working on PCB

Attachments:
![image](https://github.com/fadnis-shaunak28/ECE-445-Notebooks/assets/157566074/da955e9b-899a-4175-ba13-2b924528f0a2)
![image](https://github.com/fadnis-shaunak28/ECE-445-Notebooks/assets/157566074/978a4fc1-7b80-45a5-a0c4-c1e9941571b0)


## Week 11 (4/15)
Objective of the Week: This week my goal is to work with my team to connect the major subsystems on the bread board, and possibly on the PCB if our 4th order PCB comes in time. 

Tasks Accomplished:
- This week Navin and I finished connecting the front-end code to the bluetooth channels, allowing for data transmission between ESP32 and the front end to be displayed on the app.
- Additionally, I worked with Shaunak to coil up our resistive coil for the heating subsystem, so that him and Navin can begin testing it and find our temperature ranges.
- In the mean time I also worked on developing power width modulation code for the ESP32, so that it can provide various power outpus and duty cycles for our power and heating subsystems.
- As a team, we tried to solider on the power jack to the PCB; however, when we were testing it, only 1.6V were being outputted. Therefore, we had to scrap the idea of a PCB, and completely more our project to the breadboard.

Goals for the following week:
- For the folliwng week, my goal is to help my team wrap our project and also give a presentation to Professor Gruev and other TA's

Attachments:
![image](https://github.com/fadnis-shaunak28/ECE-445-Notebooks/assets/157566074/49337e23-520a-481e-823c-20bb293544f4)



## Week 12 (4/22)
Objective of the Week: Finish up project on breadboard and present to the class

Tasks Accomplished:
- This week our goal was to finish up as much of our project as we can.
- I was able to link control, software, power, and sensor subsystems togeather with the help of Navin and Shaunak. We ran into problem with the heating subsystem, as our power subsystem was not able to draw enough current to heat up our resistive coil. This made our heating subsystem unusable for the demo
- Overall, we were able to show 4/5 main subsystems and meet 2/3 high level requirements for the project demo

