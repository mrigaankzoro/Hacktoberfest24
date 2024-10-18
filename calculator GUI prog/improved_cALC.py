import tkinter as tk

# Initialize the main application window
root = tk.Tk()
root.title("Calculator")
root.geometry('350x460')
root.resizable(0, 0)
root.configure(bg='black')

# Global variables for operands and operator
fnum = sec_num = operator = None

# Function to set the operator and clear the display
def getop(op):
    global fnum, operator
    fnum = int(result_label['text'])
    operator = op
    clr()

# Function to append numbers to the display
def print_text(s):
    current = result_label['text']
    new = current + str(s)
    result_label.config(text=new)

# Function to clear the display
def clr():
    result_label.config(text='')

# Function to calculate and display the result
def result():
    global fnum, operator, sec_num
    sec_num = int(result_label['text'])

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
            result_label.config(text=str(round(fnum / sec_num)))

# Create and configure the result label
result_label = tk.Label(root, text='', bg='black', fg='white', font=('verdana', 30, 'bold'))
result_label.grid(row=0, column=0, pady=(40, 20), columnspan=6, sticky='w')

# Create number buttons
buttons = [
    ('7', 4, 0), ('8', 4, 1), ('9', 4, 2),
    ('4', 5, 0), ('5', 5, 1), ('6', 5, 2),
    ('1', 6, 0), ('2', 6, 1), ('3', 6, 2),
    ('0', 7, 1)
]

for (text, row, col) in buttons:
    btn = tk.Button(root, text=text, bg='green', fg='white', width=7, height=3,
                    command=lambda s=text: print_text(s))
    btn.grid(row=row, column=col)
    btn.config(font=('verdana', 14, 'bold'))

# Create operator buttons
operators = [
    ('+', 4, 3), ('-', 5, 3), ('*', 6, 3), ('/', 7, 3),
    ('=', 7, 2), ('C', 7, 0)
]

for (text, row, col) in operators:
    if text == '=':
        btn = tk.Button(root, text=text, fg='white', bg='green', width=7, height=3,
                        command=result)
    elif text == 'C':
        btn = tk.Button(root, text=text, fg='white', bg='green', width=7, height=3,
                        command=clr)
    else:
        btn = tk.Button(root, text=text, fg='white', bg='green', width=7, height=3,
                        command=lambda s=text: getop(s))
    
    btn.grid(row=row, column=col)
    btn.config(font=('verdana', 14, 'bold'))

# Start the main event loop
root.mainloop()
