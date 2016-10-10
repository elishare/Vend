from kivy.app import App
from kivy.uix.gridlayout import GridLayout
from kivy.properties import NumericProperty
from kivy.properties import ObjectProperty
from kivy.properties import StringProperty
from kivy.network.urlrequest import UrlRequest
import time
import sys
import json
import serial
import urllib2

class vend(GridLayout):
    Num = StringProperty('[color=224422][size=64]Test')
    print Num
    def APIcall(root, str):
        Slot = str
        BaseUrl = 'https://vending-service.herokuapp.com/vend/'
        Url = BaseUrl + Slot
        print Url
        print Num
        req = urllib2.urlopen(Url)
        print req.getcode()
        if (req.getcode() == 200):
            #req = UrlRequest(Url)
            j = req.read()
            thejson = json.loads(j)
            print thejson["inStock"]
            if (thejson["inStock"] == 'true'):
                ser = serial.Serial('/dev/ttyACM0',9600)
                time.sleep(2)
                ser.write(str(Num))
                time.sleep(3)

                serial_line=ser.read(ser.inWaiting())
                print serial_line
            else:
                print "Out of Stock"
        else:
            print "Recieved an error"

class vendApp(App):
    def build(self):
        return vend()

   
    
if __name__ == '__main__':
    vendApp().run()

  
