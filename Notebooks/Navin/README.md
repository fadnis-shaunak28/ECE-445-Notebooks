## Week 1 (2/5)
Objective of the Week: Build off of our initial project proposal post and complete our RFA Proposal

Tasks Accomplished:
- Met with my team members, Varun and Shaunak, to work on completing RFA in a timely and satisfactory manner
- Also met with our TA, Zicheng Ma, for our first weekly meeting to discuss important details for our semester such as lab notebooks, deadlines, and goals for our project
- Worked on understanding requirements and design specifications for the sensor and software subsystems of our product
- Worked on a tolerance analysis using specific heat capacity equation (as follows):

![Example Image](tolanalysis)

## Week 2 (2/12)

Objective of the Week: Beginning the final draft of our design document highlighting design schematics, requirements and verifications, and cost analysis 

Tasks Accomplished:
- In our weekly meeting with TA Zicheng, we received feedback and discussed things to build off of from our RFA Proposal as we continued to work on our design document
- Assisted in creating the sensor schematic, finding our parts and details regarding labor costs, fine-tuning our high-level requirements as it pertains to our product design goals.

## Week 3 (2/19)
Objective of the Week: Complete the design document, start guaging how to go about PCB schematic and implementation of key subsystem components

Tasks Accomplished:
- Finished our final list for part orders and began looking into PCB design
- Met with TA Zicheng to address questions we had regarding design document features as well as ideas for our subsystem implementations
- Looked into safety and ethic protocols that were mandatory in for marketing/using our product (IEEE Code of Ethics)

## Week 4 (2/26)
Objective of the Week: Improve upon design document, prepare for design review, and revisit RFA Proposal to make revisions based on feedback and design document content. Also looked into (briefly) working on software application for product

Tasks Accomplished:
- Design review with Professor Gruev. Professor mentioned was using a P-Type mosfet and buck converter to allow for power to pass through to our heating subsystem in a more efficient manner. Also emphasized importance of feedback loop consideration within our product 
- Began looking into developing the software with Varun. We met up and started outlining the design for the front-end in Xcode.
- Made the necessary changes to our RFA based on updated block diagram and fine-tuning of high-level requirements and R&V table
  
## Week 5 (3/4)
Objective of the Week: Have parts ordered and begin working in Xcode to develop Swift iOS mobile application.

Tasks Accomplished:
- Completed team evaluation to help course staff and Professors guage member involvement
- Varun and I added button inputs and event listeners for the Swift mobile app
- Lighter week as I prepared to head home for spring break

## Week 6 (Spring Break 3/11)

## Week 7 (3/18)
Objective of the Week: Have our PCB finalized to be ready for 3rd round order, complete front-end for mobile application

Tasks accomplished
- We were able to have our first PCB order sent in!
- Other Digikey and Amazon parts have started to come in, orders for semester all finalized (for the most part)
- mobile application UI finished, with three buttons for low, medium, and high heating and a cooling, as well as bluetooth connect/disconnect button (see below):

  


## Week 8 (3/25)
Objective of the Week: For me the objective of this week is to work on the ESP 32 dev kit and write code for bluetooth infrastructure

Tasks accomlished
- My team and I sent in third wave orders for PCB.
- This week I was able to get bluetooth code working on the ESP32. I was able to test this via an nrfi editor that scans for blueooth signals. In my code, I utilized bluetooth low energy (BLE); however, I might switch to Bluetooth Serial as the signal cannot be seen on the normal bluetooth settings.
- In addition to this, I also worked with Navin to test out the software subsystem on iOS. We did not have much luck in deploying the code, we also thought of alternative ways to build the app, such as MIT app inventor. We decided that we will parallely work on the Software subsytem, with Navin working on the iOS side, and I will work on the MIT app inventor side. 

Attachments:
![image](https://github.com/fadnis-shaunak28/ECE-445-Notebooks/assets/157566074/788a4cfe-ffd0-447c-98a4-76304c8ecb8c)
![image](https://github.com/fadnis-shaunak28/ECE-445-Notebooks/assets/157566074/c8c572d1-2160-4ef5-a5c2-cf722cf16ad2)



## Week 9 (4/1)
Objective of the Week: This week my objective is to continue working on the control subsystem features, such as bluetooth connectivity and IR sensor integration. I also plan on working with Navin to finalize our software subsystem. 

Tasks accomplished:
- This week I was able to finish up the bluetooth connectivity with Bluetooth serial. With bluetooth serial, I am able to see the bluetooth device on the device list. I also took some readings of the signal strenght and noticed that within 20 meters, the ESP32 signal strenght is relatively good.
- I also began assembling the IR sensor on the breadboard. At first some of the wires were a little bit lose, so testing it was a bit of a problem. For future use,
I think we should solder on the IR sensor to a mount.
- Finally, I also finished making the app in MIT app inventor. Navin and I decided it would be easier for us to use MIT app inventor since it provides easy to use code and testing. XCode/Swift on the other hand, would require us to continiously deploy app to iPhone, which made hte proceess a lot harder.
  
Attachments:
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


