# Autonomous Colored Object Recognition Robot

# <b> Brief Description: </b>

Modern-day technology has revolutionized the way we work. All machines are now becoming autonomous. They are performing every task without the need for human eﬀorts. Robots are used in factories to assemble, manufacture, pick and place parts, replace the components, and many more. In this Project, a robot is built that automatically detects an object around it and then moves towards it and recognizes the object's color. According to the given color the user picks, the robot picks it and brings it back to the user. This bot uses Arduino Uno, a microcontroller board based on the ATmega328P. To detect the object nearby, it uses the hc-sr04 ultrasonic sensor, and when the object is detected, it moves towards it and stops. Then it uses a color sensor TCS 3200, which recognizes the object's color and sends the information to Arduino, which decides whether to pick the object or not. For picking the object, MG995r Servo motor is used. The bot here can do task that generally requires image processing or high cost components; using only a microcontroller and few sensors this bot can be used in factories for assembling where speciﬁc colored products are manufactured like toy making companies. The bot's capabilities can be improved in the future by using more advanced components like raspberry pi and camera modules for image processing.

# <b> Circuit Diagram </b>

![image](https://user-images.githubusercontent.com/53033119/148650960-e0db7d0f-4911-415a-a1ba-a7daaeeffd83.png)

# <b> Working of the System </b>

After doing all connections properly the bot will start to work the working of the bot is described in following steps:-<br>
Step 1:- Detection of object: When the bot is powered on, it starts to move in clockwise direction or in 360 degrees continuously. The ultrasonic sensor starts to work as soon as ultrasonic waves hits the object within the range, the sensor sends data to Arduino and bot will stop rotating at that point and starts to move towards the object. When the bot reaches close enough to the object it stops. Here, ultrasonic sensor is again used to stop at particular distance which is given by the user.

![image](https://user-images.githubusercontent.com/53033119/148651025-6f369ae8-a910-4023-b671-5edbae527c4c.png)

Step 2:- Detection of color: When the bot is near the object the color sensor will start to work it will detect the frequency of the color reﬂected and if the range of the frequency is within the range of red/blue/green color that is speciﬁed by the user it will send the message to Arduino. If here the bot doesn't recognizes the speciﬁed color than it will go backward to its original position.  After some delay it will again starts its searching process.

![image](https://user-images.githubusercontent.com/53033119/148651030-70731193-61c2-4257-a373-736deb921b23.png)

Step 3:- Picking the object: Now the color is recognized, arduino sends high value (1) data to servo motor pin which is attached to a robotic gripper, the motor rotates 180 degrees and therefore opening the gripper mouth. The bot moves little forward and grasp the object.

![image](https://user-images.githubusercontent.com/53033119/148651048-4efed22e-5e75-44d8-bf99-0ee9fbc82475.png)

Step 4:- Placing the object: After grasping the object the bot moves backward to its original location. Arduino again sends instruction to servo motor and gripper opens up.The bot keeps the object and turns to take its position for searching the object again.

![image](https://user-images.githubusercontent.com/53033119/148651051-b066a55e-4b36-424a-bb5e-ecbbd507ce8f.png)


To run entire system Arduino IDE is used which can run on windows platform. The program is made on IDE and then it is compiled and burned into the Arduino Uno board. Procedure for writing program:-

Step 1:- First open the IDE and select your board like here Arduino Uno is selected </br> 
Step 2:- Make sure you have selected right port for your Arduino in this case COM4 is selected.</br>
Step 3:- Open a new sketch</br>
Step 4:- Write your program inside sketch and save it.</br>
Step 5:-Compile your program to see if there is any error.</br>
Step 6:-After successful compilation run your program to see if it works on Arduino.</br>

# <b> Limitations & Future Scope </b>

As the industries are searching for more autonomy, the demand for autonomous bots has increased. The bot designed here is autonomous, capable of recognizing a colored object. The robot uses Arduino, color sensor, and ultrasonic sensor, which helps perform all the tasks here. The bot can search objects within the range of the ultrasonic sensor. Hence, its accuracy is less for detecting an object. The color sensor used to detect color can only work if the bot is very close to the object, limiting the color sensing capabilities. Still, in the future, if a microprocessor like raspberry pi is used, then using a camera module, we can enhance the bot capabilities by computer vision or image processing. The bot then will be able to detect a colored object from long distances and also will be able to reach it without using ultrasonic sensors. We can also use computer vision to make robot place objects at a particular spot.


![IMG_3298](https://user-images.githubusercontent.com/53033119/148635876-b1d6682d-12af-4299-939a-376ee7ba7545.JPG)
