import serial
import time

sr = serial.Serial('/dev/ttyACM0', 9600)

data = ''

while(True):
    data += sr.read(1)
    if (data[-1:] == '\n'):
        print data
        print '-------'
        data = ''
        sr.flushOutput()
    time.sleep(0.5)

sr.close()

--------------------

sr.write('data')