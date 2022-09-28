import random
import winsound
def alarm():
    for i in range(10):
        if i%2==0:
            winsound.Beep(3000,2000)
        else:
            pass
def check_temperature(temp):
    if temp>=1100:
        print('Current temperature is',temp)
        print('Fire is Detected')
        alarm()
    else:
        print('Current temperature is',temp)
        print('Environment is Safe')

temp=random.randint(0,5000)
check_temperature(temp)

