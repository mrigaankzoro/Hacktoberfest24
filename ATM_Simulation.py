from datetime import datetime
import time
print("Insert Card")
time.sleep(2)
Account_balance= 10000
Password= 1234
print("""Welcome!!! 
Account Balance Enquiry = 1 
Cash Withdrawal = 2
Cash Deposit = 3
Password Change = 4
Transaction History = 5
Exit = 6 """)
Transaction_history={}
while True:
  dt= datetime.now()
  choice = int(input("Enter your choice - "))
  Verify= int(input("Enter password to verify yourself - "))
  if Password==Verify:
     if choice==1:
         print("Your account balance is",Account_balance,"\nExit = 0\nContinue = 1")
         n= int (input("Enter - "))
         if n==1:
             continue
         elif n==0:
             break
         else:
             print("Invalid input!! Enter either 0 or 1.")
     elif choice==2:
         Withdrawal_amount= int(input("Enter amount to be withdrawn - "))
         if Account_balance>=Withdrawal_amount:
             Account_balance-=Withdrawal_amount
             print("Cash Withdrawn Successfully. Current account balance is",Account_balance)
             Transaction_history[dt]=(f"{Withdrawal_amount} amount of cash Withdrawn")
             n= int (input("Exit = 0\nContinue = 1\nEnter - "))
             if n==1:
                 continue
             elif n==0:
                 break
             else:
                 print("Invalid input!! Enter either 0 or 1.")
         else:
             print("Insufficient Account Balance")
             Transaction_history[dt]=("Unsuccessful Transaction due to insufficient balance.")
             n= int (input("Exit = 0\nContinue = 1\nEnter - "))
             if n==1:
                continue
             elif n==0:
                break
             else:
                print("Invalid input!! Enter either 0 or 1.")
     elif choice==3:
         Deposit_amount= int(input("Enter amount to be deposited - "))
         Account_balance+=Deposit_amount
         print("Cash deposited successfully. Current Account Balance is",Account_balance)
         Transaction_history[dt]=(f"{Deposit_amount} amount of cash deposited")
         n= int (input("Exit = 0\nContinue = 1\nEnter - "))
         if n==1:
             print("""Welcome!!! 
             
             continue
         elif n==0:
             break
         else:
             print("Invalid input!! Enter either 0 or 1.")
     elif choice==4:
         Password= int(input("Enter new password - "))
         print("New password has been successfully set")
         n= int (input("Exit = 0\nContinue = 1\nEnter - "))
         if n==1:
             print("""Welcome!!! 
             Account Balance Enquiry = 1 
             Cash Withdrawal = 2
             Cash Deposit = 3
             Password Change = 4
             Transaction History = 5
             Exit = 6 """)
             continue
         elif n==0:
             break
         else:
             print("Invalid input!! Enter either 0 or 1.")
     elif choice==5:
         print("Transaction history :-\n")
         for key,value in Transaction_history.items():
             print(f"{key} -- {value}")
         n= int (input("Exit = 0\nContinue = 1\nEnter - "))
         if n==1:
             print("""Welcome!!! 
             Account Balance Enquiry = 1 
             Cash Withdrawal = 2
             Cash Deposit = 3
             Password Change = 4
             Transaction History = 5
             Exit = 6 """)
             continue
         elif n==0:
             break
         else:
             print("Invalid input!! Enter either 0 or 1.")
     else:
         print("Invalid input!! Enter your choice from 1 to 5")
  else:
    print("Incorrect password. Try again later.")

