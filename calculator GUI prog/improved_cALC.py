import tkinter as tk

# Initialize the main application window
root = tk.Tk()

fnum = sec_num = operator = None
root.title("Calculator")

def getop(op):
    global fnum, operator
    fnum = float(result_label['text']) if result_label['text'] else 0  # Corrected variable name
    operator = op
    clr()

def print_text(s):
    current = result_label['text']
    new = current + str(s)
    result_label.config(text=new) 

def clr():
    result_label.config(text='')

def result():
    global fnum, operator, sec_num

    sec_num = float(result_label['text']) if result_label['text'] else 0  # Corrected variable name

    if operator == '+':
        result_label.config(text=str(fnum + sec_num))
    elif operator == '-':
        result_label.config(text=str(fnum - sec_num))
    elif operator == '*':
        result_label.config(text=str(fnum * sec_num))
    elif operator == '/':
        if sec_num == 0:
            result_label.config(text='Error')
        else:
            result_label.config(text=str(round(fnum / sec_num, 2)))

root.geometry('350x460')
root.resizable(0, 0)
root.configure(bg='black')

result_label = tk.Label(root, text='', bg='black', fg='white')
result_label.grid(row=0, column=0, pady=(40, 20), columnspan=6, sticky='w')
result_label.config(font=('verdana', 30, 'bold'))

# Number buttons
btn7 = tk.Button(root, text='7', bg='green', fg='white', width=7, height=3, command=lambda: print_text(7))
btn8 = tk.Button(root, text='8', bg='green', fg='white', width=7, height=3, command=lambda: print_text(8))
btn9 = tk.Button(root, text='9', bg='green', fg='white', width=7, height=3, command=lambda: print_text(9))
btn4 = tk.Button(root, text='4', bg='green', fg='white', width=7, height=3, command=lambda: print_text(4))
btn5 = tk.Button(root, text='5', bg='green', fg='white', width=7, height=3, command=lambda: print_text(5))
btn6 = tk.Button(root, text='6', bg='green', fg='white', width=7, height=3, command=lambda: print_text(6))
btn1 = tk.Button(root, text='1', bg='green', fg='white', width=7, height=3, command=lambda: print_text(1))
btn2 = tk.Button(root, text='2', bg='green', fg='white', width=7, height=3, command=lambda: print_text(2))
btn3 = tk.Button(root, text='3', bg='green', fg='white', width=7, height=3, command=lambda: print_text(3))
btn0 = tk.Button(root, text='0', bg='green', fg='white', width=7, height=3, command=lambda: print_text(0))

# Operator buttons
btn_add = tk.Button(root, text='+', fg='white', bg='green', width=7, height=3, command=lambda: getop('+'))
btn_sub = tk.Button(root, text='-', fg='white', bg='green', width=7, height=3, command=lambda: getop('-'))
btn_mult = tk.Button(root, text='*', fg='white', bg='green', width=7, height=3, command=lambda: getop('*'))
btn_div = tk.Button(root, text='/', fg='white', bg='green', width=7, height=3, command=lambda: getop('/'))
btn_eq = tk.Button(root, text='=', fg='white', bg='green', width=7, height=3, command=lambda: result())
btn_clr = tk.Button(root, text='C', fg='white', bg='green', width=7, height=3, command=clr)

# Button layout
btn0.grid(row=7, column=1)
btn7.grid(row=4, column=0)
btn8.grid(row=4, column=1)
btn9.grid(row=4, column=2)
btn4.grid(row=5, column=0)
btn5.grid(row=5, column=1)
btn6.grid(row=5, column=2)
btn1.grid(row=6, column=0)
btn2.grid(row=6, column=1)
btn3.grid(row=6, column=2)
btn_add.grid(row=4, column=3)
btn_sub.grid(row=5, column=3)
btn_mult.grid(row=6, column=3)
btn_div.grid(row=7, column=3)
btn_eq.grid(row=7, column=2)
btn_clr.grid(row=7, column=0)

# Set button fonts
for button in [btn0, btn7, btn8, btn9, btn4, btn5, btn6, btn1, btn2, btn3, btn_add, btn_sub, btn_mult, btn_div, btn_eq, btn_clr]:
    button.config(font=('verdana', 14, 'bold'))

# Run the application
root.mainloop()
