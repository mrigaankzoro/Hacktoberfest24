import tkinter as tk

# Initialize the main application window
root = tk.Tk()
root.title("Calculator")
root.geometry('350x460')
root.resizable(0, 0)
root.configure(bg='black')

# Global variables to hold the first number, second number, and operator
fnum = sec_num = operator = None

# Function to set the operator and first number
def getop(op):
    global fnum, operator
    fnum = int(result_label['text']) if result_label['text'] else 0
    operator = op
    clr()

# Function to append text to the display
def print_text(s):
    current = result_label['text']
    new = current + str(s)
    result_label.config(text=new)

# Function to clear the display
def clr():
    result_label.config(text='')

# Function to calculate the result based on the operator
def result():
    global fnum, operator, sec_num
    sec_num = int(result_label['text']) if result_label['text'] else 0

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

# Create the display label
result_label = tk.Label(root, text='', bg='black', fg='white', font=('verdana', 30, 'bold'))
result_label.grid(row=0, column=0, pady=(40, 20), columnspan=6, sticky='w')

# Create buttons
buttons = [
    ('7', 4, 0), ('8', 4, 1), ('9', 4, 2),
    ('4', 5, 0), ('5', 5, 1), ('6', 5, 2),
    ('1', 6, 0), ('2', 6, 1), ('3', 6, 2),
    ('0', 7, 1), ('+', 4, 3), ('-', 5, 3),
    ('*', 6, 3), ('/', 7, 3), ('=', 7, 2),
    ('C', 7, 0)
]

# Create and place buttons in the grid
for (text, row, col) in buttons:
    if text.isdigit():
        command = lambda x=text: print_text(x)
    elif text == '=':
        command = result
    elif text == 'C':
        command = clr
    else:
        command = lambda x=text: getop(x)
    
    button = tk.Button(root, text=text, bg='green', fg='white', width=7, height=3, command=command)
    button.config(font=('verdana', 14, 'bold'))
    button.grid(row=row, column=col)

# Run the application
root.mainloop()
