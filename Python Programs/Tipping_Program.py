#tipper program
#takes input of total dollar amount, and then how much you want to tip

bill = float(input("how much was your bill? "))

percentTip = float(input("what percentage do you want to tip? "))
percentTip /= 100

bill = bill + (bill * percentTip)

print("your total is: ", bill)
