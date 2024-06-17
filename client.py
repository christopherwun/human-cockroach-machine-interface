import serial
import json
from setup import setup, receivedData

# Port of arduino
ser = serial.Serial('COM5', 9600)

# Get value funtion
def get_value():
    data = json.loads(receivedData.recv())
    if 'met' in data:
        value = data['met']
        return value
    else:
        return -1
    
sum1 = 0
total = 0
avg = 0.5

while not exit_flag:
    val = get_value()
    print(val[2], avg)
    if val[2] > avg:
        ser.write('1'.encode())
        print(1)
    else:
        ser.write('0'.encode())
        print(0)
    sum1+=val[2]
    total+=1
    avg = sum1/total