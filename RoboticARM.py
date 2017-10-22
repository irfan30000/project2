#TITLE:-Develop Robotics(stepper motor) Application using Beagle Board.
#ASSIGNMENT NO:
#BATCH:T
#------------------------------------------------------------------

#!/usr/bin/python 
##########################################################
# * Python code (Adafruit BBIO Library Version) for 
# * Square/Sine wave generation using ADC-DAC Card and 
# * Beaglebone Black running Debian 7 Linux distribution
##########################################################
# * Developed by MicroEmbedded Technologies
##########################################################
 
# Import standard python libraries
import sys
import os
import time
from array import*

# Import GPIO part of Adafruit BBIO Library
import Adafruit_BBIO.GPIO as GPIO
# Import ADC part of Adafruit BBIO Library
import Adafruit_BBIO.ADC as ADC



##############################################################
# GPIO Pin definitions for Stepper Interfacing Board 
# Please refer "MicroEmbedded_BBB_Interfacing Details_New.pdf" 
# for all the PIN details
##############################################################

STEPPER_1   =    "P9_11"
STEPPER_2   =    "P8_7"
STEPPER_3   =    "P9_12"
STEPPER_4   =    "P8_8"
 	
MOTOR_EN    =    "P8_9"
ARM_ON	    =    "P9_26"	
ARM_STOP    =    "P8_17"
MAGNET_CTL  =    "P9_13"

START_ANGLE  = 30
STOP_ANGLE   = 120

##############################################################
# Description 	: This function turns the Motor COntrol ON or OFF  
# Input		: "1" will turn it ON and "0" will turn it OFF
# Return	: None	 
# Note		: 
##############################################################

def MOTOR_Control(val):
	GPIO.setup(MOTOR_EN, GPIO.OUT)
	if (val == "1"):
		GPIO.output(MOTOR_EN, GPIO.HIGH)
	else:
		GPIO.output(MOTOR_EN, GPIO.LOW)
	return 

##############################################################
# Description 	: This function turns the stepper PIN ON 
# 		  It will setup a PIN as GPIO, sets the 
# 		  direction as OUT and then makes the PIN high  
# Input		: @pin = Pin No associated with LED
# Return	: None	 
# Note		: 
##############################################################

def Stepper(pin, val):
	GPIO.setup(pin, GPIO.OUT)
	if (val == "1"):
		GPIO.output(pin, GPIO.HIGH)
	else:
		GPIO.output(pin, GPIO.LOW)
	return 

##############################################################
# Description 	: This function writes the sequence on stepper motor pins
#		  While writing start from LSB, hence LSB
#		  goes to stepper pin #1 	 
# Input		: None	 
# Return	: None	 
##############################################################

global NXT_STEP
STEP = array('i',[8,10,2,6,4,5,1,9])
stp_cnt=0
NXT_STEP = STEP[0]

def REV_StepMotor(val):
	global stp_cnt
	#CUR_STEP = STEP[stp_cnt]
	MOTOR_Control("0")
	Stepper(STEPPER_1, val[3])
	Stepper(STEPPER_2, val[2])
	Stepper(STEPPER_3, val[1])
	Stepper(STEPPER_4, val[0])
	MOTOR_Control("1")
	stp_cnt+=1
	NXT_STEP = STEP[stp_cnt]		
	#print "%d" %NXT_STEP
	if(stp_cnt ==7):
		stp_cnt = 0
	return NXT_STEP 


def FW_StepMotor(val):
	global stp_cnt
	#CUR_STEP = STEP[stp_cnt]
	MOTOR_Control("0")
	Stepper(STEPPER_1, val[3])
	Stepper(STEPPER_2, val[2])
	Stepper(STEPPER_3, val[1])
	Stepper(STEPPER_4, val[0])
	MOTOR_Control("1")
	NXT_STEP = STEP[7-stp_cnt]		
	#print "%d" %NXT_STEP
	stp_cnt+=1
	if(stp_cnt>7):
		stp_cnt = 0
	#print "%d" %stp_cnt
	return NXT_STEP 
#main

GPIO.setup(ARM_ON, GPIO.IN)
GPIO.setup(ARM_STOP, GPIO.IN)
GPIO.setup(MAGNET_CTL, GPIO.OUT)

while True:
	while(GPIO.input(ARM_STOP)):
			#print "Main NXT STEP = %d" %NXT_STEP
			stp_seq = str('{:04b}'.format(NXT_STEP))
			NXT_STEP = REV_StepMotor(stp_seq)
			time.sleep(0.1)			# pause
	time.sleep(1)			# pause		
	for i in range(0,START_ANGLE):  
			stp_seq = str('{:04b}'.format(NXT_STEP))
			NXT_STEP = FW_StepMotor(stp_seq)
			time.sleep(0.1)			# pause
	time.sleep(1)			# pause		
	GPIO.output(MAGNET_CTL, GPIO.HIGH)
	time.sleep(1)			# pause		
	for i in range(START_ANGLE+1, STOP_ANGLE):  
			stp_seq = str('{:04b}'.format(NXT_STEP))
			NXT_STEP = FW_StepMotor(stp_seq)
			time.sleep(0.1)			# pause
	GPIO.output(MAGNET_CTL, GPIO.LOW)
	time.sleep(30)			# pause		
	exit()

#-----------------OUTPUT-----------------------------------------------

#-------------------ON HOST SYSTEM----------------------

admin1@proj-17:~$ cd Desktop
admin1@proj-17:~/Desktop$ scp RoboticARM.py root@192.168.7.2:/home
Debian GNU/Linux 7

BeagleBoard.org BeagleBone Debian Image 2014-04-23

Support/FAQ: http://elinux.org/Beagleboard:BeagleBoneBlack_Debian
RoboticARM.py                                 100% 4111     4.0KB/s   00:00    
admin1@proj-17:~/Desktop$

#--------------------ON TARGET SYSTEM----------------------

admin1@proj-17:~$ ssh root@192.168.7.2
Debian GNU/Linux 7

BeagleBoard.org BeagleBone Debian Image 2014-04-23

Support/FAQ: http://elinux.org/Beagleboard:BeagleBoneBlack_Debian
Last login: Wed Apr 23 20:23:51 2014 from comp-swl-06.local
root@beaglebone:~# ls
RoboticARM.py  a.out  evenodd  proj
root@beaglebone:~# python RoboticARM.py

root@beaglebone:~# poweroff

Broadcast message from root@beaglebone (pts/0) (Wed Apr 23 20:24:24 2014):
The system is going down for system halt NOW!
root@beaglebone:~# Connection to 192.168.7.2 closed by remote host.
Connection to 192.168.7.2 closed.
admin1@proj-17:~$ 



