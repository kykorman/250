months=6
salary=500.75

print("%d  %.2f"%(months,salary))

name = input("Enter name: ")

if name=="tom":
	print(250)
elif name == "josh":
	print(245)
else:
	print("huh?")

for i in range(1,10):
	print(i)
	print(name)

total=salary*months
print("%.2f %d"%(total,months))
print("${:,.2f}".format(total))
