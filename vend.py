from kivy.app import App
from kivy.uix.gridlayout import GridLayout
from kivy.properties import NumericProperty
from kivy.properties import ObjectProperty
from kivy.properties import StringProperty

class vend(GridLayout):
    Num = StringProperty('[color=224422][size=64]Test') 
    

class vendApp(App):
    def build(self):
        return vend()

if __name__ == '__main__':
    vendApp().run()
