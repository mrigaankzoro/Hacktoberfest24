import tkinter as tk

root = tk.Tk()

fnum = sec_num = operator = None
root.title("Calculator")

def getop(op):
    global fnum, operator
    fnum = int(result_lable['text'])
    operator = op
    clr()

def print_text(s):
    current = result_lable['text']
    new = current + str(s)
    result_lable.config(text = new) 

def clr():
    result_lable.config(text='')

def result():
    global fnum, operator, sec_num

    sec_num = int(result_lable['text'])

    if(operator == '+'):
        result_lable.config(text=str(fnum+sec_num))
    elif(operator == '-'):
        result_lable.config(text=str(fnum-sec_num))
    elif(operator == '*'):
        result_lable.config(text=str(fnum*sec_num))
    else:
        if(sec_num==0):
            result_lable.config(text='Error')
        else:
            result_lable.config(text=str(round(fnum/sec_num)))

root.geometry('350x460')
root.resizable(0,0)
root.configure(bg='black')

result_lable = tk.Label(root, text='', bg='black', fg='white')
result_lable.grid(row=0,column=0,pady=(40,20),columnspan=6,sticky='w')
result_lable.config(font=('verdana', 30, 'bold'))



btn7 = tk.Button(root, text='7', bg='green', fg='white',width = 7, height =3,command=lambda: print_text(7))
btn8 = tk.Button(root, text='8', bg='green', fg='white',width = 7, height =3,command=lambda:print_text(8))
btn9 = tk.Button(root, text='9', bg='green', fg='white',width = 7, height =3,command=lambda:print_text(9))


btn4 = tk.Button(root, text='4', bg='green', fg='white',width = 7, height =3,command=lambda:print_text(4))
btn5 = tk.Button(root, text='5', bg='green', fg='white',width = 7, height =3,command=lambda:print_text(5))
btn6 = tk.Button(root, text='6', bg='green', fg='white',width = 7, height =3,command=lambda:print_text(6))

btn1 = tk.Button(root, text='1', bg='green', fg='white',width = 7, height =3,command=lambda:print_text(1))
btn2 = tk.Button(root, text='2', bg='green', fg='white',width = 7, height =3,command=lambda:print_text(2))
btn3 = tk.Button(root, text='3', bg='green', fg='white',width = 7, height =3,command=lambda:print_text(3))
btn0 = tk.Button(root, text='0', bg='green', fg='white',width = 7, height =3,command=lambda:print_text(0))

btn_add = tk.Button(root, text='+', fg = 'white', bg='green',width = 7, height=3,command= lambda: getop('+'))
btn_sub = tk.Button(root, text='-', fg = 'white', bg='green',width = 7, height=3,command= lambda: getop('-'))
btn_mult = tk.Button(root, text='*', fg = 'white', bg='green',width = 7, height=3,command= lambda: getop('*'))
btn_div = tk.Button(root, text='/', fg = 'white', bg='green',width = 7, height=3,command= lambda: getop('/'))
btn_eq = tk.Button(root, text='=', fg = 'white', bg='green',width = 7, height=3,command=lambda: result())
btn_clr = tk.Button(root, text='C', fg = 'white', bg='green',width = 7, height=3,command= clr)


btn0.grid(row=7,column=1)
btn0.config(font=('verdana,14,bold'))
btn7.grid(row=4,column=0)
btn7.config(font=('verdana,14,bold'))
btn8.grid(row=4,column=1)
btn8.config(font=('verdana,14,bold'))
btn9.grid(row=4,column=2)
btn9.config(font=('verdana,14,bold'))
btn4.grid(row=5,column=0)
btn4.config(font=('verdana,14,bold'))
btn5.grid(row=5,column=1)
btn5.config(font=('verdana,14,bold'))
btn6.grid(row=5,column=2)
btn6.config(font=('verdana,14,bold'))

btn1.grid(row=6,column=0)
btn1.config(font=('verdana,14,bold'))
btn2.grid(row=6,column=1)
btn2.config(font=('verdana,14,bold'))
btn3.grid(row=6,column=2)
btn3.config(font=('verdana,14,bold'))

btn_add.grid(row=4,column=3)
btn_add.config(font=('verdana,14,bold'))
btn_sub.grid(row=5,column=3)
btn_sub.config(font=('verdana,14,bold'))
btn_mult.grid(row=6,column=3)
btn_mult.config(font=('verdana,14,bold'))
btn_div.grid(row=7,column=3)
btn_div.config(font=('verdana,14,bold'))

btn_eq.grid(row=7,column=2)
btn_eq.config(font=('verdana,14,bold'))
btn_clr.grid(row=7,column=0)
btn_clr.config(font=('verdana,14,bold'))

root.mainloop()