#! /usr/bin/python
from Tkinter import *

root = Tk()
Label(root, text="Enter number of players").pack(side=TOP)

e = Entry()
e.pack(side=BOTTOM)

e.focus_set()
def callback():
    return e.get()

e.delete(0, END)

b = Button(root, text="get", width=10, command=callback)
b.pack()
root.mainloop()

players = e.get() 
print(players)
