from tkinter import *    # Carga módulo tk (widgets estándar)
from tkinter import ttk  # Carga ttk (para widgets nuevos 8.5+)
import time
import serial
import sys


raiz = Tk()
voltaje1 = 0
voltaje2 = 0
voltaje3 = 255



def mas():
    elemento = 43
    try:
        numero = int(elemento)
        numero = numero.to_bytes(1,'little')
        ser.write(numero)
        ser.flushOutput()
        raiz.update()
        time.sleep(0.1)
    except TypeError:
        print('no')

    print(chr(elemento))

def menos():
    elemento = 45
    try:
        numero = int(elemento)
        numero = numero.to_bytes(1,'little')
        ser.write(numero)
        ser.flushOutput()
        raiz.update()
        time.sleep(0.1)
    except TypeError:
        print('no')

    print(chr(elemento))


raiz.geometry('400x300') # anchura x altura



raiz.configure(bg = 'yellow')
raiz.title('Interfaz Gráfica COM-Serial')

# Define un botón en la parte inferior de la ventana
# que cuando sea presionado hará que termine el programa.
# El primer parámetro indica el nombre de la ventana 'raiz'
# donde se ubicará el botón
#BOTON DE SALIR
ttk.Button(raiz, text='Salir', command=quit).pack(side=BOTTOM)

#LETREROS DE VOLTAJES
hola1 = Label(raiz,text="Pot1" ,fg="blue",font=(30)).place (x=50, y= 100)
hola2 = Label(raiz,text="Pot2" ,fg="blue",font=(30)).place (x=50, y= 150)
hola3 = Label(raiz,text="Contador" ,fg="blue",font=(30)).place (x=50, y= 200)
nombre1 = Label(raiz, text="Vincenzo Musella" ,fg= "black", font=(30)).place (x=120, y=10)

#leer datos
voltaje1 = Label(raiz,text=str(voltaje1) ,fg="red",font=(30))
voltaje1.place(x=200, y= 100)
voltaje2 = Label(raiz,text=str(voltaje2) ,fg="red",font=(30))
voltaje2.place(x=200, y= 150)
voltaje3 = Label(raiz,text=str(voltaje3) ,fg="red",font=(30))
voltaje3.place(x=200, y= 200)

#sim
h1 = Label(raiz,text="V" ,fg="red",font=(30)).place (x=250, y= 100)
h2 = Label(raiz,text="V" ,fg="red",font=(30)).place (x=250, y= 150)

ttk.Button(raiz, text='Incrementa', command=mas).place(x=250, y= 200)
ttk.Button(raiz, text='Decrementa', command=menos).place(x=250, y= 230)

raiz.mainloop()
