import tkinter as tk

root = tk.Tk()

fnum = sec_num = operator = None
root.title("Calculator")

def getop(op):
    global fnum, operator
    fnum = float(result_label['text'])
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

    sec_num = float(result_label['text'])

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
            result_label.config(text=str(fnum / sec_num))

root.geometry('350x460')
root.resizable(0, 0)
root.configure(bg='black')

result_label = tk.Label(root, text='', bg='black', fg='white', font=('verdana', 30, 'bold'))
result_label.grid(row=0, column=0, pady=(40, 20), columnspan=6, sticky='w')

buttons = [
    ('7', 4, 0), ('8', 4, 1), ('9', 4, 2),
    ('4', 5, 0), ('5', 5, 1), ('6', 5, 2),
    ('1', 6, 0), ('2', 6, 1), ('3', 6, 2),
    ('0', 7, 1), 
    ('+', 4, 3), ('-', 5, 3), ('*', 6, 3), ('/', 7, 3),
    ('=', 7, 2), ('C', 7, 0)
]

for (text, row, col) in buttons:
    if text == 'C':
        btn = tk.Button(root, text=text, bg='green', fg='white', width=7, height=3, command=clr)
    elif text == '=':
        btn = tk.Button(root, text=text, bg='green', fg='white', width=7, height=3, command=result)
    else:
        btn = tk.Button(root, text=text, bg='green', fg='white', width=7, height=3, command=lambda t=text: print_text(t))
    
    btn.grid(row=row, column=col)
    btn.config(font=('verdana', 14, 'bold'))

root.mainloop()
