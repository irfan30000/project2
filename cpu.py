'''Title:Write an application to and demonstrate the change in BeagleBoard/ ARM Cortex A5 /Microprocessor /CPU frequency or square wave of programmable frequency.
Assignment No.:
Batch:T2
------------------------------------------------------------------------------------------------------------'''
#!/usr/bin/python 
import sys
import os
import time

PWM_DIR = "/sys/devices/ocp.3/pwm_test_P8_13.15"
PWM_PERIOD = 20000000
PWM_DUTY = 18000000

def pwmWritePeriod(val):
	try: 
   		fo = open(PWM_DIR + "/period","w")  
   		fo.write(val)
   		fo.close()
   		return
   	except IOError:
 		return

def pwmWriteDuty(val):
	try: 
   		fo = open(PWM_DIR + "/duty","w")  
   		fo.write(val)
   		fo.close()
   		return
   	except IOError:
 		return
 		
def pwmReset():
	try: 
   		fo = open(PWM_DIR + "/run","w")  
   		fo.write("0")
   		fo.close()
   		return
   	except IOError:
 		return 		
 		
def pwmStart():
	try: 
   		fo = open(PWM_DIR + "/run","w")  
   		fo.write("1")
   		fo.close()
   		return
   	except IOError:
 		return

print "\nSquare wave of Programmable frequency using Python\n"
print  "--------------------------------------------------------------------------------------\n" 	
pwmWritePeriod(str(PWM_PERIOD))
pwmWriteDuty(str(PWM_DUTY))
pwmReset()
time.sleep(2)
pwmStart()
for i in range(0,9):
	PWM_DUTY = PWM_DUTY - 1000000
	pwmWriteDuty(str(PWM_DUTY))
	time.sleep(1)
	print "increasing duty"
print"------------------------"
for i in range(0,9):
	PWM_DUTY = PWM_DUTY + 1000000
	pwmWriteDuty(str(PWM_DUTY))
	time.sleep(1)
	print "decreasing duty"
pwmReset()	
exit()

'''---------------------------------------------------------------

OUTPUT:
TERMINAL 1:
comp-sl-22@compsl22-OptiPlex-3020:~$ ssh root@192.168.7.2
Debian GNU/Linux 7

BeagleBoard.org BeagleBone Debian Image 2014-04-23

Support/FAQ: http://elinux.org/Beagleboard:BeagleBoneBlack_Debian
Last login: Wed Apr 23 20:20:21 2014 from compsl22-optiplex-3020.local
-------------------------------------------------------------------------
TERMINAL 2:
comp-sl-22@compsl22-OptiPlex-3020:~$ scp pwm.py root@192.168.7.2:/home
Debian GNU/Linux 7

BeagleBoard.org BeagleBone Debian Image 2014-04-23

Support/FAQ: http://elinux.org/Beagleboard:BeagleBoneBlack_Debian
pwm.py                                        100% 1291     1.3KB/s   00:00    
comp-sl-22@compsl22-OptiPlex-3020:~$ 
---------------------------------------------------------------------------
TERMINAL 1
root@beaglebone:~# cd /home
root@beaglebone:/home# ls
a.out  debian  e3  elevator.cpp  elevator.py   pwm.py  sneha.py 
root@beaglebone:/home# echo am33xx_pwm > /sys/devices/bone_capemgr.9/slots 
root@beaglebone:/home# echo bone_pwm_P8_13 > /sys/devices/bone_capemgr.9/slots
root@beaglebone:/home# python pwm.py

Square wave of Programmable frequency using Python

--------------------------------------------------------------------------------------

increasing duty
increasing duty
increasing duty
increasing duty
increasing duty
increasing duty
increasing duty
increasing duty
increasing duty
------------------------
decreasing duty
decreasing duty
decreasing duty
decreasing duty
decreasing duty
decreasing duty
decreasing duty
decreasing duty
decreasing duty
'''
