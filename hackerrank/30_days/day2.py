# Enter your code here. Read input from STDIN. Print output to STDOUT
m = float(raw_input())
t = int(raw_input())
x = int(raw_input())

t = (m * t)/100
x = (m * x)/100

print "The final price of the meal is $" + str(int(round(m+t+x))) + "."
